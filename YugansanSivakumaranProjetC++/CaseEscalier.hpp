/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CaseEscalier.hpp
 * Author: yugan
 *
 * Created on 12 janvier 2018, 18:02
 */

#ifndef CASEESCALIER_HPP
#define CASEESCALIER_HPP

#include "Case.hpp"

class CaseEscalier :public Case{
    private:
        bool isMonter;
    public:
        CaseEscalier(char representation,int posX, int posY,bool isMonter);
        bool getIsMonter();
        bool EtreVivantPeutAllerSur() override;
        bool setEtreVivant(EtreVivant *etreVivant2) override;
        bool ItemPeutAllerSur() override;
        bool estEscalier() override;


}; 

#endif /* CASEESCALIER_HPP */

