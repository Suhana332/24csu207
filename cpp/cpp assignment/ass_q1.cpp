#include <iostream>
using namespace std;
int isprime(int x) {
    if (x < 2) {
        return 0;
    }
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int x;
    cout << "Enter the value of x: ";
    cin >> x;

    if (isprime(x)) {
    cout << "The number " << x << " is prime." << endl;
    } else {
    cout << "The factors are: ";
        for (int i = 1; i <= x / 2; i++) {
            if (x % i == 0) {
            cout << i << " ";
            }
        }
        cout << x << endl;  }

    cout << "The nearest prime number after " << x << " is: ";
    int next_prime = x + 1;
    while (isprime(next_prime) == 0) {  
        next_prime++;
    }
    cout << next_prime << endl;
 return 0;
}
