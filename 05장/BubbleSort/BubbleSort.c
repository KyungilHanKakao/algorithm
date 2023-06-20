#include "BubbleSort.h"
void Swap(int *left, int *right)
{
    int temp = *right;
    *right = *left;
    *left = temp;
}
void BubbleSort(int DataSet[], int Length)
{
    for (int i = 0; i < Length - 1; i++)
    {
        for (int j = 0; j < Length - (i + 1); j++)
        {
            if (DataSet[j] > DataSet[j + 1])
            {
                Swap(&DataSet[j], &DataSet[j + 1]);
            }
        }
    }
}
