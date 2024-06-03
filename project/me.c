#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_MEMBRES 100
#define MAX_LIVRES 100

typedef struct Livre {
    int code;
    char titre[50];
    char auteur[50];
    float prix;
    int copies;
    int disponible;  // 1 pour disponible, 0 pour non disponible
    char categorie[20];
    struct Livre *suivant;
} Livre;

typedef struct Membre {
    char nom[50];
    int phone;
    char adresse[50];
    char CNI[10];
    char livreEmprunte[50];
} Membre;
void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

Livre *livres = NULL;
int nbLivres = 0;

Membre membres[MAX_MEMBRES];
int nbMembres = 0;

void introduction() {
    setConsoleColor(FOREGROUND_RED);
    printf("\n\t\t\t\t\t*************************************************\n");
    printf("\n\t\t\t\t\t*                                               *\n");
	printf("\n\t\t\t\t\t*       Bienvenue dans la Bibliotheque          *\n");
    printf("\n\t\t\t\t\t*                                               *\n");
    printf("\n\t\t\t\t\t*************************************************\n");
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN); 
    printf("\n\t\t\t************************************************************************************************\n");
    printf("\n\t\t\t*\tCe projet offre la possibilite de gerer les enregistrements des LIVRES et des MEMBRES. *\n");
    printf("\n\t\t\t*Il peut stocker plus de 10 000 enregistrements de livres.                                     *\n");
    printf("\n\t\t\t*\tUn membre peut emprunter un livre à la fois. S'il/elle ne retourne pas le livre dans   *\n");
    printf("\n\t\t\t*les 15 jours, une amende de 2 dh par jour sera appliquee.                                     *\n");
    printf("\n\t\t\t************************************************************************************************\n");
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void ajouterLivre() {
    char choix;
    do {
        if (nbLivres >= MAX_LIVRES) {
            printf("La capacite maximale des livres est atteinte.\n");
            return;
        }
        setConsoleColor(FOREGROUND_RED);
    printf("\n\t\t\t\t\t*************************************************\n");
    printf("\n\t\t\t\t\t*                                               *\n");
	printf("\n\t\t\t\t\t*            AJOUT LIVRE                        *\n");
    printf("\n\t\t\t\t\t*                                               *\n");
    printf("\n\t\t\t\t\t*************************************************\n");
        Livre *nouveauLivre = (Livre *)malloc(sizeof(Livre));
        setConsoleColor(FOREGROUND_GREEN);
        printf("\n\t\t\t\t\t\t*********************************************************************************************\n");
        printf("\n\t\t\t\t\t\tLe code : ");
        scanf("%d", &nouveauLivre->code);
        printf("\n\t\t\t\t\t\t*********************************************************************************************\n");
        printf("\n\t\t\t\t\t\tLe titre : ");
        getchar();  // Pour consommer le '\n' laissé par le précédent scanf
        fgets(nouveauLivre->titre, sizeof(nouveauLivre->titre), stdin);
        nouveauLivre->titre[strcspn(nouveauLivre->titre, "\n")] = '\0';
        printf("\n\t\t\t\t\t\t*********************************************************************************************\n");
        printf("\n\t\t\t\t\t\tL'auteur : ");
        fgets(nouveauLivre->auteur, sizeof(nouveauLivre->auteur), stdin);
        nouveauLivre->auteur[strcspn(nouveauLivre->auteur, "\n")] = '\0';
        printf("\n\t\t\t\t\t\t*********************************************************************************************\n");
        printf("\n\t\t\t\t\t\tLe prix : ");
        scanf("%f", &nouveauLivre->prix);
        printf("\n\t\t\t\t\t\t*********************************************************************************************\n");
        printf("\n\t\t\t\t\t\tNombre de copies : ");
        scanf("%d", &nouveauLivre->copies);

        nouveauLivre->disponible = nouveauLivre->copies > 0 ? 1 : 0;
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\n On a 4 classes de livres dans cette bibliotheque. Choisissez parmi les suivants : ");
        printf("\n1. Scientifique");
        printf("\n2. Litteral");
        printf("\n3. Economique");
        printf("\n4. Autre\n");
        int nb;
        scanf("%d", &nb);

        switch (nb) {
            case 1:
                strcpy(nouveauLivre->categorie, "scientifique");
                break;
            case 2:
                strcpy(nouveauLivre->categorie, "litteral");
                break;
            case 3:
                strcpy(nouveauLivre->categorie, "economique");
                break;
            case 4:
                strcpy(nouveauLivre->categorie, "autre");
                break;
            default:
                printf("Option invalide !\n");
                free(nouveauLivre);
                return;
        }

        nouveauLivre->suivant = livres;
        livres = nouveauLivre;
        nbLivres++;
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN);
        printf("\n\t\t\t\t\t\tLivre ajoute avec succes.\n");
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("Voulez-vous ajouter un autre livre ? (Y/n) : ");
        scanf(" %c", &choix);

    } while (choix == 'Y' || choix == 'y');
}

