#include <stdio.h>

void swap(int *a , int *b);

int main(){

    
    int a = 5;
    int b = 7;

    //swap(&a,&b);
    //local change

    a = a-b;
    b = a+b;
    a = b -a;

    printf("a = %d\n",a);
    printf("b = %d\n",b);


    

    return 0;
}

void swap(int *a , int *b){

    int tmp = *a;
    *a = *b;
    *b = tmp;

}