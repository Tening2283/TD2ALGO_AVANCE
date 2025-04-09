#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercice2.h"

// Variables globales pour le début et la fin de la liste
EX2_Maillon *ex2_premier = NULL;
EX2_Maillon *ex2_dernier = NULL;

// Fonction 1 : Ajoute un maillon en tête de la liste
void ex2_ajouter_devant(char *s) {
    EX2_Maillon *nouveau = (EX2_Maillon *)malloc(sizeof(EX2_Maillon));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }

    nouveau->info = strdup(s);
    nouveau->precedent = NULL;
    nouveau->suivant = ex2_premier;

    if (ex2_premier != NULL) {
        ex2_premier->precedent = nouveau;
    } else {
        ex2_dernier = nouveau;
    }

    ex2_premier = nouveau;
}

// Fonction 2 : Ajoute un maillon en tête de la liste avec paramètres
void ex2_ajouter_devant_param(char *s, EX2_Maillon **p_premier, EX2_Maillon **p_dernier) {
    EX2_Maillon *nouveau = (EX2_Maillon *)malloc(sizeof(EX2_Maillon));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }

    nouveau->info = strdup(s);
    nouveau->precedent = NULL;
    nouveau->suivant = *p_premier;

    if (*p_premier != NULL) {
        (*p_premier)->precedent = nouveau;
    } else {
        *p_dernier = nouveau;
    }

    *p_premier = nouveau;
}

// Fonction 3 : Supprime le premier maillon contenant la chaîne s
void ex2_supprimer(char *s) {
    EX2_Maillon *courant = ex2_premier;

    while (courant != NULL) {
        if (strcmp(courant->info, s) == 0) {
            if (courant->precedent != NULL) {
                courant->precedent->suivant = courant->suivant;
            } else {
                ex2_premier = courant->suivant;
            }

            if (courant->suivant != NULL) {
                courant->suivant->precedent = courant->precedent;
            } else {
                ex2_dernier = courant->precedent;
            }

            free(courant->info);
            free(courant);
            return;
        }
        courant = courant->suivant;
    }
}

// Fonction 4 : Affiche la liste de début à fin
void ex2_afficher_liste() {
    EX2_Maillon *courant = ex2_premier;
    printf("Liste : ");
    while (courant != NULL) {
        printf("[%s] ", courant->info);
        courant = courant->suivant;
    }
    printf("\n");
}

// Fonction principale pour tester l'exercice 2
void exercice2() {
    ex2_ajouter_devant("bonjour");
    ex2_ajouter_devant("tout");
    ex2_ajouter_devant("le");
    ex2_ajouter_devant("monde");

    ex2_afficher_liste();

    ex2_supprimer("tout");
    printf("Après suppression de 'tout' :\n");
    ex2_afficher_liste();
}