#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercice1.h"

// Fonction 1 : Ajoute un mot au début de la liste chaînée
EX1_PTR ex1_ajoute_debut(char *mot, EX1_PTR L) {
    EX1_PTR nouv = (EX1_PTR)malloc(sizeof(EX1_MAILLON));
    if (!nouv) {
        printf("Erreur allocation mémoire.\n");
        return L;
    }
    nouv->mot = strdup(mot);
    nouv->suiv = L;
    return nouv;
}

// Fonction 2 : Ajoute un mot à la fin de la liste chaînée
EX1_PTR ex1_ajoute_fin(char *mot, EX1_PTR L) {
    EX1_PTR nouv = (EX1_PTR)malloc(sizeof(EX1_MAILLON));
    if (!nouv) {
        printf("Problème mémoire.\n");
        return L;
    }
    nouv->mot = strdup(mot);
    nouv->suiv = NULL;

    if (L == NULL)
        return nouv;

    EX1_PTR p = L;
    while (p->suiv != NULL) {
        p = p->suiv;
    }
    p->suiv = nouv;
    return L;
}

// Fonction 3 : Supprime un maillon contenant un mot donné
EX1_PTR ex1_supprimer(char *mot, EX1_PTR L) {
    EX1_PTR courant = L;
    EX1_PTR precedent = NULL;

    while (courant != NULL && strcmp(courant->mot, mot) != 0) {
        precedent = courant;
        courant = courant->suiv;
    }

    if (courant == NULL) {
        return L;
    }

    if (precedent == NULL) {
        L = courant->suiv;
    } else {
        precedent->suiv = courant->suiv;
    }

    free(courant->mot);
    free(courant);
    return L;
}

// Fonction 4 : Affiche les n premiers mots de la liste
void ex1_premiers(EX1_PTR liste, int n) {
    int i = 0;
    EX1_PTR temp = liste;
    while (temp != NULL && i < n) {
        printf("%s\n", temp->mot);
        temp = temp->suiv;
        i++;
    }
}

// Fonction 5 : Supprime les doublons consécutifs dans une liste triée
void ex1_purifie(EX1_PTR liste) {
    EX1_PTR actuel = liste;

    while (actuel != NULL) {
        EX1_PTR suivant = actuel;
        while (suivant != NULL && suivant->suiv != NULL) {
            if (strcmp(actuel->mot, suivant->suiv->mot) == 0) {
                EX1_PTR doublon = suivant->suiv;
                suivant->suiv = doublon->suiv;  // supprimer le doublon
                free(doublon->mot);
                free(doublon);
            } else {
                suivant = suivant->suiv;  // continuer avec l'élément suivant
            }
        }
        actuel = actuel->suiv;  // avancer dans la liste
    }
}



// Affiche toute la liste chaînée
void ex1_afficher_liste(EX1_PTR l) {
    while (l != NULL) {
        printf("%s -> ", l->mot);
        l = l->suiv;
    }
    printf("NULL\n");
}

// Fonction principale pour tester les fonctions
void exercice1() {
    EX1_PTR ma_liste = NULL;

    ma_liste = ex1_ajoute_debut("chat", ma_liste);
    ma_liste = ex1_ajoute_debut("chien", ma_liste);
    ma_liste = ex1_ajoute_fin("oiseau", ma_liste);
    ma_liste = ex1_ajoute_fin("chat", ma_liste); // doublon

    printf("Liste après ajouts :\n");
    ex1_afficher_liste(ma_liste);

    printf("\nAffichage des 2 premiers mots :\n");
    ex1_premiers(ma_liste, 2);

    ma_liste = ex1_supprimer("chien", ma_liste);
    printf("\nListe après suppression de 'chien' :\n");
    ex1_afficher_liste(ma_liste);

    ex1_purifie(ma_liste);
    printf("\nListe après purification :\n");
    ex1_afficher_liste(ma_liste);
}