void ajouterMembre() {
	setConsoleColor(FOREGROUND_RED);
    printf("\n\t\t\t\t\t*************************************************\n");
    printf("\n\t\t\t\t\t*                                               *\n");
	printf("\n\t\t\t\t\t*            AJOUT MEMBRE                       *\n");
    printf("\n\t\t\t\t\t*                                               *\n");
    printf("\n\t\t\t\t\t*************************************************\n");
	setConsoleColor(FOREGROUND_BLUE);
    if (nbMembres >= MAX_MEMBRES) {
        printf("\nLa capacite maximale des membres est atteinte.\n");
        return;
    }
    setConsoleColor(FOREGROUND_BLUE);
    printf("\n\t\t\t\t\t\t*************************");
    printf("\n\t\t\t\t\t\tNom : ");
    getchar();  // Pour consommer le '\n' laissé par le précédent scanf
    fgets(membres[nbMembres].nom, sizeof(membres[nbMembres].nom), stdin);
    membres[nbMembres].nom[strcspn(membres[nbMembres].nom, "\n")] = '\0';
    
	printf("\n\t\t\t\t\t\t*************************");
    printf("\n\t\t\t\t\t\tAdresse : ");
    fgets(membres[nbMembres].adresse, sizeof(membres[nbMembres].adresse), stdin);
    membres[nbMembres].adresse[strcspn(membres[nbMembres].adresse, "\n")] = '\0';

    printf("\n\t\t\t\t\t\t*************************");
    printf("\n\t\t\t\t\t\tNumero de telephone : ");
    scanf("%d", &membres[nbMembres].phone);

    printf("\n\t\t\t\t\t\t*************************");
    printf("\n\t\t\t\t\t\tCNI : ");
    getchar();  // Pour consommer le '\n' laissé par le précédent scanf
    fgets(membres[nbMembres].CNI, sizeof(membres[nbMembres].CNI), stdin);
    membres[nbMembres].CNI[strcspn(membres[nbMembres].CNI, "\n")] = '\0';

    strcpy(membres[nbMembres].livreEmprunte, ""); // Initialise le champ livreEmprunte à vide

    nbMembres++;
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void emprunterLivre() {
    setConsoleColor(FOREGROUND_RED);
    printf("\n\t\t\t\t\t*************************************************\n");
    printf("\n\t\t\t\t\t*                                               *\n");
    printf("\n\t\t\t\t\t*             EMPRUNTE LIVRE                    *\n");
    printf("\n\t\t\t\t\t*                                               *\n");
    printf("\n\t\t\t\t\t*************************************************\n");
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    if (nbLivres == 0) {
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN); // Jaune
        printf("\n******Aucun livre disponible pour emprunter.******\n");
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        return;
    }

    int code;
    setConsoleColor(FOREGROUND_BLUE);
    
    printf("\n\t\t\t\t\t\tEntrer le code du livre a emprunter : ");
    scanf("%d", &code);
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    Livre *actuel = livres;
    while (actuel != NULL) {
        if (actuel->code == code) {
            if (actuel->copies > 0) {
                actuel->copies--;
                actuel->disponible = (actuel->copies > 0) ? 1 : 0;
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN); // Jaune
                printf("\nLivre emprunte avec succes.\n");
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                // Demande les informations du membre
                if (nbMembres >= MAX_MEMBRES) {
                    setConsoleColor(FOREGROUND_BLUE);
                    printf("**********\nLa capacite maximale des membres est atteinte. Le livre ne peut pas etre emprunte.***********\n");
                    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    return;
                }

                setConsoleColor(FOREGROUND_BLUE);
                char cni[10];
                printf("\n\t\t\t\t\t\t*************************************************************");
                printf("\n\t\t\t\t\t\t* Entrez le CNI du membre : ");
                getchar();  // Pour consommer le '\n' laissé par le précédent scanf
                fgets(cni, sizeof(cni), stdin);
                cni[strcspn(cni, "\n")] = '\0';
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                int i;
                int membreTrouve = 0;
                for (i = 0; i < nbMembres; i++) {
                    if (strcmp(membres[i].CNI, cni) == 0) {
                        strcpy(membres[i].livreEmprunte, actuel->titre);
                        membreTrouve = 1;
                        break;
                        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }

                if (!membreTrouve) {
                    printf("\n\t\t\t\t\t\t*************Entrez les informations du membre:*************\n");
                    printf("\n\t\t\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t\t\tNom : ");
                    getchar();  // Pour consommer le '\n' laissé par le précédent scanf
                    fgets(membres[nbMembres].nom, sizeof(membres[nbMembres].nom), stdin);
                    membres[nbMembres].nom[strcspn(membres[nbMembres].nom, "\n")] = '\0';
                    printf("\n\t\t\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t\t\tAdresse : ");
                    fgets(membres[nbMembres].adresse, sizeof(membres[nbMembres].adresse), stdin);
                    membres[nbMembres].adresse[strcspn(membres[nbMembres].adresse, "\n")] = '\0';
                    printf("\n\t\t\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t\t\tNumero de telephone : ");
                    scanf("%d", &membres[nbMembres].phone);

                    strcpy(membres[nbMembres].CNI, cni);

                    strcpy(membres[nbMembres].livreEmprunte, actuel->titre);

                    nbMembres++;
                    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }

                return;
            } else {
                setConsoleColor(FOREGROUND_RED);
                printf("\n-->Livre non disponible.\n");
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                return;
            }
        }
        actuel = actuel->suivant;
    }
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\n-->Livre introuvable.\n");
}

