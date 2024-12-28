//
// Created by Luan Moreno on 17/12/2024.
//

#include "teste.h"
#include <stdio.h>
#include <stdlib.h>
#include "DynamicMatrix.h"
#include "StringOperations.h"

//Teste para adicionar uma string na matriz
DynamicMatrix *testAddString(){
    printf("===== Teste addString =====\n");
    DynamicMatrix *matrix = createDynamicMatrix(5);
    addString(matrix, "claro");
    addString(matrix, "aro");
    addString(matrix, "faro");
    addString(matrix, "pifaro");
    addString(matrix, "pifa");
    addString(matrix, "ar");
    listStrings(matrix);
    return matrix;
}

DynamicMatrix* testAddRandomString(){
    printf("===== Teste addRandomString =====\n");
    DynamicMatrix *matrix = createDynamicMatrix(5);
    for (int i = 0; i < 30; ++i) {
        int stringlength = 3 + rand() % 3; //Tamanho da string aleatória de 3 a 5 chars
        randomString(matrix, stringlength);
    }
    if (matrix->size > 1){
        printf("Strings aleatórias adicionadas com sucesso\n");
    } else {
        printf("Erro ao adicionar strings aleatórias\n");
    }
    listStrings(matrix);
    return matrix;
}

DynamicMatrix* testAddStringsFromFile(const char* filename) {
    printf("===== Teste addStringsFromFile =====\n");

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    DynamicMatrix *matrix = createDynamicMatrix(5);
    if (matrix == NULL) {
        printf("Erro ao criar a matriz dinâmica\n");
        fclose(file);
        return NULL;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';

        // Add string to the matrix
        size_t previousSize = matrix->size; // Track the matrix size before adding
        addString(matrix, buffer);

        // Check if the size increased
        if (matrix->size == previousSize) {
            printf("Erro ao adicionar string à matriz: %s\n", buffer);
            fclose(file);
            free(matrix); // Free allocated memory for the matrix
            return NULL;
        }
    }

    if (ferror(file)) {
        printf("Erro ao ler o arquivo %s\n", filename);
        fclose(file);
        free(matrix); // Free allocated memory for the matrix
        return NULL;
    }

    fclose(file);

    printf("Strings adicionadas a partir do arquivo %s:\n", filename);
    listStrings(matrix);
    return matrix;
}



void testRemoveMultipleStrings(DynamicMatrix *matrix) {
    int indicesToRemove[] = {1, 3}; // Índices das strings a serem removidas
    removeMultipleStrings(matrix, indicesToRemove, 2);
    freeMatrix(matrix);
}

//Teste para ordenar strings alfabeticamente
void testSortStringsAlphabeticallyAscending(DynamicMatrix *matrix){
    printf("===== Teste sortStringsAlphabetically Ascending =====\n");
    sortStringsAlphabeticallyAscending(matrix);
    listStrings(matrix);
}
void testSortStringsAlphabeticallyDescending(DynamicMatrix *matrix){
    printf("===== Teste sortStringsAlphabetically Descending =====\n");
    sortStringsAlphabeticallyDescending(matrix);
    listStrings(matrix);
}

//Teste para ordenar strings por tamanho
void testSortStringsBySizeAscending(DynamicMatrix *matrix){
    printf("===== Teste sortStringsBySize Ascending =====\n");
    sortStringsBySizeAscending(matrix);
    listStrings(matrix);
}

void testSortStringsBySizeDescending(DynamicMatrix *matrix){
    printf("===== Teste sortStringsBySize Descending =====\n");
    sortStringsBySizeDescending(matrix);
    listStrings(matrix);
}

void test_generate_sequences(DynamicMatrix *matrix) {
    printf("=== Test: Generate Sequences ===\n");
    generate_sequences(matrix);
}