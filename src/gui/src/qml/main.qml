import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: "Hello ROS2 Qt App"

    Text {
        text: "Hello, ROS2!"
        anchors.centerIn: parent
        font.pixelSize: 24
    }
}
