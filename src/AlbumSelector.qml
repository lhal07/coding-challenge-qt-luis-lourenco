import QtQuick 2.0

Item {
    property variant dataModel: ({})

    ListView {
        orientation: ListView.Horizontal
        model: dataModel
        highlight: Rectangle { width: 170; height: 200; color: "lightsteelblue"; radius: 5}
        delegate: albumsDelegate
        width: parent.width
        focus: true
    }

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
                    source: image
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
