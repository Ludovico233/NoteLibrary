#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int top = -1;//top����ʱ�̱�ʾջ��Ԫ������λ��
void push(char* a, int elem) {
    a[++top] = elem;
}
void pop(char* a) {
    if (top == -1) {
        return;
    }
    top--;
}
char visit(char* a) {
    //��ȡջ��Ԫ�أ������ڵ�ջ�����ջΪ�գ�Ϊʹ���򲻷������󣬷��ؿ��ַ�
    if (top != -1) {
        return a[top];
    }
    else {
        return ' ';
    }
}
int main() {
    int length, i;
    char a[30];
    char bracket[100];
    printf("�������������У�");
    scanf("%s", bracket);
    getchar();
    length = (int)strlen(bracket);
    for (i = 0; i < length; i++) {
        if (bracket[i] == '(' || bracket[i] == '{') {
            push(a, bracket[i]);
        }
        else {
            if (bracket[i] == ')') {
                if (visit(a) == '(') {
                    pop(a);
                }
                else {
                    printf("���Ų�ƥ��");
                    return 0;
                }
            }
            else {
                if (visit(a) == '{') {
                    pop(a);
                }
                else {
                    printf("���Ų�ƥ��");
                    return 0;
                }
            }
        }
    }
    if (top != -1) {
        printf("���Ų�ƥ��");
    }
    else {
        printf("����ƥ��");
    }
}