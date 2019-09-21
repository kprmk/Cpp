#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

char * sgets(char* str, int n);
char * getstr(char *str, int max);
int getstrs(char ** s, int ss[MAX]);
void pr(char **s, int m);
int mininStr(char * s);
int lastminsort(int nums[], int n);
char ** init(char ** strs, int n);
int MinWordLen(char * str);

int main(void)
{
	char ** strs = NULL;
	int strsize[MAX];
	strs = init(strs, MAX);
	int i = getstrs(strs, strsize);

	int ind = lastminsort(strsize, i);
	printf("\n\tMinWord--->Len = %d\n", strsize[ind]);
	printf("From string ---> %s", *(strs + ind));

	getchar();
	return 0;
}

char ** init(char ** strs, int n)
{
	strs = (char **)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; ++i)
	{
		*(strs + i) = (char *)malloc(sizeof(char) * n);
	}
	return strs;
}

int getstrs(char ** s, int ss[MAX])
{
	int a = 0;
	char * str = (char *)malloc(sizeof(char) * MAX);

	puts("ENTER STRS ACROSS \"ENTER\"");
	while ((str = sgets(str, MAX)) != NULL)
	{
		ss[a] = MinWordLen(str);
		memcpy(*(s + a), str, sizeof(char) * (strlen(str) + 1));
		a++;
	}
	ss[a] = '\0';
	return a;
}

char * sgets(char* str, int n)
{
	char * f;
	int i = 0;
	f = fgets(str, n, stdin);
	if (f)
	{
		while (str[i] != '\n' && str[i] != '\0')i++;
		if (str[i] == '\n')
			str[i] = '\0';
		else
			while (getchar() != '\n');
	}
	if (strlen(str) == 0)
		return NULL;
	return f;
}

void pr(char **s, int m)
{
	for (int i = 0; i < m; i++)
	{
		printf("%s\n", *(s + i));
	}
}

int MinWordLen(char * str)  //key == 1 -inword == 0 -outside
{
	char strW[] = "{}[]()1234567890-=/*-+.,@#$%^&	 ";
	int i = 0, a = strlen(str), b = 0, key = 0;
	while (str[i])
	{
		if (!strchr(strW, str[i]))
		{
			if (!key)
			{
				b = i;
				key = 1;
			}
			if (strchr(strW, str[i + 1]))
			{
				if (a > i + 1 - b)
				{
					a = i + 1 - b;
				}
				key = 0;
			}
		}
		i += 1;
	}
	return a;
}

int lastminsort(int nums[], int n)
{
	int min = 0, i;
	for (i = 1; i < n; i++)
	{
		if (nums[i] <= nums[min])
			min = i;
		//printf("%d\n", nums[min]);
	}
	return min;
}