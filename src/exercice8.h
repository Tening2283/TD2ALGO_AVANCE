#ifndef EXERCICE8_H
#define EXERCICE8_H

typedef struct ex8_maillon {
    int numero;
    struct ex8_maillon *suiv, *prec;
} EX8_MAILLON, *EX8_PTR;

typedef struct ex8_lcb {
    EX8_PTR tete, queue;
} EX8_LCB;

typedef struct ex8_abr {
    char nom[50];
    EX8_LCB pages;
    struct ex8_abr *gauche, *droite;
} EX8_ABR, *EX8_PABR;

EX8_LCB ex8_ajout_numero(int num, EX8_LCB numeros);
EX8_PABR ex8_ajout_nompropre(char* nom, int t[], int nombre, EX8_PABR a);
EX8_PABR ex8_supprimer_numero(char *nom, int numero, EX8_PABR a);
void ex8_afficher_index(EX8_PABR a);
void ex8_afficher_arbre(EX8_PABR arbre, int niveau);
void exercice8();

#endif
