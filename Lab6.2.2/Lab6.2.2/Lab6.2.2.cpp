#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// --- Рекурсивна генерація масиву ---
void Create(int* a, int n, int Low, int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);

    if (i < n - 1)
        Create(a, n, Low, High, i + 1);
}

// --- Рекурсивне форматоване виведення ---
void Print(const int* a, int n, int i)
{
    cout << setw(4) << a[i];

    if (i < n - 1)
        Print(a, n, i + 1);
    else
        cout << endl;
}

// --- Рекурсивна сума елементів з парними індексами ---
int SumEvenIndex(const int* a, int n, int i = 0)
{
    if (i >= n)
        return 0;

    return a[i] + SumEvenIndex(a, n, i + 2);
}

// --- Рекурсивний підрахунок елементів з парними індексами ---
int CountEvenIndex(const int* a, int n, int i = 0)
{
    if (i >= n)
        return 0;

    return 1 + CountEvenIndex(a, n, i + 2);
}

// --- Функція, що ОБЧИСЛЮЄ середнє арифметичне ---
double AverageEvenIndex(const int* a, int n)
{
    int sum = SumEvenIndex(a, n, 0);
    int count = CountEvenIndex(a, n, 0);

    if (count == 0)
        return 0;

    return (double)sum / count;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 20;
    int a[n];

    int Low = -20;
    int High = 40;

    // 1. Формування масиву
    Create(a, n, Low, High, 0);

    // 2. Виведення масиву
    cout << "Array:" << endl;
    Print(a, n, 0);

    // 3. Обчислення
    double avg = AverageEvenIndex(a, n);

    // 4. Виведення результату
    cout << "\nAverage (even indexes) = " << avg << endl;

    return 0;
}
