#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int max(int n, ...);

int main(void)
{

    printf("The max value is %d\n", max(1, 2, 10, 46, 87));
    system("PAUSE");
    return 0;
}

int max(int n, ...)
{

    int i;
    va_list ap;      //定義va_list函數
    va_start(ap, n); //進行ap初始化,初始化後ap指向參考表中第一個參數
    int max = -0x7fffffff;
    int tmp;
    for (i = 0; i < n; i++)
    {

        tmp = va_arg(ap, int); //va_arg(ap,參數類型)出取後,指向下一個
        if (max < tmp)
            max = tmp;
    }
    va_end(ap);
    return max;
}