include <stdio.h>
#include <stdlib.h>

//���������� ��� ������, �������������� ����� ���������
typedef struct queue
{
	unsigned buf_size;		//������ ������ ��� ���������� ��������� �������
	unsigned head, tail;	//������� "������" � "������" �������
	int* buf;				//��������� ��� ��������� � ����������� ����������� ������
} queue;
/*
tail �������� ���������� top_index � �����
head ��������� ��������������� �� �������� ������� �������
������� �������, ��� ����� �����������!
������� ��� ���������� ����� ������,
������� �������������� �� ������ ������
*/

//��������� ������ � �������� � ������������ ����������� ������������� ������
void queue_allocation(queue* pQueue, unsigned buf_size);
void queue_free(queue* pQueue);

void enter(queue* pQueue, int value);	//���������� �������� � ����� �������
int depart(queue* pQueue);				//�������� �������� � ������ �������
bool isEmpty(queue* pQueue);			//�������� - ������� �����?
bool isFull(queue* pQueue);				//�������� - ����� ������� �����?
void print(queue* pQueue);				//����� �� ������

int main()
{
	queue _queue;

	//���������� ������ � ��������
	queue_allocation(&_queue, 4);

	//��������� 4 ��������
	enter(&_queue, 1);
	print(&_queue);
	enter(&_queue, 2);
	print(&_queue);
	enter(&_queue, 3);
	print(&_queue);
	enter(&_queue, 4);
	print(&_queue);

	//���������� ��������,
	//������� �������� � ������������
	//enter(&_queue, 0);
	//print(&_queue);

	//������� ������
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

	//�� �������� ����������� ������
	queue_free(&_queue);

	getchar();
	return 0;
}

void queue_allocation(queue* pQueue, unsigned buf_size)
{
	//�������������� ���� ���������
	pQueue->buf_size = buf_size;
	pQueue->head = 0;
	pQueue->tail = 0;
	//� ����������� ������������ ������ ��� �����
	pQueue->buf = (int*)malloc(buf_size * sizeof(int));
}

void queue_free(queue* pQueue)
{
	//�� �������� ����������� ������
	free(pQueue->buf);
}

void enter(queue* pQueue, int value)
{
	/*
	�������� ��������:
	����� ������������ tail,
	�.�. ������� ����������� � ����� �������
	*/

	/*
	����� �� �������������� ������������� ������.
	��� ���������� ������ ���� ����� ������� �������,
	���� �������� ����� ��������������� �������� isFull
	*/

	//���� �� ��������� ����� ������
	if (pQueue->tail < pQueue->buf_size)
		//������ ���������� ���������� ������ �� ������
		pQueue->buf[pQueue->tail++] = value;
	else
	{
		//����� �������� ����� ������,
		//����� �������� ����������� � ������ ������
		pQueue->buf[0] = value;
		pQueue->tail = 1;
	}
}

int depart(queue* pQueue)
{
	/*
	�������� ��������:
	����� ������������ head,
	�.�. ������� ��������� � ������ �������
	*/

	/*
	����� �� �������������� ������� ������.
	��� ���������� ������ ���� ����� ������� �������,
	���� �������� ����� ��������������� �������� isEmpty
	*/

	//���� �� ��������� ����� ������
	if (pQueue->head < pQueue->buf_size)
		//������ �������� ���������� ������ ����������
		return pQueue->buf[pQueue->head++];
	else
	{
		//����� �������� ����� ������,
		//������� ������� � ������ ������
		pQueue->head = 0;
		return pQueue->buf[0];
	}
}

bool isEmpty(queue* pQueue)
{
	//������� �����,
	//����� ������� ������ � ������ �����
	return (pQueue->head == pQueue->tail);
}

bool isFull(queue* pQueue)
{
	//������� ����������� 2 ������:
	//����� ������ ����� ������
	if (pQueue->head < pQueue->tail)
		return ((pQueue->tail - pQueue->head) == pQueue->buf_size);
	else
		//��� ����� ������ ������ ������
		return ((pQueue->head - pQueue->tail) == 1);
}

void print(queue* pQueue)
{
	int i;

	//������� ����������� 2 ������:
	//����� ������ ����� ������
	if (pQueue->head <= pQueue->tail)
		for (i = pQueue->head; i < pQueue->tail; i++)
			printf("%4d", pQueue->buf[i]);
	else
	{
		//��� ����� ������ ������ ������
		for (i = pQueue->head; i < pQueue->buf_size; i++)
			printf("%4d", pQueue->buf[i]);
		for (i = 0; i < pQueue->tail; i++)
			printf("%4d", pQueue->buf[i]);
	}
	printf("\n");
}
