//创建一个空洞文件。
//这个程序我发现了一个新问题，不信你运行一遍就发现了,不骗你

#include <apue.h>
#include <fcntl.h>

char buf1[]  = "1234";
char buf2[]  = "ABCDFGHIJK";

int main()
{
    int fd;

    if((fd=creat("file.hole",FILE_MODE))<0)
	err_sys("creat error");

    if(write(fd,buf1,10)!=10)
	err_sys("buf1 write error");

    if(lseek(fd,16384,SEEK_END)== -1)
	err_sys("lseek error");

    if(write(fd,buf2,10)!=10)
	err_sys("buf2 write error");

    exit(0);
}
