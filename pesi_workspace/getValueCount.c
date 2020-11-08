#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getValueCount(char *values);
////Z:\B5328\SDK\source\component\standalone\httpd\cgi\utils.cgi.c

int main()
{

    char *value = "704,Mick,Female;888,Richard,Female;984,POPO,Man;706,Mick2,Man";
    int count = getValueCount(value);

    //以分號分割三個分號=>4筆資料
    printf("count=%d",count);
    //Count = 4

    system("PAUSE");
    return 0;
}

int getValueCount(char *values)
{
    int cnt = 0;

    if (NULL == values)
        return 0;
    while (*values++ != '\0')
    {
        if (*values == ';')
            ++cnt;
    }
    return (cnt + 1);
}
