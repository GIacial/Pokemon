#ifndef RAPIDECOURBE_H
#define RAPIDECOURBE_H

#include <QObject>
#include "abstractcourbe.h"

class RapideCourbe : public AbstractCourbe
{
    Q_OBJECT
public:
    //constructeur
    explicit RapideCourbe(int base, int level =1);
    //destructeur
    virtual ~RapideCourbe() throw();

signals:


protected:
    //override
     int calcXpNextLevel()const;

public slots:
};

#endif // RAPIDECOURBE_H
