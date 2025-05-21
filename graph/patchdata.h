#ifndef PATCHDATA_H
#define PATCHDATA_H

#include <QObject>
#include "nodedata.h"

//******** PATCH DATA ********//
class PatchData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString description READ getDescription WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString author READ getAuthor WRITE setAuthor NOTIFY authorChanged)
    Q_PROPERTY(QQmlListProperty<NodeData> nodes READ getNodes NOTIFY nodesChanged)
    Q_PROPERTY(QQmlListProperty<PinData> connections READ getConnections NOTIFY connectionsChanged)
public:
    QString getTitle() const { return title; }
    void setTitle(const QString &value)
    {
        title = value;
        emit titleChanged();
    }
    QString getDescription() const { return description; }
    void setDescription(const QString &value)
    {
        description = value;
        emit descriptionChanged();
    }
    QString getAuthor() const { return author; }
    void setAuthor(const QString &value)
    {
        author = value;
        emit authorChanged();
    }
    QQmlListProperty<NodeData> getNodes() { return QQmlListProperty<NodeData>(this, &nodes); }
    QQmlListProperty<PinData> getConnections() { return QQmlListProperty<PinData>(this, &connections); }
    void addNode(NodeData *node)
    {
        nodes.append(node);
        emit nodesChanged();
    }
private:
    QString title;
    QString description;
    QString author;
    QList<NodeData *> nodes;
    QList<PinData *> connections;
signals:
    void titleChanged();
    void descriptionChanged();
    void authorChanged();
    void nodesChanged();
    void connectionsChanged();
};

#endif // PATCHDATA_H