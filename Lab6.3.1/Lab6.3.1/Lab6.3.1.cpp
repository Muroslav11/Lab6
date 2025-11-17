#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;

// --- Формування масиву ---
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// --- Форматоване виведення ---
void Print(const int* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// --- Функція пошуку мінімального елемента (звичайна) ---
int Min(int* a, const int size)
{
    int min = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

// --- Універсальна шаблонна функція ---
template <typename T>
T Min(T* a, const int size)
{
    T min = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;

    // --- Масив int ---
    int a[n];
    int Low = -20;
    int High = 20;
    Create(a, n, Low, High);
    cout << "Array int:" << endl;
    Print(a, n);

    cout << "Min(int) = " << Min(a, n) << endl;
    cout << "Min<int>(a, n) = " << Min<int>(a, n) << endl << endl;

    // --- Масив double ---
    double b[n] = { 2.5, 1.1, 9.3, -2.2, 5.5, 4.1, 0.0, -3.4, 6.6, 1.0 };
    cout << "Min<double>(b, n) = " << Min<double>(b, n) << endl << endl;

    // --- Масив string ---
    string c[n] = { "5", "7", "1", "9", "3", "0", "2", "8", "6", "4" };
    cout << "Min<string>(c, n) = " << Min<string>(c, n) << endl;

    return 0;
}