//
// Created by Luan Moreno on 17/12/2024.
//

#include "DynamicMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Funções para manipular a matriz dinâmica de strings
DynamicMatrix* createDynamicMatrix(int capacity){
    DynamicMatrix *matrix = (DynamicMatrix*)malloc(sizeof(DynamicMatrix));
    if (!matrix){
        printf("Erro ao alocar memoria para a matriz dinamica\n");
        exit(1);
    }

    matrix->data = (char**)malloc(capacity * sizeof(char*));
    matrix->size = 0;
    matrix->capacity = capacity;
    return matrix;
}


//Função para redimensionar a matriz dinâmica de strings
void resizeDynamicMatrix(DynamicMatrix *matrix, int newCapacity){
    matrix->data = (char**)realloc(matrix->data, newCapacity * sizeof(char*));
    matrix->capacity = newCapacity;
}

//Função para adicionar uma string na matriz dinâmica
void addString(DynamicMatrix *matrix, char *string){
    //Verifica se a matriz está cheia
    if (matrix->size == matrix->capacity){
        resizeDynamicMatrix(matrix, matrix->capacity * 2);
    }

    //Alocar memória para a nova string
    matrix->data[matrix->size] = strdup(string);
    matrix->size++;
}

void randomString(DynamicMatrix *matrix, int size) {
    // Seed the random number generator only once
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }

    // Allocate memory for the random string
    char *string = (char *)malloc((size + 1) * sizeof(char));
    if (!string) {
        printf("Erro ao alocar memória para a string.\n");
        return;
    }

    // Generate random characters
    for (int i = 0; i < size; ++i) {
        string[i] = 'a' + rand() % 26; // Letras de 'a' a 'z'
        //string[i] = 'A' + rand() % 26; // Letras de 'A' a 'Z'
    }
    string[size] = '\0'; // Null-terminate the string

    // Add the string to the matrix
    addString(matrix, string);

    // Free local memory if addString doesn't take ownership (validate behavior)
    free(string);
}

//Função para fazer lista das strings da Matriz
void listStrings(DynamicMatrix *matrix){
    printf("Strings na matriz:\n");
    for (int i = 0; i < matrix->size; ++i) {
        printf("%d : %s\n", i, matrix->data[i]);
    }
}

//Função Remover String da matriz
void remove_string(DynamicMatrix *matrix, int index) {
    printf("===== Teste removeString =====\n");
    if (index < 0 || index >= matrix->size) {
        printf("Índice inválido para remoção.\n");
        return;
    }
    free(matrix->data[index]); // Libera memória da string removida

    for (int i = index; i < matrix->size - 1; i++) {
        matrix->data[i] = matrix->data[i + 1]; // Desloca elementos subsequentes
    }

    matrix->size--; // Atualiza o tamanho da matriz
    listStrings(matrix);
}

void removeMultipleStrings(DynamicMatrix *matrix, int *indices, int count) {
    printf("===== Teste removeMultipleStrings =====\n");
    for (int i = 0; i < count; ++i) {
        int index = indices[i] - i; // Ajusta o índice para compensar as remoções anteriores
        if (index < 0 || index >= matrix->size) {
            printf("Índice inválido: %d\n", indices[i]);
            continue;
        }
        free(matrix->data[index]); // Libera memória da string removida
        for (int j = index; j < matrix->size - 1; ++j) {
            matrix->data[j] = matrix->data[j + 1]; // Desloca elementos subsequentes
        }
        matrix->size--; // Atualiza o tamanho da matriz
    }
    listStrings(matrix);
}



//Função para libertar memória alocada para a matriz
void freeMatrix(DynamicMatrix *matrix){
    for (int i = 0; i < matrix->size; ++i) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}