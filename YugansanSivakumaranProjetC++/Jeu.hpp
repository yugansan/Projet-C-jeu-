/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jeu.hpp
 * Author: yugan
 *
 * Created on 3 janvier 2018, 20:12
 */

#ifndef JEU_HPP
#define JEU_HPP
#include <vector>
#include "Carte.hpp"
#include "Item.hpp"
#include "EtreVivant.hpp"
#include "Joueur.hpp"
#include "Monstre.hpp"
#include <iostream>
#include <dirent.h>
#include <algorithm> // find iterator
class Jeu{
private :
    Joueur *joueur;
    Carte *carte;
    

    std::vector<std::string> listeCartes;
    int carteCourante = 0;
    
    std::vector<Item*> listItem;
    std::vector<EtreVivant*> listEtreVivant;
    bool deleteEtreVivantInList(EtreVivant *etreVivant);
    void moveJoueur();
    void moveEtreInList();
    void verifieEscalierEtChargeCarte();
public:
    Jeu();
    void lancerJeu();
    bool addItemInList(Item *item);
    bool addEtreVivantInList(EtreVivant * etreVivant);
    
    bool addCartesInList();
    void initCarte();
    void changerCarte(char escalier);
};

#endif /* JEU_HPP */

