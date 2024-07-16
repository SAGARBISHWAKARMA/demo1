#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

void main(int arg, char *argv[])
{

char buffer[50];
int fd;
int length;
int i=0;

fd = open("/dev/msg3",O_RDWR);

if(fd < 0)
{
perror("fd failed");
exit(2);
}	

printf("write %d\n",write(fd,"hello world",sizeof("helloi world ")));
printf("write %d\n",write(fd,"bye world",sizeof("bye world ")));

lseek(fd, 0, SEEK_SET);
perror("lseek");
memset(buffer, 0,sizeof(buffer));
length = read(fd, buffer, sizeof(buffer));

buffer[length] = '\0';

printf("Read : %s\t length %d\n",buffer, length);

for(i=0 ; i<length ; i++)
printf("buffer[%d]: \t%c\n",i,buffer[i]);

memset(buffer,o,sizeof(buffer));
buffer[length]='\0';

printf("Read %s \t length: %d\n",buffer ,length);

close(fd);
}
