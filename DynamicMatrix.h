//
// Created by Luan Moreno on 17/12/2024.
//

#ifndef JARDIM_DE_STRINGS_MANIPULAR_STRINGS_H
#define JARDIM_DE_STRINGS_MANIPULAR_STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura de dados para guardar as strings
typedef struct {
    char **data; //ponteiro para matriz de strings
    int size; //Numero atual de strings na matriz
    int capacity; //Capacidade maxima da matriz
} DynamicMatrix;

//Estrutura de dados para guardar uma sequência de strings
typedef struct {
    char **sequence; //Array de strings
    int length; //Tamanho da sequência
} StringSequence;

//Estrutura de dados para guardar uma lista de sequências
typedef struct {
    StringSequence *sequences; //Array de sequências
    int size; //Número atual de sequências
    int capacity; //Capacidade máxima
} SequenceList;

//Funções para manipular a matriz dinâmica de strings
DynamicMatrix* createDynamicMatrix(int capacity);

//Função para redimensionar a matriz dinâmica de strings
void resizeDynamicMatrix(DynamicMatrix *matrix, int newCapacity);

//Função para adicionar uma string na matriz dinâmica
void addString(DynamicMatrix *matrix, char *string);

//Função para adicionar uma string aleatória na matriz dinâmica
void randomString(DynamicMatrix *matrix, int size);

//Função para fazer lista das strings da Matriz
void listStrings(DynamicMatrix *matrix);

//Função para remover uma string da matriz
void remove_string(DynamicMatrix *matrix, int index);

//Função para remover várias strings da matriz
void removeMultipleStrings(DynamicMatrix *matrix, int *indices, int count);


//Função para libertar memória alocada para a matriz
void freeMatrix(DynamicMatrix *matrix);

#endif //JARDIM_DE_STRINGS_MANIPULAR_STRINGS_H

