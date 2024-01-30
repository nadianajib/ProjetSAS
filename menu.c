#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 200
int num=0;


// Structure pour stocker les informations de chaque t�che
struct Tache {
    char Description[200];
    char dateEcheance[30];
    int priorite;
};

// Fonction pour ajouter une t�che
int ajouterTache(struct Tache taches[], int nombreTaches) {
    if (nombreTaches < MAX_TASKS) {
        printf("Entrez la description de la t�che : ");
        scanf(" %[^\n]s", taches[nombreTaches].Description);

        printf("Entrez la date d'�ch�ance de la t�che : ");
        scanf(" %[^\n]s", taches[nombreTaches].dateEcheance);
		
        printf("Entrez la priorit� de la t�che (1 - Faible, 2 - Moyenne, 3 - �lev�e) : ");
        scanf("%d", &taches[nombreTaches].priorite);

        return nombreTaches + 1;  // Retourne le nouveau nombre de t�ches
    } else {
        printf("Votre choix est invalide, veuillez r�essayer.\n");
        return nombreTaches;
    }
}

// Fonction pour afficher la liste des t�ches
void afficherTaches(struct Tache taches[], int nombreTaches) {
    if (nombreTaches > 0) {
        printf("Liste des t�ches :\n");
         int i;
        for (i = 0; i < nombreTaches; i++) {
            printf("T�che %d :\n", i + 1);
            printf("Description : %s\n", taches[i].Description);
            printf("Date d'�ch�ance : %s\n", taches[i].dateEcheance);
            printf("Priorit� : %d\n", taches[i].priorite);
            printf("\n");
        }
    } else {
        printf("Aucune t�che n'est disponible.\n");
    }
}

// Fonction pour modifier une t�che
void modifierTache(struct Tache taches[], int nombreTaches) {
    int numeroTache;
    printf("Entrez le num�ro de la t�che � modifier : ");
    scanf("%d", &numeroTache);

    if (numeroTache >= 1 && numeroTache <= nombreTaches) {
        // L'utilisateur doit entrer les nouvelles informations pour la t�che
        printf("Entrez la nouvelle description de la t�che : ");
        scanf(" %[^\n]s", taches[numeroTache - 1].Description);

        printf("Entrez la nouvelle date d'�ch�ance de la t�che : ");
        scanf(" %[^\n]s", taches[numeroTache - 1].dateEcheance);

        printf("Entrez la nouvelle priorit� de la t�che (1 - Faible, 2 - Moyenne, 3 - �lev�e) : ");
        scanf("%d", &taches[numeroTache - 1].priorite);

        printf("La t�che a �t� modifi�e avec succ�s.\n");
    } else {
        printf("Num�ro de t�che invalide.\n");
    }
}

// Fonction pour supprimer une t�che


int main() {
    struct Tache taches[MAX_TASKS];
    int nombreTaches = 0;
    int choix;

    do {
        // Menu principal
        printf("\n1. Ajouter une t�che\n");
        printf("2. Afficher la liste des t�ches\n");
        printf("3. Modifier une t�che\n");
        printf("4. Supprimer une t�che\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                nombreTaches = ajouterTache(taches, nombreTaches);
                break;
            case 2:
                afficherTaches(taches, nombreTaches);
                break;
            case 3:
                modifierTache(taches, nombreTaches);
                break;
            case 4:
                supprimerTache(taches, &nombreTaches);
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }

    } while (choix != 5);

    return 0;
}

