#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// --- Рекурсивна генерація масиву ---
void Create(int* c, int size, int Low, int High, int i)
{
    c[i] = Low + rand() % (High - Low + 1);
    if (i < size-1) 
        Create(c, size, Low, High, i + 1);
}

// --- Рекурсивне виведення ---
void Print(int* c, const int size, int i)
{
    cout << setw(4) << c[i];
    if (i < size - 1)
        Print(c, size, i + 1);
    else
        cout << endl;
}

// --- Критерій ---
bool Criterion(int value, int index)
{
    return (value % 2 != 0) && (index % 13 != 0);
}

// --- Рекурсивний підрахунок ---
int CountSelected(int* c, const int size, int i)
{
    int count = 0;
    if (Criterion(c[i], i))
        count = 1;

    if (i < size - 1)
        return count + CountSelected(c, size, i + 1);

    return count;
}


int SumSelected(int* c, const int size, int i)
{
    int add = 0;
    if (Criterion(c[i], i))
        add = c[i];

    if (i < size - 1)
        return add + SumSelected(c, size, i + 1);

    return add;
}

void ReplaceWithZero(int* c, const int size, int i)
{
    if (!Criterion(c[i], i))
        c[i] = 0;

    if (i < size - 1)
        ReplaceWithZero(c, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));

    const int SIZE = 21;
    int c[SIZE];

    int Low = 15;
    int High = 85;

    // 1. Генерація
    Create(c, SIZE, Low, High, 0);

    // 2. Виведення
    cout << "Initial array:" << endl;
    Print(c, SIZE, 0);

    // 3. Підрахунок і сума
    int count = CountSelected(c, SIZE, 0);
    int sum = SumSelected(c, SIZE, 0);

    // 4. Заміна нулями
    ReplaceWithZero(c, SIZE, 0);

    // 5. Виведення результатів
    cout << "\nCount: " << count << endl;
    cout << "Sum: " << sum << endl;

    cout << "Modified array:" << endl;
    Print(c, SIZE, 0);

    return 0;
}