
#include <QApplication>
#include "myrecognizer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Qt::GestureType gestureType = QGestureRecognizer::registerRecognizer(new MyRecognizer());
    QGestureRecognizer::unregisterRecognizer(gestureType);
    // If fix is applied, this will now print deletion log
    return 0;
}
