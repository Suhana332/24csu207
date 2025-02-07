#include <iostream>
using namespace std;
int main() {
    int max;
    cout << "Enter the size of the array: ";
    cin >> max;
 int arr[max], temp;
 cout << "Enter the elements of the array: ";
     for (int i = 0; i < max; i++) {
        cin >> arr[i];
    }
for (int i = 0; i < max / 2; i++) {
        temp = arr[i];
        arr[i] = arr[max - i - 1];
        arr[max - i - 1] = temp;
    }
    cout << "The reversed array is: ";
    for (int i = 0; i < max; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < max - 1; i++) {
        for (int j = 0; j < max - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }  } }
cout << "The sorted array is: ";
    for (int i = 0; i < max; i++) {
        cout << arr[i] << " ";
    }
 if (max > 1) {
        cout << endl << "The second smallest element is: " << arr[1] << endl;
        cout << "The second largest element is: " << arr[max - 2] << endl;
    }  return 0;
}
