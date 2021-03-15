/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.5
// Nom du programmeur: MP Pinaud
// Contributeur(s): A Martin
// Date de création : 05/02/2021
// Dernière modification : 15/03/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: CPartie
//                              CJoueur
//                              iostream
// Historique du fichier: Ajout du joueur2
//                        Ajout dynamique du joueur3 Ghost à la fin du jeu
//                        Ajout de la moyenne des tentatives
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/Partie.h"

int main()
{

    //Création d'un joueur
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Veuillez entrer le nom du Joueur1" << endl;
    string un_nom;
    cin >> un_nom;
    CJoueur joueur (un_nom);

    // Création d'un 2ème joueur
    cout << "----------------------------------------------"<< endl;
    cout << "Veuillez entrer le nom du Joueur2" << endl;
    string un_nom2;
    cin >> un_nom2;
    CJoueur joueur2 (un_nom2);


    cout << "----------------------------------------------"<< endl;
    cout << "Combien de parties voulez-vous jouer ?" << endl;
    int nbParties;
    cin >> nbParties;



    for (int i = 0; i <nbParties; i++)
    {
        cout << "----------------------------------------------"<< endl;
        cout <<"Partie Numero : " << i+1 << endl;
        cout << "----------------------------------------------"<< endl;

        CPartie partie (0,10,4); // nombre à deviner entre 0 et 10, nombre de tentatives maximum 4

        partie.Jouer(joueur); // exécution d'une partie pour le joueur1
        partie.Jouer(joueur2); // exécution d'une partie pour le joueur2
    }


    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats du joueur "<< joueur.Nom() << endl;
    cout << "----------------------------------------------"<< endl;
    // Récupération des résultats du joueur1
    int nbsucces, nbechecs, nbessais;
    float moyenne;
    joueur.Resultats(nbsucces, nbechecs, nbessais, moyenne);  // les paramètres sont passés par référence
    // Affichage des résultats
    cout << "Nombre de parties gagnees : " << nbsucces << endl;
    cout << "Nombre de parties perdues : " << nbechecs << endl;
    cout << "Nombre de tentatives totales : " << nbessais << endl;
    cout << "Moyenne de tentatives : " << moyenne << endl;
    cout << "----------------------------------------------"<< endl;

    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats du joueur "<< joueur2.Nom() << endl;
    cout << "----------------------------------------------"<< endl;


    int nbsucces2, nbechecs2, nbessais2; // Récupération des résultats du joueur2
    float moyenne2;
    joueur2.Resultats(nbsucces2, nbechecs2, nbessais2, moyenne2);  // les paramètres sont passés par référence
    // Affichage des résultats
    cout << "Nombre de parties gagnees : " << nbsucces2 << endl;
    cout << "Nombre de parties perdues : " << nbechecs2 << endl;
    cout << "Nombre de tentatives totales : " << nbessais2 << endl;
    cout << "Moyenne de tentatives : " << moyenne2 << endl;
    cout << "----------------------------------------------"<< endl;

    // Indiquer quel joueur a gagné
    if (nbsucces2>nbsucces)
        cout << joueur2.Nom() << "a gagné!" << endl;
    else if (nbsucces2<nbsucces)
        cout << joueur.Nom() << "a gagné!" << endl;
    else
        cout << joueur.Nom() << " et " << joueur2.Nom() << " sont ex-aequo!" << endl;



    // Création dynamique du joueur Ghost
    CJoueur * joueur3;
    joueur3 = new CJoueur("Ghost");
    // Création dynamique de la partie
    CPartie * partie;
    partie = new CPartie(1, 10, 3);

    partie -> Jouer(*joueur3); // Exécution dynamique de la partie du joueur3

    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats du joueur Ghost"<< endl;
    cout << "----------------------------------------------"<< endl;
    // Afficher les résultats du 3ème joueur
    int nbsucces3, nbechecs3, nbessais3; // Récupération des résultats du joueur3
    float moyenne3;
    joueur3 -> Resultats(nbsucces3,nbechecs3,nbessais3,moyenne3);
    // Affichage des résultats
    cout << "Nombre de parties gagnees : " << nbsucces3 << endl;
    cout << "Nombre de parties perdues : " << nbechecs3 << endl;
    cout << "Nombre de tentatives totales : " << nbessais3 << endl;
    cout << "Moyenne de tentatives : " << moyenne3 << endl;
    cout << "----------------------------------------------"<< endl;

    return 0;
}

