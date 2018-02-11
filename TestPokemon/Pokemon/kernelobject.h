#ifndef KERNELOBJECT_H
#define KERNELOBJECT_H

#include <QObject>

class KernelObject : public QObject
{
    Q_OBJECT
public:
    explicit KernelObject();
    virtual ~KernelObject() throw();

signals:
    void sendMsg(QString msg)const;              //envoie un msg à afficher

public slots:
    void afficheMsg(QString msg);
};

#endif // KERNELOBJECT_H
