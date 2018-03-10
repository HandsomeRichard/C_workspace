#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *reverseString(char *s);

int main(void)
{

    char a[] = "abcd";
    //char a[4] = {'a','b','c'};

    //
    //int n = strlen(a);

    reverseString(a);

    printf("%s",a);
    system("PAUSE");
    return 0;
}

char *reverseString(char *s)
{

    //算個數最簡單方法
    int length;
    char *tmptr =s;
    for (length = 0; *s != '\0'; s++){
        length++;
    }
    printf("%d",length);
        
    s = tmptr;


    

    int last_pos = length-1;
    for(int i = 0; i < length/2; i++)
    {
        char tmp = s[i];
        s[i] = s[last_pos-i];
        s[last_pos-i] = tmp;
    }

    return s;
}