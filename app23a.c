#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>



void main(void)
{

printf("write %d\n",write(fd,"hello world",sizeof("helloi world ")));
printf("write %d\n",write(fd,"bye world",sizeof("bye world ")));

lseek(fd, 0, SEEK_SET);
perror("lseek");
memset(buffer, 0,sizeof(buffer));
length = read(fd, uffer, sizeof(buffer));

buffer[length] = '\0';

printf("Read : %s\t length %d\n",buffer, length);

for(i=0 ; i<length ; i++)
printf("buffer[%d]: \t%c\n",i,buffer[i]);

memset(buffer,o,sizeof(buffer));
buffer[length]='\0';

printf("Read %s \t length: %d\n",buffer ,length);

close(fd);
}
