#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// --- Генерація масиву ---
void Create(int* c, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        c[i] = Low + rand() % (High - Low + 1);
}

// --- Виведення масиву ---
void Print(int* c, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << c[i];
    cout << endl;
}

// --- Перевірка критерію ---
bool Criterion(int value, int index)
{
    return (value % 2 != 0) && (index % 13 != 0);
}

// --- Підрахунок кількості ---
int countSelected(const int c[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (Criterion(c[i], i))
            count++;
    return count;
}

// --- Сума відібраних ---
int sumSelected(const int c[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        if (Criterion(c[i], i))
            sum += c[i];
    return sum;
}

// --- Заміна відібраних елементів нулями ---
void replaceWithZero(int c[], int size)
{
    for (int i = 0; i < size; i++)
        if (Criterion(c[i], i))
            c[i];
        else
            c[i] = 0;
}

int main()
{
    srand((unsigned)time(nullptr));

    const int SIZE = 21;
    int c[SIZE];

    // 1. Генерація
    Create(c, SIZE, 15, 85);

    // 2. Виведення початкового масиву
    cout << "Initial array:" << endl;
    Print(c, SIZE);

    // 3. Обчислення
    int count = countSelected(c, SIZE);
    int sum = sumSelected(c, SIZE);

    // 4. Модифікація
    replaceWithZero(c, SIZE);

    // 5. Результати
    cout << "\nCount: " << count << endl;
    cout << "Sum: " << sum << endl;
    cout << "Modified array:" << endl;
    Print(c, SIZE);

    return 0;
}
