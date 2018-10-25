/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CaseEscalier.hpp"


CaseEscalier::CaseEscalier(char representation, int posX, int posY, bool isMonter):Case(representation,posX,posY){
    this->isMonter=isMonter;
}

bool CaseEscalier::getIsMonter(){
    return this->isMonter;
}

bool CaseEscalier::EtreVivantPeutAllerSur() {
    if(this->etreVivant==nullptr){
          return true;
      }else{
          return false;
      }
}

bool CaseEscalier::ItemPeutAllerSur() {
    return false;
}


bool CaseEscalier::setEtreVivant(EtreVivant* etreVivant2) {
    if(EtreVivantPeutAllerSur()){
          this->etreVivant=etreVivant2;
          return true;
      }else{
          return false;
      }
}

bool CaseEscalier::estEscalier() {
    return true;
}




