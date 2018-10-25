#include "EtreVivant.hpp"


  EtreVivant::EtreVivant(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque,int champsdeVision,int deplacement,Position *position)
  :name(name),forceDeVie(forceDeVie),resistanceAuxAttaque(resistanceAuxAttaque),forceDAttaque(forceDAttaque),champsdeVision(champsdeVision),deplacement(deplacement),position(position){
  }
  EtreVivant::EtreVivant(const EtreVivant& etreVivant){
    this->name = etreVivant.name;
    this->forceDeVie = etreVivant.forceDeVie;
    this->resistanceAuxAttaque = etreVivant.resistanceAuxAttaque;
    this->forceDAttaque = etreVivant.forceDAttaque;
    this->champsdeVision = etreVivant.champsdeVision;
    this->deplacement = etreVivant.deplacement;
    this->position=etreVivant.position;
  }
  
  EtreVivant::~EtreVivant(){}

  //GETTERS
  char EtreVivant::getName() const{
    return name;
  }
  int EtreVivant::getForceDAttaque() const{
    return forceDAttaque;
  }
  int EtreVivant::getResistanceAuxAttaque() const{
    return resistanceAuxAttaque;
  }
  int EtreVivant::getForceDeVie() const{
    return forceDeVie;
  }
  int EtreVivant::getChampsdeVision() const{
      return champsdeVision;
  }
  int EtreVivant::getDeplacement() const{
      return deplacement;
  }
  Position* EtreVivant::getPosition() const {
      return this->position;
  }

  
  //SETTERS
  void EtreVivant::setForceDAttaque(int forceDAttaque){
    EtreVivant::forceDAttaque=forceDAttaque;
  }
  void EtreVivant::setResistanceAuxAttaque(int resistanceAuxAttaque){
    EtreVivant::resistanceAuxAttaque=resistanceAuxAttaque;
  }
  void EtreVivant::setForceDeVie(int forceDeVie){
    EtreVivant::forceDeVie=forceDeVie;
  }
  void EtreVivant::setChampsdeVision(int champs){
      this->champsdeVision=champs;
  }
  void EtreVivant::setPosition(Position* position) {
      this->position =position;
  }

void EtreVivant::setRepresentation(char rep) {
    this->name = rep;
}


  bool EtreVivant::attaque(EtreVivant *aAttaque){
    if(aAttaque->getForceDeVie()>0){
      int force =getForceDAttaque();
      int pdv = aAttaque->getForceDeVie() - (force-(aAttaque->getResistanceAuxAttaque()/1.25));
      aAttaque->setForceDeVie(pdv);
      return true;
    }
    aAttaque->setForceDeVie(0);
    return false;
  }

  Position *EtreVivant::launchMove(){
      return nullptr;
  }
  bool EtreVivant::estVivant() const{
    return forceDeVie>0;
  }
  bool EtreVivant::estAAttaquerParMonstre() {
      return false;
  }
