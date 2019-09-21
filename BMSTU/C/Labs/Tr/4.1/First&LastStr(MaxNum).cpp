#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

char * sgets(char* str, int n);
char * getstr(char *str, int max);
int getstrs(char ** s, int[MAX]);
void pr(char **s, int m);
int maxinStr(char * s);
int maxsort(int nums[], int n);
char ** init(char ** strs, int n);

int main(void)
{
	char ** strs = NULL;
	int strnum[MAX];
	strs = init(strs, MAX);
	int i = getstrs(strs, strnum);
	/*for(int j=0; j<i; j++)
	{
	printf("\n\tMAX = %d\n", strnum[j]);
	}*/
	int ind = maxsort(strnum, i);
	printf("\n\tMAX = %d\n", strnum[ind]);
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
		ss[a] = maxinStr(str);
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
int maxinStr(char * s)
{
	int num = 0, i = 0, n = 0;
	while (s[i])
	{
		if (isdigit(s[i]))
		{
			n = 10 * n + s[i] - '0';
			/*printf("%d\n", n);*/
			if (!isdigit(s[i + 1]))
			{
				if (n > num)
					num = n;
				n = 0;
			}
		}
		i++;
	}
	return num;
}
int maxsort(int nums[], int n)
{
	int maxNum = nums[0], maxPos, i;
	for (i = 0; i < n; i++)
	{
		if (nums[i] > maxNum)
		{
			maxNum = nums[i];
			maxPos = i;
		}
		printf("%d\n", nums[i]);
	}
	return maxPos;
}

//ÅÑËÈ ÍÀÌ ÍÓÆÍÀ ÏÎÑËÅÄÍßß, ÒÎ  if (nums[i] >= maxNum) ÂÑ¨!!!!!ÁÎËÜØÅ ÍÈ×ÅÃÎ ÍÅ ÒĞÎÃÀÒÜ
