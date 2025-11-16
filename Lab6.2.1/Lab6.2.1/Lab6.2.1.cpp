#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Генерація масиву 
void Create(int* a, int n, int Low, int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// --- Форматований вивід ---
void Print(const int* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// --- Функція, що ОБЧИСЛЮЄ середнє арифметичне елементів з парними індексами ---
double AverageEvenIndex(const int* a, int n)
{
    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i += 2) // тільки парні індекси
    {
        sum += a[i];
        count++;
    }

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
    Create(a, n, Low, High);

    // 2. Виведення масиву
    cout << "Array:" << endl;
    Print(a, n);

    // 3. Обчислення (функція нічого не виводить сама!)
    double avg = AverageEvenIndex(a, n);

    // 4. Виведення результату
    cout << "\nAverage (even indexes) = " << avg << endl;

    return 0;
}