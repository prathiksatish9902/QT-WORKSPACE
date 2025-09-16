// #include <QApplication>
// #include <QToolBox>
// #include <QLabel>

// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);
//     QToolBox toolbox;
//     toolbox.addItem(new QLabel("Content of Page 1"), "Page 1");
//     toolbox.addItem(new QLabel("Content of Page 2"), "Page 2");
//     toolbox.show();
//     return app.exec();
// }


#include <QApplication>
#include <QToolBox>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QToolBox toolbox;
    toolbox.addItem(new QLabel("Content of Page 1"), "Page 1");
    toolbox.addItem(new QLabel("Content of Page 2"), "Page 2");
    toolbox.addItem(new QLabel("Content of Page 3"), "Page 3");
    toolbox.setFocus(); // Ensure the toolbox can receive focus
    toolbox.show();
    return app.exec();
}












