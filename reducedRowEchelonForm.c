#include <stdio.h>

// Program for --> Reduced Row Echelon Form
#define row 3
#define COL 4


// Function to find the first non-zero row
int nonZero(double arr[][COL], int pivotRow, int col) 
{
    for (int i = pivotRow; i < row; i++) {
        if (arr[i][col] != 0) {
            return i;
        }
    }
    return -1; 
}

// Function to swap two rows
void swapp(double arr[][COL], int pivotRow, int non_zero_row) 
{
    for (int i = 0; i < row; i++) {
        double temp = arr[pivotRow][i];
        arr[pivotRow][i] = arr[non_zero_row][i];
        arr[non_zero_row][i] = temp;
    }
}


// Function to make the leading entry 1
void makeOne(double arr[][COL], int pivotRow, int col) 
{
    double pivot_element = arr[pivotRow][col];
    for (int i = 0; i < COL; i++) {
        arr[pivotRow][i] /= pivot_element;
    }
}


// Function to make zero (below pivot)
void makeZero(double arr[][COL], int pivotRow, int col) 
{
    for (int i = pivotRow + 1; i < row; i++) {
        double num = arr[i][col];
        for (int j = 0; j < COL; j++) {
            arr[i][j] -= num * arr[pivotRow][j];
        }
    }
}

// Function to make zero (above pivot)
void makeAboveZero(double arr[][COL], int pivotRow, int col) {
    
    // if pivot element is in the first row then there is no need
    // to make zeroes above this pivot 
    // we can avoid unnecessary calculations by using if condition
    if(pivotRow > 0)
    {
     for (int Row = pivotRow - 1; Row >= 0; Row--) {
        double num = arr[Row][col];
        for (int col = 0; col < COL; col++) {
            arr[Row][col] -= num * arr[pivotRow][col];
        }
    }
    }
    return;
}

// Function to convert matrix to reduced row echelon form
void convertToRREF(double arr[][COL]) {
    int pivotRow = 0;

    for (int column = 0; column < COL; column++) {
        int non_zero_row = nonZero(arr, pivotRow, column);

        if (non_zero_row != -1) {
            swapp(arr, pivotRow, non_zero_row);
            makeOne(arr, pivotRow, column);
            makeZero(arr, pivotRow, column);
            makeAboveZero(arr, pivotRow, column);
        }

        pivotRow++;
    }
}

int main() {
    double arr[row][COL];

    // Input matrix
    printf("Enter elements for a %dx%d matrix:\n", row, COL);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < COL; j++) {
            printf("Enter the element at position (%d, %d): ", i + 1, j + 1);
            scanf("%lf", &arr[i][j]);
        }
    }

    // Display the original matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%.2lf  ", arr[i][j]);
        }
        printf("\n");
    }

    // Convert the matrix to reduced row echelon form
    convertToRREF(arr);

    // Display the matrix after conversion
    printf("\nMatrix in Reduced Row Echelon Form:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%.2lf  ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
