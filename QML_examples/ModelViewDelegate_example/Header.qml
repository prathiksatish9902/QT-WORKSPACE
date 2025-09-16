import QtQuick 2.12
Rectangle
{
    id: background
    width: listView.width
    height: listView.height / 5
    color: "blue"
    z : 2

    Row
    {
        spacing: 10
        width: parent.width
        height: parent.height
        topPadding: parent.height / 2.5

        Text {
            id: slno
            text: "sl no"
        }

        Text {
            id: stname
            text: "student name"
        }

        Text {
            id: strollno
            text: "rollno"
        }

        Text {
            id: stphone
            text: "phone"
        }
    }
}

