#include <iostream>

using namespace std;

template <typename MyType>
class Array {
public:
    Array(int n) {
        size = n;
        arr = new MyType[size];
        pos = 0;
        neg = 0;
    }
    MyType rangedRand(int min_value, int max_value) {
        register int res = rand() % (max_value + 1 - min_value) + min_value;
        return res;
    }
    MyType result() {
        for (int i = 0; i < size; i++) {
            arr[i] = rangedRand(-10, 10);
            cout << arr[i] << endl;
            if (arr[i] > 0) {
               pos += arr[i];
            }
            else if (arr[i] < 0) {
               neg -= arr[i];
            }
        }
        return sqrt(pos) - sqrt(neg);
    }
    int size;
    MyType pos;
    MyType neg;
    MyType* arr;
};

int main()
{
    int size;
    cout << "Size - " << endl;
    cin >> size;
    Array <int> arr(size);
    cout << arr.result();
}
