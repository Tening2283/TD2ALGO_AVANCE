#include <stdio.h>
#include <stdlib.h>
#include "exercice7.h"

// Fonction pour afficher les feuilles de l'arbre
void ex7_afficher_feuilles(ex7_PointeurArbre arbre) {
    if (arbre != NULL) {
        if (arbre->gauche == NULL && arbre->droite == NULL) {
            printf("%d ", arbre->valeur);
        }
        ex7_afficher_feuilles(arbre->gauche);
        ex7_afficher_feuilles(arbre->droite);
    }
}

// Fonction pour afficher le degré de chaque nœud
void ex7_afficher_degre(ex7_PointeurArbre arbre) {
    if (arbre != NULL) {
        int degre = 0;
        if (arbre->gauche != NULL) degre++;
        if (arbre->droite != NULL) degre++;
        printf("Nœud %d : Degré %d\n", arbre->valeur, degre);
        ex7_afficher_degre(arbre->gauche);
        ex7_afficher_degre(arbre->droite);
    }
}

// Fonction pour trouver la profondeur d'un nœud donné
void ex7_trouver_profondeur(ex7_PointeurArbre arbre, int x, int niveau) {
    if (arbre == NULL) return;

    if (arbre->valeur == x) {
        printf("Profondeur du nœud %d : %d\n", x, niveau);
        return;
    }

    ex7_trouver_profondeur(arbre->gauche, x, niveau + 1);
    ex7_trouver_profondeur(arbre->droite, x, niveau + 1);
}

// Fonction pour calculer la hauteur de l'arbre
int ex7_calculer_hauteur(ex7_PointeurArbre arbre) {
    if (arbre == NULL) return -1;

    int hg = ex7_calculer_hauteur(arbre->gauche);
    int hd = ex7_calculer_hauteur(arbre->droite);

    return 1 + (hg > hd ? hg : hd);
}

// Fonction pour calculer la somme des valeurs des nœuds
int ex7_somme_noeuds(ex7_PointeurArbre arbre) {
    if (arbre == NULL) return 0;
    return arbre->valeur + ex7_somme_noeuds(arbre->gauche) + ex7_somme_noeuds(arbre->droite);
}

// Programme principal pour tester les fonctions
void exercice7() {
    ex7_PointeurArbre arbre = (ex7_PointeurArbre)malloc(sizeof(ex7_ArbreBinaire));
    arbre->valeur = 10;

    arbre->gauche = (ex7_PointeurArbre)malloc(sizeof(ex7_ArbreBinaire));
    arbre->gauche->valeur = 5;
    arbre->gauche->gauche = NULL;
    arbre->gauche->droite = NULL;

    arbre->droite = (ex7_PointeurArbre)malloc(sizeof(ex7_ArbreBinaire));
    arbre->droite->valeur = 15;

    arbre->droite->gauche = (ex7_PointeurArbre)malloc(sizeof(ex7_ArbreBinaire));
    arbre->droite->gauche->valeur = 12;
    arbre->droite->gauche->gauche = NULL;
    arbre->droite->gauche->droite = NULL;

    arbre->droite->droite = (ex7_PointeurArbre)malloc(sizeof(ex7_ArbreBinaire));
    arbre->droite->droite->valeur = 20;
    arbre->droite->droite->gauche = NULL;
    arbre->droite->droite->droite = NULL;

    printf("Feuilles de l'arbre : ");
    ex7_afficher_feuilles(arbre);
    printf("\n");

    printf("\nDegré des nœuds :\n");
    ex7_afficher_degre(arbre);

    printf("\nProfondeur du nœud 12 : ");
    ex7_trouver_profondeur(arbre, 12, 0);

    printf("\nHauteur de l'arbre : %d\n", ex7_calculer_hauteur(arbre));

    printf("\nSomme des nœuds de l'arbre : %d\n", ex7_somme_noeuds(arbre));
}