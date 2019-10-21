#include <iostream>
#include <cstdlib>
#include "ArbreBI.h"

using namespace std;

Arbre::Arbre(){
    root = NULL;
}

Arbre::Noeud* Arbre::CreerFeuille(int cle){
    Noeud* n = new Noeud;
    n->cle = cle;
    n->gauche = NULL;
    n->droite = NULL;

    return n;
}

void   Arbre::AjouterNoeud (int cle){
    AjouterNoeudPrivee(cle, root);
}
void    Arbre::AjouterNoeudPrivee(int cle, Noeud* Ptr){
        if (root == NULL){
            root = CreerFeuille(cle);
        }
        else if(cle < Ptr->cle){
                if(Ptr->gauche !=NULL){
                    AjouterNoeudPrivee(cle, Ptr->gauche);
                }
                else{  // inserer mon noeud
                    Ptr->gauche = CreerFeuille(cle);
                }
        }
        else if(cle > Ptr->cle){
                if(Ptr->droite !=NULL){
                    AjouterNoeudPrivee(cle, Ptr->droite);
                }
                else{  // inserer mon noeud
                    Ptr->droite = CreerFeuille(cle);
                }
        }
        else{
            cout << "cet element existe deja !!!   \n" ;
        }
}

void    Arbre::AfficherArbre(){
   AfficherArbrePrivee(root);
}

 void    Arbre::AfficherArbrePrivee(Noeud* Ptr){
  if (root !=NULL){
        if (Ptr->gauche !=NULL){
            AfficherArbrePrivee(Ptr->gauche);
        }
        cout << Ptr->cle << " ** ";

        if (Ptr->droite !=NULL){
            AfficherArbrePrivee(Ptr->droite);
        }
    }
    else{
        cout << " arbre n existe  pas !!! \n";
    }
 }

 Arbre::Noeud* Arbre::GetNoeud(int cle){
    return GetNoeudPrivee(cle, root);
}

Arbre::Noeud* Arbre::GetNoeudPrivee(int cle, Noeud* Ptr){
    if (Ptr !=NULL){
        if(Ptr->cle == cle){
            return Ptr;
        }
        else {
            if (cle < Ptr->cle){
                 return GetNoeudPrivee(cle, Ptr->gauche);
            }
            else {
                return GetNoeudPrivee(cle, Ptr->droite);
            }
        }
    }
    else {
        return NULL;
    }
}

int Arbre::GetCleRoot(){
    if (root !=NULL){
        return root->cle;
    }
    else return -999;
}

void Arbre::AfficherEnfants(int cle){
    Noeud* Ptr = GetNoeud(cle);
    cout << "Ptr->cle: " << Ptr->cle;
    if (Ptr != NULL){
       cout<<"Le Noeud Parent est = "<< Ptr->cle << endl;
       Ptr->gauche == NULL ?
       cout << "Il n y a pas de fils a gauche \n" :
       cout << "Le fils gauche est = " << Ptr->gauche->cle <<endl;

       Ptr->droite == NULL ?
       cout << "Il n y a pas de fils a droite \n" :
       cout << "Le fils a droite est = "<< Ptr->droite->cle <<endl;
    }
    else{
        cout << "La cle est " << cle << " n existe pas \n";
    }
}

int Arbre::TrouverPlusPetiteCle(){
   return TrouverPlusPetiteClePrivee(root);
}

int Arbre::TrouverPlusPetiteClePrivee(Noeud* Ptr){
    if (root == NULL){
        cout << "l arbre est vide.... \n" ;
        return -999;
    }
    else {
        if(Ptr->gauche !=NULL){
            return TrouverPlusPetiteClePrivee(Ptr->gauche);
        }
        else {
            return Ptr->cle;
        }
    }
}
int Arbre::TrouverPlusGrandeCle(){
   return TrouverPlusGrandeClePrivee(root);
}

int Arbre::TrouverPlusGrandeClePrivee(Noeud* Ptr){
    if (root == NULL){
        cout << "l arbre est vide.... \n" ;
        return -999;
    }
    else {
        if(Ptr->droite !=NULL){
            return TrouverPlusGrandeClePrivee(Ptr->droite);
        }
        else {
            return Ptr->cle;
        }
    }
}
Arbre::Noeud* Arbre::deleteNode(Noeud* root, int key) {
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->cle)
        root->gauche = deleteNode(root->gauche, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->cle)
        root->droite = deleteNode(root->droite, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->gauche == NULL)
        {
            struct Noeud *temp = root->droite;
            free(root);
            return temp;
        }
        else if (root->droite == NULL)
        {
            struct Noeud *temp = root->gauche;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Noeud* temp = GetNoeud(TrouverPlusPetiteClePrivee(root->droite));

        // Copy the inorder successor's content to this node
        root->cle = temp->cle;

        // Delete the inorder successor
        root->droite = deleteNode(root->droite, temp->cle);
    }
    return root;
}
