#ifndef  _COMMAND_H
#define  _COMMAND_H

/*嵌入式Linux c語言程式設計實務 p340 10.3 函數指標使用範例*/

typedef int (*cmdfun_t) (int argc ,char *argv[]);
/*表示指令的結構體包含指令名；指令函數；*/
/*(*cmdfun_t) 指令函數的原型*/

typedef struct {

    char *cmdname;  /*指令名稱*/
    cmdfun_t  comfun; /*對應函數*/
    char *cmdinfo;  /*指令相關資訊*/
    
 
}CMD_T;


int parsecmd(int argc,char* argv[]);
//parsecmd 接受外部傳入的參數

int getcmdmatch(char *cmdline);
int listcmd(int argc,char *argv[]);
int showcmd(int argc, char** argv);
int add(int argc, char** argv);


#endif