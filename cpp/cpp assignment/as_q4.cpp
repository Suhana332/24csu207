#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Size of square: ";
    cin >> n;
int arr[100][100];
    int num = 1;
    int top = 0, bot = n - 1, left = 0, right = n - 1;

    while (top <= bot && left <= right) {
        for (int i = left; i <= right; i++) arr[top][i] = num++;
        top++;
        for (int i = top; i <= bot; i++) arr[i][right] = num++;
        right--;
        if (top <= bot) {
            for (int i = right; i >= left; i--) arr[bot][i] = num++;
            bot--;
        }
        if (left <= right) {
            for (int i = bot; i >= top; i--) arr[i][left] = num++;
            left++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
