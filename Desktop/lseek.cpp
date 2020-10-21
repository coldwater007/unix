#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<limits.h>
int main()
{
    if(lseek(STDIN_FILENO,0,SEEK_CUR)==-1)
        printf("cannot seek\n");
    else
        printf("seek ok\n");
    exit(0);
}



s
