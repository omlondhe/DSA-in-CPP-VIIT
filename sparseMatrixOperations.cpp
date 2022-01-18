#include<iostream>

using namespace std;

const int MATRIX_SIZE = 100;
const int ROWS = 5;
const int COLS = 5;
int arr1[ROWS][COLS];
int arr2[ROWS][COLS];

typedef struct Matrix {
    int row;
    int column;
    int value;
} Matrix;

void getTraditionalArrayFromUser(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cin >> arr[i][j];
        }
    }
}

void generateSparseMatrix(int arr[ROWS][COLS], Matrix mat[MATRIX_SIZE]) {
    int k = 1;
    int rows = 0;
    int cols = 0;
    int value = 0;
    bool colupdated = false;
    bool rowupdated = false;
    for (int i = 0; i < ROWS; i++) {
        rowupdated = false;
        for (int j = 0; j < COLS; j++) {
            colupdated = false;
            if (arr[i][j] != 0) {
                colupdated = true;
                rowupdated = true;
                mat[k].row = i;
                mat[k].column = j; 
                mat[k].value = arr[i][j];
                k++;
                value++;
            }
            if (colupdated) cols++;
        }
        if (rowupdated) rows++;
    }
    mat[0].row = rows; 
    mat[0].column = cols; 
    mat[0].value = value; 
}

void generateTransposeOfSparseMatrix(Matrix sparse[], Matrix transpose[]) {
    int row_terms[MATRIX_SIZE], starting_position[MATRIX_SIZE];
    int terms = sparse[0].value;
    int columns = sparse[0].column;

    transpose[0].row = columns;
    transpose[0].column = sparse[0].row;
    transpose[0].value = terms;

    if (terms > 0) {
        for (int i = 0; i < columns; i++) {
            row_terms[i] = 0;
        }
        for (int i = 0; i <= terms; i++) {
            row_terms[sparse[i].column]++;
        }
        starting_position[0] = 1;
        for (int i = 1; i < columns; i++) {
            starting_position[i] = starting_position[i - 1] + row_terms[i - 1];
        }
        for (int i = 1; i <= terms; i++) {
            int j = starting_position[sparse[i].column]++;
            transpose[j].row = sparse[i].column;
            transpose[j].column = sparse[i].row;
            transpose[j].value = sparse[i].value;
        }
    }
}

void addSparseMatrix(Matrix sparse1[MATRIX_SIZE], Matrix sparse2[MATRIX_SIZE], Matrix addition[MATRIX_SIZE]) {
    int i = 1, j = 1, k = 1;

    while (i <= sparse1[0].value && j <= sparse2[0].value) {
        if ((sparse1[i].row < sparse2[j].row) || ((sparse1[i].row == sparse2[j].row) && (sparse1[i].column < sparse2[j].column))) {
            addition[k].row = sparse1[i].row;
            addition[k].column = sparse1[i].column;
            addition[k].value = sparse1[i++].value;
        } else if ((sparse1[i].row > sparse2[j].row) || ((sparse1[i].row == sparse2[j].row) && (sparse1[i].column > sparse2[j].column))) {
            addition[k].row = sparse2[j].row;
            addition[k].column = sparse2[j].column;
            addition[k].value = sparse2[j++].value;
        } else {
            addition[k].row = sparse1[i].row;
            addition[k].column = sparse1[i].column;
            addition[k].value = sparse1[i++].value + sparse2[j++].value;
        }
        k++;
    }
    while (i <= sparse1[0].value) {
        addition[k].row = sparse1[i].row;
        addition[k].column = sparse1[i].column;
        addition[k].value = sparse1[i++].value;
    }
    while (j <= sparse2[0].value) {
        addition[k].row = sparse2[j].row;
        addition[k].column = sparse2[j].column;
        addition[k].value = sparse2[j++].value;
    }

    addition[0].row = i - 1;
    addition[0].column = j - 1;
    addition[0].value = k - 1;
}

void multiplySparseMatrix(Matrix sparse[MATRIX_SIZE], Matrix transpose[MATRIX_SIZE], Matrix product[MATRIX_SIZE]) {
    int i, j, k = 1;

    product[0].row = sparse[0].row;
    product[0].column = sparse[0].column;
    product[0].value = sparse[0].value;

    for (i = 1; i <= sparse[0].value;) {
        int row = sparse[i].row;
        for (j = 1; j < transpose[0].value;) {
            int column = transpose[j].row;
            int temp_i = i;
            int temp_j = j;
            int sum = 0;

            while (temp_i < sparse[0].value && sparse[temp_i].row == row && temp_j < transpose[0].value && transpose[temp_j].row == column) {
                if (sparse[temp_i].column < transpose[temp_j].column) temp_i++;
                else if (sparse[temp_i].column > transpose[temp_j].column) temp_j++;
                else sum += sparse[temp_i++].value * transpose[temp_j++].value;
            }

            if (sum != 0) {
                product[k].row = row;
                product[k].column = column;
                product[k].value = sum;
                k++;
            }

            while (j < transpose[0].value && transpose[j].row == column) j++;
        }
        i++;
    }
}

