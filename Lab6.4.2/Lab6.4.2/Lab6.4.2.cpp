#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>
using namespace std;

//  Рекурсивне створення 
void Create(int* a, int size, int Low, int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Рекурсивний вивід 
void Print(const int* a, int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

//  Мінімальний за модулем 
int MinAbs(const int* a, int size, int i, int currentMin)
{
    if (abs(a[i]) < abs(currentMin))
        currentMin = a[i];

    if (i < size - 1)
        return MinAbs(a, size, i + 1, currentMin);
    else
        return currentMin;
}

//  Сума після першого нуля 
int SumAfterZero(const int* a, int size, int i, bool zeroFound)
{
    if (i == size)
        return 0;

    if (!zeroFound)
    {
        if (a[i] == 0)
            return SumAfterZero(a, size, i + 1, true);
        else
            return SumAfterZero(a, size, i + 1, false);
    }
    else
    {
        return abs(a[i]) + SumAfterZero(a, size, i + 1, true);
    }
}

//  Підрахунок парних індексів 
int CountEvenIndexes(int size, int i)
{
    if (i >= size) return 0;
    return 1 + CountEvenIndexes(size, i + 2);
}

//  Копіювання елементів у temp 
void FillTemp(int* a, int* tmp, int size, int i, int evenPos, int oddPos)
{
    if (i == size)
        return;

    if (i % 2 == 0)
        tmp[evenPos] = a[i];
    else
        tmp[oddPos] = a[i];

    FillTemp(a, tmp, size, i + 1, evenPos + (i % 2 == 0), oddPos + (i % 2 == 1));
}

//  Копіювання temp назад у a 
void CopyBack(int* a, int* tmp, int size, int i)
{
    a[i] = tmp[i];
    if (i < size - 1)
        CopyBack(a, tmp, size, i + 1);
}

//  Перетворення масиву 
void Transform(int* a, int size)
{
    int* tmp = new int[size];

    int evenCount = CountEvenIndexes(size, 0);
    int oddStart = evenCount;

    FillTemp(a, tmp, size, 0, 0, oddStart);
    CopyBack(a, tmp, size, 0);

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

    Create(a, n, Low, High, 0);

    cout << "Original array:\n";
    Print(a, n, 0);

    int minAbs = MinAbs(a, n, 0, a[0]);
    cout << "\nMin absolute element = " << abs(minAbs) << endl;

    int sumAfter0 = SumAfterZero(a, n, 0, false);
    cout << "Sum after first zero = " << sumAfter0 << endl;

    Transform(a, n);

    cout << "\nTransformed array:\n";
    Print(a, n, 0);

    delete[] a;
    return 0;
}
