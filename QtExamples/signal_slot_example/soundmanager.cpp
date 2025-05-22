#include "soundmanager.h"
#include "qdebug.h"
#include<iostream>
using namespace std;

SoundManager::SoundManager()
{

}
SoundManager::~SoundManager()
{

}

void SoundManager::announce(QString message)
{
    qDebug()<<message;
}