void listeLivres() {
	printf("\n\t\t\t\t\t*************************************************\n");
    printf("\n\t\t\t\t\t*                                               *\n");
	printf("\n\t\t\t\t\t*             LISTE DE LIVRES                   *\n");
    printf("\n\t\t\t\t\t*                                               *\n");
    printf("\n\t\t\t\t\t*************************************************\n");
    system("cls");  // Efface l'écran pour un bon affichage
    if (nbLivres == 0) {
        printf("Aucun livre dans la bibliotheque.\n");
        return;
    }
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN);
    printf("\nListe des livres:\n");
    printf("| CODE    | Titre                    | Auteur                   | Prix    | Disponible | Categorie   | Copies |\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    Livre *actuel = livres;
    while (actuel != NULL) {
        printf("| %-7d | %-24s | %-23s | %-7.2f | %-10s | %-11s | %-6d |\n",
               actuel->code, actuel->titre, actuel->auteur, actuel->prix, 
               actuel->disponible ? "Oui" : "Non", actuel->categorie, actuel->copies);
        actuel = actuel->suivant;
    }
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void listeMembres() {
	setConsoleColor(FOREGROUND_RED);
	printf("\n\t\t\t\t\t*************************************************\n");
    printf("\n\t\t\t\t\t*                                               *\n");
	printf("\n\t\t\t\t\t*             LISTE DE MEMBRES                  *\n");
    printf("\n\t\t\t\t\t*                                               *\n");
    printf("\n\t\t\t\t\t*************************************************\n");
    system("cls");  // Efface l'écran pour un bon affichage
    if (nbMembres == 0) {
        printf("Aucun membre dans la bibliotheque.\n");
        return;
    }
	int i;
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN); // Jaune
    for ( i = 0; i < nbMembres; i++) {
    	
    	printf("+******************************************************************************************************************************************************************************+\n");
        printf("Nom: %s---> Adresse: %s--> Numero de telephone: %d--> CNI: %s--> Livre Emprunte: %s                                                                                           \n",
               membres[i].nom, membres[i].adresse, membres[i].phone, membres[i].CNI, 
               membres[i].livreEmprunte[0] != '\0' ? membres[i].livreEmprunte : "Aucun");
        printf("+******************************************************************************************************************************************************************************+\n");
    }
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void resetConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void modifierLivre() {
    int code;
    setConsoleColor(FOREGROUND_RED);
    printf("\n\t\t\t\t\t*************************************************\n");
    printf("\n\t\t\t\t\t*                                               *\n");
    printf("\n\t\t\t\t\t*             MODIFIE LIVRE                     *\n");
    printf("\n\t\t\t\t\t*                                               *\n");
    printf("\n\t\t\t\t\t*************************************************\n");
    resetConsoleColor();

    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN); // Jaune
    printf("Entrer le code de votre livre : ");
    scanf("%d", &code);
    resetConsoleColor();

    Livre *actuel = livres;
    setConsoleColor(FOREGROUND_BLUE);
    while (actuel != NULL) {
        if (actuel->code == code) {
            printf("\n\t\t\t\t\t\t*************************************************************");
            printf("\n\t\t\t\t\t\tLe code : ");
            scanf("%d", &actuel->code);
            printf("\n\t\t\t\t\t\t*************************************************************");
            printf("\n\t\t\t\t\t\tLe titre : ");
            getchar();  // Pour consommer le '\n' laissé par le précédent scanf
            fgets(actuel->titre, sizeof(actuel->titre), stdin);
            actuel->titre[strcspn(actuel->titre, "\n")] = '\0';
            printf("\n\t\t\t\t\t\t*************************************************************");
            printf("\n\t\t\t\t\t\tL'auteur : ");
            fgets(actuel->auteur, sizeof(actuel->auteur), stdin);
            actuel->auteur[strcspn(actuel->auteur, "\n")] = '\0';
            printf("\n\t\t\t\t\t\t*************************************************************");
            printf("\n\t\t\t\t\t\tLe prix : ");
            scanf("%f", &actuel->prix);
            printf("\n\t\t\t\t\t\t*************************************************************");
            printf("\n\t\t\t\t\t\tNombre de copies : ");
            scanf("%d", &actuel->copies);

            actuel->disponible = (actuel->copies > 0) ? 1 : 0;

            resetConsoleColor();
            return;
        }
        actuel = actuel->suivant;
    }
    resetConsoleColor();
    printf("\nLivre introuvable.\n");
    resetConsoleColor();
}

