#include <iostream>
using namespace std;

//QUESTION 4 PART 3 ASSIGNMENT 1

int main() {
    int rows, cols;
    cout << "Enter rows and columns of matrix: ";
    cin >> rows >> cols;

    int mat[rows][cols], trans[cols][rows];

    cout << "Enter matrix elements:\n";
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            cin >> mat[i][j];

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }

    cout << "Transpose Matrix:\n";
    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
