#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void main()
{
	int flag = 1;
	printf("输入小写字母:");
	while (flag) {
		char c1, c2;
		c1 = getchar();
		if ((97 <= c1) && (c1 <= 122))
		{
			c2 = c1 - 32;
			printf("大写字母为%c", c2);
			flag = 0;
		}
		else {
			printf("请重新输入:");
			c1 = getchar();
		}
	}
}