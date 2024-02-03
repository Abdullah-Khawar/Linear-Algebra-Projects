#include <stdio.h>

// Program for --> DETERMINANT

#define MAX_SIZE 10

// Function to display a matrix
void displayMatrix(double mat[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.2lf ", mat[i][j]);
        }
        printf("\n");
    }
}


// Function to find the determinant of a matrix using recursion
double findDeterminant(double mat[MAX_SIZE][MAX_SIZE], int size) {
   
    // Base case
     if (size == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    double determinant = 0;

    // Calculate the determinant by breaking down the matrix into smaller submatrices
    for (int i = 0; i < size; i++) {
     
        double submat[MAX_SIZE][MAX_SIZE];
        int submatSize = size - 1;

        // Create the submatrix by excluding the current row and column
        for (int row = 1; row < size; row++) {
            int submatCol = 0;
            int submatRow = row - 1;
            for (int col = 0; col < size; col++) {
                if (col != i) {
                    submat[submatRow][submatCol] = mat[row][col];
                    submatCol++;
                }
            }
            submatRow++;
        }

        // Calculate the determinant recursively
        determinant += (i % 2 == 0 ? 1 : -1) * mat[0][i] * findDeterminant(submat, submatSize);
    }

    return determinant;
}

int main() {

    int size;
    printf("Enter the size of the square matrix (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    double matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter the element at position (%d, %d): ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    displayMatrix(matrix, size);

    double determinant = findDeterminant(matrix, size);

    printf("\nDeterminant = %.2lf\n", determinant);

    return 0;
}
