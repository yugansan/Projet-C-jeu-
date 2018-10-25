/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Item.hpp"

/*** ITEM ***/
Item::Item(char representation, std::string description, int effet, Position*position) {
    this->representation = representation;
    this->description = description;
    this->effet = effet;
    this->position = position;
}

Item::Item() {

}

Item::Item(Item &item) {

}

char Item::getRepresentation() const {
    return this->representation;
}

void Item::setEffet(int e){
    this->effet = e;
}

std::string Item::getDescription() const {
    return this->description;
}

int Item::getEffet() const {
    return this->effet;
}

int Item::utiliserItem() const {
    return this->effet;
}

Position* Item::getPosition() const {
    return this->position;
}

bool Item::mettreDansBesace() const {
    return false;
}

/*** POTION ***/
Potion::Potion(char represention, Position *position) {
    int effet = (rand() % 100) - 50;
    if (effet==0)
        effet++;
    std::string description;
    if (effet > 0){
        description = "Potion Bonus Vie";
    } else if (effet < 0){
        description = "Potion Malus Attaque";
    }
    Item(represention, description, effet, position);
}

Potion::Potion(Item &item) : Item(item) {
}


/*** BOMBE ***/
Bombe::Bombe(char represention, Position *position) {
    std::string description = "Explosion d'une Bombe";
    
    Item(represention, description, -50, position);
}

Bombe::Bombe(Item &item) : Item(item) {
}

/*** Bouclier ***/
Bouclier::Bouclier(char represention, Position *position) {
    int effet = (rand() % 100) + 50;
    
    std::string description = "Bouclier";
    
    Item(represention, description, effet, position);
}

Bouclier::Bouclier(Item &item) : Item(item) {
}

bool Bouclier::mettreDansBesace() const {
    return true;
}