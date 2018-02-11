#include "kernelobject.h"

KernelObject::KernelObject() : QObject()
{

}

KernelObject::~KernelObject(){

}

void KernelObject::afficheMsg(QString msg){
    emit sendMsg(msg);
}
