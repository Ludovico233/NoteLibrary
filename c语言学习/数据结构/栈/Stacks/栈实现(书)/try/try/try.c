#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int top = -1;//top变量时刻表示栈顶元素所在位置
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
    //调取栈顶元素，不等于弹栈，如果栈为空，为使程序不发生错误，返回空字符
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
    printf("请输入括号序列：");
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
                    printf("括号不匹配");
                    return 0;
                }
            }
            else {
                if (visit(a) == '{') {
                    pop(a);
                }
                else {
                    printf("括号不匹配");
                    return 0;
                }
            }
        }
    }
    if (top != -1) {
        printf("括号不匹配");
    }
    else {
        printf("括号匹配");
    }
}