//
// Created by Luan Moreno on 17/12/2024.
//

#include "StringOperations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função para procurar strings que contém uma substring
void search_strings(DynamicMatrix *matrix, const char *substring) {
    printf("Pesquisando por strings que contêm: \"%s\"\n", substring);
    int found = 0;

    for (int i = 0; i < matrix->size; i++) {
        if (strstr(matrix->data[i], substring) != NULL) { // Verifica se a substring está presente
            printf("String %d: %s\n", i, matrix->data[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Nenhuma string encontrada contendo \"%s\".\n", substring);
    }
}

//Função para comparar strings alfabeticamente
int compareStringsAscending(const void *a, const void *b){
    return strcmp(*(char**)a, *(char**)b);
}
int compareStringsDescending(const void *a, const void *b){
    return strcmp(*(char**)b, *(char**)a);
}

//Função para ordenar strings alfabeticamente
void sortStringsAlphabeticallyAscending(DynamicMatrix *matrix){
    qsort(matrix->data, matrix->size, sizeof(char*), compareStringsAscending);
}
void sortStringsAlphabeticallyDescending(DynamicMatrix *matrix){
    qsort(matrix->data, matrix->size, sizeof(char*), compareStringsDescending);
}

//Função para comparar strings por tamanho
int compareStringsBySizeAscending(const void *a, const void *b){
    return strlen(*(char**)a) - strlen(*(char**)b);
}

int compareStringsBySizeDescending(const void *a, const void *b){
    return strlen(*(char**)b) - strlen(*(char**)a);
}

//Função para ordenar a matriz por tamanho das strings
void sortStringsBySizeAscending(DynamicMatrix *matrix){
    qsort(matrix->data, matrix->size, sizeof(char*), compareStringsBySizeAscending);
}
void sortStringsBySizeDescending(DynamicMatrix *matrix){
    qsort(matrix->data, matrix->size, sizeof(char*), compareStringsBySizeDescending);
}


// Helper function to compare strings by length (ascending order)
int compare_by_length(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strlen(str1) - strlen(str2);
}

// Function to generate all possible sequences of strings
void generate_sequences(DynamicMatrix *matrix) {
    // Step 1: Sort strings by length
    qsort(matrix->data, matrix->size, sizeof(char *), compare_by_length);

    int longest_sequence = 0;       // Track the length of the longest sequence
    int total_combinations = 0;    // Total number of valid sequences

    // Step 2: Dynamic array to store all sequences
    for (int start = 0; start < matrix->size; start++) {
        // Initialize a new sequence
        int sequence_length = 1;
        printf("  Sequence: %s", matrix->data[start]);

        // Build the sequence
        const char *current = matrix->data[start];
        for (int i = start + 1; i < matrix->size; i++) {
            // Check if current string grows into the next one
            if (strstr(matrix->data[i], current) != NULL) {
                current = matrix->data[i];
                sequence_length++;
                printf(" -> %s", current);
            }
        }

        // Update metrics
        total_combinations++;
        if (sequence_length > longest_sequence) {
            longest_sequence = sequence_length;
        }

        printf(" (Length: %d)\n", sequence_length);
    }

    // Step 3: Output results
    printf("\nTotal Combinations: %d\n", total_combinations);
    printf("Longest Sequence Length: %d\n", longest_sequence);
}
