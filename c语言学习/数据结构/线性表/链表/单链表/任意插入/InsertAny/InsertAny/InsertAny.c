#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* Insert(Node* head,int idx,int x) {//������뺯��ʵ��
	Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1->data = x;
	temp1->next = NULL;                        //�½�����Ľڵ�
	if (idx == 1) {                            //�������ڵ�Ϊ1��Ҳ����ͷ�ڵ㣬��ͷ�巨
		temp1->next = head;
		head = temp1;
		return head;
	}                                          //Ҫ��idxλ�ò���ڵ㣬��Ҫ�ҵ� n-1 ��λ��
	Node* temp2 = head;
	for (int i = 0; i < idx - 2; i++) {        //���Ƕ��Ǵӵ�һ���ڵ㿪ʼ�������ҵ�idx - 1��λ�ã�
		                                       //����int i = 1��i < idx - 1  ==>  int i = 0; i < ida - 2
		temp2 = temp2->next;
	}                                          //����ʱ�ڵ� temp2 �ƶ��� n-1 ��λ��
	temp1->next = temp2->next;
	temp2->next = temp1;
	return head;
}
void Print(Node* head) {
	printf("����Ϊ��");
	while (head != NULL) {
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}
int main(){
	struct Node* head = NULL;
	printf("��������Ҫ�����Ԫ�صĸ�����");
	int n,idx,x;
	scanf("%d", &n);
    printf("����λ�ú�Ԫ��:\n(λ�� Ԫ��)\n");
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &idx, &x);
		head = Insert(head,idx,x);
	}
	Print(head);
} 