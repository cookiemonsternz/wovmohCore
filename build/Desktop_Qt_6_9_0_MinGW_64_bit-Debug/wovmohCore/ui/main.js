var pinComponent;

function createPin(){
    if (pinComponent == null) {
        pinComponent = Qt.createComponent("Pin.qml");
    }

    console.log(Component.Ready);

    if (pinComponent.status == Component.Ready) {
        finishCreation();
    } else {
        pinComponent.statusChanged.connect(finishCreation);
    }
}

function finishCreation() {
    if (pinComponent.status == Component.Ready) {
        var dynamicObject = pinComponent.createObject(pinContainer)
        if (dynamicObject == null) {
            console.log("Error creating object");
            console.log(pinComponent.errorString());
            return false;
        }
        dynamicObject.x = 50;
        dynamicObject.y = 50;
    } else if (pinComponent.status == Component.Error) {
        console.log("Error loading component");
        console.log(pinComponent.errorString());
        return false;
    }
}
