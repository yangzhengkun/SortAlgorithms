//
// Created by yangzhengkun on 2018/7/31.
//

#include <iostream>

namespace sort
{
    class Sort
    {
    private:
        template<typename T>
        void swap(T *a, T *b)
        {
            auto temp = *a;
            *a = *b;
            *b = temp;
        }

    public:
        // 选择类排序：简单选择排序
        // 思想：每一次从未排序部分中选择最小的元素，并将其与未排序部分的第一个进行交换
        template<typename T>
        void selectSort(T arr[], int n)
        {
            auto minIndex = -1;
            for (int i = 0; i < n - 1; ++i)
            {
                minIndex = i;
                for (int j = i + 1; j < n; ++j)
                {
                    if (arr[j] < arr[minIndex])
                        minIndex = j;
                }
                swap(&arr[minIndex], &arr[i]);
            }
        }

        // 交换类排序：冒泡排序
        // 思想：每一趟都不断地将一个未排序部分最大的元素往后排--沉底
        template<typename T>
        void bubbleSort(T arr[], int n)
        {
            for (int i = n - 1; i > 0; --i)
            {
                for (int j = 0; j < i; ++j)
                {
                    if (arr[j] > arr[j + 1])
                        swap(&arr[j], &arr[j + 1]);
                }
            }
        }

        // 冒泡排序的递归写法
        template<typename T>
        void bubbleSortRecursive(T arr[], int n)
        {
            if (n == 1)
                return;
            for (int i = 0; i < n - 1; ++i)
            {
                if (arr[i] > arr[i + 1])
                    swap(&arr[i], &arr[i + 1]);
            }
            bubbleSortRecursive(arr, n - 1);
        }

        // 交换类排序：快速排序
        // 对[left,right]区间内的元素进行排序
        template<typename T>
        void quickSort(T arr[], int left, int right)
        {
            T temp;
            int i = left, j = right;
            if (left < right)
            {
                temp = arr[left];

                while (i != j)
                {
                    while (i < j && arr[j] > temp)
                        --j;
                    if (i < j)
                    {
                        arr[i] = arr[j];
                        ++i;
                    }

                    while (i < j && arr[i] < temp)
                        ++i;
                    if (i < j)
                    {
                        arr[j] = arr[i];
                        --j;
                    }
                }
                arr[i] = temp;
                quickSort(arr, left, i - 1);
                quickSort(arr, i + 1, right);
            }
        }

        // 插入类排序：简单插入排序
        template<typename T>
        void insertionSort(T arr[], int n)
        {
            int j;
            for (int i = 1; i < n; ++i)
            {
                auto key = arr[i];
                j = i - 1;
                while (j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    --j;
                }
                arr[j + 1] = key;
            }
        }
    };
}

using namespace sort;
using namespace std;

template<typename T>
void printArray(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {12, 23, 10, 16, 43, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
//    Sort().selectSort(arr, n);
//    Sort().bubbleSort(arr, n);
//    Sort().quickSort(arr, 0, n - 1);
    Sort().insertionSort(arr, n);
    printArray(arr, n);
}