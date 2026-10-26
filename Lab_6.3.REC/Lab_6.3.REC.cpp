
#include <iostream>
#include <iomanip>
using namespace std;

void Print(int a[], int n, int i)
{
    if (i == n)
        return;

    cout << setw(4) << a[i];
    Print(a, n, i + 1);
}

int SumEven(int a[], int n, int i)
{
    if (i == n)
        return 0;

    if (a[i] % 2 == 0)
        return a[i] + SumEven(a, n, i + 1);
    else
        return SumEven(a, n, i + 1);
}

template <typename T>
T SumEven(T a[], int n, int i)
{
    if (i == n)
        return T();

    if (a[i] % 2 == 0)
        return a[i] + SumEven<T>(a, n, i + 1);
    else
        return SumEven<T>(a, n, i + 1);
}

int main()
{
    const int n = 6;
    int a[n] = { 2, 7, 4, 9, -6, 8 };

    cout << "Array: ";
    Print(a, n, 0);
    cout << endl;

    int result1 = SumEven(a, n, 0);
    cout << "Sum = " << result1 << endl;

    int result2 = SumEven<int>(a, n, 0);
    cout << "Template Sum = " << result2 << endl;

    return 0;
}
