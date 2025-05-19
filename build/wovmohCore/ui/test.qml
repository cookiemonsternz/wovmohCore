// MyItem.qml
import QtQuick 2.0
import WovmohCore 1.0

Item {
    //property var patchManager

    width: 100; height: 100

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(patchManager.patchData)
            //var result = patchManager.patchData
            //console.log("Result of postMessage():", result)
            //var result2 = patchManager.testGetStrings()
            //for (var obj of result2){
            //    console.log(obj.name)
            //}
            //patchManager.refresh();
        }
    }
}