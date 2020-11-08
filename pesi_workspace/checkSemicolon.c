#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkSemicolon(char *str);

int main()
{

    char *value = "704,Mick,Female;888,Richard,Female;984,POPO,Man;706,Mick2,Man";


    //return 1 代表有；分號

    //需要一個字串及一個字元當作參數，
    //然後搜尋字元在字串中第一次出現的位置，回傳該位置的指標
    printf("%d\n",checkSemicolon(value));
    //strchr(value,';');


    system("PAUSE");
    return 0;
}

int checkSemicolon(char *str)
{
    char *c = strchr(str, ';');
    if (c)
        return 1;
    return 0;
}