void quitter() {
    exit(0);
}

int main() {
    int choix;
    do {
        printf("\n");
        
        printf("\n\t\t\t\t\t\t\tBibliotheque");
        printf("\n\t\t\t\t\t\t\t************");
        printf("\n\t\t\t\t\t\t|*****************************|");
        printf("\n\t\t\t\t\t\t| 1. Introduction             | ");         
        printf("\n\t\t\t\t\t\t|*****************************|");
        printf("\n\t\t\t\t\t\t| 2. Ajouter un nouveau livre |");
        printf("\n\t\t\t\t\t\t|*****************************|");
        printf("\n\t\t\t\t\t\t| 3. Ajouter un nouveau membre|");
        printf("\n\t\t\t\t\t\t|*****************************|");
        printf("\n\t\t\t\t\t\t| 4. Emprunter un livre       | ");
        printf("\n\t\t\t\t\t\t|*****************************|");
        printf("\n\t\t\t\t\t\t| 5. Liste des livres         | ");
        printf("\n\t\t\t\t\t\t|*****************************|");
        printf("\n\t\t\t\t\t\t| 6. Liste des membres        | ");
        printf("\n\t\t\t\t\t\t|*****************************|");
        printf("\n\t\t\t\t\t\t| 7. Modifier                 | ");
        printf("\n\t\t\t\t\t\t|*****************************|");
        printf("\n\t\t\t\t\t\t| 8. Quitter                  | ");
        printf("\n\t\t\t\t\t\t|*****************************|");
        printf("\n\n\t\t\t\t\t\t Entrez votre choix : ");
        scanf("%d", &choix);
        

        switch (choix) {
            case 1:
                introduction();
                break;
            case 2:
                ajouterLivre();
                break;
            case 3:
                ajouterMembre();
                break;
            case 4:
                emprunterLivre();
                break;
            case 5:
                listeLivres();
                break;
            case 6:
                listeMembres();
                break;
            case 7:
                modifierLivre();
                break;
            case 8:
                quitter();
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 8);

    return 0;
}

