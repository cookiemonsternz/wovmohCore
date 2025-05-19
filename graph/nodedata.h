#ifndef NODEDATA_H
#define NODEDATA_H

#include <QQmlListProperty>
#include "../types/datatypes.h"
#include "pindata.h"

//******** NODE DATA ********//
class NodeData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(VectorData position READ getPosition WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QQmlListProperty<PinData> inputPins READ getInputPins NOTIFY inputPinsChanged)
    Q_PROPERTY(QQmlListProperty<PinData> outputPins READ getOutputPins NOTIFY outputPinsChanged)
public:
    NodeData(const QString &id, const QString &name, const QString &type, const VectorData &position = VectorData())
        : id(id), name(name), type(type), position(position) {}
    // PROPERTIES
    // -- ID -- //
    QString getId() const { return id; }
    void setId(const QString &value)
    {
        id = value;
        emit idChanged();
    }
    QString getName() const { return name; }
    void setName(const QString &value)
    {
        name = value;
        emit nameChanged();
    }
    QString getType() const { return type; }
    void setType(const QString &value)
    {
        type = value;
        emit typeChanged();
    }
    VectorData getPosition() const { return position; }
    void setPosition(const VectorData &value)
    {
        position = value;
        emit positionChanged();
    }
    QQmlListProperty<PinData> getInputPins() { return QQmlListProperty<PinData>(this, &inputPins); }
    QQmlListProperty<PinData> getOutputPins() { return QQmlListProperty<PinData>(this, &outputPins); }
    void addInputPin(const QString &id, const QString &name)
    {
        PinData *pin = new PinData(id, name);
        inputPins.append(pin);
    }
    void addOutputPin(const QString &id, const QString &name)
    {
        PinData *pin = new PinData(id, name);
        outputPins.append(pin);
    }
private:
    QString id;
    QString name;
    QString type;
    VectorData position;
    QList<PinData *> inputPins;
    QList<PinData *> outputPins;
signals:
    void idChanged();
    void nameChanged();
    void typeChanged();
    void positionChanged();
    void inputPinsChanged();
    void outputPinsChanged();
};

#endif // nodedata_h