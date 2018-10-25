/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Case.hpp
 * Author: yugan
 *
 * Created on 31 décembre 2017, 16:59
 */

#ifndef CASE_HPP
#define CASE_HPP

#include "EtreVivant.hpp"
#include "Position.hpp"
#include "Item.hpp"

class Case{
  private:
    char representiton;
    Item *item;
    Position *position;
    
  public:
    EtreVivant *etreVivant;
    Case();
    Case(char representation,int posX, int posY);
    Case(char representation,int posX,int posY,EtreVivant *etreVivant,Item *item);
    char getRepresentation() const;
    Position *getPosition();
    virtual bool setEtreVivant(EtreVivant *etreVivant2);
    bool setItem(Item *item);
    EtreVivant *getEtreVivant() const;
    void setNullEtreVivant();
    Item *getItem() const;
    virtual bool EtreVivantPeutAllerSur();
    virtual bool ItemPeutAllerSur();
    virtual bool estEscalier();
};

#endif /* CASE_HPP */

