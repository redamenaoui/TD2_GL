#ifndef ARBREBI_H_INCLUDED
#define ARBREBI_H_INCLUDED

#include <iostream>
#include <cstdlib>

using namespace std;

class Arbre{

private:
    struct Noeud{
        int cle;
        Noeud* gauche;
        Noeud* droite;
    };
    Noeud* root;

    void    AjouterNoeudPrivee(int cle, Noeud* Ptr);
    void    AfficherArbrePrivee(Noeud* Ptr);
    Noeud*  GetNoeudPrivee(int cle, Noeud* Ptr);
    int     TrouverPlusPetiteClePrivee(Noeud* Ptr);
    int     TrouverPlusGrandeClePrivee(Noeud* Ptr);
    Noeud*  deleteNodeP(Noeud* root, int k);

public:
    Arbre();
    Noeud*  CreerFeuille(int cle);
    void    AjouterNoeud (int cle);
    void    AfficherArbre();
    Noeud* GetNoeud(int cle);
    int   GetCleRoot();
    void  AfficherEnfants(int cle);
    int   TrouverPlusPetiteCle();
    int   TrouverPlusGrandeCle();
    void deleteNode(int k);
    //~Arbre();


};


#endif // ARBREBI_H_INCLUDED
