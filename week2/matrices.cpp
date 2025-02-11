// # anamaytripathy
#include <iostream>
using namespace std;

int main() {
    int m;

    // Get matrix dimension
    cout << "Enter the dimension of the square matrix: ";
    cin >> m;

    if (m <= 0) {
        cout << "Invalid matrix dimension! Exiting program.\n";
        return 1;
    }

    int upperTriangular[(m * (m + 1)) / 2]; // 1D array for storing non-zero elements
    int index = 0;

    // Input only the non-zero elements
    cout << "Enter the " << (m * (m + 1)) / 2 << " non-zero elements of the upper triangular matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            cin >> upperTriangular[index++];
        }
    }

    // Display the upper triangular matrix
    cout << "\nThe entered upper triangular matrix is:\n";
    index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i > j)
                cout << "0 ";
            else
                cout << upperTriangular[index++] << " ";
        }
        cout << endl;
    }

    // Display the mapped 1D array
    cout << "\nThe mapped 1D array storing only non-zero elements is:\n";
    for (int i = 0; i < (m * (m + 1)) / 2; i++) {
        cout << upperTriangular[i] << " ";
    }
    cout << endl;

    // Retrieve an element
    int row, col;
    cout << "\nEnter the row and column to retrieve: ";
    cin >> row >> col;

    if (row < 0 || row >= m || col < 0 || col >= m) {
        cout << "Invalid indices! Please enter values within the matrix size.\n";
    } else if (row > col) {
        cout << "The element at (" << row << ", " << col << ") is: 0\n";
    } else {
        cout << "The element at (" << row << ", " << col << ") is: "
             << upperTriangular[(row * m) + col - ((row * (row + 1)) / 2)] << endl;
    }

    return 0;
}
