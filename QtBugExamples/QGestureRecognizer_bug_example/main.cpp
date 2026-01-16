
#include <QApplication>
#include "myrecognizer.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Register a recognizer
    Qt::GestureType gestureType = QGestureRecognizer::registerRecognizer(new MyRecognizer());

    // Unregister the recognizer (leak occurs here)
    QGestureRecognizer::unregisterRecognizer(gestureType);

    // You’ll see that MyRecognizer is NOT deleted.
    return 0;
}
