#include <stdio.h>
//#include <string.h>		//����������, ���� ����� ����������� ����������� ����������� ������� ��������� �����

char* s_gets(char* str, unsigned buf_size);		//���������� ���������� gets �� ���� fgets
char* s_gets_c(char* str, unsigned buf_size);		//���������� ���������� gets �� ���� getchar
unsigned str_len(char* str);				//����������� ����� ������
char* str_cpy(char* dst, char* src);		//����������� ������
char* str_cat(char* str1, char* str2);		//��������� �����
int str_cmp(char* str1, char* str2);		//��������� �����
char* str_str(char* str, char* sub);		//����� ��������� � ������

char* remove_char(char* str, unsigned pos);	//�������� ������� � �������� ������� �� �������
char* remove_duplicates(char* str);			//�������� ���������� ��������

unsigned sum_of_digits(char* str);			//����� ���� � ������
unsigned sum_of_decimals(char* str);		//����� ����� � ������

void swap(char* pa, char* pb);				//����� ���������� ����� �����������

char* reverse_string(char* str);			//������������ ���� �������� ������ � �������� �������
char* reverse_substring(char* str, int left, int right);	//������������ �������� � �������� ��������� �������� 

unsigned char_in_string(char symbol, char* str);	//���������� ��������� ������� � ������
unsigned words_count(char* str);		//������� ����� ���� � ������
unsigned longest_word(char* str);		//����������� ����� ������ �������� ����� � ������
unsigned shortest_word(char* str);		//����������� ����� ������ ��������� ����� � ������
void print_words(char* str);			//���������� ���� ������ �� �����������
char* reverse_words(char* str);			//������������ �������� ������ ������� �����

int main()
{
	const unsigned buf_size = 50;
	char str1[buf_size];
	char str2[buf_size];

	s_gets_c(str1, buf_size);
	//s_gets(str2, buf_size);

	//printf("%u", sum_of_digits(str1));
	//printf("%u", sum_of_decimals(str1));

	//puts(remove_duplicates(str1));
	//puts(reverse_string(str1));

	puts(str1);
	puts(reverse_words(str1));

	//print_words(str1);
	//printf("%u", shortest_word(str1));

	getchar();
	return 0;
}

char* s_gets(char* str, unsigned buf_size)
{
	/*
	���������� (� ����� ������ ����� ����������� ������)
	���������� ������ ������ � �������
	�������� ������� ������ ������� fgets
	*/

	unsigned i = 0;
	//���� ����� fgets ���������� ��������� NULL
	if (!fgets(str, buf_size, stdin))
		//���� ������ NULL - ������� ������ �����
		return NULL;

	//fgets �� �������� ������ �������� ������
	//��� ������ ��� ������, � ��� ����� � ����������
	//������� ������� ��� �����
	do
		if (str[i] == '\n')
			break;
	while (str[++i]);

	//������ ����� ������ ������ �� �� �������,
	//�� ������� ����������� ����
	//��� ����� ���� ��� ������ '\0', ���� '\n'
	str[i] = '\0';

	//����� ������������� ������������ ��������,
	//����� fgets ����������, ��������� �������� �����
	//��� ���� ���������� ��, ��� �������� � ������ �����
	//�������� ��������, ��� ���� ����� �����
	//��� �������� ������ �������� � ���� �������� �������
	//�� ���� ������ getchar
	while (getchar() != '\n');

	return str;
}

char* s_gets_c(char* str, unsigned buf_size)
{
	/*
	���������� (� ����� ������ ����� ����������� ������)
	���������� ������ ������ � �������
	�������� �� ������������ ������ ������ ����� (getchar)
	*/

	unsigned i = 0;
	int ch;

	//� ������ ������ �� ������ ����� �������� ��,
	// ��� ���� �� ������� '\n' (����� ����� ����� ����)
	while ((ch = getchar()) != '\n')
		//�� ���������� ������ ���� ���� ����� � ������
		if (i < (buf_size - 1))
			str[i++] = ch;
	//� ����� �� �������� ��������� ������ ����� ������
	str[i] = '\0';

	return str;
}

