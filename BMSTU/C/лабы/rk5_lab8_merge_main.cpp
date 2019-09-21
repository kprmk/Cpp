#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 13

void printMass(int mass[], int size)
{
    int i;
    printf("Array: ");
    for (i = 0; i < size; ++i)
    {
        printf("%d ", mass[i]);
    }
    printf("\n");
}

void rightCycleShift(int mass[], int size)
{
    int i, temp = mass[size - 1];
    for (i = size - 1; i > 0; --i)
    {
        mass[i] = mass[i - 1];
    }
    mass[0] = temp;
}

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int minElement(int mass[], int size)
{
    int i, minIndex = 0;
    
    for (i = 1; i < size; ++i)
    {
        if (mass[i] < mass[minIndex])
            minIndex = i;
    }
    
    return minIndex;
}

int maxElement(int mass[], int size)
{
    int i, maxIndex = 0;
    
    for (i = 1; i < size; ++i)
    {
        if (mass[i] > mass[maxIndex])
            maxIndex = i;
    }
    
    return maxIndex;
}

void threeSort(int mass[])
{
    if (mass[0] > mass[1])
    {
        if (mass[1] >= mass[ 2])
        {
            swap(mass, mass + 2);
            return;
        }
        else
        {
            swap(mass, mass + 1);
            return;
        }
    }
    else if (mass[0] == mass[1])
    {
        if (mass[1] > mass[2])
        {
            swap(mass, mass + 2);
            return;
        }
    }
    else
    {
        if (mass[1] > mass[2])
        {
            swap(mass + 1, mass + 2);
            return;
        }
    }
}

void mergeBuf(int mass[], int leftSize, int rightSize)
{
    int i, leftI = 0, rightI = leftSize, mergedSize = leftSize + rightSize;
    int *mergedMass = (int*)malloc(mergedSize * sizeof(int));
    
    for (i = 0; i < mergedSize; ++i)
    {
        if (leftI >= leftSize)
        {
            mergedMass[i] = mass[rightI];
            ++rightI;
            continue;
        }
        
        if (rightI >= mergedSize)
        {
            mergedMass[i] = mass[leftI];
            ++leftI;
            continue;
        }
        
        if (mass[leftI] < mass[rightI])
        {
            mergedMass[i] = mass[leftI];
            ++leftI;
        }
        else
        {
            mergedMass[i] = mass[rightI];
            ++rightI;
        }
    }
    
    memcpy(mass, mergedMass, mergedSize * sizeof(int));
    free(mergedMass);
}

void merge(int mass[], int leftSize, int rightSize)
{
    int leftI = 0, rightI = leftSize;
    
    while(rightI < leftSize + rightSize)
    {
        if (leftI == rightI)
        {
            break;
        }
        
        if (mass[leftI] < mass[rightI])
        {
            ++leftI;
            continue;
        }
        
        rightCycleShift(mass + leftI, rightI - leftI + 1);
        ++leftI;
        ++rightI;
    }
}

void mergeSort(int mass[], int size)
{
    if (size <= 1)
        return;
    else if (size == 2)
    {
        if (mass[0] > mass[1])
            swap(mass, mass + 1);
        
        return;
    }
    else if (size == 3)
    {
        threeSort(mass);
        return;
    }
    else
    {
        int leftSize = (size - 1) / 2 + 1, rightSize = size - leftSize; // при нечетном size левая часть массива будет больше
        //int leftSize = size / 2, rightSize = size - leftSize; // при нечетном size правая часть массива будет больше
        
        mergeSort(mass, leftSize);
        mergeSort(mass + leftSize, rightSize);
        // Вариант с дополнительным выделением памяти
        mergeBuf(mass, leftSize, rightSize);
        // Вариант без дополнительного выделения памяти
        //merge(mass, leftSize, rightSize);
    }
}

int main()
{
    int arr[N] = { 0, 5, 11, 16, 0, 5, 0, 7, 1, 1, 19, 17, -100 };
    printMass(arr, N);
    
    mergeSort(arr, N);
    printMass(arr, N);
    
    getchar();
    return 0;
}
