#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{	
int retval;
char buffer[10];
int pid; 

FILE *fp;

int fd=open("/dev/tty",O_RDWR);

//fp=fopen("10.c","w+");

if(fork())
{
printf("parent process execuing and write hello\n");
write(fd,"hello embedded p",sizeof("hello embedded"));
printf("close file\n");
}
else
{
printf("child process is executing and write a hello world\n ");
write(fd,"hello embedded",sizeof("hello embedded"));
printf("close child file\n");
}


return 0;
}
