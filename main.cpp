#include <QCoreApplication>
#include <QDebug>
#include "DataTypes.h"
#include "patchgraph.h"
#include "node.h"
#include "nodes/corenodes.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "starting app.";

    PatchGraph patchGraph;

    // Create nodes
    Node* constantNode = new ConstantNumberNode("const1", "Constant Node 1", 50.0);
    Node* constantNode2 = new ConstantNumberNode("const2", "Constant Node 2", 10.0);
    Node* addNode = new MultiplyNode("add1", "Add Node");
    Node* debugNode = new DebugNode("debug1", "Debug Node");

    if (!constantNode || !constantNode2 || !addNode || !debugNode)
    {
        qDebug() << "Failed to create nodes";
        return -1;
    }
    // Add nodes to the patch graph
    patchGraph.addNode(std::unique_ptr<Node>(constantNode));
    patchGraph.addNode(std::unique_ptr<Node>(constantNode2));
    patchGraph.addNode(std::unique_ptr<Node>(addNode));
    patchGraph.addNode(std::unique_ptr<Node>(debugNode));

    patchGraph.connect("const1", "out", "add1", "in1");
    patchGraph.connect("const2", "out", "add1", "in2");
    patchGraph.connect("add1", "out", "debug1", "inNum");

    constantNode->process();
    constantNode2->process();
    addNode->process();
    debugNode->process();

    qDebug() << "Engine test finished";

    return a.exec();
}
