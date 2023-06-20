#include <stdio.h>
#include <string.h>

void InsertionSort(int DataSet[], int Length)
{
    for (int i = 1; i < Length; i++)
    {
        if (DataSet[i] > DataSet[i - 1])
            continue;

        int value = DataSet[i];
        for (int j = 0; j < i; j++)
        {
            if (DataSet[j] > DataSet[i])
            {
                memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
                DataSet[j] = value;
                break;
            }
        }
    }
}
