#include <QApplication>
#include <QLineEdit>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLineEdit *lineEdit = new QLineEdit();
    QObject::connect(lineEdit, &QLineEdit::editingFinished, [](){
        qDebug() << "editingFinished() emitted!";
    });

    lineEdit->setText("Read-only text");
    lineEdit->setReadOnly(true);
    lineEdit->show();

    return app.exec();
}
