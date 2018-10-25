/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Monstre.hpp
 * Author: yugan
 *
 * Created on 31 décembre 2017, 17:00
 */

#ifndef MONSTRE_HPP
#define MONSTRE_HPP

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "EtreVivant.hpp"
#include "Position.hpp"
#include "Item.hpp"

/** Monstre **/
//par defaut, deplacement aleatoire
class Monstre : public EtreVivant{
  private:
    char representation;
  public:
    //CONSTRUCTEUR
    Monstre(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque, int deplacement,Position *position);
    Monstre(EtreVivant &etreVivant);
    //DESTRUCTEUR
    virtual ~Monstre();
    char getRepresentation()const;
    virtual Position* launchMove() override;
    
    virtual bool estMonstreSurprise();
    
};

/** Monstre Statique **/
//pas de deplacement
class MonstreStatique : public Monstre{
  public:
    //CONSTRUCTEUR
    MonstreStatique(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque,Position *position);
    MonstreStatique(Monstre &monstre);
    //DESTRUCTEUR
    virtual ~MonstreStatique();
    Position* launchMove();
};

/** Monstre Intelligent **/
//deplacement vers le joueur
class MonstreIntelligent : public Monstre{
  public:
    //CONSTRUCTEUR
    MonstreIntelligent(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque, int deplacement,Position *position);
    MonstreIntelligent(Monstre &monstre);
    //DESTRUCTEUR
    virtual ~MonstreIntelligent();
    Position* launchMove(Position *posJoueur);
};

/** Monstre Surprise **/
//monstre possedant un Item, à sa mort il sera remplace par son item
class MonstreSurprise : public Monstre{
    private:
        Item *item=nullptr;
  public:
    //CONSTRUCTEUR
    MonstreSurprise(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque, int deplacement, Position *position, Item *item);
    MonstreSurprise(Monstre &monstre);
    bool estMonstreSurprise() override;
    Item *getItemMonstreSurprise()const;
    //DESTRUCTEUR
    virtual ~MonstreSurprise();
};

#endif /* MONSTRE_HPP */
