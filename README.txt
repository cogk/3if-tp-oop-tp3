UTILISATION DE NOTRE PROJET :

- Pour une utilisation classique :
    > 'make' crée l'exécutable ./exec
    > './build.sh' crée l'exécutable en forçant une recompilation complète
    > './run.sh' recompile et lance l'exécutable

- Pour une utilisation en mode debugage :
    > 'DEBUG=1 make -B' pour créer ./exec avec les flags de debug
    > Ou bien './debug.sh' pour faire la ligne d'au dessus puis immédiatement lancer valgrind

- Pour faire les tests (notamment de fuite mémoire) :
    > './test.sh' recompile et lance un ensemble de jeu de test avec valgrind
