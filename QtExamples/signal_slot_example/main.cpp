#include "batterymanager.h"
#include"soundmanager.h"
#include<QApplication>
#include <QObject>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SoundManager manager;
    BatteryManager battery;
    QObject::connect(&battery, &BatteryManager::batteryLow, &manager, &SoundManager::announce);
    QObject::connect(&battery, &BatteryManager::batteryLow, &manager, &SoundManager::announce,Qt::SingleShotConnection);

    battery.batteryCapacityVariation();

    return app.exec();
}
