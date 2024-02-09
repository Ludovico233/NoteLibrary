#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//创建节点结构
typedef struct Node {
	int data;
	struct Node* next;
}Node;

//头插法
Node* Insert(Node* head, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}

//迭代实现链表反转
Node* Reverse(Node* head) {      
	Node* current;
	Node* prev;
	Node* next;
	current = head;
	prev = NULL;
	while(current != NULL) {
		next = current->next;  //记录下一节点信息
		current->next = prev;  //当前节点连接前节点
		prev = current;        //前节点后移
		current = next;        //本节点后移
	}
	return prev;
}

//递归实现链表反向输出
//显示为链表好像已经反转了
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
	printf("反转前：\n");
	Print(head);
	head = Reverse(head);
	printf("\n反转后：\n");
	Print(head);
	return 0;
}