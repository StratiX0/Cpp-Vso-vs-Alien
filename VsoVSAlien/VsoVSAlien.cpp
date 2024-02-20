// test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <sstream>
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;


class Vaisseau {
public:
    int id;
    std::string nom;
    int vie;
    int missiles;
    int plasma;
    int mc;
    int shieldPower;
    int fsdCldw;
    int reparation;

};

class Ennemie {
public:
    int id;
    std::string nom;
    int vie;
    int attack1;
    int attack2;
    int armure;
    int regen;

};



// Fonction permettant de créer le vaisseau du joueur en fonction de la difficulté
int createVaisseau(int difficulte) {
    // Initialisation du générateur de nombres aléatoires
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Définir des noms de vaisseau prédéfinis
    std::vector<std::string> vaisseauNom = { "Anaconda", "Kraken", "Kom'Rk" };
    int index = std::rand() % vaisseauNom.size();
    std::string value = vaisseauNom[index]; // un nom de vaisseau aléatoire pris de la liste

    int hp = 250;

    Vaisseau vaisseau;

    switch (difficulte) {
    case 1:
        vaisseau.id = 0;
        vaisseau.nom = value;
        vaisseau.vie = hp;
        vaisseau.missiles = 35;
        vaisseau.plasma = 60;
        vaisseau.mc = 30;
        vaisseau.shieldPower = 30;
        vaisseau.fsdCldw = 2;
        vaisseau.reparation = 15;
        break;

    case 2:
        vaisseau.id = 1;
        vaisseau.nom = value;
        vaisseau.vie = hp;
        vaisseau.missiles = 25;
        vaisseau.plasma = 50;
        vaisseau.mc = 20;
        vaisseau.shieldPower = 20;
        vaisseau.fsdCldw = 3;
        vaisseau.reparation = 10;
        break;

    case 3:
        vaisseau.id = 2;
        vaisseau.nom = value;
        vaisseau.vie = hp;
        vaisseau.missiles = 15;
        vaisseau.plasma = 40;
        vaisseau.mc = 10;
        vaisseau.shieldPower = 10;
        vaisseau.fsdCldw = 4;
        vaisseau.reparation = 5;
        break;

    default:
        // Gérer la valeur de difficulté par défaut ici
        break;
    }

    std::ofstream VaisseauFile("Vaisseau.txt", std::ios::trunc);

    if (!VaisseauFile.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        return -1; // Retourner une valeur d'erreur
    }
    else {
        VaisseauFile << vaisseau.id << std::endl << vaisseau.nom << std::endl << vaisseau.vie << std::endl << vaisseau.missiles << std::endl << vaisseau.plasma << std::endl << vaisseau.mc << std::endl << vaisseau.shieldPower << std::endl << vaisseau.fsdCldw << std::endl << vaisseau.reparation << std::endl;
        VaisseauFile.close();
    }

    std::cout << "Vous avez choisi: " << vaisseau.nom << std::endl << "Ce dernier a " << vaisseau.vie << "HP," << std::endl << "Il tansporte des missiles ayant une puissance de feu de " << vaisseau.missiles << ',' << std::endl << "Il a comme equipement des lanceur Plasma ayant comme puissance " << vaisseau.plasma << ',' << std::endl << "Ainsi que des Multi-Canons qui ont " << vaisseau.mc << " de puissance," << std::endl << "Il dispose comme protection d'un generateur de bouclier d'une puissance de " << vaisseau.shieldPower << "MJ," << std::endl << "Le generateur FSD est de classe " << vaisseau.fsdCldw << "A," << std::endl << "Il a dans la soute " << vaisseau.reparation << " drones reparateurs." << std::endl;

    return 0; // Renvoyer 0 pour indiquer le succès
}




