#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "exercice6.h"

// Fonction pour vérifier si une matrice est symétrique
bool ex6_symetrique(EX6_MATCARREE m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (m.mat[i][j] != m.mat[j][i]) {
                return false;
            }
        }
    }
    return true;
}

// Fonction pour calculer le nombre de coefficients nécessaires
int ex6_nombre_coefficients(int n) {
    return (n * (n + 1)) / 2;
}

// Fonction pour générer la représentation compacte d'une matrice symétrique
double* ex6_symCompacte(EX6_MATCARREE m, int n) {
    if (!ex6_symetrique(m, n)) {
        return NULL;
    }

    int taille = ex6_nombre_coefficients(n);
    double* compacte = (double*)malloc(taille * sizeof(double));
    if (compacte == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            compacte[k++] = m.mat[i][j];
        }
    }

    return compacte;
}

// Fonction pour accéder à un coefficient dans la représentation compacte
double ex6_acces(double* c, int i, int j, int n) {
    if (i < j) {
        int temp = i;
        i = j;
        j = temp;
    }
    return c[(i * (i + 1)) / 2 + j];
}

// Fonction pour traiter un coefficient (par exemple, l'afficher)
void ex6_traiterCoef(double x) {
    printf("%.2f ", x);
}

// Fonction pour traiter une ligne de la matrice symétrique
void ex6_traiterLigne(double* c, int n, int i) {
    for (int j = 0; j < n; j++) {
        ex6_traiterCoef(ex6_acces(c, i, j, n));
    }
    printf("\n");
}

// Fonction pour afficher une matrice symétrique
void ex6_afficher(double* c, int n) {
    for (int i = 0; i < n; i++) {
        ex6_traiterLigne(c, n, i);
    }
}

// Programme principal pour tester les fonctions
void exercice6() {
    EX6_MATCARREE m = {
        .mat = {
            {1, 2, 3},
            {2, 4, 5},
            {3, 5, 6}
        }
    };
    int n = 3;

    if (ex6_symetrique(m, n)) {
        printf("La matrice est symétrique.\n");

        double* compacte = ex6_symCompacte(m, n);
        if (compacte != NULL) {
            printf("Représentation compacte :\n");
            for (int i = 0; i < ex6_nombre_coefficients(n); i++) {
                printf("%.2f ", compacte[i]);
            }
            printf("\n");

            printf("Matrice symétrique :\n");
            ex6_afficher(compacte, n);

            free(compacte);
        }
    } else {
        printf("La matrice n'est pas symétrique.\n");
    }
}