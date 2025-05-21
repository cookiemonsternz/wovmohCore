// MyItem.qml
import QtQuick 2.0
import "main.js" as Main
Item {
    //property var patchManager

    id: pinContainer
    width: 100; height: 100
    MouseArea {
        anchors.fill: parent
        onClicked: {
            var result = patchManager.patchData.nodes[0].inputPins[0].id
            console.log("Result of postMessage():", result)
            Main.createPin()
            //var result2 = patchManager.testGetStrings()
            //for (var obj of result2){
            //    console.log(obj.name)
            //}
            //patchManager.refresh();
        }
    }
}
