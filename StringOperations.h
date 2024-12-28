//
// Created by Luan Moreno on 17/12/2024.
//

#ifndef JARDIM_DE_STRINGS_STRINGOPERATIONS_H
#define JARDIM_DE_STRINGS_STRINGOPERATIONS_H

#include "DynamicMatrix.h"

//Função para procurar strings que contém uma substring
void search_strings(DynamicMatrix *matrix, const char *substring);

//Função para comparar strings alfabeticamente
int compareStringsAscending(const void *a, const void *b);
int compareStringsDescending(const void *a, const void *b);

//Função para ordenar strings alfabeticamente
void sortStringsAlphabeticallyAscending(DynamicMatrix *matrix);
void sortStringsAlphabeticallyDescending(DynamicMatrix *matrix);

//Função para comparar strings por tamanho
int compareStringsBySizeAscending(const void *a, const void *b);
int compareStringsBySizeDescending(const void *a, const void *b);


//Função para ordenar a matriz por tamanho das strings
void sortStringsBySizeAscending(DynamicMatrix *matrix);
void sortStringsBySizeDescending(DynamicMatrix *matrix);

void generate_sequences(DynamicMatrix *matrix);

#endif //JARDIM_DE_STRINGS_STRINGOPERATIONS_H
