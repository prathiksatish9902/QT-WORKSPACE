import QtQuick 2.15

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
            text: "sl.no"
        }

        Text {
            id: stname
            text: "studentName"
        }

        Text {
            id: stphone
            text: "contactNumber"
        }

        Text {
            id: stfathername
            text: "fatherName"
        }

        Text {
            id: stmail
            text: "mailId"
        }

        Text {
            id: stusername
            text: "userName"
        }

        Text {
            id: stpassword
            text: "password"
        }
    }
}
