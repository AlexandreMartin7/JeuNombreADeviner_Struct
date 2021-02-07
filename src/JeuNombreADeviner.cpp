/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
// 01/02/2020 - D�claration InitJoueur; TirerNombreMystere
/*************************************************/
#include <iostream>
#include <ctime>
using namespace std;
#include "../include/JeuNombreAdeviner.h"

// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : un_nom
// Param�tres de sortie : TJoueur, &jouerACreer
// Param�tres d'entr�e/sortie :

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom; // Initialise le nom de joueur � la cha�ne un_nom
    joueurAcreer.nbPartiesJouees = 0; // Initialise le nombre de parties jou�es
    joueurAcreer.nbPartiesGagnees = 0; // Initialise le nombre de parties gagn�es
    joueurAcreer.nbTentatives = 0; // Initialise le nombre de tentatives
}


// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

int TirerNombreMystere()
{

    srand ((int)time(0));
    int nombreADeviner = rand() % 10 + 1;
    return nombreADeviner;
}


// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: &un_joueur
// Param�tres de sortie: TJoueur, nombreADeviner
// Param�tres d'entr�e/sortie :

void JouerPartie(TJoueur &un_joueur, int nombreADeviner)
{
    int nbSaisi = 0; // Proposition de r�ponse du joueur
    int i = 0; // Compteur de tentatives
    while (i<4) // Tant qu'on a moins de 4 tentatives
    {
        cout << "Trouve le chiffre mystere, compris entre 1 et 10\n";
        cin >> nbSaisi; // Saisie du nombre myst�re
        if (nbSaisi == nombreADeviner)
        {
            (cout << "Bravo, tu as trouve !\n");
            i++;
            un_joueur.nbTentatives = i; // Met � jour le compte de tentatives
            MajResultatsJoueur(un_joueur, i, true);
            i = 5; // Permet de sortir de la boucle
        }
        else if (nbSaisi > nombreADeviner)
        {
            i++; // Met � jour le compteur d'essais
            un_joueur.nbTentatives = i; // Met � jour nbTentatives
            (cout << "Plus petit\n");
            MajResultatsJoueur(un_joueur, i, false);
        }
        else if (nbSaisi < nombreADeviner)
        {
            i++; // Met � jour le compteur d'essais
            un_joueur.nbTentatives = i; // Met � jour nbTentatives
            cout << "Plus grand \n" << "Tentative " << un_joueur.nbTentatives << " sur 4" << "\n";
             // Met � jour
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
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e: nbEssais, gagne
// Param�tres de sortie:
// Param�tres d'entr�e/sortie : TJoueur, joueur

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
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e:
// Param�tres de sortie: joueur, nbEssais, gagne
// Param�tres d'entr�e/sortie :

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = joueur.nbPartiesGagnees/2;
    nbechec = (joueur.nbPartiesJouees - joueur.nbPartiesGagnees)/2;
    nbessais = joueur.nbTentatives;
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

