#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//�����ڵ�ṹ
typedef struct Node {
	int data;
	struct Node* next;
}Node;

//ͷ�巨
Node* Insert(Node* head, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}

//����ʵ������ת
Node* Reverse(Node* head) {      
	Node* current;
	Node* prev;
	Node* next;
	current = head;
	prev = NULL;
	while(current != NULL) {
		next = current->next;  //��¼��һ�ڵ���Ϣ
		current->next = prev;  //��ǰ�ڵ�����ǰ�ڵ�
		prev = current;        //ǰ�ڵ����
		current = next;        //���ڵ����
	}
	return prev;
}

//�ݹ�ʵ�����������
//��ʾΪ��������Ѿ���ת��
void Print(Node* head) {         
	if (head == NULL) return;    
	Print(head->next);
	printf("%d ", head->data);
}

int main() {
	Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 5);
	head = Insert(head, 6);
	head = Insert(head, 1);
	head = Insert(head, 9);
	printf("��תǰ��\n");
	Print(head);
	head = Reverse(head);
	printf("\n��ת��\n");
	Print(head);
	return 0;
}