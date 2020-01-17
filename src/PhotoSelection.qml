import QtQuick 2.0

Item {
    property variant dataModel: ({})

    GridView {
        width: parent.width
        height: parent.height
        model: photosModel
        cellWidth: 170; cellHeight: 200
        focus: true
        visible: !showAlbumMenu
        highlight: Rectangle { width: albumsGrid.cellWidth; height: albumsGrid.cellHeight; color: "lightsteelblue"; radius: 5}
        delegate: photosDelegate
    }
    Component {
        id: photosDelegate

        Item {
            width: photosGrid.cellWidth; height: photosGrid.cellHeight

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
                    source: thumbnailUrl
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
