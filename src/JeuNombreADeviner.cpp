/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
// 01/02/2020 - Déclaration InitJoueur; TirerNombreMystere
/*************************************************/
#include <iostream>
#include <ctime>
using namespace std;
#include "../include/JeuNombreAdeviner.h"

// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : un_nom
// Paramètres de sortie : TJoueur, &jouerACreer
// Paramètres d'entrée/sortie :

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom; // Initialise le nom de joueur à la chaîne un_nom
    joueurAcreer.nbPartiesJouees = 0; // Initialise le nombre de parties jouées
    joueurAcreer.nbPartiesGagnees = 0; // Initialise le nombre de parties gagnées
    joueurAcreer.nbTentatives = 0; // Initialise le nombre de tentatives
}


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere()
{

    srand ((int)time(0));
    int nombreADeviner = rand() % 10 + 1;
    return nombreADeviner;
}


// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: &un_joueur
// Paramètres de sortie: TJoueur, nombreADeviner
// Paramètres d'entrée/sortie :

void JouerPartie(TJoueur &un_joueur, int nombreADeviner)
{
    int nbSaisi = 0; // Proposition de réponse du joueur
    int i = 0; // Compteur de tentatives
    while (i<4) // Tant qu'on a moins de 4 tentatives
    {
        cout << "Trouve le chiffre mystere, compris entre 1 et 10\n";
        cin >> nbSaisi; // Saisie du nombre mystère
        if (nbSaisi == nombreADeviner)
        {
            (cout << "Bravo, tu as trouve !\n");
            i++;
            un_joueur.nbTentatives = i; // Met à jour le compte de tentatives
            MajResultatsJoueur(un_joueur, i, true);
            i = 5; // Permet de sortir de la boucle
        }
        else if (nbSaisi > nombreADeviner)
        {
            i++; // Met à jour le compteur d'essais
            un_joueur.nbTentatives = i; // Met à jour nbTentatives
            (cout << "Plus petit\n");
            MajResultatsJoueur(un_joueur, i, false);
        }
        else if (nbSaisi < nombreADeviner)
        {
            i++; // Met à jour le compteur d'essais
            un_joueur.nbTentatives = i; // Met à jour nbTentatives
            cout << "Plus grand \n" << "Tentative " << un_joueur.nbTentatives << " sur 4" << "\n";
             // Met à jour
            MajResultatsJoueur(un_joueur, i, false);
        }

    }

    if (i==4)
    {
        cout << "Perdu!\n";
        un_joueur.nbPartiesJouees++;
        un_joueur.nbTentatives = i;

    }
}


// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée: nbEssais, gagne
// Paramètres de sortie:
// Paramètres d'entrée/sortie : TJoueur, joueur

void MajResultatsJoueur(TJoueur &un_joueur, int nbEssais, bool gagne)
{
    un_joueur.nbTentatives;

    if (gagne == true)
    {
        un_joueur.nbPartiesGagnees++;
    }
    un_joueur.nbPartiesJouees++;
}

// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée:
// Paramètres de sortie: joueur, nbEssais, gagne
// Paramètres d'entrée/sortie :

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = joueur.nbPartiesGagnees/2;
    nbechec = (joueur.nbPartiesJouees - joueur.nbPartiesGagnees)/2;
    nbessais = joueur.nbTentatives;
}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

