#include <QCoreApplication>
#include <QProcess>
#include <QThread>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QProcess process;

    // Start a short-lived process (sleep for 1 second)
    process.start("sleep", QStringList() << "1");

    // Wait for 2 seconds so that the process definitely finishes
    // QThread::sleep(2);

    // At this point, the process is already finished
    bool result = process.waitForFinished(5000);  // Timeout doesn't matter

    // Print results
    qDebug() << "Process state is NotRunning? " << (process.state() == QProcess::NotRunning);
    qDebug() << "waitForFinished() returned: " << result;

    return 0;
}
