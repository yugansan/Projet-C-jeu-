/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Jeu.hpp"

Jeu::Jeu() {
    this->joueur = new Joueur('<', 10, 12, 12, 3, 3, new Position(3, 3));
    
}

void Jeu::lancerJeu() {
    if (listeCartes.empty()) {
        //init listeCartes en utilisant toutes les cartes contenues dans rep CartesJeu
        if (!addCartesInList()) {
            std::cout << "Aucune carte disponible dans le repertoire CartesJeu !" << std::endl;
            return;
        }
        this->initCarte();
    }
    
    listEtreVivant =carte->getListEtreVivant();
    listItem=carte->getListItem();
    if(!this->carte->MajJoueur(joueur))
        return;
    carte->MajMap(listEtreVivant, listItem);
    while (true) {
        moveJoueur();
        moveEtreInList();
        carte->majRepresentation(this->joueur->getPosition(), this->joueur->getChampsdeVision()); 
        std::cout << carte->getRepresentationCarte()<< std::endl;
        std::cout<< "PointDeVie : "<<joueur->getForceDeVie() << " ForceDAttaque : "<<joueur->getForceDAttaque()<< "\n";
    }
}

void Jeu::moveJoueur() {
    Position *posit;
    posit=this->joueur->launchMove();
    if(posit != nullptr){
        carte->moveTo(this->joueur,posit);
        verifieEscalierEtChargeCarte();
        if(!this->joueur->estVivant()){
            if(carte->deleteFromeMap(this->joueur)){
                deleteEtreVivantInList(this->joueur);
                delete this->joueur;
                std::cout <<"Vous etes Mort :p Bonne chance la prochaine fois ;) " << std::endl;
                return;
            }
        }else{
            if(carte->IsCaseJoueurEscalierMontante(joueur)){
                
            }else if(carte->IsCaseJoueurEscalierMontante(joueur)){
                
            }
        }
    }
}


void Jeu::moveEtreInList() {
    Position *posit;
    EtreVivant *etreV = nullptr;
    for(int j=0; j<listEtreVivant.size();j++){
        etreV = listEtreVivant[j];
        posit=etreV->launchMove();
        if(posit != nullptr){
            carte->moveTo(etreV,posit);
            if(!etreV->estVivant()){
                if(carte->deleteFromeMap(etreV)){
                    deleteEtreVivantInList(etreV);
                    delete etreV;
                }  
            }
        }
    }
}


    bool Jeu::addItemInList(Item *item){
            this->listItem.push_back(item);
            return true;
    }
     
    bool Jeu::addEtreVivantInList(EtreVivant *etreVivant){
        this->listEtreVivant.push_back(etreVivant);
        return true;
    }

    bool Jeu::deleteEtreVivantInList(EtreVivant* etreVivant) {
        EtreVivant *etreViv = etreVivant;
        std::vector <EtreVivant*>::iterator i = std::find(this->listEtreVivant.begin(),this->listEtreVivant.end(), etreViv);
        if (i != this->listEtreVivant.end()){
            this->listEtreVivant.erase(i);
            return true;
        }
        return false;
    }

    
    bool Jeu::addCartesInList(){
        DIR * rep = opendir("./CartesJeu");
        if (rep != NULL) {
            struct dirent * ent;
            std::string filename("");
            std::string extension(".txt");
            std::size_t found;
            while ((ent = readdir(rep)) != NULL) {
                filename = ent->d_name;
                found = filename.find(extension); //si filename ne contient pas extension, 'find' renvoie string::npos (-1).
                if (found != std::string::npos) {
                    listeCartes.push_back(filename);
                }
            }
            closedir(rep);
        }
        if(listeCartes.size() > 0){
            return true;
        } else {
            return false;
        }
    }
    
    void Jeu::initCarte() {
        std::string filename;
        if(carteCourante<listeCartes.size()){
            filename = listeCartes[carteCourante];
        }else{
            filename = listeCartes[0];
        }
        this->carte = new Carte(filename);
        std::cout << carte->getRepresentationCarte() << std::endl;
    }


void Jeu::verifieEscalierEtChargeCarte(){
    if(carte->IsCaseJoueurEscalierDescendante(joueur)){
        if (carteCourante > 0) {
            delete carte;
            carteCourante--;
            this->initCarte();
            Position *pos =this->carte->getPositionEscalierMontant();
            this->carte->placeAutourEscalier(joueur,pos);
            this->carte->MajJoueur(joueur);
            this->lancerJeu();
        } else {
            Position *pos =this->carte->getPositionEscalierDescendant();
            this->carte->placerSurCaseEscalier(joueur,pos);
            std::cout << "Vous etes a l'etage le plus bas." << std::endl;
        }
    }else if(carte->IsCaseJoueurEscalierMontante(joueur)){
        if (carteCourante < listeCartes.size() - 1) {
            delete carte;
            carteCourante++;
            this->initCarte();
            Position *pos =this->carte->getPositionEscalierDescendant();
            this->carte->placeAutourEscalier(joueur,this->carte->getPositionEscalierMontant());
            this->carte->MajJoueur(joueur);
            this->lancerJeu();
        } else {
            Position *pos =this->carte->getPositionEscalierMontant();
            this->carte->placerSurCaseEscalier(joueur,pos);
            std::cout << "Vous etes a l'etage le plus haut." << std::endl;
        }
    }
}

std::ostream& operator<<(std::ostream &os, Joueur &joueur) {
    os << "PointDeVie: "<<joueur.getForceDeVie() << "ForceDAttaque: "<<joueur.getForceDAttaque()<< "\n";
    return os;
}