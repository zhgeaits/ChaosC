#include <stdio.h>
#include <windows.h>
//link数组记录打印字符串数组的下标，实现链式打印字符串 
int link[15] = {-1,8,9,-1,-1,12,0,1,2,3,4,5,-1,14,-1};
//程序用到的字符串 
char *str[15];
init()
{
    str[0] = "  ***   ***  \n";
    str[1] = " *   * *   * \n";
    str[2] = "*China*Dream*\n";
    str[3] = "  *       *  \n";
    str[4] = "    *   *    \n";
    str[5] = "      *      \n";
    str[6] = "Please input your name:\n";
    str[7] = "Do you have a china dream?(choose one of the follow items):\n";
    str[8] = "A.Yes, I totally have a china dream.\n";
    str[9] = "B.NO, I lost in china now! Help me please!\n";
    str[10] = "Wow, I do believe you can have achieve your dream in china or in uestc!\n";
    str[11] = "Hey, handsome boy or pretty girl! Don't be upset, I will give you a china dream now!\n";
    str[12] = "-:), I hope that you will like it!\n";
    str[13] = "Thank you! My name is zhangge from UESTC!\n";
    str[14] = "Here is my email:zhgeaits@gmail.com, contact me if you like me!\n";
}
//递归打印字符，链式打印字符串，使用putchar，非printf 
//next参数记录下一个要打印字符串的下标  next是link数组的值 
recur_put(char *pstr,int *next)
{
	(*pstr)!='\0'?putchar(*pstr),recur_put(++pstr,next):(Sleep(1000),((*next)==-1?1:recur_put(str[*next],next+1)));
}
//读取用户的选项 
char readchar()
{
    return getchar() != '\n'?readchar():getchar();
}
//欢迎信息 
int welcome()
{
    char name[32];
    scanf("%s",name);
    Sleep(1000);
    printf("Hi, %s! Welcome to China!\n",name);
    Sleep(1000);
}
main()
{
    init();
    recur_put(str[6],&link[0]);
    welcome();
    recur_put(str[7],&link[1]);
    switch(readchar())
    {
	case 'A':recur_put(str[10],&link[4]);break;
	case 'B':recur_put(str[11],&link[5]);
    }
    recur_put(str[13],&link[14]);
}