#include <stdio.h>

void setNum(int *num2);
//void setNum_PassReference(int &num2);

int main(int argc, char *argv[])
{
    int num1 = 2;
    printf("before setNum(), num1: %d\n", num1);

    setNum(&num1);
    //setNum_PassReference(num1);
    printf("123 = %d",sizeof(long));

    printf("after setNum(), num1: %d\n", num1);

    char str[] = "Hello" ;
    char *p = str ;
    printf("sizeof(str) = %d\n", sizeof(str));
    printf("sizeof(p) = %d\n", sizeof(p));
}

void setNum(int *num2)
{
    printf("before setting, num2: %d\n", *num2);
    *num2 = 5;
    printf("after sett ing, num2: %d\n", *num2);
}

/**void setNum_PassReference(int &num2) 
{   
    //這種寫法放入到C不能，要用C++編譯器才能WORK
    printf("before setting, num2: %d\n", num2);
    num2 = 5;
    printf("after setting, num2: %d\n", num2);
}**/