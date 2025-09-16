#include <QApplication>
#include <QDateTimeEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    auto *layout = new QVBoxLayout(&window);

    QLabel *info = new QLabel("Try entering: 2025-07-17 12:00 +05:30");
    layout->addWidget(info);

    QDateTimeEdit *edit = new QDateTimeEdit;
    edit->setDisplayFormat("yyyy-MM-dd HH:mm t");
    edit->setTimeSpec(Qt::UTC);  // Force it to use UTC
#if QT_VERSION >= QT_VERSION_CHECK(6, 2, 0)
    // Qt 6.2+ has support for time-zone settings
    edit->setTimeZone(QTimeZone("UTC"));
#endif

    edit->setCalendarPopup(true);
    layout->addWidget(edit);

    QLabel *result = new QLabel("Parsed datetime will appear here");
    layout->addWidget(result);

    QObject::connect(edit, &QDateTimeEdit::dateTimeChanged, [&](const QDateTime &dt) {
        result->setText("Parsed: " + dt.toString(Qt::ISODateWithMs));
        qDebug() << "Internal datetime:" << dt;
    });

    window.show();
    return app.exec();
}
