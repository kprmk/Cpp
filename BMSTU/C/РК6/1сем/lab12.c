#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct emp {
	         char *p_str;
	         int num;
	         struct emp *next;
	       } *start=NULL;
void add_new(struct emp *element, char *word)
{
	struct emp *newstr;
	if((newstr=(struct emp*)malloc(sizeof(struct emp)))==NULL)
		printf("Memory allocation error!\n"), exit(1);
	newstr->p_str=word;
    newstr->next=element->next;
	element->next=newstr;
	newstr->num=1;
}
void create(void)
{
    	if((start=(struct emp*)malloc(sizeof(struct emp)))==NULL)
		printf("Memory allocation error!\n"), exit(1);
    	start->next=NULL;
}
void add(char *word)
{
	struct emp *helper=start->next;
	if(helper==NULL)
		add_new(start, word);
	else
	{
		while(strcmp(helper->p_str, word)!=0&&helper->next!=NULL)
			helper=helper->next;
		if(strcmp(helper->p_str, word)==0) 
        {     
          helper->num++; 
        } 
        else 
       add_new(helper, word);
	}
}
void output(void)
{
	struct emp *helper=start->next;
	while(helper!=NULL)
	{
		printf("%s\n   - %d\n", helper->p_str, helper->num);
		helper=helper->next;
	}
}
void free_emp(void)
{struct emp *helper; 
    while(start->next!=NULL) 
    { 
     helper=start->next; 
     start->next=helper->next; 
     free(helper->p_str); 
     free(helper); 
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
int main(void)
{create();
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
		     if (i==bs)
             {
              bs+=5;
              oldbuffer=buffer;
              buffer=packer(buffer, bs);
              free(oldbuffer);
              }
        }
    else if (i!=0)
		add(packer(buffer, i)), i=0;
    }		
if(i!=0)
		add(packer(buffer, i)), i=0;
output();
free_emp();
free(start);
}