unsigned str_len(char* str)
{
	/*
	������� ����������� ����� ������
	���������, ��� �� ���� ������� ��������� �������������� ������
	(������������� '\0')
	��������������� ������ ������ �� ���������,
	�.�. �� �������������� �� ����� ������ �������
	*/

	unsigned i = 0;
	//�������� ��������, ��� ���� ����� �����
	//��� �������� ������ �������� � ���� �������� �������
	//�� ���� ����������
	while (str[i++]);

	//�� �������� ��� ���������
	return (i - 1);
}

char* str_cpy(char* dst, char* src)
{
	/*
	������� ����������� �����
	���������� ������ src (�� ����� source)
	������� ������ ������ dst (�� ����� destination)
	���������� �����������!
	�� ����� �� ���������,
	���������� �� ������ �������� ��� ���������� dst
	���������, ��� ������ ���� �������� �����������
	������ ������� �������������� ����� ������� �������
	*/

	unsigned i = 0;
	do
		dst[i] = src[i];
	while (src[i++]);

	//��� ������� ��� ������� ��������� ����� ����������
	//��������� �� char, ������� ��������� �� ������-���������
	//��� ��������� � ����� ������ ��� �� ��������������� �����������
	return dst;
}

char* str_cat(char* str1, char* str2)
{
	/*
	������� ������������ (���������) �����
	���������� ������ str2 ������������
	����� str1
	���������� �����������!
	�� ����� �� ���������,
	���������� �� ������ �������� ��� ���������� str1
	���������, ��� ������ ���� �������� �����������
	������ ������� �������������� ����� ������� �������
	*/

	/*
	����� ������������ ����������� �����������
	����� ������ ��������� ���������,
	� ����� ������� � ������ ������
	����� �������� ����������
	������� ������ ������
	�� ������ ������� ������ '\0' � ������ ������,
	������� �� ��� ����� ��������� ������ ������ ������

	unsigned str1_len = str_len(str1);
	unsigned i = 0;
	do
	str1[i + str1_len] = str2[i];
	while (str2[i++]);

	return str1;*/

	//����� ������ ���������� ��������� � �����������
	//�������� ������ ������ �� ������,
	//���������������� ������� ����� ������ � str1
	return str_cpy(str1 + str_len(str1), str2);
}

int str_cmp(char* str1, char* str2)
{
	/*
	������� ��� ��������� �����
	������ ������������ �����������
	���� ��� ��������� ��������� - ������������ 0
	���� � ���� ������������� �������� ������ ��� �������,
	�������� � ������ ������ - ����������� ������������� �����,
	� ��������� ������ - �������������
	*/
	unsigned i = 0;
	int delta;


	//���������� �������� ����� ��������
	//��� �������� �������� ����������� �����
	do
	{
		delta = str1[i] - str2[i];
	} while (!delta && str1[i++]);
	//����� ���� ��� ���������� ������ ������ ����� �������
	//���� �� ������ ������ ����������� ������,
	//�� ��������� ����� �� delta

	return (delta);
}

char* str_str(char* str, char* sub)
{
	/*
	������� ������ ��������� (sub) � ������ (str)
	���������� ��������� �� ������,
	� �������� ���������� ������ ��������� ���������
	���� ��������� ���, ���������� NULL
	*/

	unsigned i = 0, j, flag;

	do
	{
		j = 0;
		flag = 1;
		do
			//���� ����� ������������� �������
			if (str[i + j] != sub[j])
			{
				//�������� ���� � �����
				flag = 0;
				break;
			}
		//�������� ��������, ��� ���������� j ����� �����������
		//����� ��������� ������� ����������� �����
		while (sub[++j]);
		//���� � �������� ��������� ���� �� ��� �������,
		//�� �� ����� ������� �������
		if (flag) return (str + i);
	} while (str[i++]);

	return NULL;
}

char* remove_char(char* str, unsigned pos)
{
	/*
	������� �������� ������� � �������� ��������
	*/

	//���������� �� ���� ����� ������,
	//������� � �������� �������
	do
		str[pos] = str[pos + 1];
	while (str[pos++]);
	//������ ���� ����������y �� ������ �������� �� '\0'

	//� ���������� char*,
	//��� ��� ������ �������� � �������� ��������� �����
	return str;
}

