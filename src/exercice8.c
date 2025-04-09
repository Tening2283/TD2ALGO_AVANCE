#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercice8.h"



// Fonction 1 : Ajoute un numéro de page dans une LCB
EX8_LCB ex8_ajout_numero(int num, EX8_LCB numeros) {
    EX8_PTR nouveau = (EX8_PTR)malloc(sizeof(EX8_MAILLON));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    nouveau->numero = num;
    nouveau->suiv = NULL;
    nouveau->prec = NULL;

    if (numeros.tete == NULL) {
        numeros.tete = numeros.queue = nouveau;
        return numeros;
    }

    EX8_PTR courant = numeros.tete;
    while (courant && courant->numero < num)
        courant = courant->suiv;

    if (courant && courant->numero == num) {
        free(nouveau);
        return numeros;
    }

    if (courant == numeros.tete) {
        nouveau->suiv = numeros.tete;
        numeros.tete->prec = nouveau;
        numeros.tete = nouveau;
    } else if (courant == NULL) {
        numeros.queue->suiv = nouveau;
        nouveau->prec = numeros.queue;
        numeros.queue = nouveau;
    } else {
        nouveau->suiv = courant;
        nouveau->prec = courant->prec;
        courant->prec->suiv = nouveau;
        courant->prec = nouveau;
    }

    return numeros;
}

// Fonction 2 : Ajoute un nom propre dans l’ABR
EX8_PABR ex8_ajout_nompropre(char* nom, int t[], int nombre, EX8_PABR a) {
    if (a == NULL) {
        a = (EX8_PABR)malloc(sizeof(EX8_ABR));
        if (!a) {
            printf("Erreur d'allocation mémoire.\n");
            exit(1);
        }
        strcpy(a->nom, nom);
        a->pages.tete = a->pages.queue = NULL;

        for (int i = 0; i < nombre; i++)
            a->pages = ex8_ajout_numero(t[i], a->pages);

        a->gauche = a->droite = NULL;
    } else if (strcmp(nom, a->nom) < 0) {
        a->gauche = ex8_ajout_nompropre(nom, t, nombre, a->gauche);
    } else if (strcmp(nom, a->nom) > 0) {
        a->droite = ex8_ajout_nompropre(nom, t, nombre, a->droite);
    }

    return a;
}

// Fonction 3 : Supprime un numéro d’une LCB associée à un nom
EX8_PABR ex8_supprimer_numero(char *nom, int numero, EX8_PABR a) {
    if (a == NULL) return NULL;

    if (strcmp(nom, a->nom) < 0) {
        a->gauche = ex8_supprimer_numero(nom, numero, a->gauche);
    } else if (strcmp(nom, a->nom) > 0) {
        a->droite = ex8_supprimer_numero(nom, numero, a->droite);
    } else {
        EX8_PTR courant = a->pages.tete;
        while (courant && courant->numero != numero)
            courant = courant->suiv;

        if (courant) {
            if (courant->prec) courant->prec->suiv = courant->suiv;
            if (courant->suiv) courant->suiv->prec = courant->prec;
            if (courant == a->pages.tete) a->pages.tete = courant->suiv;
            if (courant == a->pages.queue) a->pages.queue = courant->prec;
            free(courant);
        }
    }

    return a;
}

// Fonction 4 : Affiche l’index (infixe)
void ex8_afficher_index(EX8_PABR a) {
    if (a != NULL) {
        ex8_afficher_index(a->gauche);
        printf("%s: ", a->nom);
        EX8_PTR courant = a->pages.tete;
        while (courant) {
            printf("%d ", courant->numero);
            courant = courant->suiv;
        }
        printf("\n");
        ex8_afficher_index(a->droite);
    }
}

// Fonction 5 : Représentation graphique de l’ABR
void ex8_afficher_arbre(EX8_PABR arbre, int niveau) {
    if (arbre == NULL) return;

    ex8_afficher_arbre(arbre->droite, niveau + 1);

    for (int i = 0; i < niveau; i++)
        printf("   ");
    printf("%s\n", arbre->nom);

    ex8_afficher_arbre(arbre->gauche, niveau + 1);
}

// Fonction principale de test
void exercice8() {
    EX8_PABR index = NULL;

    int pagesFatou[] = {110, 250, 300};
    int pagesMamadou[] = {3, 14, 101};
    int pagesOusseynou[] = {11, 50};
    int pagesPierre[] = {3, 7, 100, 287};
    int pagesSoda[] = {6, 10, 34, 66, 98};

    index = ex8_ajout_nompropre("Fatou", pagesFatou, 3, index);
    index = ex8_ajout_nompropre("Mamadou", pagesMamadou, 3, index);
    index = ex8_ajout_nompropre("Ousseynou", pagesOusseynou, 2, index);
    index = ex8_ajout_nompropre("Pierre", pagesPierre, 4, index);
    index = ex8_ajout_nompropre("Soda", pagesSoda, 5, index);

    printf("Index avant suppression :\n");
    ex8_afficher_index(index);

    printf("\nReprésentation graphique de l'ABR :\n");
    ex8_afficher_arbre(index, 0);

    printf("\nSuppression du numéro 50 de Ousseynou...\n");
    index = ex8_supprimer_numero("Ousseynou", 50, index);

    printf("\nIndex après suppression :\n");
    ex8_afficher_index(index);
}

/*
    7) Les performances de l'ABR dans cet exemple ne sont pas meilleures que celles
    qu'on obtiendrait avec une liste chaînée, car si les noms sont insérés dans un
    ordre trié ou presque trié, l'arbre devient dégénéré et ressemble à une liste 
    chaînée, ce qui mène à une complexité de recherche, insertion et suppression en O(n).
    
    Solution :
    Pour améliorer les performances, il est recommandé d'utiliser un arbre équilibré
    comme un arbre AVL ou un arbre Red-Black. Ces structures garantissent que l'arbre
    reste équilibré après chaque insertion ou suppression, assurant ainsi une hauteur
    logarithmique (O(log n)) et des performances optimales pour les opérations de recherche
    et modification.
*/
