#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *setNthValue(int index, char *old_values, char *new_value);

int main()
{

    //setNthValue test
    char *putin;
    char *old_value = "704,Mick,Female;888,Richard,Female;984,POPO,Man;706,Mick2,Man";
    char new_value[9] = "OK,OK,OK";

    
    printf("old_value=%s\n",old_value);

    //說明:創一個putin的char pointer，透過setNthValue將以分號隔開
    //704,Mick,Female;888,Richard,Female;984,POPO,Man;706,Mick2,Man//
    //-------0-----------1-----------------2------------3----------//筆數資料
    //(0,old_value,new_value) →將第0筆資料更動成new_value的資料!!
    putin = setNthValue(0,old_value,new_value);

    

    printf("%s",putin);
    //輸出:OK,OK,OK;888,Richard,Female;984,POPO,Man;706,Mick2,Man
    system("PAUSE");
    return 0;
}



char *setNthValue(int index, char *old_values, char *new_value)
{
	int i;
	char *p, *q;
	static char ret[2048];
	char buf[8][256];

	memset(ret, 0, 2048);
	for (i = 0; i < 8; i++)
		memset(buf[i], 0, 256);

	//copy original values
	for ( i = 0, p = old_values, q = strchr(p, ';')  ;
	      i < 8 && q != NULL                         ;
	      i++, p = q + 1, q = strchr(p, ';')         )
	{
		strncpy(buf[i], p, q - p);
	}
	strcpy(buf[i], p); //the last one

	//replace buf[index] with new_value
	strncpy(buf[index], new_value, 256);

	//calculate maximum index
	index = (i > index)? i : index;

	//concatenate into a single string delimited by semicolons
	strcat(ret, buf[0]);
	for (i = 1; i <= index; i++) {
		strncat(ret, ";", 2);
		strncat(ret, buf[i], 256);
	}

	return ret;
}
