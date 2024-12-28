#include <stdio.h>
#include "teste.h"
#include "StringOperations.h"

int main(void) {
    printf("===== INÍCIO DOS TESTES =====\n");

    //DynamicMatrix *matrix = testAddString();

    //DynamicMatrix *matrix = testAddRandomString();

    DynamicMatrix *matrix = testAddStringsFromFile("strings.txt");

    //remove_string(matrix, 2);

    //testRemoveMultipleStrings(matrix);

    //testSortStringsAlphabeticallyAscending(matrix);
    //testSortStringsAlphabeticallyDescending(matrix);

    //testSortStringsBySizeAscending(matrix);
    //testSortStringsBySizeDescending(matrix);

    //search_strings(matrix, "ac");

    //Função para testar combinações de strings

    //test_generate_sequences(matrix);


    freeMatrix(matrix);

    printf("===== FIM DOS TESTES =====\n");
    return 0;
}
