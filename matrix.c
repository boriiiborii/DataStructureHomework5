#include <stdio.h>

void printMatrix();
void additionMatrix();
void subtractionMatrix();
void transposeMatrix();
void multiplyMatrix();
void freeMatrix();


void main() {
    printf("[----- [leeHwaJin]  [2020037103] -----]\n");
    int rows, cols;

    printf("A,B의 행과 열을 입력하라: \n");
    scanf("%d %d", &rows, &cols);

    //동적 메모리 할당
    int **matrixA = (int **)malloc(rows * sizeof(int *));
    int **matrixB = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrixA[i] = (int *)malloc(cols * sizeof(int));
        matrixB[i] = (int *)malloc(cols * sizeof(int));
    }

void printMatrix() {
   
}

void additionMatrix() {
   
}


void subtractionMatrix() {
   
}


void transposeMatrix() {
   
}


void multiplyMatrix() {

}


void freeMatrix() {

}