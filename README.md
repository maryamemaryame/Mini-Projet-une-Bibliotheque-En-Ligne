Voici un fichier README.md pour votre projet de gestion de bibliothèque écrit en C. Cela aidera les utilisateurs à comprendre le projet et à l'utiliser.
# Système de Gestion de Bibliothèque en ligne 
Ce projet est un système de gestion de bibliothèque en ligne de commande écrit en C. Le système permet de gérer les livres et les membres, et prend en charge des opérations telles que l'ajout de nouveaux livres, l'ajout de nouveaux membres, l'emprunt de livres, la liste de tous les livres et la liste de tous les membres.

Voici un fichier README.md pour votre projet de gestion de bibliothèque écrit en C. Cela aidera les utilisateurs à comprendre le projet et à l'utiliser.

markdown
Copier le code
# Système de Gestion de Bibliothèque

Ce projet est un système de gestion de bibliothèque en ligne de commande écrit en C. Le système permet de gérer les livres et les membres, et prend en charge des opérations telles que l'ajout de nouveaux livres, l'ajout de nouveaux membres, l'emprunt de livres, la liste de tous les livres et la liste de tous les membres.

### Utilisation
À l'exécution du programme, un menu avec plusieurs options vous sera présenté :

**Introduction** : Affiche une introduction au système de gestion de bibliothèque.
**Ajouter un Nouveau Livre** : Vous invite à entrer les détails d'un nouveau livre à ajouter à la bibliothèque.
**Ajouter un Nouveau Membre** : Vous invite à entrer les détails d'un nouveau membre à enregistrer dans la bibliothèque.
**Emprunter un Livre** : Permet à un membre d'emprunter un livre en entrant le code du livre et les détails du membre.
**Liste des Livres** : Affiche une liste de tous les livres disponibles dans la bibliothèque.
**Liste des Membres** : Affiche une liste de tous les membres inscrits.
**Modifier un Livre** : Permet de modifier les détails d'un livre existant en entrant le code du livre.
**Quitter** : Quitte l'application.

 ### Structure du Code
Les principales structures de données utilisées sont :

**Livre** : Contient les détails d'un livre tels que le code, le titre, l'auteur, le prix, les copies disponibles, le statut de disponibilité et la catégorie.
**Membre** : Contient les détails d'un membre tels que le nom, le numéro de téléphone, l'adresse, le CNI et le livre emprunté.

## Fonctions

- `introduction()` : Affiche une introduction au système.
- `ajouterLivre()` : Ajoute un nouveau livre à la bibliothèque.
- `ajouterMembre()` : Ajoute un nouveau membre à la bibliothèque.
- `emprunterLivre()` : Permet à un membre d'emprunter un livre.
- `listeLivres()` : Affiche tous les livres dans la bibliothèque.
- `listeMembres()` : Affiche tous les membres dans la bibliothèque.
- `modifierLivre()` : Modifie les détails d'un livre existant.
- `quitter()` : Quitte l'application.
- `setConsoleColor(int color)` : Définit la couleur du texte de la console (spécifique à Windows).
- `resetConsoleColor()` : Réinitialise la couleur du texte de la console à la valeur par défaut (spécifique à Windows).

### Prérequis

- Un compilateur C (par exemple, GCC)
- Un système d'exploitation Windows (le programme utilise des en-têtes et des fonctions spécifiques à Windows)

### Remarques
** Le programme est conçu pour fonctionner sous Windows en raison de l'utilisation des en-têtes et des fonctions spécifiques à Windows telles que windows.h et les paramètres de couleur de la console.
** Le nombre maximum de livres et de membres est défini par MAX_MEMBRES et MAX_LIVRES, tous deux fixés à 100.

