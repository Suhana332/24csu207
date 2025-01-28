#include <iostream>
using namespace std;

int main() {
    int n;

    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Declare the array
    int arr[n];
    
    // Input elements of the array
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate the sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Calculate the average
    double average = static_cast<double>(sum) / n;

    // Output the sum and average
    cout << "Sum of the array elements: " << sum << endl;
    cout << "Average of the array elements: " << average << endl;

    return 0;
}