// Fonction permettant de créer un ennemi en fonction de la difficulté
int createEnnemie(int difficulte) {
    // Initialisation du générateur de nombres aléatoires
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Définir des noms d'ennemis prédéfinis
    std::vector<std::string> ennemieNoms = { "Xenomorphe", "Predator", "Gary" };
    int index = std::rand() % ennemieNoms.size();
    std::string value = ennemieNoms[index]; // Un nom de vaisseau aléatoire pris de la liste

    Ennemie ennemie;
    ennemie.id = index + 1; // Utiliser l'index (0, 1, 2) comme ID (1, 2, 3)
    ennemie.nom = value;

    switch (difficulte) {

    case 1:

        switch (index) {

        case 0:

            ennemie.vie = 400;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.regen = 2;
            break;

        case 1:

            ennemie.vie = 300;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.regen = 2;
            break;

        case 2:

            ennemie.vie = 600;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.regen = 2;
            break;
        }

        break; // Ajoutez cette ligne pour sortir du premier switch

    case 2:

        switch (index) {

        case 0:

            ennemie.vie = 500;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.regen = 2;
            break;

        case 1:

            ennemie.vie = 400;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.regen = 2;
            break;

        case 2:

            ennemie.vie = 700;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.regen = 2;
            break;

        }

        break; // Ajoutez cette ligne pour sortir du deuxième switch

    case 3:

        switch (index) {

        case 0:

            ennemie.vie = 600;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.regen = 2;
            break;

        case 1:

            ennemie.vie = 500;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.regen = 2;
            break;

        case 2:

            ennemie.vie = 1000;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.regen = 2;
            break;

        }

        break; // Ajoutez cette ligne pour sortir du troisième switch

    default:

        break;
    }

    std::ofstream EnnemiFile("Ennemi.txt", std::ios::trunc);

    if (!EnnemiFile.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        return -1; // Retourner une valeur d'erreur
    }
    else {
        EnnemiFile << ennemie.id << std::endl << ennemie.nom << std::endl << ennemie.vie << std::endl << ennemie.attack1 << std::endl << ennemie.attack2 << std::endl << ennemie.armure << std::endl << ennemie.regen << std::endl;
        EnnemiFile.close();
    }

    std::cout << ennemie.nom << std::endl << "\nCe dernier a " << ennemie.vie << "HP" << std::endl << "Son attaque principale a une puissance de " << ennemie.attack1 << std::endl << "Son attaque secondaire a une puissance de " << ennemie.attack2 << std::endl << "Il a " << ennemie.armure << " points d'armure" << std::endl << "Et peux se regenerer " << ennemie.regen << " fois.\n" << std::endl;

    return 0; // Renvoyer 0 pour indiquer le succès
}


