import QtQuick 2.0

Item {
    id: node
    property string node_id: ""
    property string node_name: ""
    property string node_type: ""
    

    Rectangle {
        id: nodeRect
        width: 100
        height: 50
        color: "lightblue"
        radius: 10
        Item {
            id: pinContainer
        }
    }
}