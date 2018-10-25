#include <iostream>
#include "Carte.hpp"

Carte::Carte() {
    initCarte("carteDefaut.txt");
}

Carte::Carte(std::string fileName) {
    initCarte(fileName);
}

Carte::Carte(std::string fileName, char tabMur2[sizeTabMur], char escalier[sizeTabEscalier]) {
    for (int i = 0; i < sizeTabMur; i++) {
        tabMur[i] = tabMur2[i];
    }
    for (int i = 0; i < sizeTabEscalier; i++) {
        tabEscalier[i] = escalier[i];
    }
    initCarte(fileName);
}

Carte::Carte(std::string fileName, char tabMur2[], char escalier[], char tabMonstre[], char tabItem[]) {
    for (int i = 0; i < sizeTabMur; i++) {
        tabMur[i] = tabMur[i];
    }
    for (int i = 0; i < sizeTabEscalier; i++) {
        tabEscalier[i] = escalier[i];
    }
    for (int i = 0; i < sizeTabMonstre; i++) {
        tabMonstreDansLodreNiveau[i] = tabMonstre[i];
    }
    for (int i = 0; i < sizeTabItem; i++) {
        tabItemDansLodreNiveau[i] = tabItem[i];
    }
    initCarte(fileName);
}

/*
Carte::Carte (const Carte& carte){}
 */

void Carte::initCarte(std::string fileName) {
    positionEscalierMontant = nullptr;
    positionEscalierDescendant = nullptr;
    std::ifstream fichier(fileName);
    if (fichier) {
        char car;
        int ligne = 0, colonne = 0;
        do {
            fichier.get(car);
            if (car == '\n') {
                ligne++;
                colonne = 0;
            }
            if (car == ' ') {
                map[ligne][colonne] = nullptr;
                colonne++;
            }
            if (car != ' ' && car != '\n') {
                if (tabEscalier[0] == car) {
                    map[ligne][colonne] = new CaseEscalier(car, ligne, colonne, false);
                    positionEscalierDescendant = new Position(ligne, colonne);
                    representationCarte[ligne][colonne] = car;
                    colonne++;
                } else if (tabEscalier[1] == car) {
                    map[ligne][colonne] = new CaseEscalier(car, ligne, colonne, true);
                    positionEscalierMontant = new Position(ligne, colonne);
                    representationCarte[ligne][colonne] = car;
                    colonne++;
                } else {
                    bool ajouter = false;
                    for (int i = 0; i < sizeTabMur; i++) {
                        if (tabMur[i] == car) {
                            map[ligne][colonne] = new CaseMur(car, ligne, colonne);
                            representationCarte[ligne][colonne] = car;
                            i = sizeTabMur;
                            ajouter = true;
                            colonne++;
                        }
                    }
                    for (int i = 0; i < sizeTabMonstre; i++) {
                        if (tabMonstreDansLodreNiveau[i] == car) {

                            Monstre *m = nullptr;
                            map[ligne][colonne] = new Case('.', ligne, colonne);
                            switch (i) {
                                case 0:
                                    m = new Monstre(tabMonstreDansLodreNiveau[i], 5, 3, 2, 1, new Position(ligne, colonne));
                                    map[ligne][colonne]->setEtreVivant(m);
                                    addEtreVivantInList(m);
                                    break;
                                case 1:
                                    m = new MonstreStatique(tabMonstreDansLodreNiveau[i],5,2,3, new Position(ligne, colonne));
                                    map[ligne][colonne]->setEtreVivant(m);
                                    addEtreVivantInList(m);
                                    break;
                                case 2:
                                    m = new MonstreIntelligent(tabMonstreDansLodreNiveau[i],8,5,10,3,new Position(ligne, colonne));
                                    map[ligne][colonne]->setEtreVivant(m);
                                    addEtreVivantInList(m);
                                    break;
                                case 3://monstre inteligent
                                    //Item *itemMons = new Potion('@',new Position(ligne, colonne));
                                    ///m =new MonstreSurprise(tabMonstreDansLodreNiveau[i],10,7,8,3,new Position(ligne, colonne),item);
                                    m = new MonstreStatique(tabMonstreDansLodreNiveau[i],5,2,3, new Position(ligne, colonne));
                                    map[ligne][colonne]->setEtreVivant(m);
                                    addEtreVivantInList(m);
                                    break;
                                /*case 4:
                                    m = new Monstre(tabMonstreDansLodreNiveau[i], 35, 3, 2, 5, new Position(ligne, colonne));
                                    map[ligne][colonne]->setEtreVivant(m);
                                    addEtreVivantInList(m);
                                    break;*/
                            }
                            i = sizeTabMur;
                            colonne++;
                            ajouter = true;
                        }
                    }
                    for (int i = 0; i < sizeTabItem; i++) {
                        if (tabItemDansLodreNiveau[i] == car) {
                            Item *it = nullptr;
                            map[ligne][colonne] = new Case('.', ligne, colonne);
                            switch (i) {
                                case 0:
                                    it = new Bouclier(tabItemDansLodreNiveau[i], new Position(ligne, colonne));
                                    map[ligne][colonne]->setItem(it);
                                    //addItemInList(it);
                                    break;
                                case 1:
                                    it = new Bombe(tabItemDansLodreNiveau[i], new Position(ligne, colonne));
                                    map[ligne][colonne]->setItem(it);
                                    //addItemInList(it);
                                    break;
                                case 2:
                                    it = new Potion(tabItemDansLodreNiveau[i], new Position(ligne, colonne));
                                    map[ligne][colonne]->setItem(it);
                                    //addItemInList(it);
                                    break;
                                case 3:
                                    it = new Potion(tabItemDansLodreNiveau[i], new Position(ligne, colonne));
                                    map[ligne][colonne]->setItem(it);
                                    //addItemInList(it);
                                    break;
                                case 4:
                                    it = new Bombe(tabItemDansLodreNiveau[i], new Position(ligne, colonne));
                                    map[ligne][colonne]->setItem(it);
                                    //addItemInList(it);
                                    break;
                            }
                            i = sizeTabMur;
                            ajouter = true;
                            colonne++;
                        }
                    }
                    if (!ajouter) {
                        map[ligne][colonne] = new Case(car, ligne, colonne);
                        representationCarte[ligne][colonne] = car;
                        colonne++;
                    }
                }
            }
        } while (!fichier.eof());
    } else {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
    }
}

