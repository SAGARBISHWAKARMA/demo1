#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

#define DEVICE_FILE "/dev/msg20"


int main()
{
int fd;
int retval;
char buffer[10];
int i;

printf("opening files %s",DEVICE_FILE);
fd =open(DEVICE_FILE,O_RDWR);

if(fd < 0)
{
perror("open fail");
exit(1);
}

getchar();

retval =write(fd ,"hello",5);
printf("write retval : %d\n",retval);
getchar();

for(i=0;i<10;i++)
{
	retval = read(fd ,buffer,1);

printf("read retval: %d\n",retval);
printf("read buffer : %c\n",buffer[i]);

}

printf("close file \n");
close(fd);

getchar();

}
