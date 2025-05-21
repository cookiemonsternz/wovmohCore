import QtQuick
// import WovmohCore 1.0

// Rectangle {
//     width: 20; height: 20
//     color: "blue"
// }

Item {
    id: pin
    property string pin_id: ""
    property string pin_name: ""
    property string pin_type: ""

    Rectangle {
        id: pinCircle
        width: 10
        height: 10
        radius: 180
        color: "red"
    }
}