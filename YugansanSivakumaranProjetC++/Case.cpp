#include <string.h>
#include <iostream>
#include "Case.hpp"

using namespace std;

Case::Case(){}
Case::Case(char rep,int posX, int posY):representiton(rep){
    Case::position=new Position(posX,posY);
    this->etreVivant=nullptr;
    this->item = nullptr;
}

/**
 * 
 * @param representation
 * @param posX
 * @param posY
 * @param etreVivant
 * @ lors du creation passer par argument nullptr pour etrevivant ou item
 */
Case::Case(char representation,int posX,int posY,EtreVivant *etreVivant2,Item *item){
    Case(representation,posX,posY);
    this->etreVivant = etreVivant2;
    this->item = item;
    
}
  char Case::getRepresentation() const{
      if(this->etreVivant!=nullptr){
          return etreVivant->getName();
      }else if(this->item != nullptr){
          return this->item->getRepresentation();
      }
      return representiton;
  }
  Position* Case::getPosition(){
    return position;
  }
  EtreVivant* Case::getEtreVivant() const {
      return this->etreVivant;
  }
void Case::setNullEtreVivant() {
    if(this->etreVivant!=nullptr){
          this->etreVivant=nullptr;
    }
}

Item* Case::getItem() const{
    return this->item;
}

  
  bool Case::setEtreVivant(EtreVivant *etreVivant2){
      if(EtreVivantPeutAllerSur()){
          this->etreVivant=etreVivant2;
          return true;
      }else{
          return false;
      }
  }
  bool Case::setItem(Item* item){
      if(this->item==nullptr){
          this->item=item;
          return true;
      }else{
          return false;
      }
  }

  bool Case::EtreVivantPeutAllerSur(){
      if(this->etreVivant==nullptr){
          return true;
      }else{
          return false;
      }
  }
  
  bool Case::ItemPeutAllerSur(){
      if(this->item==nullptr){
          return true;
      }else{
          return false;
      }
  }
  bool Case::estEscalier() {
      return false;
  }
