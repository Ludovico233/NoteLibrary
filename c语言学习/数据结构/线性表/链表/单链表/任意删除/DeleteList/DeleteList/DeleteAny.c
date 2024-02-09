#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//�����ڵ�ṹ ��������Ϊ Node
typedef struct Node {
	int data;
	struct Node* next;
}Node;

//����ʹ�õ���β�巨
Node* Insert(Node* head,int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) head = temp;
	else {
		Node* temp1 = head;
		while (temp1->next != NULL) temp1 = temp1->next;
		temp1->next = temp;
	}
	return head;
}

Node* Delete(Node* head,int idx) {           //ɾ������λ�÷���ʵ��
	Node* temp1 = head;
	if (idx == 1) {                           //�����ɾ��ͷ�ڵ㣬ֱ���� head ָ��ڶ��ڵ㣬�ͷ�ͷ�ڵ�
		head = temp1->next;
		free(temp1);
		return head;
	}
	for (int i = 0; i < idx - 2; i++) {      //ɾ�� idx λ�õĽڵ㣬Ҫ�ҵ� idx -1 λ�õĽڵ�
		temp1 = temp1->next;
	}
	Node* temp2 = temp1->next;              //�� temp2 ָ��Ҫɾ���Ľڵ�
	temp1->next = temp2->next;
	free(temp2);                           //�ͷ� temp2 �ڵ�ռ�
	return head;
}

//�ݹ��ӡ����
void Print(Node* head) {
	Node* temp = head;
	if (temp == NULL) {
		printf("\n");
		return;
	}
	//printf("����Ϊ��");
	printf("%d ", temp->data);
	Print(temp->next);

}

int main() {
	struct Node* head = NULL;
	printf("��������Ҫ�����Ԫ�صĸ�����");
	int n, idx, x;
	scanf("%d", &n);
	printf("����Ԫ��:");
	for (int i = 0; i < n; i++) {
		scanf("%d",&x);
		head = Insert(head, x);
	}
	Print(head);
	printf("������Ҫɾ��Ԫ�ص�λ�ã�");
	scanf("%d", &idx);
	Delete(head, idx);
	Print(head);
}