#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct stack {
             char *p_str;
             struct stack *p_stek;
             } *start=NULL;
void push(char *word)
{struct stack *MyStack;
   if((MyStack=(struct stack*)malloc(sizeof(struct stack)))==NULL)
		printf ("Memory allocation error!\n"), exit(3);
MyStack->p_stek=start;
MyStack->p_str=word;
start=MyStack; 
}
void pop(char **out)
{struct stack *cleaner;
    if (start!=NULL)
    {
		cleaner=start;
		*out=start->p_str;
		start=start->p_stek;
		free(cleaner);
    }
	else
		printf("Stack is empty\n");
}

void write(FILE *file) 
{ 
char *out; 
  while (start!=NULL) 
  { 
   pop(&out); 
   fwrite(out, strlen(out), sizeof(char), file); 
   fputc('\n', file); 
   free(out); 
  } 
}
char *packer(char buffer[], int i)
{char *memory;
   if ((memory=malloc(i+1))==NULL)
   {
    printf("Memory allocation error!\n");
    exit(2);
   }
memory[i]='\0';
    for (i--; i>=0; i--)
      memory[i]=buffer[i];
return memory;
}

int main(int argc, char *argv[])
{int i=0, bs=10;
char *buffer, *oldbuffer, s;
    if (argc!=2)
	{printf("Error in the input file name");
		exit(6);
	}
FILE *file;
file=fopen(argv[1], "w");
	if(file==NULL)
	{
		printf("Open failed!\n");
		exit(4);
	}

  if ((buffer=malloc(bs))==NULL)
   {
    printf("Memory allotation error!\n");
    exit(1);
   }
  while ((s=getchar())!='0')
   {
    if (isalpha(s))
    {
     buffer[i]=s;
     i++;
     if (i==bs)
     {
      bs+=10;
      oldbuffer=buffer;
      buffer=packer(buffer, bs);
      free(oldbuffer);
     }
    }
	if ((s==' ' || s=='\t' || s=='\n') && (i!=0))
     push(packer(buffer, i)), i=0;
}	
	if(i!=0)
		push(packer(buffer, i)), i=0;
write(file);
}


