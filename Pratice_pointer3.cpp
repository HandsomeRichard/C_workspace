#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define DAY_ONE (60 * 60 * 24 * 365UL)
#define SQR(x) (x) * (x)

int main(void)
{

    // char s[] = "0113256";
    // char *p = s;

    // printf("%c\n",*p++);

    // printf("%c\n",*(p++) );

    // printf("%c\n",(*p)++);

    // printf("%c\n",*++p);

    // printf("%c\n",*(++p));

    // printf("%c\n",++*p);

    // printf("%c\n",++(*p));

    // printf(s);

    // int a[5] = {1,2,3,4,5};

    // for(int i=0 ; i<5 ;i++){

    //     cout << &a[i] << endl;
    // }

    // cout << "------------" <<endl;

    // int *p = (int *)(&a+1);
    // cout <<"p=" << p << endl;
    // cout << "*p=" << *p <<endl;
    // cout << "------------" <<endl;

    // cout << "*a=" << *a << endl;

    // cout << "&a="<<&a <<endl;
    // cout << "&a+1="<<(&a+1) <<endl;
    // cout << "&a+2="<<(&a+2) <<endl;

    // cout<< "*(a+1)=" <<  *(a+1) << endl;
    // cout<< "*(p-1)=" <<  *(p-1) << endl;

    // int a = 3,b = 5;

    // int c=0,d=0;

    // a = a ^b;
    // b = a ^b;
    // a = a ^b;

    // cout << a;
    // cout << b;
    // int a = 17;
    // int *c;
    // *c = a;
    // printf("c=%d ", *c);//17
    // printf("a=%d ", a);//17

    // *c = *c + 3;
    // printf("c=%d ", *c);
    // printf("a=%d ", a);
    // a = a + 5;
    // printf("c=%d ", *c);
    // printf("a=%d ", a);

    // int a=5,b=7,c=0;
    // c = a+++b;
    // printf("a=%d b=%d c=%d", a,b,c);

    // unsigned int a = 6;
    // int b = -20;

    // if (a + (unsigned int)b > 6)
    // {
    //     puts(">6");
    // }
    // else
    // {
    //     puts("<=6");
    // }

    //  cout << (a+b);
    // // (a+b>6) ? puts(">6"):puts("<=6");

    // char str[10] = "HELLO!";
    // int a = strlen(str);
    // int b = sizeof(str);

    // cout << "a=" << a;
    // cout << "b=" << b;

    // printf("%d", SQR(2+6));
    int a[5] = {1, 2, 3, 4, 5};
    const int *p = a; //a是一個陣列的首位址.p是指向常量的指標
    //*p = 2;
    *p++;

    // int *const p = a;       //a是一個陣列的首位址.p是指針常量；
    // *(p+1) = 9;
    // *p++;
    //const int *const p = a; //a是一個陣列的首位址。p是指向常量的指標常量

    //unsigned long a = 0x00001111;
    system("PAUSE");
    return 0;
}