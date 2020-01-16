import QtQuick 2.0
import QtQuick.Layouts 1.12
import Albums 1.0

ColumnLayout {

    AlbumsListModel { id: albumsModel }
    PhotosListModel { id: photosModel }
    InfoDataModel { id: infoDataModel }

    Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        border.color: "black"
        border.width: 2
        radius: 10

        Text {
            id: headerText
            text: "Albuns"
            y: 60
            x: 30
            anchors.top: parent.top
            anchors.topMargin: 30
            font.pointSize: 24
        }

        ListView {
            id: albumsGrid
            anchors.left: parent.left
            anchors.leftMargin: 25
            anchors.top: headerText.bottom
            anchors.topMargin: 25
            anchors.right: parent.right
            anchors.rightMargin: 25
            width: parent.width
            orientation: ListView.Horizontal
            height: 200
            model: albumsModel
            focus: true
            highlight: Rectangle { width: 170; height: 200; color: "lightsteelblue"; radius: 5}
            delegate: albumsDelegate
        }

        Rectangle {
            Component {
                id: albumsDelegate

                Item {
                    width: 170; height: 200

                    Rectangle {
                        id: photoImage
                        anchors.top: parent.top
                        anchors.topMargin: 10
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: 150
                        height: 150
                        color: "transparent"
                        border.color: "black"
                        border.width: 2
                        Image {
                            id: photo
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                            //  source: icon
                        }
                    }

                    Rectangle {
                        color: "dimgrey"
                        width: albumText.paintedWidth + 4
                        height: albumText.paintedHeight + 4
                        radius: 5
                        anchors.top: photoImage.bottom;
                        anchors.topMargin: 10;
                        anchors.horizontalCenter: parent.horizontalCenter;

                        Text {
                            width: 110
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                            id: albumText
                            font.pixelSize: 14
                            color: "white"
                            text: title
                            elide: Text.ElideRight
                        }
                    }
                }
            }
        }

        ListView {
            id: infoGrid
            anchors.left: parent.left
            anchors.leftMargin: 25
            anchors.top: albumsGrid.bottom
            anchors.topMargin: 25
            anchors.right: parent.right
            anchors.rightMargin: 25
            width: parent.width
            height: 100
            orientation: ListView.Horizontal
            model: infoDataModel
            delegate: infoDelegate
            focus: false
        }

        Rectangle {
            Component {
                id: infoDelegate

                Item {
                    width: 125; height: 80
                    Rectangle {
                        color: "whitesmoke"
                        anchors.fill: parent
                        anchors.margins: 5
                        radius: 10
                        width: parent.width; height: parent.height

                        Column {
                            anchors.fill: parent
                            Text { id: infoField; text: name; font.pixelSize: 14; color: "dimgrey"; anchors.horizontalCenter: parent.horizontalCenter }
                            Text { id: infoTotal; text: count; font.pixelSize: 45; color: "dimgrey"; anchors.horizontalCenter: parent.horizontalCenter }
                        }
                    }
                }
            }
        }

    }
}
