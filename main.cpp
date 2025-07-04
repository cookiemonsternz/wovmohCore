#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <fstream>
#include "core/patchgraph.h"
#include "graph/patchmanager.h"
// #include "node.h"
// #include "nodes/corenodes.h"

int core_main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "starting app.";

    PatchGraph patchGraph;

    // Create nodes
    // Node* constantNode = new ConstantNumberNode("const1", "Constant Node 1", 50.0);
    // Node* constantNode2 = new ConstantNumberNode("const2", "Constant Node 2", 10.0);
    // Node* addNode = new MultiplyNode("add1", "Add Node");
    // Node* debugNode = new DebugNode("debug1", "Debug Node");

    // if (!constantNode || !constantNode2 || !addNode || !debugNode)
    // {
    //     qDebug() << "Failed to create nodes";
    //     return -1;
    // }

    // Add nodes to the patch graph
    // patchGraph.addNode(std::unique_ptr<Node>(constantNode));
    // patchGraph.addNode(std::unique_ptr<Node>(constantNode2));
    // patchGraph.addNode(std::unique_ptr<Node>(addNode));
    // patchGraph.addNode(std::unique_ptr<Node>(debugNode));

    // patchGraph.connect("const1", "out", "add1", "in1");
    // patchGraph.connect("const2", "out", "add1", "in2");
    // patchGraph.connect("add1", "out", "debug1", "inNum");

    // load json
    std::ifstream i("../pretty.json");
    json j;
    i >> j;
    
    patchGraph.fromJson(j);

    // sort and evaluate
    patchGraph.sort();
    patchGraph.evaluate();

    // Serialize to JSON
    json serializedGraph = patchGraph.toJson();
    qDebug() << "Engine test finished";

    return a.exec();
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("wovmohCore", "Main");

    // qmlRegisterType<PatchManager>("WovmohCore", 1, 0, "PatchManager");

    PatchManager patchManager;

    auto patchGraph = std::make_unique<PatchGraph>();

    std::ifstream i("../pretty.json");
    json j;
    i >> j;
    
    patchGraph->fromJson(j);

    patchManager.setPatchGraph(std::move(patchGraph));

    engine.rootContext()->setContextProperty("patchManager", &patchManager);
    
    
    
    return app.exec();
}