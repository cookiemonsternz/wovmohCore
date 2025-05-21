#include "patchmanager.h"

// Includes
#include "../core/patchgraph.h"
#include "patchdata.h"
#include "nodedata.h"
#include "pindata.h"

PatchData* PatchManager::patchGraphToData(const PatchGraph &patchGraph)
{
    PatchData *patchData = new PatchData();
    patchData->setTitle(QString::fromStdString(patchGraph.title));
    patchData->setDescription(QString::fromStdString(patchGraph.description));
    patchData->setAuthor(QString::fromStdString(patchGraph.author));

    // Convert nodes
    for (const auto &pair : patchGraph.getAllNodes())
    {
        const std::string &nodeId = pair.first;
        Node *node = pair.second;

        NodeData *nodeData = new NodeData(
            QString::fromStdString(node->getId()),
            QString::fromStdString(node->getName()),
            QString::fromStdString(node->getType()), 
            node->getPosition()
        );

        for (const auto &inputPin : node->getInputPins())
        {
            nodeData->addInputPin(QString::fromStdString(inputPin->getId()), QString::fromStdString(inputPin->getName()));
        }
        for (const auto &outputPin : node->getOutputPins())
        {
            nodeData->addOutputPin(QString::fromStdString(outputPin->getId()), QString::fromStdString(outputPin->getName()));
        }

        patchData->addNode(nodeData);
        // qDebug() << "Node: " << nodeData->getId() << "Type:" << nodeData->getType() << "Position:" << nodeData->getPosition().toString();
    }
    return patchData;
}

void PatchManager::setPatchGraph(std::unique_ptr<PatchGraph> graph)
{
    patchGraph = std::move(graph);
    patchData = patchGraphToData(*patchGraph);
    emit patchDataChanged();
}