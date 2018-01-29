#include "tabletypes.h"

using namespace std;

//---------------------------------------------------------------------------------------
//-------------------------------Constructeur--------------------------------------------
//---------------------------------------------------------------------------------------
TableTypes::TableTypes() : QObject()
{
    this->tableDesTypes = new vector<vector<double> >();
    for(int t = ACIER; t<= VOL ;t++) {
        this->tableDesTypes->push_back(vector<double>());
        for(int d = ACIER; t<= VOL ;d++) {
            (*(this->tableDesTypes))[t].push_back(COEF_NORMAL);
        }
    }
    //ACIER
    (*(this->tableDesTypes))[ACIER][ACIER]       = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ACIER][COMBAT]      = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[ACIER][DRAGON]      = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ACIER][FEU]         = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[ACIER][FEE]         = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ACIER][GLACE]       = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ACIER][INSECTE]     = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ACIER][NORMAL]      = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ACIER][PLANTE]      = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ACIER][POISON]      = COEF_INEFFICACE;
    (*(this->tableDesTypes))[ACIER][PSY]         = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ACIER][ROCHE]       = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ACIER][SOL]         = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[ACIER][VOL]         = COEF_PEUEFFICACE;
    //COMBAT
    (*(this->tableDesTypes))[COMBAT][FEE]        = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[COMBAT][INSECTE]    = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[COMBAT][PSY]        = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[COMBAT][ROCHE]      = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[COMBAT][TENEBRES]   = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[COMBAT][VOL]        = COEF_SUPEREFFICACE;
    //DRAGON
    (*(this->tableDesTypes))[DRAGON][DRAGON]     = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[DRAGON][EAU]        = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[DRAGON][ELECTRIQUE] = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[DRAGON][FEU]        = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[DRAGON][FEE]        = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[DRAGON][GLACE]      = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[DRAGON][PLANTE]     = COEF_PEUEFFICACE;
    //EAU
    (*(this->tableDesTypes))[EAU][ACIER]         = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[EAU][EAU]           = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[EAU][ELECTRIQUE]    = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[EAU][FEU]           = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[EAU][GLACE]         = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[EAU][PLANTE]        = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[EAU][ACIER]         = COEF_PEUEFFICACE;
    //ELECTRIQUE
    (*(this->tableDesTypes))[ELECTRIQUE][ACIER]      = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ELECTRIQUE][ELECTRIQUE] = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ELECTRIQUE][SOL]        = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[ELECTRIQUE][VOL]        = COEF_PEUEFFICACE;
    //FEU
    (*(this->tableDesTypes))[FEU][ACIER]         = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[FEU][EAU]           = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[FEU][FEU]           = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[FEU][FEE]           = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[FEU][GLACE]         = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[FEU][INSECTE]       = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[FEU][PLANTE]        = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[FEU][ROCHE]         = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[FEU][SOL]           = COEF_SUPEREFFICACE;
    //FEE
    (*(this->tableDesTypes))[FEE][ACIER]         = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[FEE][COMBAT]        = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[FEE][DRAGON]        = COEF_INEFFICACE;
    (*(this->tableDesTypes))[FEE][INSECTE]       = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[FEE][POISON]        = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[FEE][TENEBRES]      = COEF_PEUEFFICACE;
    //GLACE
    (*(this->tableDesTypes))[GLACE][ACIER]       = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[GLACE][COMBAT]      = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[GLACE][FEU]         = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[GLACE][GLACE]       = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[GLACE][ROCHE]       = COEF_SUPEREFFICACE;
    //INSECTE
    (*(this->tableDesTypes))[INSECTE][COMBAT]    = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[INSECTE][FEU]       = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[INSECTE][PLANTE]    = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[INSECTE][ROCHE]     = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[INSECTE][SOL]       = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[INSECTE][VOL]       = COEF_SUPEREFFICACE;
    //NORMAL
    (*(this->tableDesTypes))[NORMAL][COMBAT]     = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[NORMAL][SPECTRE]    = COEF_INEFFICACE;
    //PLANTE
    (*(this->tableDesTypes))[PLANTE][EAU]        = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[PLANTE][ELECTRIQUE] = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[PLANTE][FEU]        = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[PLANTE][GLACE]      = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[PLANTE][INSECTE]    = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[PLANTE][PLANTE]     = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[PLANTE][POISON]     = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[PLANTE][SOL]        = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[PLANTE][VOL]        = COEF_SUPEREFFICACE;
    //POISON
    (*(this->tableDesTypes))[POISON][COMBAT]     = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[POISON][FEE]        = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[POISON][INSECTE]    = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[POISON][PLANTE]     = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[POISON][POISON]     = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[POISON][PSY]        = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[POISON][SOL]        = COEF_SUPEREFFICACE;
    //PSY
    (*(this->tableDesTypes))[PSY][COMBAT]        = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[PSY][INSECTE]       = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[PSY][PSY]           = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[PSY][SPECTRE]       = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[PSY][TENEBRES]      = COEF_SUPEREFFICACE;
    //ROCHE
    (*(this->tableDesTypes))[ROCHE][ACIER]       = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[ROCHE][COMBAT]      = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[ROCHE][EAU]         = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[ROCHE][FEU]         = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ROCHE][NORMAL]      = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ROCHE][PLANTE]      = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[ROCHE][POISON]      = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[ROCHE][SOL]         = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[ROCHE][VOL]         = COEF_PEUEFFICACE;
    //SOL
    (*(this->tableDesTypes))[SOL][EAU]           = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[SOL][ELECTRIQUE]    = COEF_INEFFICACE;
    (*(this->tableDesTypes))[SOL][GLACE]         = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[SOL][PLANTE]        = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[SOL][POISON]        = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[SOL][ROCHE]         = COEF_PEUEFFICACE;
    //SPECTRE
    (*(this->tableDesTypes))[SPECTRE][COMBAT]    = COEF_INEFFICACE;
    (*(this->tableDesTypes))[SPECTRE][INSECTE]   = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[SPECTRE][NORMAL]    = COEF_INEFFICACE;
    (*(this->tableDesTypes))[SPECTRE][POISON]    = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[SPECTRE][SPECTRE]   = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[SPECTRE][TENEBRES]  = COEF_SUPEREFFICACE;
    //TENEBRES
    (*(this->tableDesTypes))[TENEBRES][COMBAT]   = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[TENEBRES][FEE]      = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[TENEBRES][INSECTE]  = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[TENEBRES][PSY]      = COEF_INEFFICACE;
    (*(this->tableDesTypes))[TENEBRES][SPECTRE]  = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[TENEBRES][TENEBRES] = COEF_PEUEFFICACE;
    //VOL
    (*(this->tableDesTypes))[VOL][COMBAT]        = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[VOL][ELECTRIQUE]    = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[VOL][GLACE]         = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[VOL][INSECTE]       = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[VOL][PLANTE]        = COEF_PEUEFFICACE;
    (*(this->tableDesTypes))[VOL][ROCHE]         = COEF_SUPEREFFICACE;
    (*(this->tableDesTypes))[VOL][SOL]           = COEF_INEFFICACE;
}
//---------------------------------------------------------------------------------------
//--------------------------------Destructeur--------------------------------------------
//---------------------------------------------------------------------------------------
TableTypes::~TableTypes() throw(){
    delete this->tableDesTypes;
}
//---------------------------------------------------------------------------------------
//-------------------------------operateur-----------------------------------------------
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
//-------------------------------fonction------------------------------------------------
//---------------------------------------------------------------------------------------
double TableTypes::getAttMultiplier(const TypeCreature def, const TypeCreature att){
    static TableTypes t;
    return (*(t.tableDesTypes))[def][att];
}
