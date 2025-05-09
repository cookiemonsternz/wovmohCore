#include "node.h"

Node::Node(const std::string id, const std::string name, const std::string type)
    : m_id(id),
      m_name(name),
      m_type(type)
{
}
const std::string &Node::getId() const
{
    return m_id;
};
const std::string &Node::getName() const
{
    return m_name;
};
const std::string &Node::getType() const
{
    return m_type;
};
// Pins
// Find input pin by id
InputPin *Node::getInputPin(const std::string &id) const
{
    auto it = std::find_if(
        m_inputPins.begin(),
        m_inputPins.end(),
        [&id](const std::unique_ptr<InputPin> &pin)
        { return pin->getId() == id; });
    if (it != m_inputPins.end())
    {
        return it->get();
    }
    return nullptr;
};
// Find output pin by id
OutputPin *Node::getOutputPin(const std::string &id) const
{
    auto it = std::find_if(
        m_outputPins.begin(),
        m_outputPins.end(),
        [&id](const std::unique_ptr<OutputPin> &pin)
        { return pin->getId() == id; });
    if (it != m_outputPins.end())
    {
        return it->get();
    }
    return nullptr;
};
// Get all input pins
const std::vector<std::unique_ptr<InputPin>> &Node::getInputPins() const
{
    return m_inputPins;
};
// Get all output pins
const std::vector<std::unique_ptr<OutputPin>> &Node::getOutputPins() const
{
    return m_outputPins;
};

// Protected methods (for derived classes)
void Node::addInputPin(PinDataType pinType, const std::string &id, const std::string &name) {
    m_inputPins.push_back(std::make_unique<InputPin>(this, pinType, id, name));
};
void Node::addOutputPin(PinDataType pinType, const std::string &id, const std::string &name) {
    m_outputPins.push_back(std::make_unique<OutputPin>(this, pinType, id, name));
};