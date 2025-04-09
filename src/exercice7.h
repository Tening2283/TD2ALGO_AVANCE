#ifndef EXERCICE7_H
#define EXERCICE7_H

// Définition de la structure pour un nœud d'arbre binaire
typedef struct ex7_arbre_binaire {
    int valeur;                          // Valeur du nœud
    struct ex7_arbre_binaire *gauche;    // Sous-arbre gauche
    struct ex7_arbre_binaire *droite;    // Sous-arbre droit
} ex7_ArbreBinaire, *ex7_PointeurArbre;

// Déclaration des fonctions
void ex7_afficher_feuilles(ex7_PointeurArbre arbre);
void ex7_afficher_degre(ex7_PointeurArbre arbre);
void ex7_trouver_profondeur(ex7_PointeurArbre arbre, int x, int niveau);
int ex7_calculer_hauteur(ex7_PointeurArbre arbre);
int ex7_somme_noeuds(ex7_PointeurArbre arbre);
void exercice7();

#endif
