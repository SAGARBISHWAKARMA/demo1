#include<stdio.h>
#include<sys/ioctl.h>
#include<fcntl.h>


int main()
{       
int fd;
unsigned long num_blocks;

fd = open("/dev/sda1", O_RDONLY);

perror("fd");


//0x00001260 BLKGETSIZE unsigned long
 
ioctl(fd,0x00001260,&num_blocks);

perror("ioctl");

printf("number of block %lu this make %.3f gb \n",num_blocks,(double)num_blocks * 512 /(1024*1024*1024)); 
 
close(fd); 

return 0;
 
 
 
 
}