void deroulementPartie(int difficulte) {

    std::string Ligne, NomVaisseau, NomEnnemi;
    int IdV, VieJ, Missiles, Plasma, Mc, Shield, FSD, Fix;     //Valeurs du joueur durant la partie
    int IdE, VieE, Atk1, Atk2, Armure, Regen;           //Valeur de l'ennemi durant la partie

    std::fstream VaisseauFile("Vaisseau.txt", std::ios::trunc);
    VaisseauFile.open("Vaisseau.txt");

    if (!VaisseauFile.is_open()) { //on ouvre le fichier du vaisseau et le lis en enregistrant les variables
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        // Retourner une valeur d'erreur
    }
    else {
        int i = 0;
        while (getline(VaisseauFile, Ligne))
        {
            std::stringstream ss;
            i++;
            if (i == 1) {
                ss << Ligne;
                ss >> IdV;
            }
            if (i == 2) {
                ss << Ligne;
                ss >> NomVaisseau;
            }
            if (i == 3) {
                ss << Ligne;
                ss >> VieJ;
            }
            if (i == 4) {
                ss << Ligne;
                ss >> Missiles;
            }
            if (i == 5) {
                ss << Ligne;
                ss >> Plasma;
            }
            if (i == 6) {
                ss << Ligne;
                ss >> Mc;
            }
            if (i == 7) {
                ss << Ligne;
                ss >> Shield;
            }
            if (i == 8) {
                ss << Ligne;
                ss >> FSD;
            }
            if (i == 9) {
                ss << Ligne;
                ss >> Fix;
            }
        }

    }
    VaisseauFile.close();

    std::fstream EnnemiFile("Ennemi.txt", std::ios::trunc);
    EnnemiFile.open("Ennemi.txt");

    if (!EnnemiFile.is_open()) { //on ouvre le fichier de l'ennemi et le lis en enregistrant les variables
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        // Retourner une valeur d'erreur
    }
    else {
        int i = 0;
        while (getline(EnnemiFile, Ligne))
        {
            std::stringstream ss;
            i++;
            if (i == 1) {
                ss << Ligne;
                ss >> IdE;
            }
            if (i == 2) {
                ss << Ligne;
                ss >> NomEnnemi;
            }
            if (i == 3) {
                ss << Ligne;
                ss >> VieE;
            }
            if (i == 4) {
                ss << Ligne;
                ss >> Atk1;
            }
            if (i == 5) {
                ss << Ligne;
                ss >> Atk2;
            }
            if (i == 6) {
                ss << Ligne;
                ss >> Armure;
            }
            if (i == 7) {
                ss << Ligne;
                ss >> Regen;
            }
        }

    }
    EnnemiFile.close();


    char Action;
    int faussemanip = 0;
    int MaxHP = VieJ;
    bool ReductionDPS = false;
    bool FSDactif = false;
    int VieEMax = VieE;
    while (VieJ > 0 || VieE > 0) {


        if (VieJ <= 0)
        {
            std::cout << "\n\nVotre " << NomVaisseau << " s'est fait detruire par " << NomEnnemi;
            std::cout << "\n\n(skill issue)\n\n";
            break;
        }
        else if (VieE <= 0)
        {
            std::cout << "\n\n\nVous avez vaincu " << NomEnnemi << "!\n\n\n";
            break;
        }
        else if (FSDactif != false)
        {
            std::cout << "\n\n\nIl vous reste: " << VieJ << "PV\nL'enemmi a encore: " << VieE << "HP\n\n\n\nIl reste " << FSD << " tours avant la fin du chargement du FSD\n";
            sleep_until(system_clock::now() + 2s);
            //l'ennemi joue un tour
            //L'ennemi joue un tour 
            int ActionE = (rand() % 6 + 1);
            
            int Atkrandom1 = (rand() % Atk1 + 7);
            int Atkrandom2 = (rand() % Atk2 + 15);
            int RegenE = (rand() % Regen + 50);
            int tourE = 1;
            while (tourE != 0) {
                if (ReductionDPS == true) {
                    Atkrandom1 = Atkrandom1 * 0.25;
                    Atkrandom2 = Atkrandom2 * 0.25;
                    ReductionDPS = false;

                }
                if (ActionE == 4 || ActionE == 5) {
                    VieJ = VieJ - Atkrandom2;
                    std::cout << "\n\nL'ennemi utilise une Attaque Puissante,\nIl vous inflige " << Atkrandom2 << " DPS";
                    ReductionDPS = false;
                    break;
                }
                if (ActionE == 6 && Regen > 0 && VieE < 200) {
                    VieE = VieE + RegenE;
                    Regen = Regen - 1;
                    std::cout << "\n\nL'ennemi se regen  " << RegenE << " HP";
                    break;
                }
                if (ActionE < 4) {
                    VieJ = VieJ - Atkrandom1;
                    std::cout << "\n\nL'ennemi utilise une Attaque Normale,\nIl vous inflige " << Atkrandom1 << " DPS";
                    ReductionDPS = false;
                    break;
                }
                else
                    ActionE = (rand() % 6 + 1);
            }//Fin du tour de l'ennemi
            std::cout << "\n\n\nIl vous reste: " << VieJ << "PV\nL'enemmi a encore: " << VieE << "HP\nQue voulez vous faire ?\n\n A = Attaquer,\n S = Charger les boucliers\n\n" ;
            std::cin >> Action;
            if (Action == 'A' || Action == 'a') {
                faussemanip = 0;
                std::cout << "\nVous choisissez d'attaquer.\n\nQuel arme allez vous utilisez? \nM = Missiles: Degats explosifs, peux faire plus ou moins de degats, \nP = Munition Plasma: Degats thermique, ignore une partie de l'armure,\nC = Multi Canon: Degats cinetique, Tire plusieurs fois\nAutre touche = Revenir en arriere\n";
                std::cin >> Action;
                if (Action == 'M' || Action == 'm') {
                    srand(time(NULL));
                    int DPSmin = Missiles - 5;
                    int DPSmax = Missiles + 5;
                    int DPS = DPSmin + (rand() % DPSmax);
                    double DPSArmure = Armure;
                    DPSArmure = DPS - 5;
                    std::cout << "Votre tir a inflige " << DPSArmure << "DPS a l'emmemi\n";
                    VieE = VieE - DPSArmure;
                    FSD = FSD - 1;
                }
                else if (Action == 'P' || Action == 'p') {
                    srand(time(NULL));
                    int DPSmin = Plasma - 2;
                    int DPSmax = Plasma + 2;
                    int DPS = DPSmin + (rand() % DPSmax);
                    std::cout << "Votre tir a inflige " << DPS << "DPS a l'emmemi\n";
                    VieE = VieE - DPS;
                    FSD = FSD - 1;
                }
                else if (Action == 'C' || Action == 'c') {
                    int g = 0;
                    srand(time(NULL));
                    int f = 1 + (rand() % 3);
                    FSD = FSD - 1;
                    while (g < f) {
                        int DPSmin = Mc / 0.5;
                        int DPSmax = Mc + 5;
                        int DPS = DPSmin + (rand() % DPSmax);
                        double DPSArmure = Armure;
                        DPSArmure = DPS - 10;
                        std::cout << "Votre tir a inflige " << DPSArmure << "DPS a l'emmemi\n";
                        VieE = VieE - DPSArmure;
                        g++;
                    }
                    std::cout << f << " tirs ont ete effectues";
                } // L'ennemi joue un tour 
                //L'ennemi joue un tour 
                int ActionE = (rand() % 6 + 1);
                int Atkrandom1 = (rand() % Atk1 + 7);
                int Atkrandom2 = (rand() % Atk2 + 15);
                int RegenE = (rand() % Regen + 50);
                int tourE = 1;
                while (tourE != 0) {
                    if (ReductionDPS == true) {
                        Atkrandom1 = Atkrandom1 * 0.25;
                        Atkrandom2 = Atkrandom2 * 0.25;
                        ReductionDPS = false;

                    }
                    if (ActionE == 4 || ActionE == 5) {
                        VieJ = VieJ - Atkrandom2;
                        std::cout << "\n\nL'ennemi utilise une Attaque Puissante,\nIl vous inflige " << Atkrandom2 << " DPS";
                        ReductionDPS = false;
                        break;
                    }
                    if (ActionE == 6 && Regen > 0 && VieE < 200) {
                        VieE = VieE + RegenE;
                        Regen = Regen - 1;
                        std::cout << "\n\nL'ennemi se regen  " << RegenE << " HP";
                        break;
                    }
                    if (ActionE < 4) {
                        VieJ = VieJ - Atkrandom1;
                        std::cout << "\n\nL'ennemi utilise une Attaque Normale,\nIl vous inflige " << Atkrandom1 << " DPS";
                        ReductionDPS = false;
                        break;
                    }
                    else
                        ActionE = (rand() % 6 + 1);
                }//Fin du tour de l'ennemi
            }
            else if (Action == 'S' || Action == 's') {
                faussemanip = 0;
                ReductionDPS = true;
                FSD = FSD - 1;
                std::cout << "\n\nActivation du bouclier, le prochain coup subit sera reduit de 75%\n";
                //réduit les dégats de 75% a l'attaque suivante le joueur peux attaquer au prochain tour
                //L'ennemi joue un tour 
                int ActionE = (rand() % 6 + 1);
                int Atkrandom1 = (rand() % Atk1 + 7);
                int Atkrandom2 = (rand() % Atk2 + 15);
                int RegenE = (rand() % Regen + 50);
                int tourE = 1;
                while (tourE != 0) {
                    if (ReductionDPS == true) {
                        Atkrandom1 = Atkrandom1 * 0.25;
                        Atkrandom2 = Atkrandom2 * 0.25;
                        ReductionDPS = false;

                    }
                    if (ActionE == 4 || ActionE == 5) {
                        VieJ = VieJ - Atkrandom2;
                        std::cout << "\n\nL'ennemi utilise une Attaque Puissante,\nIl vous inflige " << Atkrandom2 << " DPS";
                        ReductionDPS = false;
                        break;
                    }
                    if (ActionE == 6 && Regen > 0 && VieE < 200) {
                        VieE = VieE + RegenE;
                        Regen = Regen - 1;
                        std::cout << "\n\nL'ennemi se regen  " << RegenE << " HP";
                        break;
                    }
                    if (ActionE < 4) {
                        VieJ = VieJ - Atkrandom1;
                        std::cout << "\n\nL'ennemi utilise une Attaque Normale,\nIl vous inflige " << Atkrandom1 << " DPS";
                        ReductionDPS = false;
                        break;
                    }
                    else
                        ActionE = (rand() % 6 + 1);
                }//Fin du tour de l'ennemi
            }

            

            if (FSD == 0) {
                std::cout << "\n\nActivation\n";
                sleep_until(system_clock::now() + 0.5s);
                std::cout << "\n\nVous avez fuis le combat\n\n";
                break;
            }
        }

        else
        {


            std::cout << "\n\n\nIl vous reste: " << VieJ << "PV\nL'enemmi a encore: " << VieE << "HP\nQue voulez vous faire ?\n\n A = Attaquer,\n S = Charger les boucliers,\n J = Charger le moteur FSD / Fuite (pour les faibles),\n R = Reparation du vaisseau\n";
            std::cin >> Action;
            if (Action == 'A' || Action == 'a') {
                faussemanip = 0;
                std::cout << "\nVous choisissez d'attaquer.\n\nQuel arme allez vous utilisez? \nM = Missiles: Degats explosifs, peux faire plus ou moins de degats, \nP = Munition Plasma: Degats thermique, ignore une partie de l'armure,\nC = Multi Canon: Degats cinetique, Tire plusieurs fois\nAutre touche = Revenir en arriere\n";
                std::cin >> Action;
                if (Action == 'M' || Action == 'm') {
                    srand(time(NULL));
                    int DPSmin = Missiles - 5;
                    int DPSmax = Missiles + 5;
                    int DPS = DPSmin + (rand() % DPSmax);
                    double DPSArmure = Armure;
                    DPSArmure = DPS - 5;
                    std::cout << "Votre tir a inflige " << DPSArmure << "DPS a l'emmemi\n";
                    VieE = VieE - DPSArmure;
                }
                else if (Action == 'P' || Action == 'p') {
                    srand(time(NULL));
                    int DPSmin = Plasma - 2;
                    int DPSmax = Plasma + 2;
                    int DPS = DPSmin + (rand() % DPSmax);
                    std::cout << "Votre tir a inflige " << DPS << "DPS a l'emmemi\n";
                    VieE = VieE - DPS;
                }
                else if (Action == 'C' || Action == 'c') {
                    int g = 0;
                    srand(time(NULL));
                    int f = 1 + (rand() % 3);
                    while (g < f) {
                        int DPSmin = Mc / 0.5;
                        int DPSmax = Mc + 5;
                        int DPS = DPSmin + (rand() % DPSmax);
                        double DPSArmure = Armure;
                        DPSArmure = DPS - 10;
                        std::cout << "Votre tir a inflige " << DPSArmure << "DPS a l'emmemi\n";
                        VieE = VieE - DPSArmure;
                        g++;
                    }
                    std::cout << f << " tirs ont ete effectues";
                } // L'ennemi joue un tour 
                //L'ennemi joue un tour 
                int ActionE = (rand() % 6 + 1);
                
                int Atkrandom1 = (rand() % Atk1 + 7);
                int Atkrandom2 = (rand() % Atk2 + 15);
                int RegenE = (rand() % Regen + 50);
                int tourE = 1;
                while (tourE != 0) {
                    if (ReductionDPS == true) {
                        Atkrandom1 = Atkrandom1 * 0.25;
                        Atkrandom2 = Atkrandom2 * 0.25;
                        ReductionDPS = false;

                    }
                    if (ActionE == 4 || ActionE == 5) {
                        VieJ = VieJ - Atkrandom2;
                        std::cout << "\n\nL'ennemi utilise une Attaque Puissante,\nIl vous inflige " << Atkrandom2 << " DPS";
                        ReductionDPS = false;
                        break;
                    }
                    if (ActionE == 6 && Regen > 0 && VieE < 200) {
                        VieE = VieE + RegenE;
                        Regen = Regen - 1;
                        std::cout << "\n\nL'ennemi se regen  " << RegenE << " HP";
                        break;
                    }
                    if (ActionE < 4) {
                        VieJ = VieJ - Atkrandom1;
                        std::cout << "\n\nL'ennemi utilise une Attaque Normale,\nIl vous inflige " << Atkrandom1 << " DPS";
                        ReductionDPS = false;
                        break;
                    }
                    else
                        ActionE = (rand() % 6 + 1);
                }//Fin du tour de l'ennemi
            }
            else if (Action == 'S' || Action == 's') {
                faussemanip = 0;
                ReductionDPS = true;
                std::cout << "\n\nActivation du bouclier, le prochain coup subit sera reduit de 75%\n";
                //réduit les dégats de 75% a l'attaque suivante le joueur peux attaquer au prochain tour
                //L'ennemi joue un tour 
                int ActionE = (rand() % 6 + 1);
                
                int Atkrandom1 = (rand() % Atk1 + 7);
                int Atkrandom2 = (rand() % Atk2 + 15);
                int RegenE = (rand() % Regen + 50);
                int tourE = 1;
                while (tourE != 0) {
                    if (ReductionDPS == true) {
                        Atkrandom1 = Atkrandom1 * 0.25;
                        Atkrandom2 = Atkrandom2 * 0.25;
                        ReductionDPS = false;

                    }
                    if (ActionE == 4 || ActionE == 5) {
                        VieJ = VieJ - Atkrandom2;
                        std::cout << "\n\nL'ennemi utilise une Attaque Puissante,\nIl vous inflige " << Atkrandom2 << " DPS";
                        ReductionDPS = false;
                        break;
                    }
                    if (ActionE == 6 && Regen > 0 && VieE < 200) {
                        VieE = VieE + RegenE;
                        Regen = Regen - 1;
                        std::cout << "\n\nL'ennemi se regen  " << RegenE << " HP";
                        break;
                    }
                    if (ActionE < 4) {
                        VieJ = VieJ - Atkrandom1;
                        std::cout << "\n\nL'ennemi utilise une Attaque Normale,\nIl vous inflige " << Atkrandom1 << " DPS";
                        ReductionDPS = false;
                        break;
                    }
                    else
                        ActionE = (rand() % 6 + 1);
                }//Fin du tour de l'ennemi
            }
            else if (Action == 'J' || Action == 'j') {
                faussemanip = 0;
                std::cout << "\n\nEtes vous sur de vouloir avtiver le FSD ?\nVous ne pourrez plus attaquer et vous prenez la fuite dans " << FSD << " tours\nPour confirmer l'action, appuyer sur le meme bouton";
                std::cin >> Action;
                if (Action == 'J' || Action == 'j') {
                    FSDactif = true;
                    std::cout << "\n\nChargement FSD en cours...";
                    //prépare le FSD, met le nombre de tour celon le FSDcldw, le joueur ne peux pas attaquer entre temps
                    //L'ennemi joue un tour 
                    int ActionE = (rand() % 6 + 1);
                    
                    int Atkrandom1 = (rand() % Atk1 + 7);
                    int Atkrandom2 = (rand() % Atk2 + 15);
                    int RegenE = (rand() % Regen + 50);
                    int tourE = 1;
                    while (tourE != 0) {
                        if (ReductionDPS == true) {
                            Atkrandom1 = Atkrandom1 * 0.25;
                            Atkrandom2 = Atkrandom2 * 0.25;
                            ReductionDPS = false;

                        }
                        if (ActionE == 4 || ActionE == 5) {
                            VieJ = VieJ - Atkrandom2;
                            std::cout << "\n\nL'ennemi utilise une Attaque Puissante,\nIl vous inflige " << Atkrandom2 << " DPS";
                            ReductionDPS = false;
                            break;
                        }
                        if (ActionE == 6 && Regen > 0 && VieE < 200) {
                            VieE = VieE + RegenE;
                            Regen = Regen - 1;
                            std::cout << "\n\nL'ennemi se regen  " << RegenE << " HP";
                            break;
                        }
                        if (ActionE < 4) {
                            VieJ = VieJ - Atkrandom1;
                            std::cout << "\n\nL'ennemi utilise une Attaque Normale,\nIl vous inflige " << Atkrandom1 << " DPS";
                            ReductionDPS = false;
                            break;
                        }
                        else
                            ActionE = (rand() % 6 + 1);
                    }//Fin du tour de l'ennemi
                }
            }
            else if (Action == 'R' || Action == 'r') {
                //repare d'une certaine quantité la vie du joueur
                if (VieJ < MaxHP)
                {
                    srand(time(NULL));
                    Fix = Fix - 1;
                    if (difficulte == 1) {
                        VieJ = VieJ + (rand() % 50 + 35);
                    }
                    else if (difficulte == 2) {
                        VieJ = VieJ + (rand() % 40 + 30);
                    }
                    else if (difficulte == 3) {
                        VieJ = VieJ + (rand() % 25 + 30);
                    }

                    if (VieJ > MaxHP) {
                        VieJ = VieJ - (VieJ - MaxHP);
                    }

                    std::cout << "Vous utiliser un drone de reparation. Vous avez desormais: " << VieJ << "HP\nIl vous reste " << Fix << "drones reparateurs\n\n";
                    ////L'ennemi joue un tour 
                    //int ActionE = (rand() % 6 + 1);
                    //
                    //int Atkrandom1 = (rand() % Atk1 + 7);
                    //int Atkrandom2 = (rand() % Atk2 + 15);
                    //int RegenE = (rand() % Regen + 50);
                    //int tourE = 1;
                    //while (tourE != 0) {
                    //    if (ReductionDPS == true) {
                    //        Atkrandom1 = Atkrandom1 * 0.25;
                    //        Atkrandom2 = Atkrandom2 * 0.25;
                    //        ReductionDPS = false;

                    //    }
                    //    if (ActionE == 4 || ActionE == 5) {
                    //        VieJ = VieJ - Atkrandom2;
                    //        std::cout << "\n\nL'ennemi utilise une Attaque Puissante,\nIl vous inflige " << Atkrandom2 << " DPS";
                    //        ReductionDPS = false;
                    //        break;
                    //    }
                    //    if (ActionE == 6 && Regen > 0 && VieE < 200) {
                    //        VieE = VieE + RegenE;
                    //        Regen = Regen - 1;
                    //        std::cout << "\n\nL'ennemi se regen  " << RegenE << " HP";
                    //        break;
                    //    }
                    //    if (ActionE < 4) {
                    //        VieJ = VieJ - Atkrandom1;
                    //        std::cout << "\n\nL'ennemi utilise une Attaque Normale,\nIl vous inflige " << Atkrandom1 << " DPS";
                    //        ReductionDPS = false;
                    //        break;
                    //    }
                    //    else
                    //        ActionE = (rand() % 6 + 1);
                    //}//Fin du tour de l'ennemi
                } 

                else
                {
                    faussemanip++;
                    std::cout << "\nVous ne pouvez pas vous heal sans prendre de degats\n";
                }

            }
            else {
                faussemanip++;
                std::cout << "\n\nOption choisie inconnue\n\n";
                if (faussemanip == 3) {
                    /*ActionEnnemi();*/
                    faussemanip = 0;
                    std::cout << "Vous avez pris trop de temps pour riposter\n\n";
                    //l'adversaire joue un tour
                    //début du tour
                    int ActionE = (rand() % 6 + 1);
                    
                    int Atkrandom1 = (rand() % Atk1 + 7);
                    int Atkrandom2 = (rand() % Atk2 + 15);
                    int RegenE = (rand() % Regen + 50);
                    int tourE = 1;
                    while (tourE != 0) {
                        if (ReductionDPS == true) {
                            Atkrandom1 = Atkrandom1 * 0.25;
                            Atkrandom2 = Atkrandom2 * 0.25;
                            ReductionDPS = false;
                            
                        }
                        if (ActionE == 4 || ActionE == 5) {
                            VieJ = VieJ - Atkrandom2;
                            std::cout << "\n\nL'ennemi utilise une Attaque Puissante,\nIl vous inflige " << Atkrandom2 << " DPS";
                            ReductionDPS = false;
                            break;
                        }
                        if (ActionE == 6 && Regen > 0 && VieE < 200) {
                            VieE = VieE + RegenE;
                            Regen = Regen - 1;
                            std::cout << "\n\nL'ennemi se regen  " << RegenE << " HP";
                            break;
                        }
                        if (ActionE < 4) {
                            VieJ = VieJ - Atkrandom1;
                            std::cout << "\n\nL'ennemi utilise une Attaque Normale,\nIl vous inflige " << Atkrandom1 << " DPS";
                            ReductionDPS = false;
                            break;
                        }
                        else
                            ActionE = (rand() % 6 + 1);
                    }

                }//fin du tour de l'ennemi
            }

        }
    }

}

int main() {

    std::cout << "Bonjour jeune Astronaute !" << std::endl;

    int difficulte;

    std::cout << "Choisissez votre niveau de difficulte : 1 - Facile    2 - Normal    3 - Difficile" << std::endl;

    std::cout << "Difficulte : ";

    std::cin >> difficulte;

    std::cout << "\n\nVoici votre vaisseau:\n\n";

    createVaisseau(difficulte);

    std::cout << "\n\n...\n\n\nOh non ! (musique dramatique) \n\n\nVous etes tombes nez a nez contre ";

    createEnnemie(difficulte);

    deroulementPartie(difficulte);

    return 0;
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
