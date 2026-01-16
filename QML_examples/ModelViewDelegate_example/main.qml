import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListModel
    {
        id: studentModel

        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}
        ListElement{name: "abc"; rollno: "23"; phone: "234567745"}

    }

    Component
    {
        id: headerComponent
        Header
        {
            // anchors.fill: parent
        }
    }


    ListView
    {
        id: listView
        width: parent.width/2
        height: parent.height
        spacing: 5
        model: studentModel
        header: headerComponent
        headerPositioning: ListView.OverlayHeader
        delegate: studentDelegate
    }

    Component
    {
        id: studentDelegate
        Rectangle
        {
            id: background
            width: listView.width
            height: listView.height / 5
            color: "blue"

            Row
            {
                spacing: 10
                width: parent.width
                height: parent.height
                topPadding: parent.height / 2.5

                Text {
                    id: slno
                    text: model.index + 1
                }

                Text {
                    id: stname
                    text: name
                }

                Text {
                    id: strollno
                    text: rollno
                }

                Text {
                    id: stphone
                    text: phone
                }
            }
        }
    }
}
