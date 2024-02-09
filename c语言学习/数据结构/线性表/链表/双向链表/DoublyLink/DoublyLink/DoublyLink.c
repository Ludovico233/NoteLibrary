#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//Ϊʲô����Ҫ����˫������
//�ŵ㣺
//1. ��ָ������ڵ��ָ�룬���ǿ��Է����ѯ��
//2. ���ڲ�ѯ��ɾ���Ȳ���
//������
//1. Ҫʹ�ö�Ŀռ䴢��ڵ���Ϣ
//2. �������ɾ��ʱ��Ҫ�޸������Ӹ��࣬��ҪС��

typedef struct Node {
	int data;
	struct Node* next;//��ڵ�
	struct Node* prev;//ǰ�ڵ�
}Node;
Node* head;

Node* GetNewNode(int data) {                     //��װ�����½ڵ�ķ�����������븴��
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void InsertAtHead(int data) {
	Node* newNode = GetNewNode(data);
	if (head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void InsertAtTail(int data) {
	Node* newNode = GetNewNode(data);
	if (head == NULL) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void Print() {
	Node* temp = head;
	printf("����Ϊ��");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint() {
	Node* temp = head;
	if (temp == NULL) return;
	while (temp->next != NULL) temp = temp->next;
	printf("��ת��");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main() {
	head = NULL;
	printf("ͷ�巨��ӣ�\n");
	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
	printf("β�巨��ӣ�\n");
	InsertAtTail(1); Print(); ReversePrint();
	InsertAtTail(3); Print(); ReversePrint();
	InsertAtTail(5); Print(); ReversePrint();
	return 0;
}