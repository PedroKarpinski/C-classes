#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct Matriz {
    double** array;
    int rows;
    int cols;
};

Matriz* matriz_create(int rows, int cols) {
    Matriz* matriz = malloc(sizeof(Matriz));

    matriz->array = malloc(sizeof(double*) * rows);
    for (int i = 0; i < rows; i++) {
        matriz->array[i] = malloc(sizeof(double) * cols);
    }
    matriz->rows = rows;
    matriz->cols = cols;

    return matriz;
}

void matriz_destroy(Matriz* matriz) {
    for (int i = 0; i < matriz->rows; i++) {
        free(matriz->array[i]);
    }
    free(matriz->array);
    free(matriz);
}

void matriz_print(Matriz* matriz) {
    for (int i = 0; i < matriz->rows; i++) {
        for (int j = 0; j < matriz->cols; j++) {
            printf("%.4f ", matriz->array[i][j]);
        }
        printf("\n");
    }
}

double matriz_get(Matriz* matriz, int row, int col) {
    return matriz->array[row][col];
}

void matriz_set(Matriz* matriz, int row, int col, double value) {
    matriz->array[row][col] = value;
}

int matriz_rows(Matriz* matriz) {
    return matriz->rows;
}

int matriz_cols(Matriz* matriz) {
    return matriz->cols;
}

bool matriz_equals(Matriz* matriz1, Matriz* matriz2) {
    if (matriz1->rows != matriz2->rows || matriz1->cols != matriz2->cols) {
        return false;
    }

    for (int i = 0; i < matriz1->rows; i++) {
        for (int j = 0; j < matriz1->cols; j++) {
            if (matriz1->array[i][j] != matriz2->array[i][j]) {
                return false;
            }
        }
    }

    return true;
}

Matriz* matriz_add(Matriz* matriz1, Matriz* matriz2) {
    int rows, cols;
    if (matriz1->rows > matriz2->rows)
        rows = matriz_rows(matriz1);
    else
        rows = matriz_rows(matriz2);
    if (matriz1->cols > matriz2->cols)
        cols = matriz_cols(matriz1);
    else
        cols = matriz_cols(matriz2);

    Matriz* temp = matriz_create(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp->array[i][j] = matriz1->array[i][j] + matriz2->array[i][j];
            
    return temp;   
}

Matriz* matriz_sub(Matriz* matriz1, Matriz* matriz2) {
    int rows, cols;
    if (matriz1->rows > matriz2->rows)
        rows = matriz_rows(matriz1);
    else
        rows = matriz_rows(matriz2);
    if (matriz1->cols > matriz2->cols)
        cols = matriz_cols(matriz1);
    else
        cols = matriz_cols(matriz2);

    Matriz* temp = matriz_create(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp->array[i][j] = matriz1->array[i][j] - matriz2->array[i][j];
            
    return temp;   
}

Matriz* matriz_scalar_mul(Matriz* matriz, double scalar) {
    Matriz* temp = matriz_create(matriz_rows(matriz), matriz_cols(matriz));
    for (int i = 0; i < matriz_rows(matriz); i++)
        for (int j = 0; j < matriz_cols(matriz); j++)
            temp->array[i][j] = matriz->array[i][j] * scalar;

    return temp;
}

Matriz* matriz_transpose(Matriz* matriz) {
    Matriz* temp = matriz_create(matriz->cols, matriz->rows);
    for (int i = 0; i < temp->rows; i++)
        for (int j = 0; j < temp->cols; j++)
            temp->array[i][j] = matriz->array[j][i];

    return temp;
}

bool matriz_is_symmetric(Matriz* matriz) {
    for (int i = 0; i < matriz->rows; i++)
        for (int j = 0; j < matriz->cols; j++)
            if (matriz->array[i][j] != matriz->array[j][i])
                return false;
    
    return true;
}