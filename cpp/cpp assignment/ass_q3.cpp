#include <iostream>
using namespace std;
int main() {
    char str[100];
    int freq[30] = {0};
    cout << "Enter a string: ";
    cin >> str;
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    for (int i = 0; i < length / 2; i++) { 
        if (str[i] != str[length - i - 1]) {
            cout << "String is not a palindrome\n";
            break;
        }
        if (i == length / 2 - 1) {
        cout << "String is a palindrome\n";
        }
    }
cout << "Modified string: ";
    for (int i = 0; i < length; i++) {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || 
            str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            cout << "*";
        } else {
            cout << str[i];
        }
    }
    cout << "\n";
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            freq[str[i] - 'A']++;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            freq[str[i] - 'a']++;
        }
    }
cout << "Letter frequencies:\n";
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            cout << (char)(i + 'A') << ": " << freq[i] << "\n";
        }
    }

    return 0;
}
