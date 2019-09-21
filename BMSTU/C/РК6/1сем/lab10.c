#include <stdio.h>
#include <stdlib.h>
#define ST 3

char *packer(char buffer[], int i)
{
	char *memory;
	if((memory=malloc(i+1))==NULL)
	{
		printf("Memory allocation error!\n");
		exit(1);
	}
	memory[i]='\0';
	for(i--; i>=0; i--)
		memory[i]=buffer[i];
	return memory;
}

void output(char *lines[], int j)
{
	int i=0;
	for(i=0; i<j; i++)
	{
		printf("%s\n", lines[i]);
	}
}

void input(char *lines[ST], int *j)
{
	int i=0, s, bs=5;
	char *buffer, *oldbuffer;
	if((buffer=malloc(bs))==NULL)
	{
		printf("Memory allocation error!\n");
		exit(2);
	}
	while((s=getchar())!='0')
	{
		if((s!=' ') && (s!='\t') && (s!='\n'))
		{
			buffer[i]=s, i++;
		}
		if(s=='\n')
		{
			if((*j)==ST)
				printf("Too many lines!\n"), exit(2);
			lines[*j]=packer(buffer, i);
			i=0;
			(*j)++;
		}
		if(i==bs)
		{
			bs+=5;
			oldbuffer=buffer;
			buffer=packer(buffer, bs);
			free(oldbuffer);
		}

	}
	if(i>0)
	{
		if((*j)==ST)
			printf("Too many lines!\n"), exit(2);
		lines[*j]=packer(buffer, i);
		i=0;
		(*j)++;
	}
}

void free_lines(char *lines[], int j)
{
	for(j--; j>=0; j--)
	{
		free(lines[j]);
	}

}

int main(void)
{	
	int j=0;
	char *lines[ST];
	input(lines, &j);
	output(lines, j);
	free_lines(lines, j); 
	j=0;
	return 0;
}