char* remove_duplicates(char* str)
{
	/*
	������� �������� ��������� ��������� �������� � ������
	���������� ���������� ������ ��������
	�� �������� ��������� ��������� ��������,
	��� �������� � ������������ ������� �������
	� ������ ���������� ��������� ������� �� ���������,
	� ������ ������������.
	���� ������� ����������� ������� ���������� � ������ ������.
	�.�. � ������ ������ �������� ������������� �����,
	�� ���������� ��������� ���� ������ ����� ���� ���� �����
	������ �������� '\0'.
	��� ����� �� �� ������ �������� �������,
	�� � �������� ��������� �������� �� ���������.
	���������� �������� �������� �� ����� ���� ������,
	��� ����� �������� � ������� ������� (255).
	� ������ ��� ���� ����� ���� ������� �������.
	����� ��������, ��� � ����� ������ ������� �������� i
	�������� ������� ���������� �������� count,
	�� ����� ���� ������������� ������������� ��������,
	������� �� �� ����� ����� ����� ���������� ����� ������������
	���������� ��������
	*/

	unsigned count = 1, i = 0, j, flag;

	while (str[i])
	{
		flag = 1;
		//�������� �� ������������
		//����� ����� ������ (count-1) ���������
		for (j = 0; j < count; j++)
			if (str[j] == str[i])
			{
				flag = 0;
				break;
			}
		//���� ���� �� �������
		if (flag)
			//��������� ������ � ����� ����������			
			str[count++] = str[i];
		i++;
	}
	str[count] = '\0';

	return str;

}

unsigned sum_of_digits(char* str)
{
	/*
	������� ���������� ����� ����,
	�������� � ������ ������
	*/
	unsigned i = 0, sum = 0;

	do
		//���� ������ �������� ������
		if (str[i] >= '0' && str[i] <= '9')
			//��������� �������� ����� � �����
			//��������� � ������� ������� �����
			//�������� ������, �������� ��������
			//����� �������� �������� ��������
			//���� �������� ������� � ����� ������� '0'
			sum += str[i] - '0';
	while (str[i++]);

	return sum;
}

unsigned sum_of_decimals(char* str)
{
	/*
	������� ���������� ����� �����,
	�������� � ������ ������
	*/

	unsigned i = 0, sum = 0, decimal = 0;

	do
	{
		//���� ��������� � ������ ������ �����
		while (str[i] >= '0' && str[i] <= '9')
		{
			//��������� �����
			decimal = decimal * 10 + (str[i] - '0');
			i++;
		}
		//���� ������ �� �����
		//��������� ������������ ����� � �����
		sum += decimal;
		//� ��������� ������ ��������� �����
		decimal = 0;
	} while (str[i++]);

	return sum;
}

void swap(char* pa, char* pb)
{
	char temp = *pa;
	*pa = *pb;
	*pb = temp;
}

char* reverse_string(char* str)
{
	/*
	��������� ������
	*/

	//�������� � ���������� ���������,
	//�� ���������� ��� �������� ������
	return reverse_substring(str, 0, str_len(str) - 1);
}

char* reverse_substring(char* str, int left, int right)
{
	/*
	��������� ���������
	� ������ �������� ���������� ��������
	�� ������������ �������� ������
	(left � right)
	*/

	while (left < right)
		swap(str + left++, str + right--);

	return str;
}

unsigned char_in_string(char symbol, char* str)
{
	/*
	������� ���������, ����������� �� ������ � ������
	���� ����������� - ���������� 1, ���� ��� - 0
	�����!!! ������� �������� ���,
	����� ������������� � ������ '\0',
	������� ������ ���������� � ����� ������ � C
	*/
	unsigned i = 0;

	do
		if (str[i] == symbol)
			return 1;
	while (str[i++]);
	//��� ����� ����������� ����� ����������� � ������ '\0'

	return 0;
}

