#ifndef EXERCICE4_H
#define EXERCICE4_H

#include <stdlib.h>

// Définition de la structure pour un monome
typedef struct ex4_Monome {
    int exp;                // Exposant
    float coef;             // Coefficient
    struct ex4_Monome *suivant; // Pointeur vers le monome suivant
} EX4_Monome, *EX4_Poly;

// Déclaration des fonctions
EX4_Poly ex4_creer_monome(int exp, float coef, EX4_Poly suivant);
EX4_Poly ex4_derivee(EX4_Poly p);
EX4_Poly ex4_derivee_k(EX4_Poly p, int k);
void ex4_afficher_poly(EX4_Poly p);
void exercice4();

#endif
