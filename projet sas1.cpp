
#include <stdio.h>
#include <stdlib.h>


#define MAX_TASKS 100


// Structure pour stocker les informations de chaque tâche
//DECLARATION  & REATION DES STRUCTURES
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
// Fonction pour ajouter une  tâche

int ajouterTache(struct Tache taches[], int nombreTaches) {
    if (nombreTaches < MAX_TASKS) {
        printf("Entrez la description de la tache : ");
        scanf("%s", taches[nombreTaches].Description);

        printf("Entrez la date d'echeance de la tache : ");
        scanf("%s", taches[nombreTaches].dateEcheance);

        printf("Entrez la priorite de la tache (1 - Faible, 2 - Moyenne, 3 - Elevee) : ");
        scanf("%d", &taches[nombreTaches].priorite);

        return nombreTaches + 1;  // Retourne le nouveau nombre de tâches
    } else {
        printf("Impossible d'ajouter plus de taches, la limite est atteinte.\n");
        return nombreTaches;
    }
}
//Fonction pour afficher une tache

void afficherTache( Tache taches[], int nombreTaches) {
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
//Fonction pour modifier une tache

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
        printf("Numero de tache invalide.\n");
    }
}

// Fonction pour supprimer une tâche
int supprimerTache(struct Tache taches[], int nombreTaches) {
    int index;

    printf("Entrez le numero de la tache a supprimer : ");
    scanf("%d", &index);

    if (index >= 1 && index <= nombreTaches) {
        // Décaler les tâches suivantes vers la gauche pour remplir l'emplacement supprimé
        for (int i = index - 1; i < nombreTaches - 1; i++) {
            taches[i] = taches[i + 1];
        }

        // Décrémentation et retourne le nouveau nombre de tâches
        return nombreTaches - 1;

    } else {
        printf("Numero de tache invalide.\n");
        return nombreTaches;
    }
}

// Fonction pour filtrer une tâche
void filtrerTachesParPriorite(Tache taches[], int nombreTaches,int priorite) {
    printf("Taches avec priorite %d:\n", priorite);

    for (int i = 0; i < nombreTaches; i++) {
        if (taches[i].priorite == priorite) {
            printf("Tache %d:\n", i + 1);
            printf("la Description: %s\n", taches[i].Description);
            printf("la dateEcheance: %s\n", taches[i].dateEcheance);
            printf("la priorite: %d\n", taches[i].priorite);
            printf("\n");
        }
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
        printf("2. Afficher une tache.\n");
        printf("3. Modifier une tache.\n");
        printf("4. Supprimer une tache.\n");
        printf("5.Filtrer une tache.\n");
        printf("6. Quitter.\n");
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
            nombreTaches = supprimerTache(taches, nombreTaches);
            break;
        case 5:
        int priorite;
            printf("Entrez la priorite pour filtrer : ");
            scanf("%d", &priorite);
            filtrerTachesParPriorite(taches, nombreTaches, priorite);
            break;
        case 6:
            printf("Au revoir!\n");
            break;
        default:
            printf("Votre choix est invalide, veuillez ressayer.\n");
            break;
        }
    } while (choix != 6);

    return 0;
}


