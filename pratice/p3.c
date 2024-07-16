#include<stdlib.h>
#include<stdio.h>

int main()
{       
        
        FILE *file;
        char buffer[100];
        
        file = fopen("example.txt","r");
        if(file == NULL)
        {       
        perror("erroe opening a file");
        return -1;
        }
        
        fgets(buffer,100,file);
        printf("Read from file %s",buffer);
        fclose(file);
        
        return 0;
}

