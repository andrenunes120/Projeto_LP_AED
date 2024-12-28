cmake_minimum_required(VERSION 3.29)
project(Projeto_LP_AED C)

set(CMAKE_C_STANDARD 17)

add_executable(Projeto_LP_AED main.c
        DynamicMatrix.c
        DynamicMatrix.h
        StringOperations.c
        StringOperations.h
        teste.c
        teste.h
)
