#include <iostream> 
using namespace std; 

int main() {
    int p = 10; 
    int *ptr = &p; 
    int **ptr2 = &ptr1; 

    cout << "p value" << p 
         << endl; 
    cout << "p address : " << &p 
         << endl;
    cout << "*ptr: " << *ptr 
         << endl; 
 
    cout << "ptr address: " << ptr 
         << endl; 
    cout << "ptr trueAdress: " << &ptr 
         << endl; 
    
    system("PAUSE");     
    return 0; 
}