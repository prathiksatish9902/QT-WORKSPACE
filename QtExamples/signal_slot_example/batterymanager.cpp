#include "batterymanager.h"
#include <chrono>
#include<iostream>
#include <thread>
using namespace std;

BatteryManager::BatteryManager()
{

    m_batteryCapacity = 100;
}

BatteryManager::~BatteryManager()
{
}

int BatteryManager::batteryCapacity()
{
    return m_batteryCapacity;
}

void BatteryManager::setBatteryCapacity(int batPercentage)
{
    m_batteryCapacity = batPercentage;
}

void BatteryManager::batteryCapacityVariation()
{
    for(int i = 0; i < 20; i++)
    {
        m_batteryCapacity = m_batteryCapacity - 5;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if(m_batteryCapacity <= 0)
        {
            break;
        }
        if(m_batteryCapacity <= 20)
        {
            QString message = "BatteryLow :" + QString::number(m_batteryCapacity);
            emit batteryLow(message);
        }
        cout<<"Battery Capacity:"<<m_batteryCapacity<<endl;
    }
}
