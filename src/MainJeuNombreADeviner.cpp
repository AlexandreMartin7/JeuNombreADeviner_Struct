/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    string un_nom;
    TJoueur joueurAcreer;
    cout << "Vous allez jouer au jeu du nombre a deviner" << endl;
    cout << "Quel est votre nom de joueur?" << endl;
    cin >> un_nom;
    InitJoueur(joueurAcreer, un_nom);
    JouerPartie(joueurAcreer, TirerNombreMystere());
    MajResultatsJoueur(joueurAcreer, joueurAcreer.nbTentatives, joueurAcreer.nbPartiesGagnees);
    ResultatsJoueur(joueurAcreer, joueurAcreer.nbPartiesGagnees, joueurAcreer.nbPartiesJouees, joueurAcreer.nbTentatives);
    cout << "Resultats du joueur : " << joueurAcreer.nom << "\n" << "Tu as gagne " << joueurAcreer.nbPartiesGagnees << " fois en " << joueurAcreer.nbTentatives << " essais.";


}
