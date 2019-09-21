#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

char * sgets(char* str, int n);
char * getstr(char *str, int max);
int getstrs(char ** s, int[MAX]);
void pr(char **s, int m);
int mininStr(char * s);
int minsort(int nums[], int n);
char ** init(char ** strs, int n);


int main(void)
{
	char ** strs = NULL;
	int strnum[MAX];
	strs = init(strs, MAX);
	int i = getstrs(strs, strnum);
	/*for(int j=0; j<i; j++)
	{
	printf("\n\tMIN = %d\n", strnum[j]);
	}*/
	int ind = minsort(strnum, i);
	printf("\n\tMIN = %d\n", strnum[ind]);
	printf(" %s", *(strs + ind));

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
	while ((str = getstr(str, MAX)) != NULL)
	{
		ss[a] = mininStr(str);
		*(s + a) = (char*)memcpy(*(s + a), str, sizeof(char) * (strlen(str) + 1));
		a++;
	}
	ss[a] = '\0';
	return a;
}

char * getstr(char *str, int max)
{
	int i = 0;
	char c;
	while ((c = getchar()) != '\n')
	{
		if (i < max - 1)
		{
			str[i++] = c;
		}
		else
		{
			puts("ERROR");
			while ((c = getchar()) != '\n');
			break;
		}
	}
	str[i] = '\0';
	if (strlen(str) == 0)
		return NULL;
	return str;
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

int mininStr(char * s)
{
	int num = 1000000, i = 0, n = 0;
	while (s[i])
	{
		if (isdigit(s[i]))
		{
			n = 10 * n + s[i] - '0';
			/*printf("%d\n", n);*/
			if (!isdigit(s[i + 1]))
			{
				if (n < num)
					num = n;
				n = 0;
			}
		}
		i++;
	}
	return num;
}

int minsort(int nums[], int n)
{
	int minNum = nums[0], minPos, i;
	for (i = 0; i < n; i++)
	{
		if (nums[i] < minNum)
		{
			minNum = nums[i];
			minPos = i;
		}
		printf("%d\n", nums[i]);
	}
	return minPos;
}

//×ÒÎÁÛ ÁÛËÀ ÏÎÑÅÄÍßß ÑÒĞÎÊÀ ÈÑÏĞÀÂÈÒÜ ÑÒĞÎÊÓ
//if (nums[i] <= minNum)
//ÁÎËÜØÅ ÍÈ×ÅÃÎ ÍÅ ÌÅÍßÒÜ!!!!
