#include <stdio.h>
#include <stdlib.h>

void printMatrix();
void additionMatrix();
void subtractionMatrix();
void transposeMatrix();
void multiplyMatrix();
void freeMatrix();


int main() {
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

    //랜덤 수로 메트리스 채우기2
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixA[i][j] = rand()%10;
            matrixB[i][j] = rand()%10;
        }
    }
    
    return 0;
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