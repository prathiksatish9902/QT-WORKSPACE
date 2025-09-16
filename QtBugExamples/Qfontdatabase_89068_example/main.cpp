// #include <QGuiApplication>
// #include <QFontDatabase>
// #include <QDebug>

// int main(int argc, char *argv[]) {
//     QGuiApplication app(argc, argv);  // Required before using QFontDatabase

//     QFontDatabase db;

//     // Print all font families
//     const QStringList allFamilies = db.families();
//     for (const QString &family : allFamilies) {
//         if (family.contains("Helvetica", Qt::CaseInsensitive))
//             qDebug() << "Available family:" << family;
//     }

//     // Suppose "Adobe Helvetica" is in the families list
//     bool result = db.hasFamily("Adobe Helvetica");
//     qDebug() << "Has family 'Adobe Helvetica'?:" << result;

//     return 0;
// }

#include <QGuiApplication>
#include <QFontDatabase>
#include <QDebug>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QFontDatabase fontDb;

    // List all font families in the database
    QStringList families = fontDb.families();
    qDebug() << "Available font families:" << families;

    // Check if "Arial" exists
    bool hasArial = fontDb.hasFamily("Arial");
    qDebug() << "Has Arial?" << hasArial; // Expected: true, Actual: false (bug)

    return 0;
}
