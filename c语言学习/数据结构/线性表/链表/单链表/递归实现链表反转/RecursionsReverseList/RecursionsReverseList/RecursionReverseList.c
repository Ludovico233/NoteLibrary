#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

//尾插法
Node* Insert(Node* head,int data) {
	Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1->data = data;
	temp1->next = NULL;
	if (head == NULL) head = temp1;
	else {
		Node* temp2 = head;
		while (temp2->next != NULL) temp2 = temp2->next;
		temp2->next = temp1;
	}
	return head;
}

Node* Reverse(Node* head) {
	if (head->next == NULL || head == NULL) {
		return head;
	}
	Node* lastNode = Reverse(head->next);      //递归到末节点
	head->next->next = head;  //实现反转
	head->next = NULL;
	return lastNode;
}

void Print(Node* head) {
	if (head == NULL) return;
	printf("%d ", head->data);
	Print(head->next);
}
int main() {
	Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 5);
	head = Insert(head, 6);
	head = Insert(head, 1);
	head = Insert(head, 9);
	printf("反转前：\n");
	Print(head);
	head = Reverse(head);
	printf("\n反转后：\n");
	Print(head);
	return 0;
}