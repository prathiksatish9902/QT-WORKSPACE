#include <QApplication>
#include <QFontDatabase>
#include <QDebug>
#include <QSet>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int id = QFontDatabase::addApplicationFont(":/fonts/testfont_variable.ttf");
    if (id == -1) {
        qWarning() << "Failed to load font!";
        return -1;
    }

    QStringList families = QFontDatabase::applicationFontFamilies(id);
    qDebug() << "Font families returned:" << families;

    // Correct way to remove duplicates
    QSet<QString> uniqueFamilies(families.begin(), families.end());
    qDebug() << "Total:" << families.size() << ", Unique:" << uniqueFamilies.size();

    return 0;
}
