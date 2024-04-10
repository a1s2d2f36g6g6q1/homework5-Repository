#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 함수 선언
int **createMatrix(int rows, int cols);
void fillMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);
void freeMatrix(int **matrix, int rows);
int **additionMatrix(int **matrix1, int **matrix2, int rows, int cols);
int **subtractionMatrix(int **matrix1, int **matrix2, int rows, int cols);
int **transposeMatrix(int **matrix, int rows, int cols);
int **multiplicationMatrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2);

int main(){
    // 변수 선언 - 행렬 1, 2의 행, 열
    int rows1, cols1, rows2, cols2;

    printf("========================================\n");
    printf("[ ---- [ Suh Dong Woo ] [ 2021041094 ] ---- ]\n");
    printf("========================================\n");

    printf("Rows and Columns of Matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Rows and Columns of Matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    // 행렬 1, 2의 행, 열 수가 다를 경우 오류 출력용
    if (rows1 != rows2 || cols1 != cols2){
        printf("Matrix 1 and Matrix 2 must have the same size\n");
        return 0;
    }

    printf("========================================\n");

    int **matrix1 = createMatrix(rows1, cols1);
    int **matrix2 = createMatrix(rows2, cols2);

    // 행렬 1, 2에 랜덤 값
    srand(time(NULL));
    fillMatrix(matrix1, rows1, cols1);
    fillMatrix(matrix2, rows2, cols2);

    printf("\nMatrix 1:\n");
    printMatrix(matrix1, rows1, cols1);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2, rows2, cols2);

    printf("\n========================================\n");
    printf("1. Addition Matrix (Matrix 1 + Matrix 2)\n");
    int **addition = additionMatrix(matrix1, matrix2, rows1, cols1);
    printMatrix(addition, rows1, cols1);

    printf("========================================\n");
    printf("2. Subtraction Matrix (Matrix 1 - Matrix 2)\n");
    int **subtraction = subtractionMatrix(matrix1, matrix2, rows1, cols1);
    printMatrix(subtraction, rows1, cols1);

    printf("========================================\n");
    printf("3. Transpose Matrix 1\n");
    int **transpose = transposeMatrix(matrix1, rows1, cols1);
    printMatrix(transpose, cols1, rows1);

    printf("========================================\n");
    printf("4. Multiplication Matrix (Matrix 1 * Matrix 2)\n");
    int **multiplication = multiplicationMatrix(matrix1, matrix2, rows1, cols1, rows2, cols2);
    printMatrix(multiplication, rows1, cols2);

    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(addition, rows1);
    freeMatrix(subtraction, rows1);
    freeMatrix(transpose, cols1);
    freeMatrix(multiplication, rows1);

    return 0;
}

int **createMatrix(int rows, int cols){
    // 행렬 생성
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++){
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void fillMatrix(int **matrix, int rows, int cols){
    // 행렬에 랜덤 값
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i][j] = rand() % 10;
        }
    }
}

void printMatrix(int **matrix, int rows, int cols){
    // 행렬 출력
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int rows){
    // 행렬 메모리 해제
    for (int i = 0; i < rows; i++){
        free(matrix[i]);
    }
    free(matrix);
}

int **additionMatrix(int **matrix1, int **matrix2, int rows, int cols){
    // 행렬 덧셈
    int **addition = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            addition[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return addition;
}

int **subtractionMatrix(int **matrix1, int **matrix2, int rows, int cols){
    // 행렬 뺄셈
    int **subtraction = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            subtraction[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return subtraction;
}

int **transposeMatrix(int **matrix, int rows, int cols){
    // 행렬 전치 -> 행과 열을 바꿈 (rows, cols -> cols, rows)
    int **transpose = createMatrix(cols, rows);
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            transpose[i][j] = matrix[j][i];
        }
    }
    return transpose;
}

int **multiplicationMatrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2){
    // 행렬 곱셈
    int **multiplication = createMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < cols2; j++){
            multiplication[i][j] = 0;
            for (int k = 0; k < cols1; k++){
                multiplication[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return multiplication;
}