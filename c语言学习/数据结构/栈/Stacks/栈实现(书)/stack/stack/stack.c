#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int DataType;
typedef struct stacknode {
	DataType data;
	struct stacknode* next;
}LinkStack;

LinkStack *InitStack(){
	LinkStack* S;
	S = NULL;
	return S;
}

int EmptyStack(LinkStack* S) {
	if (S == NULL)
		return 1;
	else
		return 0;
}

LinkStack* Push(LinkStack* S, DataType x) {
	LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	p->next = S;
	S = p;
	return S;
}

LinkStack* Pop(LinkStack* S, DataType* x) {
	LinkStack* p;
	if (EmptyStack(S)) {
		pirntf("\t 栈空，不能出栈!");
		return NULL;
	}
	else {
		*x = S->data;
		p = S;
		S = S->next;
		free(p);
		return S;
	}
}

int GetTop(LinkStack* S, DataType* x) {
	if (EmptyStack(S)) {
		printf("栈空！");
		return 0;
	}
	else {
		*x = S->data;
		return 1;
	}
}

void ShowStack(LinkStack* S) {
	LinkStack* p = S;
	if (p == NULL) {
		printf("从栈顶元素起栈中的各元素为：");
		while (p != NULL) {
			pirntf("%d", p->data);
			p = p->next;
		}
	}
}

int correct(char a[]) {
	LinkStack s;
	InitStack(s);
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == '(') {
			Push(s, '(');
		}
		else if (a[i] == ')') {
			if (EmptyStack(s))
				return 0;
			else
				Pop(s);
		}
		if (EmptyStack(s))
			printf("匹配正确！");
		else
			printf("匹配失败！");
	}
}

int main() {
	char a[] = "(1 + 2) * (3 + 4)";
	correct(a);
	return 0;
}