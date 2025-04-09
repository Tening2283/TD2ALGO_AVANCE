#include <stdio.h>
#include <stdlib.h>
#include "exercice4.h"

// Fonction pour créer un nouveau terme (monome)
EX4_Poly ex4_creer_monome(int exp, float coef, EX4_Poly suivant) {
    EX4_Poly m = (EX4_Poly)malloc(sizeof(EX4_Monome));
    if (m == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    m->exp = exp;
    m->coef = coef;
    m->suivant = suivant;
    return m;
}

// Fonction pour calculer la dérivée d’un polynôme
EX4_Poly ex4_derivee(EX4_Poly p) {
    EX4_Poly result = NULL, fin = NULL;
    while (p != NULL) {
        if (p->exp > 0) {
            EX4_Poly d = ex4_creer_monome(p->exp - 1, p->coef * p->exp, NULL);
            if (result == NULL) {
                result = d;
            } else {
                fin->suivant = d;
            }
            fin = d;
        }
        p = p->suivant;
    }
    return result;
}

// Fonction pour calculer la k-ième dérivée d’un polynôme
EX4_Poly ex4_derivee_k(EX4_Poly p, int k) {
    for (int i = 0; i < k && p != NULL; i++) {
        p = ex4_derivee(p);
    }
    return p;
}

// Fonction pour afficher un polynôme
void ex4_afficher_poly(EX4_Poly p) {
    if (p == NULL) {
        printf("0\n");
        return;
    }
    while (p != NULL) {
        printf("(x^%d, %.2f) -> ", p->exp, p->coef);
        p = p->suivant;
    }
    printf("NULL\n");
}

// Programme principal pour tester les fonctions
void exercice4() {
    // Exemple : P(x) = 5x^4 + 3x^2 + 7
    EX4_Poly p = ex4_creer_monome(4, 5,
                    ex4_creer_monome(2, 3,
                    ex4_creer_monome(0, 7, NULL)));

    printf("P(x) = ");
    ex4_afficher_poly(p);

    // Calcul de la première dérivée
    EX4_Poly d1 = ex4_derivee(p);
    printf("P'(x) = ");
    ex4_afficher_poly(d1);

    // Calcul de la troisième dérivée
    EX4_Poly d3 = ex4_derivee_k(p, 3);
    printf("P'''(x) = ");
    ex4_afficher_poly(d3);
}