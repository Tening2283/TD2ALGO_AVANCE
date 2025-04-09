#ifndef EXERCICE2_H
#define EXERCICE2_H

#include <stdlib.h>
#include <string.h>

// Définition de la structure EX2_Maillon
typedef struct ex2_Maillon {
    char *info;
    struct ex2_Maillon *suivant;
    struct ex2_Maillon *precedent;
} EX2_Maillon;

// Déclaration des variables globales
extern EX2_Maillon *ex2_premier;
extern EX2_Maillon *ex2_dernier;

// Déclaration des fonctions
void ex2_ajouter_devant(char *s);
void ex2_ajouter_devant_param(char *s, EX2_Maillon **p_premier, EX2_Maillon **p_dernier);
void ex2_supprimer(char *s);
void ex2_afficher_liste();
void exercice2();

#endif