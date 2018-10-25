/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CaseMur.hpp"



CaseMur::CaseMur(char representation, int posX, int posY):Case(representation,posX,posY){}

bool CaseMur::EtreVivantPeutAllerSur(){
    return false;
}

bool CaseMur::ItemPeutAllerSur() {
    return false;
}
