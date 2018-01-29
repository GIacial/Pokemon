#ifndef TABLETYPES_H
#define TABLETYPES_H

#include <QObject>
#include <vector>

/**
 * @brief The TypeCreature enum represente tous les types des creatures
 */
enum TypeCreature{
    ACIER=0,COMBAT,DRAGON,EAU,ELECTRIQUE,FEU,FEE,GLACE,INSECTE,NORMAL,PLANTE,POISON,PSY,ROCHE,SOL,SPECTRE,TENEBRES,VOL
};

/**
 * @brief The TableTypes class  represente la tables des faiblesse de chaque type de créature
 */
class TableTypes : public QObject
{
    Q_OBJECT
public:
    //destructeur
    virtual ~TableTypes() throw();                                      //destructeur

    //fonction
    static double getAttMultiplier(const TypeCreature def , const TypeCreature att);

    //constante
    static constexpr double const&  COEF_NORMAL = 1.0;                              //coef pour une efficacite normal
    static constexpr double const&  COEF_INEFFICACE = 0.0;                          //coef pour ce qui est inneficace
    static constexpr double const&  COEF_PEUEFFICACE = 0.5;                         //coef de peu efficace
    static constexpr double const&  COEF_SUPEREFFICACE = 2.0;                       //coef de super efficace
signals:

public slots:

protected:

private:
    //constructeur
     TableTypes();                                              //constructeur

    //operateur

    //data
    std::vector<std::vector<double> >* tableDesTypes;                               //[def][att] donne les coef multipliacation de att sur def

};

#endif // TABLETYPES_H
