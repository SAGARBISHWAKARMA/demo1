#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define DEVICE_FILE "/dev/msg22"

int main(int argc ,char *argv[])
{
int fd;
int length;
char buffer[50];
int i=0;


printf("opening file %s\n",DEVICE_FILE);

fd = open(DEVICE_FILE, O_RDWR);

if(fd<0)
{
perror("open failed");
exit(2);
}

getchar();

printf("write : %ld\n ",write(fd,"hello world",sizeof("hello world")));
printf("write : %ld\n ",write(fd, "bye world ",sizeof("bye world")));

lseek(fd,0,SEEK_SET);
perror("lseek");

memset(buffer,0,sizeof(buffer));
length =read(fd,buffer,sizeof(buffer));

buffer[length] = '\0';

printf("read %s\t lenth %d\n",buffer,length);

for(i=0;i<length;i++)
printf("buffer[%d]: \t %c\n", i ,buffer[i]);

memset(buffer,0,sizeof(buffer));

length = read(fd, buffer,sizeof(buffer));
buffer[length]='\0';

printf("read %s \t length %d\n",buffer, length);
close(fd);
return 0;
}
