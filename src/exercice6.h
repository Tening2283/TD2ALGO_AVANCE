#ifndef EXERCICE6_H
#define EXERCICE6_H

#include <stdbool.h>

// Définition de la structure pour une matrice carrée
typedef struct {
    double mat[100][100]; // Matrice carrée de taille maximale 100x100
} EX6_MATCARREE;

// Déclaration des fonctions
bool ex6_symetrique(EX6_MATCARREE m, int n);
int ex6_nombre_coefficients(int n);
double* ex6_symCompacte(EX6_MATCARREE m, int n);
double ex6_acces(double* c, int i, int j, int n);
void ex6_traiterCoef(double x);
void ex6_traiterLigne(double* c, int n, int i);
void ex6_afficher(double* c, int n);
void exercice6();

#endif