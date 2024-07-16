#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *file = fopen("config.txt", "r");

	if(!file)
	{

		perror("fail to open");
		return EXIT_FAILURE;

	}
	fclose(file);
	return EXIT_SUCCESS;

}
