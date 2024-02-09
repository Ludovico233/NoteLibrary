//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include <stdbool.h>
//
////二叉排序树
////问题描述：完成二叉排序树的创建、查找、插入和删除操作。
////要求：
////1）创建一棵二叉排序树，并打印输出；
////2）分别编写函数完成二叉排序树的查找、插入和删除；
////3）测试二叉排序树的查找、插入和删除，分别打印测试结果；
////4）每一个函数要有必要的注释，在课程设计论文中有流程图。
//
//
////二叉树节点定义
//typedef struct BstNode {
//	int data;
//	struct BstNode* left;
//	struct BstNode* right;
//}BstNode;
//
////创建新节点
//BstNode* GetNewNode(int data) {
//	BstNode* newNode = (BstNode*)malloc(sizeof(BstNode));
//	if (newNode != NULL) {
//		newNode->data = data;
//		newNode->left = newNode->right = NULL;
//	}
//	return newNode;
//}
//
////插入节点
//BstNode* Insert(BstNode* root, int data) {
//	//空树情况
//	if (root == NULL) {
//		root = GetNewNode(data);
//		
//	}
//	//非空树（递归实现）
//	
//
//	//如果插入的数小于根，将他插入到左子树树中
//	else if (data <= root->data) {
//		root->left = Insert(root->left, data);
//	}
//	//如果插入的数大于根，将他插入到右子树树中
//	else {
//		root->right = Insert(root->right, data);
//	}
//	
//	return root;
//}
//
//
////查找节点
//bool Search(BstNode* root, int data) {
//	if (root == NULL) return false;
//	else if (root->data == data) return true;
//	else if (data <= root->data) return Search(root->left, data);
//	else return Search(root->right, data);
//}
//
////前序遍历
//void ProOrder(BstNode* root) {
//	if (root == NULL) return;
//	printf("%d\t", root->data);
//	ProOrder(root->left);
//	ProOrder(root->right);
//}
//
////找到最小值
//BstNode* FindMin(BstNode* root) {
//	if (root == NULL) {
//		printf("错误，此树是空树！");
//		return root;
//	}
//	BstNode* temp = root;
//	while (temp->left != NULL) {
//		temp = temp->left;
//	}
//	return temp;
//}
//
////删除节点
//BstNode* Delete(BstNode* root, int data) {
//	if (root == NULL) return NULL;
//	else if (data < root->data) root->left = Delete(root->left, data);
//	else if (data > root->data) root->right = Delete(root->right, data);
//	else{
//		//当删除元素没有子节点时
//		if (root->left == NULL && root->right == NULL) {
//			free(root);
//			root = NULL;
//		}//当删除节点有一个子节点时
//		else if (root->left == NULL) {
//			BstNode* temp = root;
//			root = root->right;
//			free(temp);
//		}
//		else if (root->right == NULL) {
//			BstNode* temp = root;
//			root = root->left;
//			free(temp);
//		}//当删除节点有两个子节点时
//		//找到右子树最小值或者左子树最大值
//		else {
//			BstNode* temp = FindMin(root->right);
//			root->data = temp->data;
//			root->right = Delete(root->right, temp->data);
//		}
//	}
//	return root;
//}
//
//int main() {
//	//二叉数初始化
//	BstNode* root = NULL;
//
//	//新建二叉树
//	int times = 0;
//	printf("您想要输入多少个数：");
//	scanf("%d", &times);
//	for (int i = 0; i < times;  i++) {
//		int num;
//		printf("请输入数字：");
//		scanf("%d", &num);
//		root = Insert(root, num);
//	}
//
//	//遍历二叉树
//	printf("\n\n二叉树前序遍历\n\n");
//	ProOrder(root);
//
//
//	//查找节点
//	int num1;
//	printf("\n\n请输入你想要查找的数：");
//	scanf("%d", &num1);
//	if (Search(root, num1)) {
//		printf("找到了！\n\n");
//	}
//	else {
//		printf("没找到！\n\n");
//	}
//
//	int num2;
//	printf("请输入想要删除的数：");
//	scanf("%d", &num2);
//	Delete(root, num2);
//
//
//	printf("\n二叉树遍历\n");
//	ProOrder(root);
//
//	return 0;
//}

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
	
	/*int i = 1;
	printf("输入小写字母:");
	c1 = getchar();
	if ((97 <= c1) && (c1 <= 122))
	{
		c2 = c1 - 32;
		printf("大写字母为%c", c2);
	}
	else {
		while (i)
				{
					printf("请重新输入:");
					c1 = getchar();
					if ((97 <= c1) && (c1 <= 122))
					{
						c2 = c1 - 32;
						break;
					}
					printf("大写字母为%c", c2);
				}
	}*/
		
}
