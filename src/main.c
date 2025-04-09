#include <stdio.h>
#include "exercice1.h"
#include "exercice2.h"
#include "exercice3.h"
#include "exercice4.h"
#include "exercice5.h"
#include "exercice6.h"
#include "exercice7.h"
#include "exercice8.h"

void afficher_menu() {
    printf("\n=== Menu des Exercices ===\n");
    printf("1. Exercice 1 : Listes chaînées et chaînes de caractères\n");
    printf("2. Exercice 2 : Listes chaînées bidirectionnelles\n");
    printf("3. Exercice 3 : Traitement de listes chaînées\n");
    printf("4. Exercice 4 : Dérivée d’un polynôme\n");
    printf("5. Exercice 5 : Vecteurs creux\n");
    printf("6. Exercice 6 : Matrices symétriques\n");
    printf("7. Exercice 7 : Terminologie sur les arbres\n");
    printf("8. Exercice 8 : LCB et ABR\n");
    printf("0. Quitter\n");
    printf("==========================\n");
    printf("Veuillez choisir un exercice à tester : ");
}

int main() {
    int choix;

    do {
        afficher_menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("\n--- Exercice 1 ---\n");
                exercice1();
                break;
            case 2:
                printf("\n--- Exercice 2 ---\n");
                exercice2();
                break;
            case 3:
                printf("\n--- Exercice 3 ---\n");
                exercice3();
                break;
            case 4:
                printf("\n--- Exercice 4 ---\n");
                exercice4();
                break;
            case 5:
                printf("\n--- Exercice 5 ---\n");
                exercice5();
                break;
            case 6:
                printf("\n--- Exercice 6 ---\n");
                exercice6();
                break;
            case 7:
                printf("\n--- Exercice 7 ---\n");
                exercice7();
                break;
            case 8:
                printf("\n--- Exercice 8 ---\n");
                exercice8();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}