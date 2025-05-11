#include "pin.h"

/********************************************************/
/*                         BASE PIN                     */
/********************************************************/
BasePin::BasePin(Node *parentNode, PinDataType pinType, const std::string &id, const std::string &name)
    : m_parentNode(parentNode),
      m_pinDataType(pinType),
      m_id(id),
      m_name(name)
{
}
// GETTERS
PinDataType BasePin::getPinDataType() const
{
    return m_pinDataType;
}
const std::string &BasePin::getId() const
{
    return m_id;
}
const std::string &BasePin::getName() const
{
    return m_name;
}
Node *BasePin::getParentNode() const
{
    return m_parentNode;
}
std::string BasePin::getDataTypeString() const
{
    switch (m_pinDataType)
    {
    case PinDataType::INVALID:
        return std::string("Invalid");
        break;
    case PinDataType::NUMBER:
        return std::string("Number");
        break;
    case PinDataType::BOOLEAN:
        return std::string("Boolean");
        break;
    case PinDataType::COLOR:
        return std::string("Color");
        break;
    case PinDataType::VECTOR:
        return std::string("Vector");
        break;
    default:
        return std::string("Unknown");
        break;
    }
}

/********************************************************/
/*                         INPUT PIN                    */
/********************************************************/
InputPin::InputPin(Node *parentNode, PinDataType pinType, const std::string &id, const std::string &name, DataValue defaultValue)
    : BasePin(parentNode, pinType, id, name)
{
    m_value = defaultValue; // Set default value
    // m_connectedOutputPin already nullptr bc default initializer
}
bool InputPin::isConnected() const
{
    if (m_connectedOutputPin == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}
// Dont need get pin direction, is defined in header
OutputPin *InputPin::getConnectedOutputPin() const
{
    return m_connectedOutputPin;
}
DataValue InputPin::getValue() const
{
    if (m_connectedOutputPin == nullptr)
    {
        return m_value;
    }
    else 
    {
        return m_connectedOutputPin->getValue();
    }
}
void InputPin::setValue(const DataValue &value)
{
    if (m_connectedOutputPin == nullptr)
    {
        m_value = value;
    }
}
// Connections
void InputPin::connect(OutputPin *outputPin)
{
    m_connectedOutputPin = outputPin;
}
void InputPin::disconnect()
{
    m_connectedOutputPin = nullptr;
}

/********************************************************/
/*                         OUTPUT PIN                   */
/********************************************************/
OutputPin::OutputPin(Node *parentNode, PinDataType pinType, const std::string &id, const std::string &name)
    : BasePin(parentNode, pinType, id, name)
{
    // m_connectedOutputPin already nullptr bc default initializer
}
const DataValue &OutputPin::getValue() const
{
    return m_value;
}
void OutputPin::setValue(const DataValue &value)
{
    m_value = value;
}
std::vector<InputPin *> OutputPin::getConnectedInputPins() const
{
    return m_connectedInputPins;
};
// Connections
void OutputPin::connect(InputPin *inputPin)
{
    inputPin->connect(this);
    m_connectedInputPins.push_back(inputPin);
};
void OutputPin::disconnect()
{
    for (InputPin *inputPin : m_connectedInputPins)
    {
        inputPin->disconnect();
    }
    m_connectedInputPins.clear();
};