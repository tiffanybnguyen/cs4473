#include <stdio.h>
#include <stdlib.h>
// Use more libraries as necessary

#define DEBUG 0

/* ---------- Project 1 - Problem 2 - Mat-Vec Mult ----------
    This file will multiply a matrix and vector.
    Complete the TODOs left in this file.
*/
// ------------------------------------------------------ //

int main(int argc, char *argv[])
{
    // Catch console errors
    if (argc != 7)
    {
        printf("USE LIKE THIS: serial_mult_mat_vec in_mat.csv n_row_1 n_col_1 in_vec.csv n_row_2 output_file.csv \n");
        return EXIT_FAILURE;
    }

    // Get the input files
    FILE *matFile = fopen(argv[1], "r");
    FILE *vecFile = fopen(argv[4], "r");

    // Get dim of the matrix
    char *p1;
    char *p2;
    int n_row1 = strtol(argv[2], &p1, 10); // height of matrix
    int n_col1 = strtol(argv[3], &p2, 10); // width of matrix

    // Get dim of the vector
    char *p3;
    int n_row2 = strtol(argv[5], &p3, 10); // height of vector

    // Get the output file
    FILE *outputFile = fopen(argv[6], "w");

    // TODO: Use malloc to allocate memory for the matrices
    long int *input_matrix = (long int *)malloc((n_row1 * n_col1) * sizeof(long int));
    long int *input_vector = (long int *)malloc((n_row2) * sizeof(long int));

    // TODO: Parse the input CSV files

    long int matrix_val;
    long int vector_val;

    // parsing for input matrix
    for (long int row = 0; row < n_row1; row++)
    {
        for (long int column = 0; column < n_col1; column++)
        {
            if (fscanf(matFile, "%ld,", &matrix_val) != 1)
            {
                fscanf(matFile, "%ld", &matrix_val);
            }
            input_matrix[row * n_col1 + column] = matrix_val;
        }
    }

    // parsing for input matrix
    for (int column = 0; column < n_row2; column++)
    {
        if (fscanf(vecFile, "%ld,", &vector_val) != 1)
        {
            fscanf(vecFile, "%ld", &vector_val);
        }

        input_vector[column] = vector_val;
    }

    // TODO: Perform the matrix-vector multiplication
    long int *result_array = (long int *)malloc((n_row1) * sizeof(long int)); // size of resultant array

    for (long int row = 0; row < n_row1; row++)
    {
        long int row_sum = 0;
        for (long int column = 0; column < n_col1; column++)
        {
            // calculate matrix multiplication
            row_sum += input_matrix[row * n_col1 + column] * input_vector[column];
        }
        // store matrix calculated value
        result_array[row] = row_sum;
    }

    // TODO: Write the output CSV file
    for (long int row = 0; row < n_row1; row++)
    {
        fprintf(outputFile, "%ld", result_array[row]);

        // case to prevent last item having comma
        if (row < n_row1 - 1)
        {
            fprintf(outputFile, ",");
        }
    }

    // TODO: Free memory
    free(input_matrix);
    free(input_vector);
    free(result_array);

    // Cleanup
    fclose(matFile);
    fclose(vecFile);
    fclose(outputFile);
    // Free buffers here as well!

    return 0;
}