void displayArray(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void displaySparseMatrix(Matrix sparse[MATRIX_SIZE]) {
    for (int i = 0; i <= sparse[0].value; i++) {
        cout << sparse[i].row << " | " << sparse[i].column << " | " << sparse[i].value << "\n"; 
    }
}

int main() {
    Matrix sparse1[MATRIX_SIZE], transpose1[MATRIX_SIZE];
    Matrix sparse2[MATRIX_SIZE], transpose2[MATRIX_SIZE];
    Matrix addition[MATRIX_SIZE], product[MATRIX_SIZE];

    getTraditionalArrayFromUser(arr1);
    cout << "---------------------\n";
    cout << "Traditional Matrix\n";
    displayArray(arr1);
    cout << "---------------------\n";
    cout << "Sparse Matrix\n";
    generateSparseMatrix(arr1, sparse1);
    displaySparseMatrix(sparse1);
    cout << "---------------------\n";
    cout << "Transpose Matrix\n";
    generateTransposeOfSparseMatrix(sparse1, transpose1);
    displaySparseMatrix(transpose1);
    cout << "---------------------\n";
    cout << "---------------------\n";

    getTraditionalArrayFromUser(arr2);
    cout << "---------------------\n";
    cout << "Traditional Matrix\n";
    displayArray(arr2);
    cout << "---------------------\n";
    cout << "Sparse Matrix\n";
    generateSparseMatrix(arr2, sparse2);
    displaySparseMatrix(sparse2);
    cout << "---------------------\n";
    cout << "Transpose Matrix\n";
    generateTransposeOfSparseMatrix(sparse2, transpose2);
    displaySparseMatrix(transpose2);
    cout << "---------------------\n";
    cout << "---------------------\n";

    cout << "Adition of two sparse matrix\n";
    addSparseMatrix(sparse1, sparse2, addition);
    displaySparseMatrix(addition);
    cout << "---------------------\n";
    cout << "Multiplication of two sparse matrix\n";
    multiplySparseMatrix(sparse1, transpose2, product);
    displaySparseMatrix(product);
    cout << "---------------------\n";

    return 0;
}

/*
0 0 0 0 9
0 8 0 0 0
4 0 0 2 0
0 0 0 0 0
0 0 2 0 0

0 9 0 0 0
0 0 0 0 8
0 0 2 0 0
5 0 0 0 0
0 0 0 2 0
*/


/*
0 0 0 0 9
0 8 0 0 0
4 0 0 2 0
0 0 0 0 0
0 0 2 0 0
---------------------
Traditional Matrix
0 0 0 0 9 
0 8 0 0 0 
4 0 0 2 0 
0 0 0 0 0 
0 0 2 0 0 
---------------------
Sparse Matrix
4 | 5 | 5
0 | 4 | 9
1 | 1 | 8
2 | 0 | 4
2 | 3 | 2
4 | 2 | 2
---------------------
Transpose Matrix
5 | 4 | 5
0 | 2 | 4
1 | 1 | 8
2 | 4 | 2
3 | 2 | 2
4 | 0 | 9
---------------------
---------------------

0 9 0 0 0
0 0 0 0 8
0 0 2 0 0
5 0 0 0 0
0 0 0 2 0
---------------------
Traditional Matrix
0 9 0 0 0 
0 0 0 0 8 
0 0 2 0 0 
5 0 0 0 0 
0 0 0 2 0 
---------------------
Sparse Matrix
5 | 5 | 5
0 | 1 | 9
1 | 4 | 8
2 | 2 | 2
3 | 0 | 5
4 | 3 | 2
---------------------
Transpose Matrix
5 | 5 | 5
0 | 3 | 5
1 | 0 | 9
2 | 2 | 2
3 | 4 | 2
4 | 1 | 8
---------------------
---------------------
Adition of two sparse matrix
5 | 5 | 9
0 | 1 | 9
0 | 4 | 9
1 | 1 | 8
1 | 4 | 8
2 | 0 | 4
2 | 2 | 2
2 | 3 | 2
3 | 0 | 5
4 | 2 | 2
---------------------
Multiplication of two sparse matrix
4 | 5 | 5
0 | 3 | 18
2 | 0 | 10
2 | 1 | 36
2 | 0 | 10
1 | 1 | 0
---------------------
*/
