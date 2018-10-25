/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CaseMur.hpp
 * Author: yugan
 *
 * Created on 12 janvier 2018, 18:45
 */

#ifndef CASEMUR_HPP
#define CASEMUR_HPP

#include "Case.hpp"


class CaseMur : public Case{
    public:
        CaseMur(char representation,int posX, int posY);
        bool EtreVivantPeutAllerSur() override;
        bool ItemPeutAllerSur() override;

};


#endif /* CASEMUR_HPP */

