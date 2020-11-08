#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MULT(x, y) x * y

void functionTest1(char *);

int main(int argc, char const *argv[])
{
    char *str;
    str = (char *)malloc(100*sizeof(char));
    strcpy(str,"hello!");
    printf("str = %s\n",str);

    functionTest1(str);  //local variable usage

    printf("functionTest1 = %s\n",str);

    

    //macro陷阱
    printf("MULT = %d\n",MULT(1+1,2+2)); // 1+1 * 2+2 會被展開 =>先乘除後加減

    return 0;
}
void functionTest1(char *p){

    p = (char *)malloc(100*sizeof(char));
    strcpy(p,"functionTest1");
    return;
    
}


#if 0
int (*a)(int); // 一個指向函數的指標，該函數有一個整數型參數並返回一個整數
int *a (int);  //這2個很像的東西，意思不一樣
swap2題 : 一般可以利用變數存tmp

不能利用額外變數:
swap(int a, int)
Ans之一:
a  = a-b;
b =  a +b;
a = b -a;

Macro陷阱+搭配inline //inline題目忘了



OOP 三大 :多型 、繼承、封裝 的說明
#endif
