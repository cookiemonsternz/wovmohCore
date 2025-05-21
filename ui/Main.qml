import QtQuick 2.0
import "main.js" as Main

Window {
    width: 680
    height: 500
    visible: true
    title: qsTr("Hello World")
    Item {
        id: mainContainer
        width: 680
        height: 500
        MouseArea {
        anchors.fill: parent
        onClicked: {
            var result = patchManager.patchData.nodes[0].inputPins[0].id
            console.log("Result of postMessage():", result)
            Main.createNode()
        }
    }
    }
}