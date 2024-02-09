#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//为什么我们要创建双向链表
//优点：
//1. 有指向任意节点的指针，我们可以反向查询。
//2. 利于查询，删除等操作
//坏处：
//1. 要使用多的空间储存节点信息
//2. 插入或者删除时想要修复的链接跟多，需要小心

typedef struct Node {
	int data;
	struct Node* next;//后节点
	struct Node* prev;//前节点
}Node;
Node* head;

Node* GetNewNode(int data) {                     //封装创建新节点的方法，避免代码复用
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
	printf("链表为：");
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
	printf("反转：");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main() {
	head = NULL;
	printf("头插法添加：\n");
	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
	printf("尾插法添加：\n");
	InsertAtTail(1); Print(); ReversePrint();
	InsertAtTail(3); Print(); ReversePrint();
	InsertAtTail(5); Print(); ReversePrint();
	return 0;
}