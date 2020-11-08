#include <stdio.h>
#include <stdlib.h>
#include <string.h>


////Z:\B5328\SDK\source\component\standalone\httpd\cgi\utils.cgi.c
int getNthValueSafe(int index, char *value, char delimit, char *result, int len);


int main()
{

    //getNthValueSafe test
    char putin[200];
    char *value = "704,Mick,Female;888,Richard,Female;984,POPO,Man;706,Mick2,Man";
    //自動分割；接著搜尋第0筆資料為 704,Mick,Female，最後將字串放入putin這個array
    getNthValueSafe(0, value, ';', putin, sizeof(putin));
    printf("%s",putin);


    system("PAUSE");
    return 0;
}


int getNthValueSafe(int index, char *value, char delimit, char *result, int len)
{
    int i = 0, result_len = 0;
    char *begin, *end;

    if (!value || !result || !len)
        return -1;
    begin = value;
    end = strchr(begin, delimit);
    while (i < index && end)
    {
        begin = end + 1;
        end = strchr(begin, delimit);
        i++;
    }
    //no delimit
    if (!end)
    {
        if (i == index)
        {
            end = begin + strlen(begin);
            result_len = (len - 1) < (end - begin) ? (len - 1) : (end - begin);
        }
        else
            return -1;
    }
    else
        result_len = (len - 1) < (end - begin) ? (len - 1) : (end - begin);
    memcpy(result, begin, result_len);
    *(result + result_len) = '\0';

    return 0;
}
