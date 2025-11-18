#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
using namespace std;

// Створення масиву
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Виведення масиву
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// Мінімальний за модулем елемент масиву
int MinAbs(const int* a, const int size)
{
    int minAbs = abs(a[0]);
    for (int i = 1; i < size; i++)
        if (abs(a[i]) < minAbs)
            minAbs = abs(a[i]);
    return minAbs;
}

// Сума модулів елементів після першого нуля
int SumAfterZero(const int* a, const int size)
{
    bool zeroFound = false;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (!zeroFound)
        {
            if (a[i] == 0)
                zeroFound = true;
        }
        else
        {
            sum += abs(a[i]);
        }
    }

    return sum;
}

// Перетворення масиву
void Transform(int* a, const int size)
{
    int* tmp = new int[size];
    int evenPos = 0;
    int oddPos = size / 2;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            tmp[evenPos++] = a[i];
        else
            tmp[oddPos++] = a[i];
    }

    for (int i = 0; i < size; i++)
        a[i] = tmp[i];

    delete[] tmp;
}


int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "n= "; 
    cin >> n;

    int* a = new int[n];

    int Low = -20, High = 20;

    Create(a, n, Low, High);

    cout << "Original array:\n";
    Print(a, n);

    cout << "\nMin absolute = " << MinAbs(a, n) << endl;
    cout << "Sum after first zero = " << SumAfterZero(a, n) << endl;

    Transform(a, n);

    cout << "\nTransformed array:\n";
    Print(a, n);

    delete[] a;
    return 0;
}