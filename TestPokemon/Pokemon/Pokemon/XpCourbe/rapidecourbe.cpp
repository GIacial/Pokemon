#include "rapidecourbe.h"

RapideCourbe::RapideCourbe(Xp base , int level) : AbstractCourbe(base)
{
    for(int i =1 ; i <level ; i++){
        isUpNextPalier(this->getSuivXp());  //monter de niveau artificielle
    }
}

RapideCourbe::~RapideCourbe() throw(){

}

Xp RapideCourbe::calcXpNextLevel()const{
    Xp a = this->getPredXp();
    return a*1.3;
}
