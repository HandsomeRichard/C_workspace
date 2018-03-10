#include <stdlib.h>
#include <stdio.h>

void swap(int *, int *);
void bubbleSort(int[], int);
void printALL(int [],int );

int main()
{

    //bubble sort

    int a[] = {5, 1, 4, 2, 8,9};

    int length = sizeof(a) / sizeof(a[0]);

    bubbleSort(a, length);

    printALL(a,length);

    system("PAUSE");
    return 0;
}

void bubbleSort(int a[], int N)
{

    for (int i = 0; i < N - 1; i++)
    {

        for (int j = 0; j < N - i-1; j++)
        {

            if (a[j] > a[j + 1])
            {

                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void swap(int *x, int *y)
{

    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}



void printALL(int a[],int length){


    for(int i= 0 ; i< length ;i++){

        printf("%d",a[i]);
    }


}