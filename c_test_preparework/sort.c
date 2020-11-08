#include <stdio.h>

void sort(int n, int *);
void sort_poniter(int n, int *);

int main(int argc, char *argv[])
{

    int n;
    int arr[] = {12, 6, 7, 10, 8};

    n = sizeof(arr)/sizeof(int);
    sort_poniter(n, arr);

    return 0;
}

void sort(int n, int arr[])
{

    //一個一個牌
    int totalcnt = n;
    while (totalcnt > 1)
    {
        totalcnt--;

        for (int i = 0; i < totalcnt; i++)
        {

            if (arr[i] > arr[i + 1])
            {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
            /**if( *ptr > *(ptr+1) ){
           
           int tmp = *ptr;
           *ptr = *(ptr+1);
           *(ptr+1) =tmp;
            } **/
        }
    }

    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("ANS =%d\n", arr[i]);
    }
}

void sort_poniter(int n, int *ptr)
{

    



    

    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("ANS =%d\n", *(ptr + i));
    }
}

