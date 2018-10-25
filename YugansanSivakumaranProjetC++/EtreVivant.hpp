/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EtreVivant.hpp
 * Author: yugan
 *
 * Created on 31 décembre 2017, 16:59
 */

#ifndef ETREVIVANT_HPP
#define ETREVIVANT_HPP

#include "Position.hpp"

#include <iostream>

class EtreVivant{
  private:
      Position *position;
    char name;
    int forceDAttaque;
    int resistanceAuxAttaque;
    int forceDeVie;
    int champsdeVision;
    int deplacement;
  public:
    //CONSTRUCTEUR
    EtreVivant(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque,int champsdeVision,int deplacement,Position *position);
    EtreVivant(const EtreVivant&);
    //DESTRUCTEUR
    virtual ~EtreVivant();
    //GETTERS
    char getName() const;
    int getForceDAttaque() const;
    int getResistanceAuxAttaque() const;
    int getForceDeVie() const;
    int getChampsdeVision() const;
    int getDeplacement() const;
    Position *getPosition()const;
    //SETTERS
    void setForceDAttaque(int forceDAttaque);
    void setResistanceAuxAttaque(int resistanceAuxAttaque);
    void setForceDeVie(int forceDeVie);
    void setChampsdeVision(int champs);
    void setPosition(Position *position);
    virtual Position *launchMove();
    void setRepresentation(char rep);
    //methodes
    bool attaque(EtreVivant *aAttaque);
    bool estVivant() const;
    virtual bool estAAttaquerParMonstre();
};

#endif /* ETREVIVANT_HPP */

