#include "apue.h"
int main(void)
{
    printf("hello world from process ID %d", getpid());
    exit(0);
}
