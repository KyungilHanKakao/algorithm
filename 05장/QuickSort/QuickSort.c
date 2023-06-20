#include <stdio.h>

void Swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

int Partition(int DataSet[], int Left, int Right)
{
    int First = Left;
    int pivot = DataSet[First];

    Left++;
    while (Left <= Right)
    {
        while ((pivot >= DataSet[Left]) && (Left < Right))
        {
            Left++;
        }
        while ((pivot <= DataSet[Right]) && (Left <= Right))
        {
            Right--;
        }
        if (Left < Right)
        {
            Swap(&DataSet[Left], &DataSet[Right]);
        }
        else
            break;
    }
    Swap(&DataSet[First], &DataSet[Right]);
    return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
    if (Left < Right)
    {
        int index = Partition(DataSet, Left, Right);

        QuickSort(DataSet, Left, index - 1);
        QuickSort(DataSet, index + 1, Right);
    }
}
