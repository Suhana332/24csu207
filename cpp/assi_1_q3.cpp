#include <iostream>
using namespace std;
int main() {
    float n1, n2;
    char oper;
    cout << "Enter first number: ";
    cin >> n1;
    cout << "Enter second number: ";
    cin >> n2;
    cout << "Enter operator (+, -, *, /): ";
    cin >> oper;
    switch(oper){
        case '+':
            cout << "Result: " << n1 + n2 << endl;
            break;
        case '-':
            cout << "Result: " << n1 - n2 << endl;
            break;
        case '*':
            cout << "Result: " << n1 * n2 << endl;
            break;
        case '/':
            if (n2 != 0) {
                cout << "Result: " << n1 / n2 << endl;
            } else {
                cout << "Error!" << endl;
            }
            break;
        default:
            cout << "Invalid operator!" << endl;
            break;
    }

    return 0;
}
