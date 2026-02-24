#include <iostream>
#include <vector>
using namespace std;

// Алгоритм 13: Просеивание i-ого элемента в куче
void siftDown(vector<int> &A, int i, int N)
{
    while (true)
    {
        int parent = i;        // полагаем, что i-тый элемент является максимальным
        int left = 2 * i + 1;  // левый ребенок
        int right = 2 * i + 2; // правый ребенок

        // если есть левый ребенок, находим максимум между ним и родителем
        if (left < N && A[left] > A[parent])
        {
            parent = left;
        }

        // если есть правый ребенок, находим максимум между ним и родителем
        if (right < N && A[right] > A[parent])
        {
            parent = right;
        }

        // если максимум - это родитель, прекращаем цикл
        if (parent == i)
        {
            break;
        }

        // иначе меняем местами максимум и родителя
        swap(A[i], A[parent]);
        i = parent; // i = max
    }
}

// Алгоритм 14: Пирамидальная сортировка
void heapSort(vector<int> &A, int N)
{
    // строим пирамиду (цикл для i = N/2 до 0)
    for (int i = N / 2; i >= 0; i--)
    {
        siftDown(A, i, N);
    }

    // извлекаем элементы из пирамиды (цикл для i = N-1 до 1)
    for (int i = N - 1; i > 0; i--)
    {
        swap(A[0], A[i]);  // меняем местами a[0] и a[i]
        siftDown(A, 0, i); // перестраиваем пирамиду
    }
}

// Вспомогательная функция для вывода массива
void printArray(const vector<int> &A)
{
    for (int val : A)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int N = arr.size();

    cout << "Исходный массив: ";
    printArray(arr);

    heapSort(arr, N);

    cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}