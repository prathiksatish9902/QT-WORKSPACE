// #include <QApplication>
// #include <QButtonGroup>
// #include <QPushButton>
// #include <QVBoxLayout>
// #include <QWidget>
// #include <QDebug>

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);

//     // Create a button group
//     QButtonGroup *buttonGroup = new QButtonGroup();

//     // Create some buttons
//     QPushButton *button1 = new QPushButton("Button 1");
//     QPushButton *button2 = new QPushButton("Button 2");
//     QPushButton *button3 = new QPushButton("Button 3");

//     qDebug() << "=== Demonstrating QButtonGroup::setId Bug ===";

//     // BUG DEMONSTRATION:
//     // Set ID for buttons that are NOT in the group yet
//     qDebug() << "\n1. Setting IDs for buttons NOT in group:";
//     buttonGroup->setId(button1, 100);  // This should not work, but it does!
//     buttonGroup->setId(button2, 200);  // This corrupts internal state
//     buttonGroup->setId(button3, 300);

//     qDebug() << "   Set button1 ID to 100 (not in group)";
//     qDebug() << "   Set button2 ID to 200 (not in group)";
//     qDebug() << "   Set button3 ID to 300 (not in group)";

//     // Now add buttons to the group
//     qDebug() << "\n2. Adding buttons to group:";
//     buttonGroup->addButton(button1);  // Uses auto-ID, but conflicts with pre-set ID
//     buttonGroup->addButton(button2);
//     buttonGroup->addButton(button3);

//     // Check what IDs the buttons actually have
//     qDebug() << "\n3. Actual button IDs after adding to group:";
//     qDebug() << "   button1 ID:" << buttonGroup->id(button1) << "(expected: 100)";
//     qDebug() << "   button2 ID:" << buttonGroup->id(button2) << "(expected: 200)";
//     qDebug() << "   button3 ID:" << buttonGroup->id(button3) << "(expected: 300)";

//     // The bug: buttons will have (expected_id - 1) instead of expected_id
//     // This happens because of the inconsistent internal state

//     qDebug() << "\n4. Bug Result:";
//     qDebug() << "   Notice how IDs are off by 1 from what we set!";
//     qDebug() << "   This is because setId() worked on non-member buttons,";
//     qDebug() << "   corrupting the internal mapping.";
// }


// #include <QApplication>
// #include <QPushButton>
// #include <QButtonGroup>
// #include <QDebug>


// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);

//     QButtonGroup someGrp;
//     QPushButton someBtn;

//     someGrp.setObjectName("SomeGrp");
//     someBtn.setObjectName("SomeBtn");


//     // allows to manipulate QButtonGroup's hashmap directly
//     someGrp.setId(&someBtn, 42);

//     // still no buttons in group, size = 0
//     qDebug() << someGrp.buttons().size();

//     // 42 mapped to someBtn
//     qDebug() << someGrp.id(&someBtn);

//     // but first added here
//     someGrp.addButton(&someBtn);

//     // now size = 1
//     qDebug() << someGrp.buttons().size();

//     // id = 42 - 1 = 41
//     qDebug() << someGrp.id(&someBtn);

//     // now Id for someBtn is 41, although group was completely empty before
//     // should have been -1 and that operation before should have been prevented, right?

//     return a.exec();
// }














#include <QApplication>
#include <QButtonGroup>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton *btn1 = new QPushButton("Button 1");
    QPushButton *btn2 = new QPushButton("Button 2");

    QButtonGroup *group = new QButtonGroup;

    group->setId(btn1, 5);   // ❌ btn1 is not in group yet
    group->addButton(btn1); // ⚠️ Adds btn1 to group, auto-assigns ID => gets 4 (5 - 1)

    group->addButton(btn2); // btn2 gets 5

    qDebug() << "ID for btn1:" << group->id(btn1); // prints 4 (!)
    qDebug() << "ID for btn2:" << group->id(btn2); // prints 5 (!)

    return 0;
}