unsigned words_count(char* str)
{
	/*
	������� ������� ����� ���� � ������
	����� ���������� ���������-�������������,
	������� ��� �������� ������������� � ���������
	������ separator. � ��������� ������� ������
	���������� ����� ������ ��� ������ �������� �������.
	��� ��������� �������� ������� ����� �������,
	��� ��� ������ ���� ��������� � ��������� ������������
	� ������ ������, ���������� ������������ �������,
	��������� ������������ �����, �� ������� �������
	����� ������
	*/

	unsigned inWord = 0, i = 0, count = 0;
	char separator[] = " \t,.!?:;";

	do
	{
		if (char_in_string(str[i], separator))
		{
			if (inWord)
				count++;
			inWord = 0;
		}
		else
			inWord = 1;
	} while (str[i++]);
	//��� ���� ������ '\0' ���� ����� ���������

	return count;
}

unsigned longest_word(char* str)
{
	/*
	������� ���������� ����� ������ �������� �����
	����� �������� ����������� - ���������� ��������
	����� ���� � ������ (��. ������� words_count).
	������� �� ������,
	����� ������� ����� ������� ���������� �����.
	���� ��� �������� ������ ������� ������
	������������ ����� - ��������� ��� ������.
	���������� ������ �������� ������ 0.
	*/

	unsigned inWord = 0, i = 0, length = 0, maxLength = 0;
	char separator[] = " \t,.!?:;";

	do
	{
		if (char_in_string(str[i], separator))
		{
			if (inWord)
				if (length > maxLength)
					maxLength = length;
			inWord = 0;
			length = 0;
		}
		else
		{
			inWord = 1;
			length++;
		}
	} while (str[i++]);
	//��� ���� ������ '\0' ���� ����� ���������

	return maxLength;
}

unsigned shortest_word(char* str)
{
	/*
	������� ���������� ����� ������ ��������� �����
	����� �������� ����������� - ���������� ��������
	����� ���� � ������ (��. ������� words_count).
	������� �� ������,
	����� ������� ����� ������� ���������� �����.
	���� ��� �������� ������ ������� ������
	����������� ����� - ��������� ��� ������
	���������� ������ �������� ������ 0.
	���� ��� ��������� ���� ������� ��������,
	��� ������ �� ��� ��� �������
	(�.�. ����������� ����� �������� ������),
	�� ��� ����� ��������� �� ������ ����������� �����.
	*/

	unsigned inWord = 0, i = 0, length = 0, minLength = 0;
	char separator[] = " \t,.!?:;";

	do
	{
		if (char_in_string(str[i], separator))
		{
			if (inWord)
				if ((length < minLength) || !minLength)
					minLength = length;
			inWord = 0;
			length = 0;
		}
		else
		{
			inWord = 1;
			length++;
		}
	} while (str[i++]);
	//��� ���� ������ '\0' ���� ����� ���������

	return minLength;
}

void print_words(char* str)
{
	/*
	������� �������� �����, ���������� ������,
	� ��������� ������� ������ ������
	(������� �� �������� '\n').
	����� �������� ����������� - ���������� ��������
	����� ���� � ������ (��. ������� words_count).
	*/

	unsigned inWord = 0, i = 0;
	char separator[] = " \t,.!?:;";

	do
	{
		if (char_in_string(str[i], separator))
		{
			if (inWord)
				putchar('\n');
			inWord = 0;
		}
		else
		{
			inWord = 1;
			putchar(str[i]);
		}
	} while (str[i++]);
	//��� ���� ������ '\0' ���� ����� ���������
}

char* reverse_words(char* str)
{
	/*
	������� ������������ ����� � ������
	� ������������ ��� ������� � ������
	�� ��� � �������� �������.
	����� �������� ����������� - ���������� ��������
	����� ���� � ������ (��. ������� words_count).
	�����, ��� � ������ ������ ����������� �������
	������ ����� (left) � ����� ����� (right).
	��� ���������� ��� ��������� ����� ����������
	������� reverse_substring.
	*/

	unsigned inWord = 0, i = 0, left = 0, right = 0;
	char separator[] = " \t,.!?:;";

	do
	{
		if (char_in_string(str[i], separator))
		{
			if (inWord)
			{
				right = i - 1;
				reverse_substring(str, left, right);
			}
			inWord = 0;
		}
		else
		{
			if (!inWord)
			{
				left = i;
				inWord = 1;
			}

		}
	} while (str[i++]);
	//��� ���� ������ '\0' ���� ����� ���������

	return str;
}
