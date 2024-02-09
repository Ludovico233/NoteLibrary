#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int data) {
	if (top == MAX_SIZE - 1) {
		printf("Error: stack overflow\n");
		return;
	}
		A[++top] = data;
}

void Pop() {
	if (top == -1) {
		printf("Error: stack is elmpty\n");
		return;
	}
	top--;
}

int Top() {
	return A[top];
}

void Print() {
	printf("Õ»Îª£º");
	for (int i = 0; i <= top; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}
int main() {
	Push(2);
	Push(4);
	Push(6);
	Push(8);
	printf("Õ»¶¥Îª£º%d\n", Top());
	Print();
	Pop();
	Pop();
	Push(10);
	Print();
	return 0;
}