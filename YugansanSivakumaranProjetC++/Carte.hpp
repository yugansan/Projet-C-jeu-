/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carte.hpp
 * Author: yugan
 *
 * Created on 31 décembre 2017, 16:59
 */

#ifndef CARTE_HPP
#define CARTE_HPP
#include "Case.hpp"
#include "Item.hpp"
#include "EtreVivant.hpp"
#include "CaseMur.hpp"
#include "CaseEscalier.hpp"
#include "Joueur.hpp"
#include "Monstre.hpp"
#include <vector>
#include <fstream>


static const int TAILLE = 80;
static  Case *map[TAILLE][TAILLE];
static  std::string representationCarte[TAILLE][TAILLE];
static const int sizeTabMur=3,sizeTabEscalier =2,sizeTabMonstre=5,sizeTabItem=4;
static char tabMur[sizeTabMur]={'|','_','-'};
static char tabEscalier[sizeTabEscalier]={'h','H'};
static char tabMonstreDansLodreNiveau[sizeTabMonstre]={'m','n','o','M','N'};
static char tabItemDansLodreNiveau[sizeTabItem]={'@','I','J','K'};

static Position *positionEscalierMontant=nullptr;
static Position *positionEscalierDescendant=nullptr;
static std::vector<Item*> listItem;
static std::vector<EtreVivant*> listEtreVivant;
    
class Carte{
  private:
    static void initCarte(std::string fileName);
    
    static void addItemInList(Item *item);
    static void addEtreVivantInList(EtreVivant * etreVivant);
    
    
    
  public:
    Carte();
    Carte(std::string fileName);
    Carte(std::string fileName,char tabMur[sizeTabMur],char escalier[sizeTabMur]);
    Carte(std::string fileName,char tabMur[sizeTabMur],char escalier[sizeTabMur],char tabMonstre[sizeTabMonstre],char tabItem[sizeTabItem]);
    Carte (const Carte&);
    
    virtual ~Carte();
    
    Carte *getCarte();
    int getTaille() const;
    std::string getRepresentationCarte() const;
    void majRepresentation(Position *position,int champs);
    bool setCasesEtreVivant(EtreVivant *etre);
    bool setCasesItem(Item *item);
    bool moveTo(EtreVivant *etreV, Position *posArv);
    void MajMap(std::vector<EtreVivant*>listEtre,std::vector<Item*>listItem);
    bool MajJoueur(Joueur *joueur);
    bool deleteFromeMap(EtreVivant * etre);
    
    bool IsCaseJoueurEscalierMontante(EtreVivant *joueur);
    bool IsCaseJoueurEscalierDescendante(EtreVivant *joueur);
    char isEscalier(Position *posit);
    
    std::vector<EtreVivant*>getListEtreVivant() const;
    std::vector<Item*>getListItem() const;
    Position *getPositionEscalierMontant()const;
    Position *getPositionEscalierDescendant()const;
    
    void placeAutourEscalier(EtreVivant *joueur, Position *positionEscalier);
    bool placerSurCaseEscalier(EtreVivant *joueur,Position *position);
    
    //Sauvegarde.
    std::string getFileName();
    void mapToFile();
};

#endif /* CARTE_HPP */

