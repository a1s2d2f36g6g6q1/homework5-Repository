#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int **createMatrix(int rows, int cols);
void fillMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);
void freeMatrix(int **matrix, int rows);
int **additionMatrix(int **matrix1, int **matrix2, int rows, int cols);
int **subtractionMatrix(int **matrix1, int **matrix2, int rows, int cols);
int **transposeMatrix(int **matrix, int rows, int cols);
int **multiplicationMatrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2);

int main(){
    int rows1, cols1, rows2, cols2;

    printf("Rows and Columns of Matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Rows and Columns of Matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    if (rows1 != rows2 || cols1 != cols2){
        printf("Matrix 1 and Matrix 2 must have the same size\n");
        return 0;
    }

    int **matrix1 = createMatrix(rows1, cols1);
    int **matrix2 = createMatrix(rows2, cols2);

    srand(time(NULL));
    fillMatrix(matrix1, rows1, cols1);
    fillMatrix(matrix2, rows2, cols2);

    printf("Matrix 1:\n");
    printMatrix(matrix1, rows1, cols1);

    printf("Matrix 2:\n");
    printMatrix(matrix2, rows2, cols2);

    
}

int **createMatrix(int rows, int cols){
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++){
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void fillMatrix(int **matrix, int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i][j] = rand() % 10;
        }
    }
}

void printMatrix(int **matrix, int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}