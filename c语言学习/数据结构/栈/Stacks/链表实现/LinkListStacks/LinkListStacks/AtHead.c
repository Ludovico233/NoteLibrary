#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* top = NULL;

Node* GetNewNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void Push(int data) {
	Node* temp = GetNewNode(data);
	temp->next = top;
	top = temp;
}

void Pop() {
	Node* temp;
	if (top == NULL) return;
	temp = top;
	top = top->next;
	free(temp);
}

int Top() {
	return top->data;
}

void Print() {
	if (top == NULL) return;
	Node* temp = top;
	printf("Õ»Îª£º");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main() {
	Push(2);
	Push(4);
	Push(6);
	Push(8);
	Print();
	printf("Õ»¶¥£º%d\n", Top());
	Pop();
	Pop();
	Push(10);
	Print();
	printf("Õ»¶¥£º%d\n", Top());
	return 0;
}