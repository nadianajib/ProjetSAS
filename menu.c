#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 200
int num=0;


// Structure pour stocker les informations de chaque tâche
struct Tache {
    char Description[200];
    char dateEcheance[30];
    int priorite;
};

// Fonction pour ajouter une tâche
int ajouterTache(struct Tache taches[], int nombreTaches) {
    if (nombreTaches < MAX_TASKS) {
        printf("Entrez la description de la tâche : ");
        scanf(" %[^\n]s", taches[nombreTaches].Description);

        printf("Entrez la date d'échéance de la tâche : ");
        scanf(" %[^\n]s", taches[nombreTaches].dateEcheance);
		
        printf("Entrez la priorité de la tâche (1 - Faible, 2 - Moyenne, 3 - Élevée) : ");
        scanf("%d", &taches[nombreTaches].priorite);

        return nombreTaches + 1;  // Retourne le nouveau nombre de tâches
    } else {
        printf("Votre choix est invalide, veuillez réessayer.\n");
        return nombreTaches;
    }
}

// Fonction pour afficher la liste des tâches
void afficherTaches(struct Tache taches[], int nombreTaches) {
    if (nombreTaches > 0) {
        printf("Liste des tâches :\n");
         int i;
        for (i = 0; i < nombreTaches; i++) {
            printf("Tâche %d :\n", i + 1);
            printf("Description : %s\n", taches[i].Description);
            printf("Date d'échéance : %s\n", taches[i].dateEcheance);
            printf("Priorité : %d\n", taches[i].priorite);
            printf("\n");
        }
    } else {
        printf("Aucune tâche n'est disponible.\n");
    }
}

// Fonction pour modifier une tâche
void modifierTache(struct Tache taches[], int nombreTaches) {
    int numeroTache;
    printf("Entrez le numéro de la tâche à modifier : ");
    scanf("%d", &numeroTache);

    if (numeroTache >= 1 && numeroTache <= nombreTaches) {
        // L'utilisateur doit entrer les nouvelles informations pour la tâche
        printf("Entrez la nouvelle description de la tâche : ");
        scanf(" %[^\n]s", taches[numeroTache - 1].Description);

        printf("Entrez la nouvelle date d'échéance de la tâche : ");
        scanf(" %[^\n]s", taches[numeroTache - 1].dateEcheance);

        printf("Entrez la nouvelle priorité de la tâche (1 - Faible, 2 - Moyenne, 3 - Élevée) : ");
        scanf("%d", &taches[numeroTache - 1].priorite);

        printf("La tâche a été modifiée avec succès.\n");
    } else {
        printf("Numéro de tâche invalide.\n");
    }
}

// Fonction pour supprimer une tâche


int main() {
    struct Tache taches[MAX_TASKS];
    int nombreTaches = 0;
    int choix;

    do {
        // Menu principal
        printf("\n1. Ajouter une tâche\n");
        printf("2. Afficher la liste des tâches\n");
        printf("3. Modifier une tâche\n");
        printf("4. Supprimer une tâche\n");
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
                printf("Choix invalide. Veuillez réessayer.\n");
        }

    } while (choix != 5);

    return 0;
}