Carte::~Carte() {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            map[i][j] = nullptr;
        }
    }
}

Carte* Carte::getCarte() {
    return this;
}

int Carte::getTaille() const {
    return TAILLE;
}

std::string Carte::getRepresentationCarte() const {
    std::string rep = "";
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (map[i][j] == nullptr) {
                rep += " ";
            } else {
                rep += representationCarte[i][j];
            }
        }
        rep += "\n";
    }
    return rep;
}

void Carte::majRepresentation(Position *position, int champs) {
    int debutX, debutY, finX, finY;
    debutX = position->getPositionX() - champs;
    finX = position->getPositionX() + champs;
    debutY = position->getPositionY() - champs;
    finY = position->getPositionY() + champs;
    if (debutX < 0) {
        debutX = 0;
    }
    if (debutY < 0) {
        debutY = 0;
    }
    if (finX > TAILLE) {
        finX = TAILLE;
    }
    if (finY > TAILLE) {
        finY = TAILLE;
    }
    for (int i = debutX; i < finX; i++) {
        for (int j = debutY; j < finY; j++) {
            if (map[i][j] == nullptr) {
                representationCarte[i][j] = " ";
            } else {
                representationCarte[i][j] = map[i][j]->getRepresentation();
            }
        }
    }
}

bool Carte::setCasesEtreVivant(EtreVivant *etre) {
    if (etre != nullptr) {
        int x, y;
        x = etre->getPosition()->getPositionX();
        y = etre->getPosition()->getPositionY();
        if (map[etre->getPosition()->getPositionX()][etre->getPosition()->getPositionY()] != nullptr) {
            if (map[etre->getPosition()->getPositionX()][etre->getPosition()->getPositionY()]->EtreVivantPeutAllerSur()) {
                if (map[etre->getPosition()->getPositionX()][etre->getPosition()->getPositionY()]->getEtreVivant() == nullptr) {
                    return map[etre->getPosition()->getPositionX()][etre->getPosition()->getPositionY()]->setEtreVivant(etre);
                }
            }
        }
    }
    return false;
}

bool Carte::setCasesItem(Item* item) {
    if (item != nullptr) {
        int x, y;
        x = item->getPosition()->getPositionX();
        y = item->getPosition()->getPositionY();
        if (map[item->getPosition()->getPositionX()][item->getPosition()->getPositionY()] != nullptr) {
            if (map[item->getPosition()->getPositionX()][item->getPosition()->getPositionY()]->ItemPeutAllerSur()) {
                return map[item->getPosition()->getPositionX()][item->getPosition()->getPositionY()]->setItem(item);
            }
        }
    }
    return false;

}

