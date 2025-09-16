#include <QApplication>
#include <QFontMetrics>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a font and QFontMetrics
    QFont font("Arial", 12);
    QFontMetrics fm(font);

    // Test with a potentially problematic character (e.g., an invalid Unicode)
    QString problematicText = QString(QChar(0xD800)); // Surrogate pair, invalid alone

    // Get bounding rect
    QRect rect = fm.boundingRect(problematicText);
    qDebug() << "Bounding Rect:" << rect;

    // Check if the rect has suspicious values (e.g., 100000)
    if (rect.width() >= 100000 || rect.height() >= 100000) {
        qDebug() << "Error: Invalid bounding box detected!";
    } else {
        qDebug() << "Bounding box seems reasonable.";
    }

    return 0;
}
