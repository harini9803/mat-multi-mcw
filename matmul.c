#include <stdlib.h>
#include <time.h>

double get_time_diff_ms(clock_t start, clock_t end)
{
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

// ijk loop order
double matrix_multiply_ijk(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B)
{

    clock_t start = clock();
    for (int i = 0; i < rows_A; i++)
    {
        for (int j = 0; j < cols_B; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < cols_A; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_t end = clock();
    double time_taken = (double)(end - start)/CLOCKS_PER_SEC*1000;
    printf("Time taken (ms): %.2f\n", time_taken);
    return time_taken;
}

// ikj loop order
double matrix_multiply_ikj(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B)
{
    clock_t start = clock();
    for (int i = 0; i < rows_A; i++)
    {
        for (int k = 0; k < cols_A; k++)
        {
            for (int j = 0; j < cols_B; j++)
            {
                if (k == 0)
                    C[i][j] = 0; 
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_t end = clock();
    double time_taken = (double)(end - start)/CLOCKS_PER_SEC*1000;
    printf("Time taken (ms): %.2f\n", time_taken);
    return time_taken;
}

// jik loop order
double matrix_multiply_jik(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B)
{
    clock_t start = clock();
    for (int j = 0; j < cols_B; j++)
    {
        for (int i = 0; i < rows_A; i++)
        {
            C[i][j] = 0;
            for (int k = 0; k < cols_A; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_t end = clock();
    double time_taken = (double)(end - start)/CLOCKS_PER_SEC*1000;
    printf("Time taken (ms): %.2f\n", time_taken);
    return time_taken;
}

// jki loop order
double matrix_multiply_jki(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B)
{
    clock_t start = clock();
    for (int j = 0; j < cols_B; j++)
    {
        for (int k = 0; k < cols_A; k++)
        {
            for (int i = 0; i < rows_A; i++)
            {
                if (k == 0)
                    C[i][j] = 0; 
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_t end = clock();
    double time_taken = (double)(end - start)/CLOCKS_PER_SEC*1000;
    printf("Time taken (ms): %.2f\n", time_taken);
    return time_taken;
}

// kij loop order
double matrix_multiply_kij(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B)
{
    clock_t start = clock();
    for (int k = 0; k < cols_A; k++)
    {
        for (int i = 0; i < rows_A; i++)
        {
            for (int j = 0; j < cols_B; j++)
            {
                if (k == 0)
                    C[i][j] = 0; 
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_t end = clock();
    double time_taken = (double)(end - start)/CLOCKS_PER_SEC*1000;
    printf("Time taken (ms): %.2f\n", time_taken);
    return time_taken;
}

// kji loop order
double matrix_multiply_kji(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B)
{
    clock_t start = clock();
    
    for (int k = 0; k < cols_A; k++)
    {
        for (int j = 0; j < cols_B; j++)
        {
            for (int i = 0; i < rows_A; i++)
            {
                if (k == 0)
                    C[i][j] = 0; 
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_t end = clock();
    double time_taken = (double)(end - start)/CLOCKS_PER_SEC*1000;
    printf("Time taken (ms): %.2f\n", time_taken);
    return time_taken;
}
