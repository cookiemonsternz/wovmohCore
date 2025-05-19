#ifndef PINDATA_H
#define PINDATA_H

#include <QObject>

//******** PIN DATA ********//
class PinData : public QObject
{
    Q_OBJECT
    // PROPERTIES
    Q_PROPERTY(QString id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged)
public:
    PinData(const QString &id, const QString &name) : id(id), name(name) {}
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
    };
private:
    QString id;
    QString name;
    QString type;
signals:
    void idChanged();
    void nameChanged();
    void typeChanged();
};

#endif // pindata_h