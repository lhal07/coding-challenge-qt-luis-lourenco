import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 480
    height: 480
    title: qsTr("Albums")

    Rectangle {
        anchors.fill: parent
        color: "white";

        AlbumManager {
            anchors.fill: parent
            anchors.margins: 20
        }
    }

}
