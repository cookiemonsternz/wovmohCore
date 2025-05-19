#ifndef PATCHMANAGER_H
#define PATCHMANAGER_H

// patchmanager
// controls sending data between the backend and frontend
// each patch manager owns one patch graph

#include <QObject>

#include "lib/json.hpp" // For json
using json = nlohmann::json;

#include "../core/patchgraph.h"
#include "patchdata.h"
#include "nodedata.h"
#include "pindata.h"

//******** PATCH MANAGER ********//
// Manages transforming actual patch graph into the data format, as well as connecting nodes
class PatchManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PatchData *patchData READ getPatchData NOTIFY patchDataChanged)
public:
    PatchManager(QObject *parent = nullptr)
        : QObject(parent) {};

    PatchData *getPatchData() const { return patchData; }
    PatchData *patchGraphToData(const PatchGraph &patchGraph);

    PatchGraph *getPatchGraph() const { return patchGraph.get(); }
    void setPatchGraph(std::unique_ptr<PatchGraph> graph);

private:
    std::unique_ptr<PatchGraph> patchGraph;
    PatchData *patchData;

signals:
    void patchDataChanged();
};
#endif // PATCHMANAGER_H
