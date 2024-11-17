#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etudiant {
    char matricule[10];
    char nom[50];
    char prenom[50];
    struct Etudiant *suivant;
} Etudiant;


Etudiant* ajouterEtudiant(Etudiant *tete, char *matricule, char *nom, char *prenom) {
    Etudiant *nouvelEtudiant = (Etudiant*)malloc(sizeof(Etudiant));
    if (nouvelEtudiant == NULL) {
        perror("Allocation mémoire échouée");
        exit(1);
    }
    strcpy(nouvelEtudiant->matricule, matricule);
    strcpy(nouvelEtudiant->nom, nom);
    strcpy(nouvelEtudiant->prenom, prenom);
    nouvelEtudiant->suivant = tete;
    return nouvelEtudiant;
}

void afficherListe(Etudiant *tete) {
    Etudiant *courant = tete;
    while (courant != NULL) {
        printf("Matricule: %s, Nom: %s, Prénom: %s\n", courant->matricule, courant->nom, courant->prenom);
        courant = courant->suivant;
    }
}


void libererMemoire(Etudiant *tete) {
    Etudiant *courant = tete;
    Etudiant *suivant;
    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
}


int main() {
    Etudiant *tete = NULL;
    char matricule[10], nom[50], prenom[50];
    int choix;

    do {
        printf("\nMenu :\n");
        printf("1 - Ajouter un étudiant\n");
        printf("2 - Afficher la liste des étudiants\n");
        printf("3 - Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Matricule : ");
                scanf("%s", matricule);
                printf("Nom : ");
                scanf("%s", nom);
                printf("Prénom : ");
                scanf("%s", prenom);
                tete = ajouterEtudiant(tete, matricule, nom, prenom);
                break;
            case 2:
                afficherListe(tete);
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 3);

    libererMemoire(tete);
    return 0;
}