bool Carte::moveTo(EtreVivant *etre, Position *posArv) {
    if (posArv->getPositionX() > TAILLE - 1 || posArv->getPositionX() < 0 || posArv->getPositionY() > TAILLE - 1 || posArv->getPositionY() < 0)
        return false;
    if (map[posArv->getPositionX()][posArv->getPositionY()] != nullptr) {
        if (map[posArv->getPositionX()][posArv->getPositionY()]->EtreVivantPeutAllerSur()) {
            if ((map[etre->getPosition()->getPositionX()][etre->getPosition()->getPositionY()]->getEtreVivant() != nullptr)
                    && map[etre->getPosition()->getPositionX()][etre->getPosition()->getPositionY()]->getEtreVivant()->estAAttaquerParMonstre()) {
                Item *item = map[etre->getPosition()->getPositionX()][etre->getPosition()->getPositionY()]->getItem();
                if (item != nullptr) {
                    ((Joueur*) etre)->putItemInBesace(item);
                }
                map[posArv->getPositionX()][posArv->getPositionY()]->setEtreVivant(map[etre->getPosition()->getPositionX()][etre->getPosition()->getPositionY()]->getEtreVivant());
                map[etre->getPosition()->getPositionX()][etre->getPosition()->getPositionY()]->setNullEtreVivant();
                etre->setPosition(posArv);
                return true;
            }
        } else if (map[posArv->getPositionX()][posArv->getPositionY()]->getEtreVivant() != nullptr) {
            EtreVivant *etreV = map[posArv->getPositionX()][posArv->getPositionY()]->getEtreVivant();
            if (etreV->estAAttaquerParMonstre() && (!etre->estAAttaquerParMonstre())) {
                etre->attaque(etreV);
                if (!etreV->attaque(etre)) {
                    if (((Monstre*) etre)->estMonstreSurprise() && map[posArv->getPositionX()][posArv->getPositionY()]->ItemPeutAllerSur()) {
                        Item *item = ((MonstreSurprise*) etre)->getItemMonstreSurprise();
                        map[posArv->getPositionX()][posArv->getPositionY()]->setItem(item);
                        map[posArv->getPositionX()][posArv->getPositionY()]->setNullEtreVivant();
                        delete etreV;
                        addItemInList(item);
                    }
                }
            } else if ((!etreV->estAAttaquerParMonstre()) && (etre->estAAttaquerParMonstre())) {
                etre->attaque(etreV);
                etreV->attaque(etre);
            }
        }
    }
    return false;
}

bool Carte::IsCaseJoueurEscalierMontante(EtreVivant *joueur) {
    if (map[joueur->getPosition()->getPositionX()][joueur->getPosition()->getPositionY()]->estEscalier()) {
        if (((CaseEscalier*) map[joueur->getPosition()->getPositionX()][joueur->getPosition()->getPositionY()])->getIsMonter()) {
            return true;
        }
    }
    return false;
}

bool Carte::IsCaseJoueurEscalierDescendante(EtreVivant *joueur) {
    if (map[joueur->getPosition()->getPositionX()][joueur->getPosition()->getPositionY()]->estEscalier()) {
        if (!((CaseEscalier*) map[joueur->getPosition()->getPositionX()][joueur->getPosition()->getPositionY()])->getIsMonter()) {
            return true;
        }
    }
    return false;
}

bool Carte::deleteFromeMap(EtreVivant* etre) {
    if (map[etre->getPosition()->getPositionX()][etre->getPosition()->getPositionY()] != nullptr) {
        map[etre->getPosition()->getPositionX()][etre->getPosition()->getPositionY()]->setNullEtreVivant();
        return true;
    }
    return false;
}

void Carte::MajMap(std::vector<EtreVivant*> listEtre, std::vector<Item*> listItem) {
    for (EtreVivant *et : listEtre) {
        setCasesEtreVivant(et);
    }
    for (Item *it : listItem) {
        setCasesItem(it);
    }
}

bool Carte::MajJoueur(Joueur *joueur) {
    return setCasesEtreVivant(joueur);
}

char Carte::isEscalier(Position *posit) {
    if (map[posit->getPositionX()][posit->getPositionY()] != nullptr) {
        if (map[posit->getPositionX()][posit->getPositionY()]->getRepresentation() == 'H') {
            return 'H';
        } else if (map[posit->getPositionX()][posit->getPositionY()]->getRepresentation() == 'h') {
            return 'h';
        }
    }
    return '\0';
}

void Carte::addItemInList(Item *item) {
    listItem.push_back(item);
}

void Carte::addEtreVivantInList(EtreVivant *etreVivant) {
    listEtreVivant.push_back(etreVivant);
}

std::vector<EtreVivant*> Carte::getListEtreVivant() const {
    return listEtreVivant;
}

std::vector<Item*> Carte::getListItem() const {
    return listItem;
}

Position* Carte::getPositionEscalierDescendant() const {
    return positionEscalierDescendant;
}

