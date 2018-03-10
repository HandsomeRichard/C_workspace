#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(void)
{

    char str[] = "Hello World";
    char *p = str;
    short a;
    int b;
    long c;
    float d;
    double e;

    cout << "str=" << sizeof(str) << endl;
    cout << "*p=" << sizeof(*p) << endl;
    cout << "p=" << sizeof(p) << endl;

    cout << "short=" << sizeof(a) << endl;
    cout << "int=" << sizeof(b) << endl;

    cout << "long=" << sizeof(c) << endl;
    cout << "float=" << sizeof(d) << endl;
    cout << "double=" << sizeof(e) << endl;

    cout << "-------------------" << endl
         << endl;
    //--------------------***********----------------//
    char str1[10] = "hello!";
    int f = strlen(str);
    int g = sizeof(str);
    cout << "strlen(str)" << strlen(str1) << endl;
    cout << "sizeof(str)" << sizeof(str1) << endl;

    //--------------------***********----------------//

    int h[] = {1, 2, 3, 4, 5, 6};
    int *pointer = h;

    // for(int i =0; i< sizeof(h) / sizeof(int) ;i++){
    //     cout << *pointer;
    //     *pointer ++;

    // }

    *(pointer++) += 100; //++在後，先取值(先做+=100)→移動指標
    *(++pointer) += 100; //++在前，先移動指標→再取值

    for (int i = 0; i < 6; i++){
        cout << h[i] << endl; //→Ans: 101,2,103,4,5,6
    }


        

    system("PAUSE");
    return 0;
}