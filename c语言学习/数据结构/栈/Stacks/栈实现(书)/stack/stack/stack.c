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
		pirntf("\t ջ�գ����ܳ�ջ!");
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
		printf("ջ�գ�");
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
		printf("��ջ��Ԫ����ջ�еĸ�Ԫ��Ϊ��");
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
			printf("ƥ����ȷ��");
		else
			printf("ƥ��ʧ�ܣ�");
	}
}

int main() {
	char a[] = "(1 + 2) * (3 + 4)";
	correct(a);
	return 0;
}