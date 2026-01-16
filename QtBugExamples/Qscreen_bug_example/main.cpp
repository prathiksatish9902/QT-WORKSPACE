#include <QGuiApplication>
#include <QScreen>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Get the primary screen
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen)
        qDebug() << "Screen resolution:" << screen->size();

    // Get all available screens
    const QList<QScreen *> screens = QGuiApplication::screens();
    for (QScreen *s : screens)
        qDebug() << "Screen:" << s->name() << "Resolution:" << s->size();

    return 0;
}
