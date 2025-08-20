/* matrix_multiplication.c
 *
 * 概要:
 *   2つの行列を掛け算するプログラム
 *
 * 実装機能:
 *   - 固定サイズの行列を初期化
 *   - 行列積を計算して出力
 */

#include <stdio.h>

#define N 3

void multiply(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[N][N];

    multiply(A, B, C);

    printf("Matrix A * B =\n");
    printMatrix(C);
    return 0;
}
