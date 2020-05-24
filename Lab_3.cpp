#include <iostream>
#include <iomanip>

using namespace std;

void func(int** arr, int n) {
    if (n%2==0) {
        for (int i = 0; i < n / 2 + 1; i++)
            for (int j = i; j < n - i; j++)
            {
                arr[(n / 2) - i - 1][j] = 0;
                arr[i + (n / 2)][j] = 0;
            }
    }
    else {
         for (int i = 0; i < n / 2; i++)
            for (int j = i; j < n - i; j++)
            {
                arr[(n / 2) - i][j] = 0;
                arr[i + (n / 2)][j] = 0;
            }
         arr[0][n / 2] = 0;
         arr[n - 1][n / 2] = 0;

    }
}

int main()
{
    cout << "Size - ";
    int n;
    cin >> n;
    int** arr = new int* [n];
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            arr[i] = new int[n];
        }
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = 1;
            }
        }
        func(arr, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << setw(4) << arr[i][j];
            cout << endl;
        }
    }
    else {
        cout << "Error - incorrect size;";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
