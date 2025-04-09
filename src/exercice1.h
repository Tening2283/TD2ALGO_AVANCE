#ifndef EXERCICE1_H
#define EXERCICE1_H

// Déclaration des types et fonctions
typedef struct ex1_maillon {
    char *mot;
    struct ex1_maillon *suiv;
} EX1_MAILLON, *EX1_PTR;

EX1_PTR ex1_ajoute_debut(char *mot, EX1_PTR L);
EX1_PTR ex1_ajoute_fin(char *mot, EX1_PTR L);
EX1_PTR ex1_supprimer(char *mot, EX1_PTR L);
void ex1_premiers(EX1_PTR liste, int n);
void ex1_purifie(EX1_PTR liste);
void ex1_afficher_liste(EX1_PTR l);

// Fonction principale pour l'exercice 1
void exercice1();

#endif
