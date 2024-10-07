#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//To do list: 
// Simuler le comportement des fonctions malloc() et free() pour gérer l'allocation et la libération de blocs de mémoire :
// void* simulerMalloc(size_t taille)
// void simulerFree(void* ptr)

// L'alignement de la mémoire signifie que les blocs de mémoire alloués 
// doivent être alignés à certaines adresses spécifiques, généralement en fonction de la taille des données stockées



/*
Utiliser une liste chaînée pour représenter les blocs de mémoire,
où chaque nœud représente un bloc avec des informations telles
que la taille, l'état (alloué ou libre), et un pointeur vers le bloc
suivant.
▪ Implémenter une structure struct BlocMemoire avec des champs
pour la taille, l'état, et un pointeur vers le bloc suivant.
▪ Implémenter des fonctions pour ajouter, supprimer, et fusionner
des blocs dans la liste.

*/

void functionhelloword(){
    printf("Hello, World!\n");
}


struct BlocMemoire {
    size_t taille;
    bool etat;
    struct BlocMemoire* suivant;
} BlocMemoire; ; 


void mallocSimuler(size_t taille) {
    struct BlocMemoire* bloc = (struct BlocMemoire*)malloc(sizeof(struct BlocMemoire));
    bloc->taille = taille;
    bloc->etat = 1;
    bloc->suivant = NULL;
}

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    functionhelloword();
    printf("Hello, World!\n");
    return 0;
}