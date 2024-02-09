#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* Insert(Node* head,int x) {//添加函数
    Node* temp = (Node*)malloc(sizeof(Node));//新建节点
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}
void Print(Node* head) {//输出函数
    printf("链表为：");
    while (head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    Node* head = NULL;//链表为空，链表初始化
    printf("请输入想要添加的个数：");
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        printf("请输入想要添加的数：");
        scanf("%d", &x);
        head = Insert(head,x);
       Print(head);
    } 
    return 0;
}