#include <stdio.h>
#include <stdlib.h>

//определяем тип данных, представляющий собой структуру
typedef struct stack
{
	unsigned buf_size;		//размер буфера для элементов стека
	unsigned top_index;		//индекс для указания вершины стека
	int* buf;				//указатель для адресации к динамическому массиву
} stack;
/*поле top_index указывает на элемент буфера,
в который будет записан очередной элемент стека
при следующем вызове push*/

//подготовка работы со стеком и освобождение динамически распределённой памяти
void stack_allocation(stack* pStack, unsigned buf_size);
void stack_free(stack* pStack);

void push(stack* pStack, int value);	//положить элемент на вершину стека
int pop(stack* pStack);					//снять элемент с вершины стека
int peek(stack* pStack);				//прочитать элемент с вершины стека (но не снимать)
bool isEmpty(stack* pStack);			//проверка - стек пуст?
bool isFull(stack* pStack);				//проверка - буфер 
void print(stack* pStack);				//вывод на печать (числа)
void print_char(stack* pStack);			//вывод на печать (символы)

int bracket_parser(char* str);			//анализ скобочного выражения
char get_pair_bracket(char c);			//получить парную закрывающую скобку

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
	//инициализируем поля структуры
	pStack->buf_size = buf_size;
	pStack->top_index = 0;
	//и динамически распределяем память под буфер
	pStack->buf = (int*)malloc(buf_size * sizeof(int));
}

void stack_free(stack* pStack)
{
	//не забываем освобождать динамически распределённую память
	free(pStack->buf);
}

void push(stack* pStack, int value)
{
	/*
	Предельно простая реализация функции
	может привести к переполнению буфера.
	Если не реализуем контроль на уровне функции,
	то не забываем это делать перед её вызовом.
	Для этого следует использовать вызов isFull.
	*/

	//сначала записываем значение value в буфер,
	//а потом увеличиваем индекс вершины стека
	//("++" записан после переменной)
	pStack->buf[(pStack->top_index)++] = value;
}

int pop(stack* pStack)
{
	/*
	Предельно простая реализация функции
	может привести к выходу за пределы буфера.
	Если не реализуем контроль на уровне функции,
	то не забываем это делать перед её вызовом.
	Для этого следует использовать вызов isEmpty.
	*/

	//сначала уменьшаем индекс вершины стека
	//("--" записан перед переменной),
	//а затем возвращаем элемент, прочитанный из буфера
	return pStack->buf[--(pStack->top_index)];
}

int peek(stack* pStack)
{
	//обращаем внимание на -1 при индексации
	return pStack->buf[(pStack->top_index) - 1];
}

bool isEmpty(stack* pStack)
{
	//стек пуст, когда top_inlex = 0
	//0 - это false, а нужно вернуть true
	//поэтому логическое "не" (операция "!")
	return !(pStack->top_index);
}

bool isFull(stack* pStack)
{
	//top_index фактически показывает,
	//сколько сейчас элементов в буфере
	return (pStack->buf_size == pStack->top_index);
}

void print(stack* pStack)
{
	//начинаем с нулевого элемента,
	//а верхняя граница определяется
	//индексом вершины стека
	for (unsigned i = 0; i < pStack->top_index; i++)
		printf("%4d", pStack->buf[i]);
	printf("\n");
}

void print_char(stack* pStack)
{
	for (unsigned i = 0; i < pStack->top_index; i++)
		//выводим целые числа как символы
		printf("%c", (char)pStack->buf[i]);
	printf("\n");
}

int bracket_parser(char* str)
{
	/*
	Анализ корректности скобочного выражения
	коды возврата:
	-1 - скобки расставлены правильно
	-2 - не хватило размера стека
	0+ - индекс элемента строки,
	на котором зафиксирована ошибка
	*/

	stack _stack;
	int i = 0;

	//инициализируем работу со стеком
	stack_allocation(&_stack, 20);

	//перебираем элементы строки
	do
	{
		//анализируем очередной символ строки
		switch (str[i])
		{
			//если встретили открывающую скобку
		case '(':
		case '[':
		case '{':
			//если буфер стека полон
			if (isFull(&_stack))
			{
				//положить новый элемент в него нельзя
				//поэтому освобождаем память и возвращаем код ошибки
				stack_free(&_stack);
				return -2;
			}
			//если же место в буфере ещё есть,
			//то кладём открывающую скобку на вершину
			push(&_stack, str[i]);
			print_char(&_stack);
			//не забываем про break в switch!
			break;
			//если встретили закрывающую скобку
		case ')':
		case ']':
		case '}':
			//если стек пуст
			if (isEmpty(&_stack))
			{
				//значит не было открывающей скобки,
				//поэтому освобождаем память
				//и возвращаем индекс символа строки,
				//где обнаружено это несоответсвие
				stack_free(&_stack);
				return i;
			}
			//если на вершине стека что-то есть,
			//следует проверить соответствие типа скобок
			if (get_pair_bracket(pop(&_stack)) != str[i])
			{
				//если закрывающая не соответствует открывающей,
				//поэтому освобождаем память
				//и возвращаем индекс символа строки,
				//где обнаружено это несоответсвие
				print_char(&_stack);
				stack_free(&_stack);
				return i;
			};
			print_char(&_stack);
			break;
			//все остальные символы игнорируем
		default:break;
		}
	} while (str[++i]);

	//если строка закончилась,
	//а в стеке ещё остались открывающие скобки
	if (!isEmpty(&_stack))
	{
		//освобождаем память
		//и возвращаем индекс символа строки,
		//где обнаружено это несоответсвие
		print_char(&_stack);
		stack_free(&_stack);
		return i;
	}

	//если нигде не вышли с кодом ошибки,
	//значит возвращаем код корректной расстоновки скобок
	//и не забываем освобождаем память!
	stack_free(&_stack);
	return -1;
}

char get_pair_bracket(char c)
{
	//подбираем закрывающую скобку
	switch (c)
	{
	case '(': return ')';
	case '[': return ']';
	case '{': return '}';
	default: return '\0';
	}
}
