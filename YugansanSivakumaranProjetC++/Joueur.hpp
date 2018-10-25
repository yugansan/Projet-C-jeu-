/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Joueur.hpp
 * Author: yugan
 *
 * Created on 31 décembre 2017, 17:00
 */

#ifndef JOUEUR_HPP
#define JOUEUR_HPP


#include "EtreVivant.hpp"
#include "Item.hpp"
#include <vector>

class Joueur : public EtreVivant{
  private:
      int sizeAutorized=5;
      std::vector<Item*> besace;
    static void initBesace();
    char repJoueur[4]= {'<','>','v','^'};
    void getJoueurRepresentation(char move);
    void launchBesace();
  public:
    //CONSTRUCTEUR
    Joueur(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque,int champsdeVision,int deplacment,Position *position);
    Joueur(EtreVivant &etreVivant);
    //DESTRUCTEUR
    virtual ~Joueur();
    bool putItemInBesace(Item *item);
    Item *getItemFromBesace(int pos);
    Position* launchMove() override;
    bool estAAttaquerParMonstre() override;


};

#endif /* JOUEUR_HPP */

