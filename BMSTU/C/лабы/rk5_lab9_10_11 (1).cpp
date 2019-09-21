#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned strLength(char str[])
{
	unsigned i = 0;
	while (str[i++]);
	return i - 1;
}

char* strCopy(char *str_dest, char *str_src)
{
	if (str_src == NULL || str_dest == NULL) 
	{
		printf("Error: dest or src is NULL\n");
		return NULL;
	}

	if (strLength(str_dest) < strLength(str_src))
	{
		printf("Error: dest memory is less than src memory\n");
		return NULL;
	}

	// Вариант 1
	unsigned i = 0;
	while (str_src[i])
	{
		str_dest[i] = str_src[i];
		++i;
	}
	str_dest[i] = '\0';

	// Вариант 2
	unsigned len = strLength(str_src);
	memcpy(str_dest, str_src, (len + 1) * sizeof(char));

	return str_dest;
}

char* strConcat(char *str1, char *str2)
{
	unsigned len1 = strLength(str1), len2 = strLength(str2);
	char *newstr = (char*)malloc((len1 + len2 + 1) * sizeof(char));

	// Вариант 1
	unsigned i = 0;
	while (str1[i])
	{
		newstr[i] = str1[i];
		++i;
	}
	i = 0;
	while (str2[i])
	{
		newstr[len1 + i] = str2[i];
		++i;
	}
	newstr[len1 + i] = '\0';

	// Вариант 2
	memcpy(newstr, str1, len1 * sizeof(char));
	memcpy(newstr + len1, str2, (len2 + 1) * sizeof(char));

	return newstr;
}

int strCompare(char *str1, char *str2)
{
    // Вариант 1
	unsigned i = 0;
	while (str1[i])
	{
		if (str1[i] < str2[i])
			return -1;
		
		if (str1[i] > str2[i])
			return 1;

		++i;
	}

	if (str1[i] == str2[i])
		return 0;
	else
		return -1;
		
	// Вариант 2
	/*int i = 0, delta;
	
	do
	{
	    delta = str1[i] - str2[i];
	} while (!delta && str1[i++]); 
	
	return delta / abs(delta);*/
}

int strChar(char *str, char c)
{
	unsigned i = 0;
	do
	{
		if (c == str[i])
			return (int)i;
	} while (str[i++]);

	return -1;
}

int strStr(char *str, char* substr)
{
	unsigned i = 0, subI = 0, strPos = 0;

	while (str[i])
	{
	    if (!substr[subI])
	        break;
	    
		if (str[i] == substr[subI])
		{
		    if (!subI)
		        strPos = i;
		        
			++subI;
		}
		else
		{
		    if (subI > 0)
		    {
		        subI = 0;
		        --i;
		    }
		}

		++i;
	}
	
    if (subI == strLength(substr))
        return strPos;
    else
        return -1;
}

char* gets_safe(char *buf, unsigned bufsize)
{
    unsigned i = 0;
    char c;
    
    while ((c = getchar()) != '\n')
    {
        if (i < bufsize - 1)
        {
            buf[i++] = c;
        }
    }
    buf[i] = '\0';
    
    return buf;
}

char* removeChar(char *str, unsigned pos)
{
    unsigned i = pos;
    
    do
    {
        str[i] = str[i + 1];
        //++i;
	} while (str[i++]);
    
    return str;
}

char* removeDublicates(char *str)
{
    unsigned i = 0, pos = 0;
    
    while (str[i])
    {
        unsigned key = 1, count;
        
        for (count = 0; count < pos; ++count)
        {
            if (str[count] == str[i])
            {
                key = 0;
                break;
            }
        }
        
        if (key)
        {
            str[pos++] = str[i];
        }
        
        ++i;
    }
    str[pos] = '\0';
    
    return str;
}

int sumOfDigits(char *str)
{
    unsigned i = 0;
    int sum = 0;
    
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            sum += (str[i] - '0');
        }
        
        ++i;
    }
    
    return sum;
}

