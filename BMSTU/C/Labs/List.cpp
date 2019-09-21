#include <stdio.h>
#include <stdlib.h>

//определяем тип данных как структуру
typedef struct listItem
{
	int data;			//информационное поле
	listItem* next;		//ссылка на аналогичную структуру
} listItem;

listItem* add_inHead(listItem* head, int value);	//добавление элемента в голову списка
listItem* add_inTail(listItem* head, int value);	//добавление элемента в хвост списка
listItem* remove_onHead(listItem* head);			//удаление элемента с головы списка
listItem* remove_onTail(listItem* head);			//удаление элемента с хвоста списка
void print(listItem* head);							//печать элементов списка
void print_recursion(listItem* head);				//рекурсивная реализация печати
void print_reverse(listItem* head);					//печать в обратном порядке
void destroyList(listItem* head);					//удаление всего списка

int main()
{
	listItem* head = NULL;

	head = add_inHead(head, 1);
	print(head);
	head = add_inHead(head, 0);
	print(head);
	head = add_inTail(head, 2);
	print(head);

	print_recursion(head);
	printf("\n");
	print_reverse(head);
	printf("\n");

	head = remove_onHead(head);
	print(head);
	head = remove_onTail(head);
	print(head);

	destroyList(head);

	getchar();
	return 0;
}

listItem* add_inHead(listItem* head, int value)
{
	//выделяем память под новый элемент с использованием malloc
	//в этом случае время существования элемента определяется
	//программистом - до тех пор пока не будет вызван free
	listItem* newItem = (listItem*)malloc(sizeof(listItem));
	//инициализируем информационное поле
	newItem->data = value;
	//связываем новый элемент с существующим списком
	//деже если head=NULL, всё равно всё будет корректно
	newItem->next = head;
	//важно: возвращаем указатель на новый элемент,
	//он теперь будет новой головой списка
	return newItem;
}

listItem* add_inTail(listItem* head, int value)
{
	//создаём новый элемент
	listItem* newItem = (listItem*)malloc(sizeof(listItem));
	//инициализируем информационное поле
	newItem->data = value;
	//элемент будет последним в списке,
	//поэтому указатель на следующий - заведом NULL
	newItem->next = NULL;

	//если изначально список был пуст
	if (!head)
		//новый элемент будет его головой
		return newItem;

	//вводим вспомогательный указатель
	//для перемещения по списку
	listItem* current = head;

	//перебираем элементы списка
	while (current->next)
		current = current->next;
	//после выхода из цикла current
	//будет указывать на последний элемент списка

	//связваем последний элемент списка
	//с новым элементом
	current->next = newItem;

	//голова не изменилась, возвращаем старое значение
	return head;
}

listItem* remove_onHead(listItem* head)
{
	//если список пуст
	if (!head)
		//удалять нечего, возвращаем NULL
		return NULL;

	//сохраняем адрес головного элемента списка
	listItem* temp = head;
	//сдвигаем гловоу на следующий элемент
	//даже если head->next=NULL, всё будет корректно
	head = head->next;
	//освобождаем память, в которой размещался
	//старый головной элемент
	free(temp);
	//возвращаем актуальное положение головы списка
	return head;
}

listItem* remove_onTail(listItem* head)
{
	//если список пуст
	if (!head)
		//удалять нечего, возвращаем NULL
		return NULL;

	//если в списке головной элемент является единственным
	if (!head->next)
	{
		//освобождаем память, в которой он размещался
		free(head);
		//и возвращаем NULL
		return NULL;
	}

	//вводим вспомогательный указатель
	//для перемещения по списку
	listItem* current = head;

	//перебираем элементы списка
	while (current->next->next)
		current = current->next;
	//после выхода из цикла current
	//будет указывать на ПРЕДпоследний элемент списка

	//освобождаем память, в которой размещался
	//посделний элемент списка
	free(current->next);
	//делаем ссылку в предпоследнем элементе нулевой
	current->next = NULL;
	//голова не меняется
	return head;
}

void print(listItem* head)
{
	//вводим вспомогательный указатель
	//для перемещения по списку
	listItem* current = head;

	//перебираем элементы списка
	while (current)
	{
		//печатаем информационное поле
		//текущего элемента списка
		printf("%4d", current->data);
		current = current->next;
	}
	printf("\n");
}

void print_recursion(listItem* head)
{
	/*рекурсивная реализация*/

	//печатаем информационное поле
	//текущего элемента списка
	printf("%4d", head->data);
	//если элемент не последний
	if (head->next)
		//делаем рекурсивный вызов
		print_recursion(head->next);
}

void print_reverse(listItem* head)
{
	/*
	вывод списка в обратном порядке возможен
	только с помощью рекурсивной реализации
	*/

	//если элемент не последний
	if (head->next)
		//делаем рекурсивный вызов
		print_reverse(head->next);

	//печатаем информационное поле
	//текущего элемента списка
	printf("%4d", head->data);
}

void destroyList(listItem* head)
{
	//вводим вспомогательный указатель
	//для перемещения по списку
	listItem* current = head;

	//вводим вспомогательный указатель
	//для сохранения адреса предыдущего
	//элемента списка
	listItem* temp;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
