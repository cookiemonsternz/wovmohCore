#include "patchgraph.h"

PatchGraph::PatchGraph() {}

// Node management
Node *PatchGraph::addNode(std::unique_ptr<Node> node)
{
    m_nodes.push_back(std::move(node));   // transfer ownership to m_nodes new pointer
    Node *nodePtr = m_nodes.back().get(); // get  raw pointer to  node
    m_nodeMap[nodePtr->getId()] = nodePtr;
    return nodePtr;
};
void PatchGraph::removeNode(const std::string &nodeId)
{
    // First delete from map, then vector. If vector is deleted, it deallocates the memory (bc of unique_ptr))
    // and then map has dangling pointer
    auto it = m_nodeMap.find(nodeId);
    if (it != m_nodeMap.end())
    {
        m_nodeMap.erase(it); // remove from map
        auto nodeIt = std::remove_if(m_nodes.begin(), m_nodes.end(),
                                     [&nodeId](const std::unique_ptr<Node> &node)
                                     { return node->getId() == nodeId; });
        if (nodeIt != m_nodes.end())
        {
            m_nodes.erase(nodeIt, m_nodes.end()); // rm from vector
        }
    }
};
Node *PatchGraph::findNode(const std::string &nodeId) const
{
    auto it = m_nodeMap.find(nodeId);
    if (it != m_nodeMap.end())
    {
        return it->second; // return the raw pointer
    }
    return nullptr; // not found
};

// Connection management
void PatchGraph::connect(const std::string &sourceNodeId, const std::string &outputPinId, const std::string &destPinId, const std::string &inputPinId)
{
    Node *sourceNode = findNode(sourceNodeId);
    Node *destNode = findNode(destPinId);

    if (!sourceNode || !destNode)
    {
        // Handle error: node not found
        return;
    }

    OutputPin *outputPin = sourceNode->getOutputPin(outputPinId);
    InputPin *inputPin = destNode->getInputPin(inputPinId);
    if (outputPin && inputPin)
    {
        outputPin->connect(inputPin); // Connect the pins
    }
    else
    {
        // Handle error: pin not found
    }
};
void PatchGraph::disconnect(const std::string &destNodeId, const std::string &inputPinId)
{
    Node *destNode = findNode(destNodeId);
    if (!destNode)
    {
        // Handle error: node not found
        return;
    }

    InputPin *inputPin = destNode->getInputPin(inputPinId);
    if (inputPin)
    {
        inputPin->disconnect(); // Disconnect the pin
    }
    else
    {
        // Handle error: pin not found
    }
};

// Processing
void evaluate(); // Later will do topological sort, for now just call sequentially from vector, so in order of creation
void PatchGraph::evaluate()
{
    for (const auto &node : m_nodes)
    {
        node->process(); // Call process on each node
    }
};

const std::map<std::string, Node*>& PatchGraph::getAllNodes() const
{
    return m_nodeMap;
}