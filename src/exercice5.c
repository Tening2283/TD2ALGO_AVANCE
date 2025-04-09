#include <stdio.h>
#include <stdlib.h>
#include "exercice5.h"

// Fonction 1 : Créer un nouveau maillon avec des valeurs initiales fournies
EX5_PTR ex5_creer_element(int position, float valeur, EX5_PTR next) {
    EX5_PTR nouveau = (EX5_PTR)malloc(sizeof(EX5_MAILLON));
    if (nouveau == NULL) {
        printf("Erreur : mémoire insuffisante.\n");
        exit(1);
    }
    nouveau->pos = position;
    nouveau->val = valeur;
    nouveau->suivant = next;
    return nouveau;
}

// Fonction 2 : Convertir un tableau classique en vecteur creux (liste chaînée)
EX5_PTR ex5_generer_vecteur_creux(float tab[], int taille) {
    EX5_PTR tete = NULL;
    EX5_PTR courant = NULL;

    for (int i = 0; i < taille; i++) {
        if (tab[i] != 0) {
            EX5_PTR elem = ex5_creer_element(i, tab[i], NULL);
            if (tete == NULL) {
                tete = elem;
            } else {
                courant->suivant = elem;
            }
            courant = elem;
        }
    }
    return tete;
}

// Fonction 3 : Additionner deux vecteurs creux
EX5_PTR ex5_addition_vecteurs(EX5_PTR v1, EX5_PTR v2) {
    EX5_PTR resultat = NULL;
    EX5_PTR* curseur = &resultat;

    while (v1 || v2) {
        int indice;
        float somme_val;

        if (!v2 || (v1 && v1->pos < v2->pos)) {
            indice = v1->pos;
            somme_val = v1->val;
            v1 = v1->suivant;
        } else if (!v1 || (v2 && v2->pos < v1->pos)) {
            indice = v2->pos;
            somme_val = v2->val;
            v2 = v2->suivant;
        } else {
            indice = v1->pos;
            somme_val = v1->val + v2->val;
            v1 = v1->suivant;
            v2 = v2->suivant;
        }

        if (somme_val != 0) {
            *curseur = ex5_creer_element(indice, somme_val, NULL);
            curseur = &((*curseur)->suivant);
        }
    }

    return resultat;
}

// Fonction 4 : Affiche la représentation du vecteur creux
void ex5_afficher(EX5_PTR v) {
    while (v) {
        printf("(%d, %.2f) -> ", v->pos, v->val);
        v = v->suivant;
    }
    printf("NULL\n");
}

// Programme principal pour tester les fonctions
void exercice5() {
    float tab1[] = {0, 0, 9, 5, 0, 7, 0, 3, 0, 0};
    float tab2[] = {0, 4, 0, 5, 0, 0, 6, 0, 0, 1};
    int taille = 10;

    EX5_PTR vect1 = ex5_generer_vecteur_creux(tab1, taille);
    EX5_PTR vect2 = ex5_generer_vecteur_creux(tab2, taille);

    printf("Vecteur A : ");
    ex5_afficher(vect1);
    printf("Vecteur B : ");
    ex5_afficher(vect2);

    EX5_PTR somme = ex5_addition_vecteurs(vect1, vect2);
    printf("Résultat (A + B) : ");
    ex5_afficher(somme);
}