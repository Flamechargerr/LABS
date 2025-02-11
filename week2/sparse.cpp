// Program to convert a matrix to sparse representation and reconstruct it
// Author: Anamay Tripathy

#include<iostream>
using namespace std;

struct sparse {
    int row;
    int col;
    int value;
};

int main() {
    int matrix[20][20], i, j, b[20][20];
    int m, n, k, counter = 0;
    sparse s[30];

    cout << "Please enter the rows and columns of the matrix: ";
    cin >> m >> n;

    cout << "Please enter the elements of the matrix:\n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] != 0) {
                counter++;
            }
        }
    }

    // Displaying the original matrix
    cout << "The matrix is:\n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Storing non-zero elements in sparse matrix representation
    s[0].row = m;
    s[0].col = n;
    s[0].value = counter;

    for (i = 0, k = 1; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {  // No need to check `k <= counter`
                s[k].row = i;
                s[k].col = j;
                s[k].value = matrix[i][j];
                k++;
            }
        }
    }

    // Reconstructing the matrix from sparse representation
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            b[i][j] = 0; // Initialize with zero
        }
    }

    for (k = 1; k <= counter; k++) {
        b[s[k].row][s[k].col] = s[k].value;
    }

    // Displaying the reconstructed matrix
    cout << "The reconstructed matrix is:\n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