int sumOfDecimals(char *str)
{
    unsigned i = 0;
    int sum = 0, num = 0;
    
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num = num * 10 + str[i] - '0';
            
            if (str[i + 1] < '0' || str[i + 1] > '9')
            {
                sum += num;
                num = 0;
            }
        }
        
        ++i;
    }
    
    if (num)
        sum += num;
        
    return sum;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* reverseSubstring(char *str, unsigned left, unsigned right)
{
    while (left < right)
    {
        swap(str + left++, str + right--);
    }
    
    return str;
}

char* reverseString(char* str)
{
    return reverseSubstring(str, 0, strLength(str) - 1);
}

unsigned wordsCount(char *str)
{
	unsigned i = 0, wordsNum = 0;
	char delimiters[] = "\t\n\"'(){}[]<>+=*\\/.,:;!? ";
	
	do
	{
		if (strChar(delimiters, str[i]) == -1)
		{	
			if (strChar(delimiters, str[i + 1]) != -1)
			{
				++wordsNum;
			}
		}
	} while (str[i++]);
	
	return wordsNum;
}

unsigned maxWordLen(char *str)
{
	unsigned i = 0, maxLen = 0, len = 0;
	char delimiters[] = "\t\n(){}[]<>+=*\\/.,:;!? ";

	do
	{
		if (strChar(delimiters, str[i]) == -1)
		{
			++len;
			if (strChar(delimiters, str[i + 1]) != -1)
			{
				if (len > maxLen)
				{
					maxLen = len;
				}
				len = 0;
			}
		}
	} while (str[i++]);

	return maxLen;
}

unsigned minWordLen(char *str)
{
	unsigned i = 0, minLen = strLength(str), len = 0;
	char delimiters[] = "(){}[]<>+=*\\/.,:;!? ";

	do
	{
		if (strChar(delimiters, str[i]) == -1)
		{
			++len;
			if (strChar(delimiters, str[i + 1]) != -1)
			{
				if (len < minLen)
				{
					minLen = len;
				}
				len = 0;
			}
		}
	} while (str[i++]);

	return minLen;
}

void wordsPrint(char *str)
{
	unsigned i = 0;
	char delimiters[] = "\t\n(){}[]<>+=*\\/.,:;!? ";

	do
	{
		if (strChar(delimiters, str[i]) == -1)
		{
			putchar(str[i]);
			if (strChar(delimiters, str[i + 1]) != -1)
			{
				putchar('\n');
			}
		}
	} while (str[i++]);
}

void wordsReverse(char *str)
{
	unsigned i = 0, left = -1;
	char delimiters[] = "\t\n(){}[]<>+=*\\/.,:;!? ";

	do
	{
		if (strChar(delimiters, str[i]) == -1)
		{
			if (left == -1)
				left = i;

			if (strChar(delimiters, str[i + 1]) != -1)
			{
				reverseSubstring(str, left, i);
				left = -1;
			}
		}
	} while (str[i++]);
}

int main()
{
	//char str1[] = "BMSTU";
	//char str2[] = "Bauman MSTU";
	//char str3[] = "MSTU";

	//printf("String: %s, length = %u\n", str1, strLength(str1));
	//strCopy(str2, str3);

	//printf("Concatenation: %s\n%s\n%s\n", str1, str2, strConcat(str1, str2));
	//printf("Comparison: %d %d %d\n", strCompare(str1, str2), strCompare(str2, str1), strCompare("Bauman ", "Bauman"));
	//printf("Char in string: %d, %d\n", strChar(str1, 'B'), strChar(str3, 'B'));
	
	/*const unsigned N = 10;
	char testStr[N];
	gets_safe(testStr, N);
	printf("This is string: %s\n", testStr);*/

	/*char str[] = "abcbcbcdbcbcbcde";
	char str2[] = "a123b45";
	printf("%d\n", strStr(str, str2));*/

	char str[] = "Hello, world! Fucking world... Okay.";
	//wordsPrint(str);
	wordsReverse(str);
	printf("%s\n", str);

	getchar();
	return 0;
}