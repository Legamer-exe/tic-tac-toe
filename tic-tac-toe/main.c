#include <stdio.h>

char plateau[3][3];
char joueur_actuel = 'X';

void initialiser_plateau() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plateau[i][j] = '1' + (i * 3 + j);
        }
    }
}

void afficher_plateau() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", plateau[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int verifier_gagnant() {
    for (int i = 0; i < 3; i++) {
        if ((plateau[i][0] == plateau[i][1] && plateau[i][1] == plateau[i][2]) ||
            (plateau[0][i] == plateau[1][i] && plateau[1][i] == plateau[2][i])) {
            return 1;
        }
    }
    if ((plateau[0][0] == plateau[1][1] && plateau[1][1] == plateau[2][2]) ||
        (plateau[0][2] == plateau[1][1] && plateau[1][1] == plateau[2][0])) {
        return 1;
    }
    return 0;
}

int est_rempli() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (plateau[i][j] != 'X' && plateau[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

void changer_joueur() {
    joueur_actuel = (joueur_actuel == 'X') ? 'O' : 'X';
}

int faire_coup(int position) {
    int ligne = (position - 1) / 3;
    int colonne = (position - 1) % 3;

    if (plateau[ligne][colonne] != 'X' && plateau[ligne][colonne] != 'O') {
        plateau[ligne][colonne] = joueur_actuel;
        return 1;
    }
    return 0;
}

int main() {
    int position;

    initialiser_plateau();

    while (1) {
        afficher_plateau();
        printf("Joueur %c, entrez votre coup (1-9) : ", joueur_actuel);
        scanf("%d", &position);

        if (position < 1 || position > 9 || !faire_coup(position)) {
            printf("Coup invalide ! Réessayez.\n");
            continue;
        }

        if (verifier_gagnant()) {
            afficher_plateau();
            printf("Le joueur %c a gagné !\n", joueur_actuel);
            break;
        }

        if (est_rempli()) {
            afficher_plateau();
            printf("C'est un match nul !\n");
            break;
        }

        changer_joueur();
    }

    return 0;
}