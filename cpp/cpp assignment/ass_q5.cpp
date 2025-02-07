#include <iostream>
using namespace std;
int main() {

    int n;
    cout << "enter the value of n: ";
    cin >> n;
    int mat[n][n] = {0};

    cout << "enter the elements of the matrix: ";             
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][n - 1 - j];
            mat[i][n - 1 - j] = temp;
        }
    }

    cout << "the rotated matrix is: " << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

    
}