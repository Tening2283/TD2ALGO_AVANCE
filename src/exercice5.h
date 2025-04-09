#ifndef EXERCICE5_H
#define EXERCICE5_H

#include <stdlib.h>

// Définition de la structure pour un élément du vecteur creux
typedef struct ex5_Element {
    int pos;                // Position dans le tableau
    float val;              // Valeur à cette position
    struct ex5_Element *suivant; // Pointeur vers l'élément suivant
} EX5_MAILLON, *EX5_PTR;

// Déclaration des fonctions
EX5_PTR ex5_creer_element(int position, float valeur, EX5_PTR next);
EX5_PTR ex5_generer_vecteur_creux(float tab[], int taille);
EX5_PTR ex5_addition_vecteurs(EX5_PTR v1, EX5_PTR v2);
void ex5_afficher(EX5_PTR v);
void exercice5();

#endif
