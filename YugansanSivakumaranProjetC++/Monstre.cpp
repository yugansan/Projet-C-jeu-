#include "Monstre.hpp"


/*** MONSTRE ***/
//CONSTRUCTEUR
Monstre::Monstre(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque, int deplacement, Position *position) : EtreVivant(name, forceDeVie, forceDAttaque, resistanceAuxAttaque, 0, deplacement, position) {
}
Monstre::Monstre(EtreVivant &etreVivant) : EtreVivant(etreVivant) {
}
//DESTRUCTEUR
Monstre::~Monstre() {
}
//METHODES
Position *Monstre::launchMove() {
    int randX, randY;
    /* generate number between 1 and deplacement: */
    randX = rand() % this->getDeplacement();
    randY = rand() % this->getDeplacement();
    return new Position(randX, randY);
}

bool Monstre::estMonstreSurprise() {
    return false;
}

/*-- FIN MONSTRE --*/

/*** MONSTRE STATIQUE ***/
//CONSTRUCTEUR
MonstreStatique::MonstreStatique(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque, Position *position) : Monstre(name, forceDeVie, forceDAttaque, resistanceAuxAttaque, 0, position) {
}
MonstreStatique::MonstreStatique(Monstre &monstre) : Monstre(monstre) {
}
//DESTRUCTEUR
MonstreStatique::~MonstreStatique() {
}
//METHODES
Position *MonstreStatique::launchMove() { //!!!gerer main/lancerJeu car fct inutile
    return new Position(this->getPosition()->getPositionX(), this->getPosition()->getPositionY());
}
/*-- FIN MONSTRE STATIQUE --*/


/*** MONSTRE INTELLIGENT ***/
//CONSTRUCTEUR
MonstreIntelligent::MonstreIntelligent(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque, int deplacement, Position *position) : Monstre(name, forceDeVie, forceDAttaque, resistanceAuxAttaque, deplacement, position) {
}
MonstreIntelligent::MonstreIntelligent(Monstre &monstre) : Monstre(monstre) {
}
//DESTRUCTEUR
MonstreIntelligent::~MonstreIntelligent() {
}
//METHODES
Position *MonstreIntelligent::launchMove(Position *posJoueur) {
    int xThis, yThis, xJoueur, yJoueur;
    xThis = this->getPosition()->getPositionX();
    yThis = this->getPosition()->getPositionY();
    xJoueur = posJoueur->getPositionX();
    yJoueur = posJoueur->getPositionY();
    
    //xThis
    if (xJoueur < xThis)
        xThis -= this->getDeplacement();
    else if (xJoueur > xThis)
        xThis += this->getDeplacement();
    //yThis
    if (yJoueur < yThis)
        yThis -= this->getDeplacement();
    else if (yJoueur > yThis)
        yThis += this->getDeplacement();
    
    return new Position(xThis, yThis);
}
/*-- FIN MONSTRE INTELLIGENT --*/


/*** MONSTRE SURPRISE ***/
//CONSTRUCTEUR
MonstreSurprise::MonstreSurprise(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque, int deplacement, Position *position, Item *item) : Monstre(name, forceDeVie, forceDAttaque, resistanceAuxAttaque, deplacement, position) {
    this->item=item;
}
MonstreSurprise::MonstreSurprise(Monstre &monstre) : Monstre(monstre) {
}

bool MonstreSurprise::estMonstreSurprise() {
    return true;
}

Item* MonstreSurprise::getItemMonstreSurprise() const {
    return this->item;
}


//DESTRUCTEUR
MonstreSurprise::~MonstreSurprise() {
}
//METHODES

/*-- FIN MONSTRE INTELLIGENT --*/