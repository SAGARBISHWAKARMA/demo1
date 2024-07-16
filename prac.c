#include<stdi.h>
#include<stdlib.h>
#include<fnctl.h>

#define DEVICE "/dev/mydevice"


void main(void)
{
int fd;
int retval;
fd=open(DEVICE,O_RDWR);


getchar();

retval =write(fd,&user_struct,sizeof(user_struct));
printf("write retval %d\n",retval);

getchar();

user_struct.i=4;
user_struct.c='b';

retval= read(fd,&user_struct,sizeof(user_struct));
printf("read retval %d and %c\n",user_struct.i,user_struct.c);




}
