#include <stdio.h>
#include <math.h>

// Program for --> INVERSE

#define ROW 3
#define COL 3

// Function to find the determinant of a matrix using recursion
double findDeterminant(double mat[ROW][COL], int size) {
    // Base cases
    if (size == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    double determinant = 0;

    // Calculate the determinant by breaking down the matrix into smaller submatrices
    for (int i = 0; i < size; i++) {
        double submat[ROW][COL];
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

// Function to calculate the cofactor of an element at a given position (i, j) in the matrix
double makeCoFactor(double arr[][COL], int i, int j) {
    double submat[ROW][COL];
    int submatRow = 0;

    for (int row = 0; row < ROW; row++) {
        if (row == i) continue;
        int submatCol = 0;
        for (int col = 0; col < COL; col++) {
            if (col != j) {
                submat[submatRow][submatCol] = arr[row][col];
                submatCol++;
            }
        }
        submatRow++;
    }

    return pow(-1, i + j) * findDeterminant(submat, ROW - 1);
}


// Function to calculate the cofactor matrix
void coFactor(double arr[][COL], double cofactorMatrix[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cofactorMatrix[i][j] = makeCoFactor(arr, i, j);
        }
    }
}

// Function to calculate the inverse matrix
void calculateInverse(double arr[][COL]) {

    double cofactorMatrix[ROW][COL];
    coFactor(arr, cofactorMatrix);

    // Find the determinant of the original matrix
    double determinant = findDeterminant(arr, ROW);
    printf("\nDeterminent is %.2lf\n", determinant);

    // Check if the determinant is zero (matrix is singular)
    if (fabs(determinant) == 0) {
        printf("The matrix is singular. Inverse does not exist.\n");
        return;
    }

    // Find the adjoint matrix by transposing the cofactor matrix
    double adjointMatrix[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            adjointMatrix[i][j] = cofactorMatrix[j][i];
        }
    }

    // Calculate and display the inverse matrix
    printf("\nInverse Matrix:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%.2lf  ", adjointMatrix[i][j] / determinant);
        }
        printf("\n");
    }
}

int main() {
    double arr[ROW][COL];

    // Input matrix
    printf("Enter elements for a %dx%d matrix:\n", ROW, COL);
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("Enter the element at position (%d, %d): ", i + 1, j + 1);
            scanf("%lf", &arr[i][j]);
        }
    }

    // Display the original matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%.2lf  ", arr[i][j]);
        }
        printf("\n");
    }

    if(ROW == COL){
    calculateInverse(arr);
    }
    else{
        printf("Sorry! Matrix should be a square matrix!\n");
    }
    return 0;
}
