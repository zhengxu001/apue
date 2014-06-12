#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);

int main(void)
{	
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if(signal(SIGINT,sig_int)==SIG_ERR)
	err_sys("signal error");

    printf("%% ");

    while(fgets(buf,MAXLINE,stdin) != NULL){
	printf("pid come from child ID %d\n",getpid());
        if(buf[strlen(buf)-1]=='\n')
	    buf[strlen(buf)-1]=0;
	if((pid=fork())<0){
	    err_sys("fork error");
	}else if(pid ==0 ){  /*child*/
	    execlp(buf,buf,(char *)0);
	    printf("pid come from child ID %d\n",getpid());
	    err_ret("couldn't execute: %s",buf);
	    exit (127);
	}

	/*parent*/
	if((pid = waitpid(pid,&status,0))<0)
	{
	    err_sys("waitpid error");
	    printf("pid come from parent ID %d\n",getpid());
        }
        printf("%%");
    }
    exit(0);
}

void sig_int(int signo)
{
    printf("interrupt\n%%");
}
