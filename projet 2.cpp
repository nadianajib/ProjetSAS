#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

// Structure pour stocker les informations de chaque tâche
typedef struct {
    int jour;
    int mois;
    int annee;
} DateEcheance;

struct Tache {
    char Description[200];
    char dateEcheance[30];
    int priorite;
};

// Fonction pour ajouter une tâche
int ajouterTache(struct Tache taches[], int nombreTaches) {
    if (nombreTaches < MAX_TASKS) {
        printf("Entrez la description de la tâche : ");
        scanf("%s", taches[nombreTaches].Description);

        printf("Entrez la date d'échéance de la tâche : ");
        scanf("%s", taches[nombreTaches].dateEcheance);

        printf("Entrez la priorité de la tâche (1 - Faible, 2 - Moyenne, 3 - Elevee) : ");
        scanf("%d", &taches[nombreTaches].priorite);

        return nombreTaches + 1;  // Retourne le nouveau nombre de tâches
    } else {
        printf("Impossible d'ajouter plus de tâches, la limite est atteinte.\n");
        return nombreTaches;
    }
}

// Fonction pour afficher les tâches
void afficherTache(struct Tache taches[], int nombreTaches) {
    if (nombreTaches == 0) {
        printf("La liste des taches est vide !\n");
    } else {
        printf("Liste des Taches:\n");
        for (int i = 0; i < nombreTaches; i++) {
            printf("Tache %d:\n", i + 1);
            printf("la Description: %s\n", taches[i].Description);
            printf("la dateEcheance: %s\n", taches[i].dateEcheance);
            printf("la priorite: %d\n", taches[i].priorite);
            printf("\n");
        }
    }
}

// Fonction pour modifier une tâche
void modifierTache(struct Tache taches[], int nombreTaches) {
    int numeroTache;
    printf("entrez le numero de la tache a modifier:");
    scanf("%d", &numeroTache);

    if (numeroTache >= 1 && numeroTache <= nombreTaches) {
        // L'utilisateur doit entrer les nouvelles informations pour la tâche
        printf("Entrez la nouvelle Description de la tache : ");
        scanf(" %[^\n]s", taches[numeroTache - 1].Description);
        printf("Entrez la nouvelle DateEchence de la tache : ");
        scanf(" %[^\n]s", taches[numeroTache - 1].dateEcheance);
        printf("Entrez la nouvelle priorite de la tache (1 - Faible, 2 - Moyenne, 3 - Elevee) : ");
        scanf("%d", &taches[numeroTache - 1].priorite);

        printf("la tache a ete modifiee avec succes.\n");

    } else {
        printf("Numéro de tache invalide.\n");
    }
}

// Fonction pour supprimer une tâche
void SupprimerTache(struct Tache taches[], int *nombreTaches) {
    int index;

    printf("Entrez le numéro de la tâche à supprimer : ");
    scanf("%d", &index);

    if (index >= 1 && index <= *nombreTaches) {
        // Décaler les tâches suivantes vers la gauche pour remplir l'emplacement supprimé
        for (int i = index - 1; i < *nombreTaches - 1; i++) {
            taches[i] = taches[i + 1];
        }

        // Décrémentation
        (*nombreTaches)--;

        printf("La tâche a été supprimée.\n");
    } else {
        printf("Numéro de tâche invalide.\n");
    }
}

int main() {
    struct Tache taches[MAX_TASKS];
    int nombreTaches = 0;
    int choix;

    do {
        // Menu principal:
        printf("         Menu: \n \n");
        printf("1. Ajouter une tache.\n");
        printf("2. Afficher les taches.\n");
        printf("3. Modifier une tache.\n");
        printf("4. Supprimer une tache.\n");
        printf("5. Quitter.\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            nombreTaches = ajouterTache(taches, nombreTaches);
            break;
        case 2:
            afficherTache(taches, nombreTaches);
            break;
        case 3:
            modifierTache(taches, nombreTaches);
            break;
        case 4:
            SupprimerTache(taches, &nombreTaches);
            break;
        case 5:
            printf("Au revoir!\n");
            break;
        default:
            printf("Votre choix est invalide, veuillez ressayer.\n");
            break;
        }
    } while (choix != 5);

    return 0;
}

