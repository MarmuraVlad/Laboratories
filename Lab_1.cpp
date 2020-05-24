#include <iostream>
using namespace std;
int func(double* arr, int length)
{
	int count=0;
	for (int i = 1; i < length-1; i++)
	{
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])count++;
	}
	return count;
}
int func(char* str)
{
	int count=0, length;
	length = sizeof(str)+1;
	for (int i = 1; i < length - 1; i++)
	{
		if (str[i] > str[i - 1] && str[i] > str[i + 1])count++;
	}
	return count;
}
int main()
{
    double arr1[] = { 1.2,1.5,1.1,7.2,3.5 };
    char arr2[] = { 'a','z','s','l','b' };
	cout << func(arr1, 5)<<endl;
	cout << func(arr2) << endl;
	system("pause");
	return 0;
}
