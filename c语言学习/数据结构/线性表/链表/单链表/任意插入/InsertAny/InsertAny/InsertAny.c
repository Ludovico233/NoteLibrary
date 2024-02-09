#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* Insert(Node* head,int idx,int x) {//任意插入函数实现
	Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1->data = x;
	temp1->next = NULL;                        //新建插入的节点
	if (idx == 1) {                            //如果插入节点为1，也就是头节点，用头插法
		temp1->next = head;
		head = temp1;
		return head;
	}                                          //要在idx位置插入节点，就要找到 n-1 的位置
	Node* temp2 = head;
	for (int i = 0; i < idx - 2; i++) {        //我们都是从第一个节点开始遍历，找到idx - 1的位置，
		                                       //所以int i = 1；i < idx - 1  ==>  int i = 0; i < ida - 2
		temp2 = temp2->next;
	}                                          //将临时节点 temp2 移动到 n-1 的位置
	temp1->next = temp2->next;
	temp2->next = temp1;
	return head;
}
void Print(Node* head) {
	printf("链表为：");
	while (head != NULL) {
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}
int main(){
	struct Node* head = NULL;
	printf("请输入想要插入的元素的个数：");
	int n,idx,x;
	scanf("%d", &n);
    printf("输入位置和元素:\n(位置 元素)\n");
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &idx, &x);
		head = Insert(head,idx,x);
	}
	Print(head);
} 