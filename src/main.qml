import QtQuick 2.12
import QtQuick.Window 2.12

import QtQuick.Controls 1.3
import QtQuick.Layouts 1.2


ApplicationWindow {
    width: 600
    height: 600
    visible: true
    title: qsTr("Albums")
    color: "white";

    AlbumManager {
        anchors.fill: parent
        anchors.margins: 10
    }
}
