#include <QApplication>
#include <QLineEdit>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a QLineEdit
    QLineEdit* lineEdit = new QLineEdit();

    // Connect editingFinished signal to a lambda that prints a message
    QObject::connect(lineEdit, &QLineEdit::editingFinished, [=]() {
        qDebug() << "editingFinished signal emitted!";
    });

    // Set the QLineEdit to read-only
    lineEdit->setReadOnly(true);

    // Show the QLineEdit
    lineEdit->show();

    return app.exec();
}
