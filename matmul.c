#include <stdlib.h>

// ijk loop order
void matrix_multiply_ijk(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B) {
    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_B; j++) {
            C[i][j] = 0;
            for (int k = 0; k < cols_A; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// ikj loop order
void matrix_multiply_ikj(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B) {
    for (int i = 0; i < rows_A; i++) {
        for (int k = 0; k < cols_A; k++) {
            for (int j = 0; j < cols_B; j++) {
                if (k == 0) C[i][j] = 0;  // Initialize C[i][j] on the first k iteration
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// jik loop order
void matrix_multiply_jik(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B) {
    for (int j = 0; j < cols_B; j++) {
        for (int i = 0; i < rows_A; i++) {
            C[i][j] = 0;
            for (int k = 0; k < cols_A; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// jki loop order
void matrix_multiply_jki(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B) {
    for (int j = 0; j < cols_B; j++) {
        for (int k = 0; k < cols_A; k++) {
            for (int i = 0; i < rows_A; i++) {
                if (k == 0) C[i][j] = 0;  // Initialize C[i][j] on the first k iteration
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// kij loop order
void matrix_multiply_kij(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B) {
    for (int k = 0; k < cols_A; k++) {
        for (int i = 0; i < rows_A; i++) {
            for (int j = 0; j < cols_B; j++) {
                if (k == 0) C[i][j] = 0;  // Initialize C[i][j] on the first k iteration
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// kji loop order
void matrix_multiply_kji(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B) {
    for (int k = 0; k < cols_A; k++) {
        for (int j = 0; j < cols_B; j++) {
            for (int i = 0; i < rows_A; i++) {
                if (k == 0) C[i][j] = 0;  // Initialize C[i][j] on the first k iteration
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
