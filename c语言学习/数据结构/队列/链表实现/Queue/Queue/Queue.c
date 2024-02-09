#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* front = NULL;
Node* rear = NULL;

Node* GetNewNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
}

void Enqueue(int data) {
	Node* temp = GetNewNode(data);
	if (front == NULL && rear == NULL) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue() {
	Node* temp = front;
	if (front == NULL) return;
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}

void Print() {
	Node* temp = front;
	printf("¶ÓÁÐ£º");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	Enqueue(2);
	Enqueue(3);
	Enqueue(7);
	Enqueue(1);
	Print();
	Dequeue(); Print();
	Dequeue(); Print();
	Dequeue(); Print();
	return 0;
}