#include <iostream>
#include <cstdlib>
#include "ArbreBI.h"
#include "ArbreBI.cpp"
using namespace std;

int main(){
    int monTableau [16]={51, 77, 22, 5, 16, 33, 65, 53, 15, 101, 84, 3, 4, 71, 88, 81};
    Arbre arbre;

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

    arbre.deleteNode(84);
    arbre.deleteNode(101);
    arbre.deleteNode(65);
    arbre.AfficherArbre();
    cout << endl;
    //***********************************
    return 0;
}
