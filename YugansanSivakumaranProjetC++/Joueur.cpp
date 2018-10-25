#include "Joueur.hpp"
#include <iostream>
//#include <ncurses.h> //EDIT

//CONSTRUCTEUR
Joueur::Joueur(char name, int forceDeVie, int forceDAttaque, int resistanceAuxAttaque,int champsdeVision,int deplacement,Position *position):EtreVivant(name,forceDeVie,forceDAttaque,resistanceAuxAttaque,champsdeVision,deplacement,position){}
Joueur::Joueur(EtreVivant &etreVivant) : EtreVivant(etreVivant){}
//DESTRUCTEUR
Joueur::~Joueur(){}


void Joueur::getJoueurRepresentation(char move){
  if('z'== move){
    setRepresentation(repJoueur[3]);
  }else if('s' == move){
    setRepresentation(repJoueur[2]);
  }else if('d' == move ){
    setRepresentation(repJoueur[1]);
  }else if('e' == move){
    setRepresentation(repJoueur[1]);
  }else if('f' == move){
      setRepresentation(repJoueur[1]);
  }else if('q' == move){
      setRepresentation(repJoueur[0]);
  }else if('w' == move){
      setRepresentation(repJoueur[0]);
  }else if('a' == move){
      setRepresentation(repJoueur[0]);
  }
}

bool Joueur::putItemInBesace(Item *item) {
    if(besace.size()<sizeAutorized){
        besace.push_back(item);
        return true;
    }
    return false;
}

Item* Joueur::getItemFromBesace(int pos) {
    if(besace.size()>pos){
        return besace.at(pos);
    }
    return nullptr;
}

Position *Joueur::launchMove(){
    char cmd;
    Position *pos=nullptr;
    int i=0;
    do{
        cmd = getchar();
        switch (cmd){
            case 'z':
                pos = new Position(this->getPosition()->getPositionX()-1,this->getPosition()->getPositionY());
                getJoueurRepresentation('z');
                 i=1; 
                break;
            case 's':
                 pos = new Position(this->getPosition()->getPositionX()+1,this->getPosition()->getPositionY());
                 getJoueurRepresentation('s');
                  i=1; 
                break;
            case 'd':
                 pos = new Position(this->getPosition()->getPositionX(),this->getPosition()->getPositionY()+1);
                 getJoueurRepresentation('d');
                  i=1; 
                break;
            case 'q':
                 pos = new Position(this->getPosition()->getPositionX(),this->getPosition()->getPositionY()-1);
                 getJoueurRepresentation('q');
                  i=1; 
                break;
            case 'a':
                 pos = new Position(this->getPosition()->getPositionX()-1,this->getPosition()->getPositionY()-1);
                 getJoueurRepresentation('a');
                  i=1; 
                break;
            case 'e':
                 pos = new Position(this->getPosition()->getPositionX()-1,this->getPosition()->getPositionY()+1);
                 getJoueurRepresentation('e');
                  i=1; 
                break;
            case 'w':
                 pos = new Position(this->getPosition()->getPositionX()+1,this->getPosition()->getPositionY()-1);
                 getJoueurRepresentation('w');
                  i=1; 
                break;
            case 'c':
                 pos = new Position(this->getPosition()->getPositionX()+1,this->getPosition()->getPositionY()+1);
                 getJoueurRepresentation('c');
                  i=1; 
                break;
            case 'x':// prendfre escalier retourne la position du joueur
                pos = this->getPosition();
                i=1; 
                break;
            case 'b':
                std::cout <<"b"<< std::endl;
                launchBesace();
                 i=1; 
                break;
            //default:
            //    std::cout <<"def"<< std::endl;
            // break;
            i=1;    
            
        }
    }while(i != 1);
    return pos;
}

void Joueur::launchBesace() {
    char cmd;
    int position=0;
    int i=0;
    Item *it;
    if(besace.size()<=0){
         std::cout <<"Vide"<<std::endl;
        return;
    }
    do{
        cmd = getchar();
        switch (cmd){
            case 's':
                position++;
                if(position==besace.size()){
                    position=0;
                }
                break;
            case 'p':
                position--;
                if(position<0){
                    position=besace.size()-1;
                }
                break;
            case 'u':
                it= besace.at(position);
                besace.erase(besace.begin()+position);
                std::cout <<"Utilisation:"<<it->getDescription()<< std::endl;
                position--;
                break;
            case 'x':
                std::cout <<"quit"<< std::endl;
                 i=1;
                break;
            default:
            if(position<0){
                return;
            }else{
                it=getItemFromBesace(position);
                if(it==nullptr)
                    return;
                std::cout <<"Item:"<<it->getDescription()<< std::endl;
            }
        }
    }while(i != 1);
    
}


bool Joueur::estAAttaquerParMonstre() {
    return true;
}