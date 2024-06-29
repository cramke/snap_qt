import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: "Hello ROS2 Qt App"

    Text {
        text: "Hello, ROS2!"
        anchors.centerIn: parent
        font.pixelSize: 24
        z: 2
    }

    Plugin {
        id: mapPlugin
        name: "osm"
        // specify plugin parameters if necessary
        // PluginParameter {
        //     name:
        //     value:
        // }
    }

    Map {
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(59.91, 10.75) // Oslo
        zoomLevel: 14
    }
}
