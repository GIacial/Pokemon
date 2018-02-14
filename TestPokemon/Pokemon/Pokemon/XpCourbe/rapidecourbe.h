#ifndef RAPIDECOURBE_H
#define RAPIDECOURBE_H

#include <QObject>
#include "abstractcourbe.h"

class RapideCourbe : public AbstractCourbe
{
    Q_OBJECT
public:
    //constructeur
    explicit RapideCourbe(Xp base, int level =1);
    //destructeur
    virtual ~RapideCourbe() throw();

signals:


protected:
    //override
     Xp calcXpNextLevel()const;

public slots:
};

#endif // RAPIDECOURBE_H
