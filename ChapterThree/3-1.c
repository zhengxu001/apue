//用于测试能否对其标准输入设置偏移量
#include <apue.h>

int main(void)
{
    if(lseek(STDIN_FILENO,0,SEEK_CUR) == -1)
	printf("cannot seek\n");
    else
	printf("seek OK\n");

    exit(0);
}
