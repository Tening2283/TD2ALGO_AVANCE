#ifndef EXERCICE3_H
#define EXERCICE3_H

// Déclaration des types et fonctions
typedef struct ex3_Node {
    int valeur;
    struct ex3_Node* suivant;
} EX3_NODE, *EX3_PTR;

EX3_PTR ex3_creer_noeud(int val, EX3_PTR suiv);
EX3_PTR ex3_creer_liste();
int ex3_sont_egales(EX3_PTR l1, EX3_PTR l2);
EX3_PTR ex3_concatener_nouvelle(EX3_PTR l1, EX3_PTR l2);
void ex3_concatener_inplace(EX3_PTR* l1, EX3_PTR l2);
void ex3_afficher_liste(EX3_PTR l);
void exercice3();

#endif
