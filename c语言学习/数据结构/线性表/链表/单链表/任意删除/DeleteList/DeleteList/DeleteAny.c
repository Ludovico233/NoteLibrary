#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//创建节点结构 并重命名为 Node
typedef struct Node {
	int data;
	struct Node* next;
}Node;

//这里使用的是尾插法
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

Node* Delete(Node* head,int idx) {           //删除任意位置方法实现
	Node* temp1 = head;
	if (idx == 1) {                           //如果是删除头节点，直接让 head 指向第二节点，释放头节点
		head = temp1->next;
		free(temp1);
		return head;
	}
	for (int i = 0; i < idx - 2; i++) {      //删除 idx 位置的节点，要找到 idx -1 位置的节点
		temp1 = temp1->next;
	}
	Node* temp2 = temp1->next;              //让 temp2 指向要删除的节点
	temp1->next = temp2->next;
	free(temp2);                           //释放 temp2 节点空间
	return head;
}

//递归打印链表
void Print(Node* head) {
	Node* temp = head;
	if (temp == NULL) {
		printf("\n");
		return;
	}
	//printf("链表为：");
	printf("%d ", temp->data);
	Print(temp->next);

}

int main() {
	struct Node* head = NULL;
	printf("请输入想要插入的元素的个数：");
	int n, idx, x;
	scanf("%d", &n);
	printf("输入元素:");
	for (int i = 0; i < n; i++) {
		scanf("%d",&x);
		head = Insert(head, x);
	}
	Print(head);
	printf("请输入要删除元素的位置：");
	scanf("%d", &idx);
	Delete(head, idx);
	Print(head);
}