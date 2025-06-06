Count Words
Description
Programme C qui analyse une chaîne de caractères passée en paramètre et affiche le nombre d'occurrences de chaque mot sur une ligne séparée.
Objectif
Implémenter un programme countwords qui doit :

Prendre une chaîne de caractères en paramètre
Compter les occurrences de chaque mot unique
Afficher les résultats dans l'ordre d'apparition des mots
Gérer les séparateurs (espaces et tabulations)
Afficher uniquement un \n si aucun paramètre n'est fourni

Règles de traitement

Les mots sont des chaînes séparées par des espaces ou des tabulations
L'ordre d'affichage suit l'ordre de première apparition dans la chaîne
Format de sortie : mot: nombre_occurrences

Contraintes

Langage : C
Fonctions autorisées : write, malloc, free, printf
Compilation via Makefile avec règles re, clean, fclean
Code d'erreur 84 en cas d'erreur, 0 sinon
Messages d'erreur sur la sortie d'erreur
