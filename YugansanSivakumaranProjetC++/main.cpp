/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: yugan
 *
 * Created on 31 décembre 2017, 16:58
 */
#include <iostream>
#include <cstdlib>

#include "Jeu.hpp"



#include <typeinfo>
#include <stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Jeu *jeu =new Jeu();
    
    //Joueur *jou = new Joueur('>',1,1,1,1,1,new Position(2,2));
    //Joueur *jou2 = new Joueur('<',100,1,1,1,1,new Position(3,4));
    Item *it = new Item('s',"sac",12, new Position(0,0));
    //jeu->addEtreVivantInList(jou);
    Monstre *m = new Monstre('M',10,1,1,3,new Position(3,7));
    Monstre *m2 = new Monstre('m',10,1,1,2,new Position(2,9));
    
    //jeu->addEtreVivantInList(jou2);
    jeu->addEtreVivantInList(m);
    jeu->addEtreVivantInList(m2);
    jeu->addItemInList(it);
    jeu->lancerJeu();

    
    
    return 0;
}

