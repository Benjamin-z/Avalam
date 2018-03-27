# Avalam

Ce programme est un projet scolaire de L3 en Science du Numérique à l'Université de Bretagne Sud

## Règles du jeu

Le plateau est composé de 48 pièces et disposées en alternance de couleur. Il se joue à 2 joueurs.

Le but du jeu est d'empiler un pion sur une case proche possédant au moins 1 pièces et de former des tours de 1 à 5 pièces avec sa propre couleur en haut. Une tour devient inchangeable quand :
* elle possède 5 pions
* elle est isolée de toute autre tour

Les déplacements se font dans toutes les directions mais seulement sur une tour de 1 à 4 pions et la taille après empilement doit être entre 2 et 5.

La partie se termine quand plus aucun coups n'est possible. Le score se compte alors en fonction du nombre de tour possédé par le joueur. une tour de 5 compte pour 1 point comme une tour de 1. Le gagnant est celui qui a le plus de points.

Vous pouvez trouver des règles plus détaillées [ici](http://jeuxstrategie.free.fr/Avalam_complet.php).

## Compilation

Le projet est entièrement en C et compilé sous gcc.

### Linux

Pour compiler le projet, il suffit de lancer le script `compile.sh` situé dans le dossier `source` puis de lancer l’exécutable `avalam`.
