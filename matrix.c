//https://github.com/boriiiborii/DataStructureHomework5
#include <stdio.h>
#include <stdlib.h>

void printMatrix();
int **additionMatrix();
int **subtractionMatrix();
int **transposeMatrix();
int **multiplyMatrix();
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

    //랜덤 수로 메트리스 채우기
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixA[i][j] = rand()%10;
            matrixB[i][j] = rand()%10;
        }
    }

    //함수들 동작 실행하고 return값 받아온것들을 변수에 담음
    int **addResultMatrix = additionMatrix(matrixA, matrixB, rows, cols);
    int **subResultMatrix = subtractionMatrix(matrixA, matrixB, rows, cols);
    int **transResultMatrix = transposeMatrix(matrixA, rows, cols);
    int **mulResultMatrix = multiplyMatrix(matrixA, matrixB, rows, cols);
    
    //결과물을 프린트 하는 함수를 만들기 위하여 인자값으로 return받았던 값들을 집어 넣음
    printMatrix(matrixA, matrixB, addResultMatrix, subResultMatrix, transResultMatrix, mulResultMatrix, rows, cols);

    //할당해제
    freeMatrix(matrixA, rows);
    freeMatrix(matrixB, rows);
    freeMatrix(addResultMatrix, rows);
    freeMatrix(subResultMatrix, rows);
    freeMatrix(transResultMatrix, cols);
    freeMatrix(mulResultMatrix, rows);
    printf("할당해제 완료");
    return 0;
}

void printMatrix(int **matrixA, int **matrixB, int **addResultMatrix, int **subResultMatrix, int **transResultMatrix, int **mulResultMatrixint, int rows, int cols) {
    printf("printMatrix함수 시작\n");
    printf("----------매트릭스A출력----------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
               printf("%d ", matrixA[i][j]);
        }  
        printf("\n");
    }
    printf("----------매트릭스B출력----------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
               printf("%d ", matrixB[i][j]);
        }  
         printf("\n");
    }

    printf("----------addResultMatrix 출력----------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
               printf("%d ", addResultMatrix[i][j]);
        }  
        printf("\n");
    }

    printf("----------subResultMatrix 출력----------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
               printf("%d ", subResultMatrix[i][j]);
        }  
        printf("\n");
    }

    //얘는 트랜스폼을 하였기 때문에 cols와 rows의 크기가 스위칭된다.
    printf("----------transResultMatrix 출력----------\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
               printf("%d ", transResultMatrix[i][j]);
        }  
        printf("\n");
    }

    printf("----------mulResultMatrixint 출력----------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
               printf("%d ", mulResultMatrixint[i][j]);
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

    // // 더한값이 들어갔는지 프린트
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //            printf("%d ", result[i][j]);
    //     }  
    //     printf("\n");
    // }

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

    // // 뺀값이 들어갔는지 프린트
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //            printf("%d ", result[i][j]);
    //     }  
    //     printf("\n");
    // }

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

    // // 확인
    // for (int i = 0; i < cols; i++) {
    //     for (int j = 0; j < rows; j++) {
    //            printf("%d ", result[i][j]);
    //     }  
    //     printf("\n");
    // }

    printf("transposeMatrix 종료\n");
    return result;
}


int  **multiplyMatrix(int **matrixA, int **matrixB, int rows, int cols) {
    printf("multiplyMatrix 시작\n");
    // 결과값 행렬 선언
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
    }
    
    // 행렬 곱셈 연산
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // // 확인
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //            printf("%d ", result[i][j]);
    //     }  
    //     printf("\n");
    // }
    printf("multiplyMatrix 끝\n");
    return result;
}

//2차원 배열의 매트릭스(row를 하나하나 반복하며)free시켜줌
//이유는 동적 2차원 배열은 1차원배열(row)이 2중으로 되어있기떄문에
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}