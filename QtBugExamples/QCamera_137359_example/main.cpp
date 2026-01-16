#include <QApplication>
#include <QCamera>
#include <QCameraDevice>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Select the default camera
    QCamera camera;

    // Check if the camera is available
    if (camera.isAvailable()) {
        qDebug() << "Camera is available. Attempting to start...";
        camera.start(); // Attempt to start the camera
        if (camera.error() != QCamera::NoError) {
            qDebug() << "Failed to start camera:" << camera.errorString();
        } else {
            qDebug() << "Camera started successfully.";
        }
    } else {
        qDebug() << "Camera is not available.";
    }

    return app.exec();
}
