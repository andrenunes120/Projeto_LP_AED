//
// Created by Luan Moreno on 17/12/2024.
//

#ifndef JARDIM_DE_STRINGS_TESTE_H
#define JARDIM_DE_STRINGS_TESTE_H

//Bibliotecas
#include "DynamicMatrix.h"
#include "StringOperations.h"
#include <stdio.h>

//Funções de teste
DynamicMatrix *testAddString();
DynamicMatrix *testAddRandomString();
DynamicMatrix *testAddStringsFromFile(const char *filename);
void testRemoveMultipleStrings( DynamicMatrix *matrix);
void testSortStringsAlphabeticallyAscending(DynamicMatrix *matrix);
void testSortStringsAlphabeticallyDescending(DynamicMatrix *matrix);
void testSortStringsBySizeAscending(DynamicMatrix *matrix);
void testSortStringsBySizeDescending(DynamicMatrix *matrix);
void test_generate_sequences(DynamicMatrix *matrix);
#endif //JARDIM_DE_STRINGS_TESTE_H
