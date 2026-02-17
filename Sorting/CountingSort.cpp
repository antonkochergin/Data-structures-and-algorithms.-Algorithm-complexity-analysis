#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(int a[], int N, int mx)
{
    // Находим минимальное значение в массиве
    int mn = a[0];
    for (int i = 1; i < N; i++)
    {
        if (a[i] < mn)
            mn = a[i];
    }

    // Корректируем размер массива с учетом отрицательных
    int range = mx - mn + 1;
    int *b = new int[range]();

    // Подсчет элементов со смещением на minVal
    for (int i = 0; i < N; i++)
    {
        b[a[i] - mn]++;
    }

    // Вывод с обратным смещением
    for (int i = 0; i < range; i++)
    {
        for (int j = 0; j < b[i]; j++)
        {
            cout << i + mn << " ";
        }
    }

    delete[] b;
}

int main()
{
    // Пример с отрицательными числами
    int a[] = {-5, 3, -2, 4, -8, 1, -3, 4, -2, 7};
    int n = sizeof(a) / sizeof(a[0]);
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > mx)
            mx = a[i];
    }

    countingSort(a, n, mx);
    cout << endl;

    return 0;
}