#include <stdio.h>
#include <stdlib.h>

void printMatrix();
int  **additionMatrix();
int **subtractionMatrix();
int **transposeMatrix();
void multiplyMatrix();
void freeMatrix();


int main() {
    printf("[----- [leeHwaJin]  [2020037103] -----]\n");
    int rows, cols;

    printf("A,B의 행과 열을 입력하라: \n");
    scanf("%d %d", &rows, &cols);

    //동적 메모리 할당
    int **matrixA = (int **)malloc(rows * sizeof(int *));
    int **matrixB = (int **)malloc(rows * sizeof(int *
    ));
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

    printMatrix(matrixA, matrixB, rows, cols);
    int **addResultMatrix = additionMatrix(matrixA, matrixB, rows, cols);
    int **subResultMatrix = subtractionMatrix(matrixA, matrixB, rows, cols);
    int **transResultMatrix = transposeMatrix(matrixA, rows, cols);
    return 0;
}

void printMatrix(int **matrixA, int **matrixB, int rows, int cols) {
    printf("printMatrix함수 시작\n");
    printf("매트릭스A출력\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
               printf("%d ", matrixA[i][j]);
        }  
        printf("\n");
    }
    printf("매트릭스B출력\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
               printf("%d ", matrixB[i][j]);
        }  
         printf("\n");
    }
    printf("printMatrix함수 종료\n");
}

int **additionMatrix(int **matrixA, int **matrixB, int rows, int cols) {
    printf("additionMatrix함수 시작\n");

    // 결과값 2차원배열 선언
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
    }
    
    // 더한 값들 집어넣는 이차원 배열
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
               result[i][j] = matrixA[i][j] + matrixB[i][j];
        }  
    }

    // 더한값이 들어갔는지 프린트
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
               printf("%d ", result[i][j]);
        }  
        printf("\n");
    }

    printf("additionMatrix함수 종료\n");
    return result;
}



int **subtractionMatrix(int **matrixA, int **matrixB, int rows, int cols) {
    printf("subtractionMatrix 시작\n");

    // 결과값 2차원배열 선언
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
    }
    
    // 뺀 값들 집어넣는 이차원 배열
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
               result[i][j] = matrixA[i][j] - matrixB[i][j];
        }  
    }

    // 뺀값이 들어갔는지 프린트
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
               printf("%d ", result[i][j]);
        }  
        printf("\n");
    }

    printf("subtractionMatrix 종료\n");
    return result;
}


int **transposeMatrix(int **matrixA, int rows, int cols) {
    printf("transposeMatrix 시작");
   // 결과값 2차원배열 선언

    int **result = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(rows * sizeof(int));
    }
    
    // 트랜스포즈
   for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
               result[i][j] = matrixA[j][i];
        }  
    }

    // 확인
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
               printf("%d ", result[i][j]);
        }  
        printf("\n");
    }

    printf("transposeMatrix 종료\n");
    return result;
}


void multiplyMatrix() {

}


void freeMatrix() {

}