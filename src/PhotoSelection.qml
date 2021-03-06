import QtQuick 2.0

Item {
    property variant dataModel: ({})
    property variant currentItem: photosListView.currentItem || ({})
    property int currentIndex: photosListView.currentIndex || 0
    property bool focused: false

    ListView {
        id: photosListView
        height: parent.height
        width: parent.width
        orientation: ListView.Horizontal
        model: dataModel
        highlight: Rectangle { width: 170; height: 200; color: "lightsteelblue"; radius: 5}
        delegate: photosDelegate
        focus: focused
    }

    Component {
        id: photosDelegate

        Item {
            id: photoSelectedItem
            width: 170; height: 200
            property variant itemModel: model

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
                    horizontalAlignment: Text.AlignHCenter
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
