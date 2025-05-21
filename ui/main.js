var pinComponent
var nodeComponent

// function createPin() {
//     if (pinComponent == null) {
//         loadPinComponent()
//         if (pinComponent.status == Component.Ready) {
//             instantiatePin()
//         } else {
//             pinComponent.statusChanged.connect(instantiatePin)
//         }
//     } else {
//         instantiatePin()
//     }
// }

// function loadPinComponent() {
//     if (pinComponent == null) {
//         pinComponent = Qt.createComponent('Pin.qml')
//     }
// }

// function instantiatePin() {
//     if (pinComponent.status == Component.Ready) {
//         var dynamicObject = pinComponent.createObject(mainContainer)
//         if (dynamicObject == null) {
//             console.log('Error creating object')
//             console.log(pinComponent.errorString())
//             return false
//         }
//         dynamicObject.x = 50
//         dynamicObject.y = 50
//     } else if (pinComponent.status == Component.Error) {
//         console.log('Error loading component')
//         console.log(pinComponent.errorString())
//         return false
//     }
// }

function createNode() {
    if (nodeComponent == null) {
        loadNodeComponent()
        if (nodeComponent.status == Component.Ready) {
            instantiateNode()
        } else {
            nodeComponent.statusChanged.connect(instantiateNode)
        }
    } else {
        instantiateNode()
    }
}

function loadNodeComponent() {
    if (nodeComponent == null) {
        nodeComponent = Qt.createComponent('Node.qml')
    }
}

function instantiateNode() {
    if (nodeComponent.status == Component.Ready) {
        var dynamicObject = nodeComponent.createObject(mainContainer)
        if (dynamicObject == null) {
            console.log('Error creating object')
            console.log(nodeComponent.errorString())
            return false
        }
        dynamicObject.x = 50
        dynamicObject.y = 50
    } else if (nodeComponent.status == Component.Error) {
        console.log('Error loading component')
        console.log(nodeComponent.errorString())
        return false
    }
}