#include "Command.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>





CMD_T CMD_LIST[] = {

    /*指令名稱     對應函數       指令相關資訊*/
    {"list", listcmd, "list command"},
    {"show", showcmd, "show message"},
    {"add", add,      "add a and  b"},
    /*新增其他指令*/
    {"NULL", NULL, "NULL"},

};

int main(int argc, char *argv[])
{

    int result = parsecmd(argc, argv);

    return result;
}


int parsecmd(int argc,char* argv[]){

    int num_commands;
    if(argc ==1){

        printf("There is no command");
        return 0;

    }
    num_commands = getcmdmatch(argv[1]);
    //printf("num_commands=%d\n",num_commands);

    if(num_commands <0){

        printf( "%s is not a valid command\n",argv[1]);
        return -1;
    }
        

    if( CMD_LIST[num_commands].comfun != NULL){

        CMD_LIST[num_commands].comfun(argc,argv);
    }
    return 0;
}


int showcmd(int argc, char** argv){

    int i;
    printf("show: argc:%d\n",argc);

    for(i=1 ;i<argc;i++){

        printf("argv[%d]:%s\n",i,argv[i]);
    }

    return 0;
}

int add(int argc, char** argv){

    int result,a,b;
    if(argc!=4){
        //check param numbers
        printf("add wrong parameter number: %d\n",argc);
        return -1;

    }
        

    a= atoi(argv[2]);
    b= atoi(argv[3]);
    result = a+b;
    printf("add result:\n %d +%d = %d\n",a,b,result);

    return 0;
}



int listcmd(int argc,char *argv[]){

    int i;
    printf("<< List all command>>\n");
    printf("%8s  %s\n","name","info");

    for(i=0 ; CMD_LIST[i].cmdname != NULL ;i++){

        if(CMD_LIST[i].cmdinfo !=NULL){

            printf("%8s:%s\n",CMD_LIST[i].cmdname ,CMD_LIST[i].cmdinfo);
        }
    }

    return 0;
}


int getcmdmatch(char *cmdline)
{

    int i;
    for (i = 0; CMD_LIST[i].cmdname != NULL; i++)
    {

        /*尋找匹配的指令名稱*/
        /*需要兩個字串及一個整數 n 當作參數，共有三個參數。
        此函數比較兩個字串的前 n 個字元是否相等，相等就回傳 0，
        第一個字串大於第二個字串回傳正值，反之回傳負值。*/
        if( strncmp (CMD_LIST[i].cmdname , cmdline ,strlen( CMD_LIST[i].cmdname)) ==0 ){

            //返回匹配指令
            return i;
        }
    }
    return -1;
}