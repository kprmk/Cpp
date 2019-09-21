#include <stdio.h>
#include <stdlib.h>

//���������� ��� ������, �������������� ����� ���������
typedef struct stack
{
	unsigned buf_size;		//������ ������ ��� ��������� �����
	unsigned top_index;		//������ ��� �������� ������� �����
	int* buf;				//��������� ��� ��������� � ������������� �������
} stack;
/*���� top_index ��������� �� ������� ������,
� ������� ����� ������� ��������� ������� �����
��� ��������� ������ push*/

//���������� ������ �� ������ � ������������ ����������� ������������� ������
void stack_allocation(stack* pStack, unsigned buf_size);
void stack_free(stack* pStack);

void push(stack* pStack, int value);	//�������� ������� �� ������� �����
int pop(stack* pStack);					//����� ������� � ������� �����
int peek(stack* pStack);				//��������� ������� � ������� ����� (�� �� �������)
bool isEmpty(stack* pStack);			//�������� - ���� ����?
bool isFull(stack* pStack);				//�������� - ����� 
void print(stack* pStack);				//����� �� ������ (�����)
void print_char(stack* pStack);			//����� �� ������ (�������)

int bracket_parser(char* str);			//������ ���������� ���������
char get_pair_bracket(char c);			//�������� ������ ����������� ������

int main()
{

	int result = bracket_parser("[(())]");

	switch (result)
	{
	case -2: printf("Stack overflow!\n"); break;
	case -1: printf("Correct expression\n"); break;
	default: printf("Incorrect symbol in %d position\n", result);
	}

	getchar();
	return 0;
}

void stack_allocation(stack* pStack, unsigned buf_size)
{
	//�������������� ���� ���������
	pStack->buf_size = buf_size;
	pStack->top_index = 0;
	//� ����������� ������������ ������ ��� �����
	pStack->buf = (int*)malloc(buf_size * sizeof(int));
}

void stack_free(stack* pStack)
{
	//�� �������� ����������� ����������� ������������� ������
	free(pStack->buf);
}

void push(stack* pStack, int value)
{
	/*
	��������� ������� ���������� �������
	����� �������� � ������������ ������.
	���� �� ��������� �������� �� ������ �������,
	�� �� �������� ��� ������ ����� � �������.
	��� ����� ������� ������������ ����� isFull.
	*/

	//������� ���������� �������� value � �����,
	//� ����� ����������� ������ ������� �����
	//("++" ������� ����� ����������)
	pStack->buf[(pStack->top_index)++] = value;
}

int pop(stack* pStack)
{
	/*
	��������� ������� ���������� �������
	����� �������� � ������ �� ������� ������.
	���� �� ��������� �������� �� ������ �������,
	�� �� �������� ��� ������ ����� � �������.
	��� ����� ������� ������������ ����� isEmpty.
	*/

	//������� ��������� ������ ������� �����
	//("--" ������� ����� ����������),
	//� ����� ���������� �������, ����������� �� ������
	return pStack->buf[--(pStack->top_index)];
}

int peek(stack* pStack)
{
	//�������� �������� �� -1 ��� ����������
	return pStack->buf[(pStack->top_index) - 1];
}

bool isEmpty(stack* pStack)
{
	//���� ����, ����� top_inlex = 0
	//0 - ��� false, � ����� ������� true
	//������� ���������� "��" (�������� "!")
	return !(pStack->top_index);
}

bool isFull(stack* pStack)
{
	//top_index ���������� ����������,
	//������� ������ ��������� � ������
	return (pStack->buf_size == pStack->top_index);
}

void print(stack* pStack)
{
	//�������� � �������� ��������,
	//� ������� ������� ������������
	//�������� ������� �����
	for (unsigned i = 0; i < pStack->top_index; i++)
		printf("%4d", pStack->buf[i]);
	printf("\n");
}

void print_char(stack* pStack)
{
	for (unsigned i = 0; i < pStack->top_index; i++)
		//������� ����� ����� ��� �������
		printf("%c", (char)pStack->buf[i]);
	printf("\n");
}

int bracket_parser(char* str)
{
	/*
	������ ������������ ���������� ���������
	���� ��������:
	-1 - ������ ����������� ���������
	-2 - �� ������� ������� �����
	0+ - ������ �������� ������,
	�� ������� ������������� ������
	*/

	stack _stack;
	int i = 0;

	//�������������� ������ �� ������
	stack_allocation(&_stack, 20);

	//���������� �������� ������
	do
	{
		//����������� ��������� ������ ������
		switch (str[i])
		{
			//���� ��������� ����������� ������
		case '(':
		case '[':
		case '{':
			//���� ����� ����� �����
			if (isFull(&_stack))
			{
				//�������� ����� ������� � ���� ������
				//������� ����������� ������ � ���������� ��� ������
				stack_free(&_stack);
				return -2;
			}
			//���� �� ����� � ������ ��� ����,
			//�� ����� ����������� ������ �� �������
			push(&_stack, str[i]);
			print_char(&_stack);
			//�� �������� ��� break � switch!
			break;
			//���� ��������� ����������� ������
		case ')':
		case ']':
		case '}':
			//���� ���� ����
			if (isEmpty(&_stack))
			{
				//������ �� ���� ����������� ������,
				//������� ����������� ������
				//� ���������� ������ ������� ������,
				//��� ���������� ��� �������������
				stack_free(&_stack);
				return i;
			}
			//���� �� ������� ����� ���-�� ����,
			//������� ��������� ������������ ���� ������
			if (get_pair_bracket(pop(&_stack)) != str[i])
			{
				//���� ����������� �� ������������� �����������,
				//������� ����������� ������
				//� ���������� ������ ������� ������,
				//��� ���������� ��� �������������
				print_char(&_stack);
				stack_free(&_stack);
				return i;
			};
			print_char(&_stack);
			break;
			//��� ��������� ������� ����������
		default:break;
		}
	} while (str[++i]);

	//���� ������ �����������,
	//� � ����� ��� �������� ����������� ������
	if (!isEmpty(&_stack))
	{
		//����������� ������
		//� ���������� ������ ������� ������,
		//��� ���������� ��� �������������
		print_char(&_stack);
		stack_free(&_stack);
		return i;
	}

	//���� ����� �� ����� � ����� ������,
	//������ ���������� ��� ���������� ����������� ������
	//� �� �������� ����������� ������!
	stack_free(&_stack);
	return -1;
}

char get_pair_bracket(char c)
{
	//��������� ����������� ������
	switch (c)
	{
	case '(': return ')';
	case '[': return ']';
	case '{': return '}';
	default: return '\0';
	}
}
