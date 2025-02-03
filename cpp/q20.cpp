#include<iostream>
using namespace std;
int main() {
    int choice;
    float n1,n2;
    do{
        cout << "calculator\n";
        cout << "addition\n";
        cout << "subtraction\n";
        cout << "multiplication\n";
        cout << "division\n";
        cout << "enter your choice\n";
        cin >> choice;
        if(choice >= 1 && choice <= 4)
        {
            cout << "enter values";
            cin >> n1 >> n2;
                }
                switch (choice) {
                    case 1:
                    cout << "result:" << n1+n2 << endl;
                    break;
                    case 2:
                    cout << "result:" << n1-n2 << endl;
                    break;
                    case  3:
                    cout << "result:" << n1*n2 << endl;
                    break;

                    case 4:
                    cout << "result" << n1/n2 << endl;
                    break;
                    case 5:
                    cout << "exit\n";
                    break;
                    default:
                    cout << "invalid choice\n" << endl;

                }}
                while(choice!=5);
                return 0;
           
}