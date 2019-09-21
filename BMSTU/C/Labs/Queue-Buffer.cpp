include <stdio.h>
#include <stdlib.h>

//определяем тип данных, представляющий собой структуру
typedef struct queue
{
	unsigned buf_size;		//размер буфера для размещения элементов очереди
	unsigned head, tail;	//индексы "головы" и "хвоста" очереди
	int* buf;				//указатель для адресации к динамически выделенному буферу
} queue;
/*
tail работает аналогично top_index в стеке
head указывает непосредственно на головной элемент очереди
Следует помнить, что буфер закольцован!
Поэтому при достижении конца буфера,
индексы перекидываются на начало буфера
*/

//подгтовка работы с очередью и освобождение динамически распределённой памяти
void queue_allocation(queue* pQueue, unsigned buf_size);
void queue_free(queue* pQueue);

void enter(queue* pQueue, int value);	//постановка элемента в хвост очереди
int depart(queue* pQueue);				//удаление элемента с головы очереди
bool isEmpty(queue* pQueue);			//проверка - очередь пуста?
bool isFull(queue* pQueue);				//проверка - буфер очереди полон?
void print(queue* pQueue);				//вывод на печать

int main()
{
	queue _queue;

	//подготовка работы с очередью
	queue_allocation(&_queue, 4);

	//добавляем 4 элемента
	enter(&_queue, 1);
	print(&_queue);
	enter(&_queue, 2);
	print(&_queue);
	enter(&_queue, 3);
	print(&_queue);
	enter(&_queue, 4);
	print(&_queue);

	//добавление элемента,
	//которое приводит к переполнению
	//enter(&_queue, 0);
	//print(&_queue);

	//штатная работа
	depart(&_queue);
	print(&_queue);
	depart(&_queue);
	print(&_queue);
	enter(&_queue, 5);
	print(&_queue);
	depart(&_queue);
	print(&_queue);
	depart(&_queue);
	print(&_queue);

	//не забываем освобождать память
	queue_free(&_queue);

	getchar();
	return 0;
}

void queue_allocation(queue* pQueue, unsigned buf_size)
{
	//инициализируем поля структуры
	pQueue->buf_size = buf_size;
	pQueue->head = 0;
	pQueue->tail = 0;
	//и динамически распределяем память под буфер
	pQueue->buf = (int*)malloc(buf_size * sizeof(int));
}

void queue_free(queue* pQueue)
{
	//не забываем освобождать память
	free(pQueue->buf);
}

void enter(queue* pQueue, int value)
{
	/*
	Обратите внимание:
	везде используется tail,
	т.к. элемент добавляется в хвост очереди
	*/

	/*
	Здесь не контролируется заполненность буфера.
	Это необходимо делать либо перед вызовом функции,
	либо вставить здесь предварительную проверку isFull
	*/

	//пока не достигнут конец буфера
	if (pQueue->tail < pQueue->buf_size)
		//логика добавления аналогична работе со стеком
		pQueue->buf[pQueue->tail++] = value;
	else
	{
		//когда достигли конца буфера,
		//новые элементы вставляются в начале буфера
		pQueue->buf[0] = value;
		pQueue->tail = 1;
	}
}

int depart(queue* pQueue)
{
	/*
	Обратите внимание:
	везде используется head,
	т.к. элемент удаляется с головы очереди
	*/

	/*
	Здесь не контролируется пустота буфера.
	Это необходимо делать либо перед вызовом функции,
	либо вставить здесь предварительную проверку isEmpty
	*/

	//пока не достигнут конец буфера
	if (pQueue->head < pQueue->buf_size)
		//логика удаления напоминает логику добавления
		return pQueue->buf[pQueue->head++];
	else
	{
		//когда достигли конца буфера,
		//снимаем элемент в начале буфера
		pQueue->head = 0;
		return pQueue->buf[0];
	}
}

bool isEmpty(queue* pQueue)
{
	//очередь пуста,
	//когда индексы головы и хвоста равны
	return (pQueue->head == pQueue->tail);
}

bool isFull(queue* pQueue)
{
	//следует рассмотреть 2 случая:
	//когда голова левее хвоста
	if (pQueue->head < pQueue->tail)
		return ((pQueue->tail - pQueue->head) == pQueue->buf_size);
	else
		//или когда голова правее хвоста
		return ((pQueue->head - pQueue->tail) == 1);
}

void print(queue* pQueue)
{
	int i;

	//следует рассмотреть 2 случая:
	//когда голова левее хвоста
	if (pQueue->head <= pQueue->tail)
		for (i = pQueue->head; i < pQueue->tail; i++)
			printf("%4d", pQueue->buf[i]);
	else
	{
		//или когда голова правее хвоста
		for (i = pQueue->head; i < pQueue->buf_size; i++)
			printf("%4d", pQueue->buf[i]);
		for (i = 0; i < pQueue->tail; i++)
			printf("%4d", pQueue->buf[i]);
	}
	printf("\n");
}
