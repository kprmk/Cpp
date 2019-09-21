#include <stdio.h>
#include <stdlib.h>

//���������� ��� ������ ��� ���������
typedef struct listItem
{
	int data;			//�������������� ����
	listItem* next;		//������ �� ����������� ���������
} listItem;

listItem* add_inHead(listItem* head, int value);	//���������� �������� � ������ ������
listItem* add_inTail(listItem* head, int value);	//���������� �������� � ����� ������
listItem* remove_onHead(listItem* head);			//�������� �������� � ������ ������
listItem* remove_onTail(listItem* head);			//�������� �������� � ������ ������
void print(listItem* head);							//������ ��������� ������
void print_recursion(listItem* head);				//����������� ���������� ������
void print_reverse(listItem* head);					//������ � �������� �������
void destroyList(listItem* head);					//�������� ����� ������

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
	//�������� ������ ��� ����� ������� � �������������� malloc
	//� ���� ������ ����� ������������� �������� ������������
	//������������� - �� ��� ��� ���� �� ����� ������ free
	listItem* newItem = (listItem*)malloc(sizeof(listItem));
	//�������������� �������������� ����
	newItem->data = value;
	//��������� ����� ������� � ������������ �������
	//���� ���� head=NULL, �� ����� �� ����� ���������
	newItem->next = head;
	//�����: ���������� ��������� �� ����� �������,
	//�� ������ ����� ����� ������� ������
	return newItem;
}

listItem* add_inTail(listItem* head, int value)
{
	//������ ����� �������
	listItem* newItem = (listItem*)malloc(sizeof(listItem));
	//�������������� �������������� ����
	newItem->data = value;
	//������� ����� ��������� � ������,
	//������� ��������� �� ��������� - ������� NULL
	newItem->next = NULL;

	//���� ���������� ������ ��� ����
	if (!head)
		//����� ������� ����� ��� �������
		return newItem;

	//������ ��������������� ���������
	//��� ����������� �� ������
	listItem* current = head;

	//���������� �������� ������
	while (current->next)
		current = current->next;
	//����� ������ �� ����� current
	//����� ��������� �� ��������� ������� ������

	//�������� ��������� ������� ������
	//� ����� ���������
	current->next = newItem;

	//������ �� ����������, ���������� ������ ��������
	return head;
}

listItem* remove_onHead(listItem* head)
{
	//���� ������ ����
	if (!head)
		//������� ������, ���������� NULL
		return NULL;

	//��������� ����� ��������� �������� ������
	listItem* temp = head;
	//�������� ������ �� ��������� �������
	//���� ���� head->next=NULL, �� ����� ���������
	head = head->next;
	//����������� ������, � ������� ����������
	//������ �������� �������
	free(temp);
	//���������� ���������� ��������� ������ ������
	return head;
}

listItem* remove_onTail(listItem* head)
{
	//���� ������ ����
	if (!head)
		//������� ������, ���������� NULL
		return NULL;

	//���� � ������ �������� ������� �������� ������������
	if (!head->next)
	{
		//����������� ������, � ������� �� ����������
		free(head);
		//� ���������� NULL
		return NULL;
	}

	//������ ��������������� ���������
	//��� ����������� �� ������
	listItem* current = head;

	//���������� �������� ������
	while (current->next->next)
		current = current->next;
	//����� ������ �� ����� current
	//����� ��������� �� ������������� ������� ������

	//����������� ������, � ������� ����������
	//��������� ������� ������
	free(current->next);
	//������ ������ � ������������� �������� �������
	current->next = NULL;
	//������ �� ��������
	return head;
}

void print(listItem* head)
{
	//������ ��������������� ���������
	//��� ����������� �� ������
	listItem* current = head;

	//���������� �������� ������
	while (current)
	{
		//�������� �������������� ����
		//�������� �������� ������
		printf("%4d", current->data);
		current = current->next;
	}
	printf("\n");
}

void print_recursion(listItem* head)
{
	/*����������� ����������*/

	//�������� �������������� ����
	//�������� �������� ������
	printf("%4d", head->data);
	//���� ������� �� ���������
	if (head->next)
		//������ ����������� �����
		print_recursion(head->next);
}

void print_reverse(listItem* head)
{
	/*
	����� ������ � �������� ������� ��������
	������ � ������� ����������� ����������
	*/

	//���� ������� �� ���������
	if (head->next)
		//������ ����������� �����
		print_reverse(head->next);

	//�������� �������������� ����
	//�������� �������� ������
	printf("%4d", head->data);
}

void destroyList(listItem* head)
{
	//������ ��������������� ���������
	//��� ����������� �� ������
	listItem* current = head;

	//������ ��������������� ���������
	//��� ���������� ������ �����������
	//�������� ������
	listItem* temp;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
