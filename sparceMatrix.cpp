#include <iostream>

using namespace std;

const int ROWS = 5;
const int COLUMNS = 6;
const int SPARSE_ROWS = 101;


struct Matrix {
    int column;
    int row;
    int value;
};

void getMatrixFromUser(int matrix[ROWS][COLUMNS]) {
    cout << "-------------------------------------------------\n";
    cout << "Enter matrix elements: \n";

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cin >> matrix[i][j];
        }
    }
}


void generateSparseMatrix(int matrix[ROWS][COLUMNS], Matrix sparseMatrix[]) {
    cout << "-------------------------------------------------\n";
    cout << "Sparse matrix representation: \n";

    sparseMatrix[0].row = ROWS;
    sparseMatrix[0].column = COLUMNS;
    sparseMatrix[0].value = COLUMNS;
    int sparseIndex = 1;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[sparseIndex].row = i;
                sparseMatrix[sparseIndex].column = j;
                sparseMatrix[sparseIndex].value = matrix[i][j];
                sparseIndex++;
            }
        }
    }
}


void generateSimpleTransposeOfSparseMatrix(Matrix sparseMatrix[], Matrix simpleTransposeOfSparseMatrix[]) {
    cout << "-------------------------------------------------\n";
    cout << "Simple Transpose of Sparse matrix representation: \n";

    int n = sparseMatrix[0].value;
    simpleTransposeOfSparseMatrix[0].row = sparseMatrix[0].column;
    simpleTransposeOfSparseMatrix[0].column = sparseMatrix[0].row;
    simpleTransposeOfSparseMatrix[0].value = n;

    if (n > 0) {
        int indexOfSimpleTransposeOfSparseMatrix = 1;
        for (int i = 0; i < sparseMatrix[0].column; i++) {
            for (int j = 1; j <= n; j++) {
                if (sparseMatrix[j].column == i) {
                    simpleTransposeOfSparseMatrix[indexOfSimpleTransposeOfSparseMatrix].row = sparseMatrix[j].column;
                    simpleTransposeOfSparseMatrix[indexOfSimpleTransposeOfSparseMatrix].column = sparseMatrix[j].row;
                    simpleTransposeOfSparseMatrix[indexOfSimpleTransposeOfSparseMatrix].value = sparseMatrix[j].value;
                    indexOfSimpleTransposeOfSparseMatrix++;
                }
            }
        }
    }
}


void generateFastTransposeOfSparseMatrix(Matrix sparseMatrix[], Matrix fastTransposeOfSparseMatrix[]) {
    cout << "-------------------------------------------------\n";
    cout << "Fast Transpose of Sparse matrix representation: \n";

    int row_terms[SPARSE_ROWS], starting_position[SPARSE_ROWS];
    int columns = sparseMatrix[0].column;
    int terms = sparseMatrix[0].value;
    fastTransposeOfSparseMatrix[0].row = columns;
    fastTransposeOfSparseMatrix[0].column = sparseMatrix[0].row;
    fastTransposeOfSparseMatrix[0].value = terms;

    if (terms > 0) {
        for (int i = 0; i < columns; i++) {
            row_terms[i] = 0;
        }
        for (int i = 0; i <= terms; i++) {
            row_terms[sparseMatrix[i].column]++;
        }
        starting_position[0] = 1;
        for (int i = 1; i < columns; i++) {
            starting_position[i] = starting_position[i - 1] + row_terms[i - 1];
        }
        for (int i = 1; i <= terms; i++) {
            int j = starting_position[sparseMatrix[i].column]++;
            fastTransposeOfSparseMatrix[j].row = sparseMatrix[i].column;
            fastTransposeOfSparseMatrix[j].column = sparseMatrix[i].row;
            fastTransposeOfSparseMatrix[j].value = sparseMatrix[i].value;
        }
    }
}


void displaySparseMatrix(Matrix sparseMatrix[]) {
    for (int i = 0; i <= COLUMNS; i++) {
        cout << sparseMatrix[i].row << " " << sparseMatrix[i].column << " " << sparseMatrix[i].value << "\n";
    }
}


int main() {
    int matrix[ROWS][COLUMNS];
    Matrix sparseMatrix[SPARSE_ROWS];
    Matrix simpleTransposeOfSparseMatrix[SPARSE_ROWS];
    Matrix fastTransposeOfSparseMatrix[SPARSE_ROWS];

    getMatrixFromUser(matrix);
    generateSparseMatrix(matrix, sparseMatrix);
    displaySparseMatrix(sparseMatrix);
    generateSimpleTransposeOfSparseMatrix(sparseMatrix, simpleTransposeOfSparseMatrix);
    displaySparseMatrix(simpleTransposeOfSparseMatrix);
    generateFastTransposeOfSparseMatrix(sparseMatrix, fastTransposeOfSparseMatrix);
    displaySparseMatrix(fastTransposeOfSparseMatrix);
    cout << "-------------------------------------------------";

    return 0;
}

/*

Test 1
---------------

Input
0 0 0 0 9 0
0 8 0 0 0 0
4 0 0 2 0 0
0 0 0 0 0 5
0 0 2 0 0 0

Output
5 6 6
0 4 9
1 1 8
2 0 4
2 3 2
3 5 5
4 2 2
-----
6 5 6
0 2 4
1 1 8
2 4 2
3 2 2
4 0 9
5 3 5

*/