#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


// Рекурсивне створення масиву
void Create(int* a, const int size, int Low, int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Рекурсивний вивід масиву
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// Рекурсивна функція пошуку MIN
int Min(int* a, const int size, int i, int min)
{
    if (a[i] < min)
        min = a[i];

    if (i < size - 1)
        return Min(a, size, i + 1, min);
    else
        return min;
}

// Рекурсивна шаблонна функція Min
template <typename T>
T Min(T* a, const int size, int i, T min)
{
    if (a[i] < min)
        min = a[i];

    if (i < size - 1)
        return Min<T>(a, size, i + 1, min);
    return min;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];

    int Low = -20;
    int High = 20;

    Create(a, n, Low, High, 0);

    cout << "Array int:" << endl;
    Print(a, n, 0);

    // Звичайна функція
    cout << "Min(int) = " << Min(a, n, 0, a[0]) << endl;

    cout << "Min<int>(a, n) = " << Min<int>(a, n, 0, a[0]) << endl << endl;

    // Приклад для double
    double b[n] = { 2.5, 1.1, 9.3, -2.2, 5.5, 4.1, 0.0, -3.4, 6.6, 1.0 };
    cout << "Min<double>(b, n) = " << Min<double>(b, n, 0, b[0]) << endl << endl;

    // --- Масив string ---
    string c[n] = { "5", "7", "1", "9", "3", "0", "2", "8", "6", "4" };
    cout << "Min<string>(c, n) = " << Min<string>(c, n, 0, c[0]) << endl;

    return 0;
}