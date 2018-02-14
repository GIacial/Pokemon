#include "rapidecourbe.h"

RapideCourbe::RapideCourbe(int base , int level) : AbstractCourbe(base)
{
    for(int i =1 ; i <level ; i++){
        isUpNextPalier(this->getSuivXp());  //monter de niveau artificielle
    }
}

RapideCourbe::~RapideCourbe() throw(){

}

int RapideCourbe::calcXpNextLevel()const{
    int a = this->getPredXp();
    return a*1.3;
}