Position* Carte::getPositionEscalierMontant()const {
    return positionEscalierMontant;
}

void Carte::placeAutourEscalier(EtreVivant* joueur, Position* positionEscalier) {
    if (joueur == nullptr)
        return;
    if (positionEscalier == nullptr) {
        positionEscalier = new Position(0, 0);
    }
    int x = positionEscalier->getPositionX();
    int y = positionEscalier->getPositionY();
    if (x == 0 && y == 0) {
        if (map[x + 1][y]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y));
            return;
        } else if (map[x][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x, y + 1));
            return;
        } else if (map[x + 1][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y + 1));
            return;
        }
    } else if (x == 0 && y == TAILLE - 1) {
        if (map[x + 1][y]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y));
            return;
        } else if (map[x][y - 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x, y - 1));
            return;
        } else if (map[x + 1][y - 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y - 1));
            return;
        }
    } else if (x == TAILLE - 1 && y == 0) {
        if (map[x + 1][y]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y));
            return;
        } else if (map[x][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x, y + 1));
            return;
        } else if (map[x + 1][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y + 1));
            return;
        }
    } else if (x == TAILLE - 1 && y == TAILLE - 1) {
        if (map[x + 1][y]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y));
            return;
        } else if (map[x][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x, y + 1));
            return;
        } else if (map[x + 1][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y + 1));
            return;
        }
    } else if (x == 0 && y > 0 && y < TAILLE - 1) {
        if (map[x + 1][y]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y));
            return;
        } else if (map[x + 1][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y + 1));
            return;
        } else if (map[x][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x, y + 1));
            return;
        } else if (map[x][y - 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x, y - 1));
            return;
        } else if (map[x + 1][y - 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y - 1));
            return;
        }
    } else if (y == 0 && x > 0 && x < TAILLE - 1) {
        if (map[x - 1][y]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x - 1, y));
            return;
        } else if (map[x + 1][y]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y));
            return;
        } else if (map[x - 1][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x - 1, y + 1));
            return;
        } else if (map[x][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x, y + 1));
            return;
        } else if (map[x + 1][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y + 1));
            return;
        }
    } else if (y == TAILLE - 1 && x > 0 && x < TAILLE - 1) {
        if (map[x - 1][y]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x - 1, y));
            return;
        } else if (map[x - 1][y - 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x - 1, y - 1));
            return;
        } else if (map[x - 1][y]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x - 1, y));
            return;
        } else if (map[x + 1][y - 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y - 1));
            return;
        } else if (map[x + 1][y]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x + 1, y));
            return;
        }
    } else if (x == TAILLE - 1 && y > 0 && y < TAILLE - 1) {
        if (map[x][y - 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x, y - 1));
            return;
        } else if (map[x - 1][y - 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x - 1, y - 1));
            return;
        } else if (map[x - 1][y]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x - 1, y));
            return;
        } else if (map[x - 1][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x - 1, y + 1));
            return;
        } else if (map[x][y + 1]->EtreVivantPeutAllerSur()) {
            moveTo(joueur, new Position(x, y + 1));
            return;
        }
    } else {
        x = 0;
        y = 0;
        do {
            moveTo(joueur, new Position(x, y));
            return;
        } while (map[x][y]->EtreVivantPeutAllerSur() && x < TAILLE - 1 && y < TAILLE - 1);
    }

}

/*** METHODES POUR SAUVEGARDE. ***/
std::string Carte::getFileName() {
    /* lire l'heure courante */
    time_t now = time(NULL);
    /* la convertir en heure locale */
    struct tm tm_now = *localtime(&now);
    /* Creer une chaine AAAAMMJJHHMMSS */
    char s_now[sizeof "AAAAMMJJHHMMSS"];
    strftime(s_now, sizeof s_now, "%Y%m%d%H%M%S", &tm_now);
    std::string fileNameToSave = "Sauvegarde/Carte_" + (std::string) s_now + ".txt";
    //Retourne le chemin relatif du fichier a creer
    return fileNameToSave;
}

void Carte::mapToFile() {
    std::string file = getFileName();
    std::ofstream fichier(file, std::ios::out | std::ios::trunc);
    if (fichier) {

        for (int i = 0; i < TAILLE; i++) {
            for (int j = 0; j < TAILLE; j++) {
                if (map[i][j] == nullptr) {
                    fichier << " ";
                } else {
                    fichier << map[i][j]->getRepresentation();
                }
            }
            fichier << "" << std::endl;
        }

        fichier.close();
    } else
        std::cerr << "Erreur à la sauvegarde !" << std::endl;
}

bool Carte::placerSurCaseEscalier(EtreVivant* joueur, Position *pos) {
    return moveTo(joueur, pos);
}