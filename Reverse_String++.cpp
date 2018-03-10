#include <iostream>
#include <string>
using namespace std;

// Given s = "hello", return "olleh".

class Solution
{

  public:
    string reverseString(string s)
    {

        int n = s.size();
        for(int i = 0; i < n/2; i++) {
            swap(s[i], s[n - 1 - i]);
        }
        return s;

        //!!!!Memory Limit Exceeded!!!!
        // string  result= "";
        // for(int i= 0 ;i< s.length() ;i++){
        //     result = s[i] + result ; ///take the newest character and add it before what we have already     
        // }
            
        // return result;

    }
};



int main(void)
{
    Solution solution;
    cout <<solution.reverseString("abcd");

    system("PAUSE");
    return 0;
}