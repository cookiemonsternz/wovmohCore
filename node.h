#ifndef NODE_H
#define NODE_H

#include "DataTypes.h"
#include "pin.h"

#include <string>
#include <vector>
#include <memory>
#include <algorithm> // for std::find_if

class Node
{
public:
    Node(const std::string id, const std::string name, const std::string type);
    virtual ~Node() = default;

    const std::string& getId() const;
    const std::string& getName() const;
    const std::string& getType() const;

    // Main
    virtual void process() = 0; // Pure virtual function - must be implemented by derived classes and means that this class can't be instantiated

    // Pins
    InputPin* getInputPin(const std::string &id) const;
    OutputPin* getOutputPin(const std::string &id) const;
    const std::vector<std::unique_ptr<InputPin>>& getInputPins() const;
    const std::vector<std::unique_ptr<OutputPin>>& getOutputPins() const;
    
protected:
    // for derived classes
    void addInputPin(PinDataType pinType, const std::string &id, const std::string &name);
    void addOutputPin(PinDataType pinType, const std::string &id, const std::string &name);
    
    std::string m_id;   // unique within node
    std::string m_name; // Display name
    std::string m_type; // Node type (e.g "AddNode, "MultiplyNode", etc.)

    std::vector<std::unique_ptr<InputPin>> m_inputPins;
    std::vector<std::unique_ptr<OutputPin>> m_outputPins;
};

#endif // NODE_H
