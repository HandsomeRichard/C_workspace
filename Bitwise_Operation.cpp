#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int count_bit_1(int n);
int bit_5_to1(int n);
int reverseBit5(int n);
int bit_5_to1_Method2(int n);
int GetBitsN(int,int);
int main(void)
{
    //left shift
    //5 = 0101(B) 全部位元向左移 1010(B)=10
    //在十進位當中，當全部位數向左移動一位時，數值大小會變成原來的十倍
    //向左移動兩位時，會變成原來的百倍。這種情形在二進位也是成立的
    //當全部位元向左移動一位時，會變成原來的兩倍，向左移動兩位時，會變成原來的四倍。至於往右移動也是類似道理，變成了除法而已。
    int n = 5;
    cout << "-----------------------" << endl;
    cout << "n=" << n <<"    "<< "left shift"<< endl;
    cout << (n << 1) << endl;
    cout << "-----------------------" << endl;
    cout << endl;


    //right shift
    //5=0101(B) 全部向右移 0010(B)=2
    n = 5;
    //cout << (n >> 1) << endl;
    // 即是 n = n / 2 之意。
    /* 該式子也可寫成 n >>= 1 或 n /= 2。 */

    //& AND (X)原理
    // 0 & 0 = 0
    // 0 & 1 = 0
    // 1 & 0 = 0
    // 1 & 1 = 1
    //=>& 的特色，就是可以判斷出位元是不是 1 。例如我們想要數一個變數有幾個位元是 1
    n = 42;

    //cout << count_bit_1(n) << endl;
    //cout << (116&41);

    //| OR (+)原理
    // 0 | 0 = 0
    // 0 | 1 = 1
    // 1 | 0 = 1
    // 1 | 1 = 1

    //=>| 的特色 | 的特色，就是把位元強制標記成 1 。例如我們想要把五位數標成 1
    cout << (116|41) << endl;
    cout <<"1."<< bit_5_to1(n) << endl;
    cout <<"Method2." << bit_5_to1_Method2(n) <<endl;

    cout<< endl;

    //如何擷取input 第n個bit?
    cout << "getbitsfromN = " << GetBitsN(n,5) <<endl; //‭00101010‬


    //XOR (^) 
    // 0 ^ 0 = 0
    // 0 ^ 1 = 1
    // 1 ^ 0 = 1
    // 1 ^ 1 = 0
    //=> ^ 的特色，就是把位元的 0 和 1 顛倒。例如我們想要顛倒第五位數：
    cout << reverseBit5(n)<< endl;


    system("PAUSE");
    return 0;
}

int count_bit_1(int n)
{
    // 由右往左看n的每一個位元。
    int c = 0;
    for (int i = 0; i < 32; ++i) // int變數有32個位元
        if (n & (1 << i))
        {
            c++;
            //cout << (1<<i)<<endl;
        }

    return c;
}

int GetBitsN(int input , int N){


    cout << (1<<(N-1)) << endl;
    cout <<( input & (1<<(N-1)) ) << endl;

    cout << (   (input & (1<<(N-1)) )  >> (N-1)   ) << endl;

    return (   (input & (1<<(N-1)) )  >> (N-1)   );

}


int bit_5_to1(int n)
{

    return (n | (1 << 4) );
    
}
int bit_5_to1_Method2(int n)
{

    return (n | 16 );
    
}


int reverseBit5(int n){

    return n ^ (1<<4);

}