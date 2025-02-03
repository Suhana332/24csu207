#include<iostream>
using namespace std;
int main()
{

    int r,c;
    cout << "enter the number of rows and columns";
    cin >> r ;
    cin >> c;
    int arr[r][c];
   for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
        cin >> arr[i][j];
        }
    }
    cout << "sum:\n";
    for(int i=0;i<r;i++)
    {
        int rsum=0;
        for (int j=0;j<c;j++)
        {
            rsum+=arr[i][j];
            
        }
        cout << "sum of row" << i++ << ": " <<  rsum << endl;
    }
    return 0;
    

}