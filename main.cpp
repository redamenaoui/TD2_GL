#include <iostream>
#include <cstdlib>
#include "ArbreBI.h"
#include "ArbreBI.cpp"
using namespace std;

int main(){
    int monTableau [16]={51, 77, 22, 5, 16, 33, 65, 53, 15, 101, 84, 3, 4, 71, 88, 81};
    Arbre arbre,arbre_test,arbre_inv;


    for (int i= 0; i<16; i++){
        arbre.AjouterNoeud(monTableau[i]);
    }

    arbre.AfficherArbre();
    cout << endl;
    //***********************************
    int racine;
    racine = arbre.GetCleRoot();
    cout << "La cle de la racine est : " << racine << endl;

    cout<< "La plus petite cle dans l'arbre est: " << arbre.TrouverPlusPetiteCle()<< endl;

    cout<< "La plus grande cle dans l'arbre est: " << arbre.TrouverPlusGrandeCle()<< endl;
   /* int tab_test[7]={5,7,4,6,9,10,8};

        for (int i= 0; i<7; i++){
        arbre_test.AjouterNoeud(tab_test[i]);
    }*/
    arbre.AfficherArbre();
    arbre.InverserArbre();
    cout << "\n------------------Mirror----------------------------------------------------------" << endl;
    arbre.AfficherArbre();
    return 0;
}
