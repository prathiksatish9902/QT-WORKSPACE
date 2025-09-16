#include <QApplication>
#include <QComboBox>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout layout(&window);

    QComboBox *combo = new QComboBox();
    combo->setEditable(false);
    combo->setPlaceholderText("Select an option...");
    combo->addItem("Option 1");
    combo->addItem("Option 2");

    combo->setCurrentIndex(-1); // manually clear selection


    layout.addWidget(combo);
    window.show();

    return app.exec();
}
