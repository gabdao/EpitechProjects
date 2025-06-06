# Count Island

## Description

Programme C implémentant un algorithme de détection et comptage d'îles dans une grille 2D. Le système analyse un tableau de caractères pour identifier les îles formées par des 'X' connectés et les numéroter séquentiellement.

## Objectif

Implémenter une fonction `count_island` qui doit :
- Scanner une grille 2D contenant des '.' (eau) et des 'X' (terre)
- Identifier les îles formées par des 'X' connectés
- Remplacer chaque 'X' par le numéro de son île (commençant à 0)
- Retourner le nombre total d'îles trouvées

### Règles de connexion

Deux caractères sont connectés s'ils sont :
- Contigus sur la même ligne (horizontalement)
- Dans la même colonne sur des lignes contiguës (verticalement)

## Contraintes

- Langage : C
- Utilisation de la récursion obligatoire
- Maximum 10 îles par grille
- Traitement ligne par ligne dans l'ordre d'apparition
