#include <stdio.h>
#include <stdlib.h>
#include "exercice3.h"

// Fonction 1 : Créer un nouveau nœud
EX3_PTR ex3_creer_noeud(int val, EX3_PTR suiv) {
    EX3_PTR p = (EX3_PTR)malloc(sizeof(EX3_NODE));
    if (p == NULL) {
        printf("Erreur lors de l'allocation mémoire\n");
        exit(1);
    }
    p->valeur = val;
    p->suivant = suiv;
    return p;
}

// Fonction 2 : Créer une liste avec 10 valeurs saisies au clavier
EX3_PTR ex3_creer_liste() {
    EX3_PTR debut = NULL, fin = NULL;
    int val;
    printf("Veuillez entrer 10 entiers :\n");
    for (int i = 0; i < 10; i++) {
        printf("Valeur %d : ", i + 1);
        scanf("%d", &val);
        EX3_PTR nouveau = ex3_creer_noeud(val, NULL);
        if (debut == NULL) {
            debut = nouveau;
            fin = nouveau;
        } else {
            fin->suivant = nouveau;
            fin = nouveau;
        }
    }
    return debut;
}

// Fonction 3 : Tester l'égalité de deux listes
int ex3_sont_egales(EX3_PTR l1, EX3_PTR l2) {
    while (l1 != NULL && l2 != NULL) {
        if (l1->valeur != l2->valeur) {
            return 0;
        }
        l1 = l1->suivant;
        l2 = l2->suivant;
    }
    return (l1 == NULL && l2 == NULL);
}

// Fonction 4a : Concaténer deux listes dans une nouvelle
EX3_PTR ex3_concatener_nouvelle(EX3_PTR l1, EX3_PTR l2) {
    EX3_PTR nouvelle = NULL, fin = NULL;

    while (l1 != NULL) {
        EX3_PTR copie = ex3_creer_noeud(l1->valeur, NULL);
        if (nouvelle == NULL) {
            nouvelle = copie;
            fin = copie;
        } else {
            fin->suivant = copie;
            fin = copie;
        }
        l1 = l1->suivant;
    }

    while (l2 != NULL) {
        EX3_PTR copie = ex3_creer_noeud(l2->valeur, NULL);
        if (nouvelle == NULL) {
            nouvelle = copie;
            fin = copie;
        } else {
            fin->suivant = copie;
            fin = copie;
        }
        l2 = l2->suivant;
    }

    return nouvelle;
}

// Fonction 4b : Concaténer sans créer une nouvelle liste
void ex3_concatener_inplace(EX3_PTR* l1, EX3_PTR l2) {
    if (*l1 == NULL) {
        *l1 = l2;
    } else {
        EX3_PTR temp = *l1;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = l2;
    }
}

// Fonction 5 : Afficher une liste
void ex3_afficher_liste(EX3_PTR l) {
    while (l != NULL) {
        printf("%d -> ", l->valeur);
        l = l->suivant;
    }
    printf("NULL\n");
}

// Fonction principale de test
void exercice3() {
    printf("Création de la première liste :\n");
    EX3_PTR liste1 = ex3_creer_liste();

    printf("Création de la deuxième liste :\n");
    EX3_PTR liste2 = ex3_creer_liste();

    printf("Liste 1 : ");
    ex3_afficher_liste(liste1);

    printf("Liste 2 : ");
    ex3_afficher_liste(liste2);

    if (ex3_sont_egales(liste1, liste2)) {
        printf("Les deux listes sont identiques.\n");
    } else {
        printf("Les listes sont différentes.\n");
    }

    EX3_PTR liste3 = ex3_concatener_nouvelle(liste1, liste2);
    printf("Liste concaténée (dans une nouvelle) : ");
    ex3_afficher_liste(liste3);

    ex3_concatener_inplace(&liste1, liste2);
    printf("Liste concaténée (modification sur place) : ");
    ex3_afficher_liste(liste1);
}
