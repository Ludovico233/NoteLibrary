//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include <stdbool.h>
//
////����������
////������������ɶ����������Ĵ��������ҡ������ɾ��������
////Ҫ��
////1������һ�ö���������������ӡ�����
////2���ֱ��д������ɶ����������Ĳ��ҡ������ɾ����
////3�����Զ����������Ĳ��ҡ������ɾ�����ֱ��ӡ���Խ����
////4��ÿһ������Ҫ�б�Ҫ��ע�ͣ��ڿγ����������������ͼ��
//
//
////�������ڵ㶨��
//typedef struct BstNode {
//	int data;
//	struct BstNode* left;
//	struct BstNode* right;
//}BstNode;
//
////�����½ڵ�
//BstNode* GetNewNode(int data) {
//	BstNode* newNode = (BstNode*)malloc(sizeof(BstNode));
//	if (newNode != NULL) {
//		newNode->data = data;
//		newNode->left = newNode->right = NULL;
//	}
//	return newNode;
//}
//
////����ڵ�
//BstNode* Insert(BstNode* root, int data) {
//	//�������
//	if (root == NULL) {
//		root = GetNewNode(data);
//		
//	}
//	//�ǿ������ݹ�ʵ�֣�
//	
//
//	//����������С�ڸ����������뵽����������
//	else if (data <= root->data) {
//		root->left = Insert(root->left, data);
//	}
//	//�������������ڸ����������뵽����������
//	else {
//		root->right = Insert(root->right, data);
//	}
//	
//	return root;
//}
//
//
////���ҽڵ�
//bool Search(BstNode* root, int data) {
//	if (root == NULL) return false;
//	else if (root->data == data) return true;
//	else if (data <= root->data) return Search(root->left, data);
//	else return Search(root->right, data);
//}
//
////ǰ�����
//void ProOrder(BstNode* root) {
//	if (root == NULL) return;
//	printf("%d\t", root->data);
//	ProOrder(root->left);
//	ProOrder(root->right);
//}
//
////�ҵ���Сֵ
//BstNode* FindMin(BstNode* root) {
//	if (root == NULL) {
//		printf("���󣬴����ǿ�����");
//		return root;
//	}
//	BstNode* temp = root;
//	while (temp->left != NULL) {
//		temp = temp->left;
//	}
//	return temp;
//}
//
////ɾ���ڵ�
//BstNode* Delete(BstNode* root, int data) {
//	if (root == NULL) return NULL;
//	else if (data < root->data) root->left = Delete(root->left, data);
//	else if (data > root->data) root->right = Delete(root->right, data);
//	else{
//		//��ɾ��Ԫ��û���ӽڵ�ʱ
//		if (root->left == NULL && root->right == NULL) {
//			free(root);
//			root = NULL;
//		}//��ɾ���ڵ���һ���ӽڵ�ʱ
//		else if (root->left == NULL) {
//			BstNode* temp = root;
//			root = root->right;
//			free(temp);
//		}
//		else if (root->right == NULL) {
//			BstNode* temp = root;
//			root = root->left;
//			free(temp);
//		}//��ɾ���ڵ��������ӽڵ�ʱ
//		//�ҵ���������Сֵ�������������ֵ
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
//	//��������ʼ��
//	BstNode* root = NULL;
//
//	//�½�������
//	int times = 0;
//	printf("����Ҫ������ٸ�����");
//	scanf("%d", &times);
//	for (int i = 0; i < times;  i++) {
//		int num;
//		printf("���������֣�");
//		scanf("%d", &num);
//		root = Insert(root, num);
//	}
//
//	//����������
//	printf("\n\n������ǰ�����\n\n");
//	ProOrder(root);
//
//
//	//���ҽڵ�
//	int num1;
//	printf("\n\n����������Ҫ���ҵ�����");
//	scanf("%d", &num1);
//	if (Search(root, num1)) {
//		printf("�ҵ��ˣ�\n\n");
//	}
//	else {
//		printf("û�ҵ���\n\n");
//	}
//
//	int num2;
//	printf("��������Ҫɾ��������");
//	scanf("%d", &num2);
//	Delete(root, num2);
//
//
//	printf("\n����������\n");
//	ProOrder(root);
//
//	return 0;
//}

#include <stdio.h>
void main()
{

	int flag = 1;
	printf("����Сд��ĸ:");
	while (flag) {
		char c1, c2;
		c1 = getchar();
		if ((97 <= c1) && (c1 <= 122))
		{
			c2 = c1 - 32;
			printf("��д��ĸΪ%c", c2);
			flag = 0;
		}
		else {
			printf("����������:");
			c1 = getchar();
		}
	}
	
	/*int i = 1;
	printf("����Сд��ĸ:");
	c1 = getchar();
	if ((97 <= c1) && (c1 <= 122))
	{
		c2 = c1 - 32;
		printf("��д��ĸΪ%c", c2);
	}
	else {
		while (i)
				{
					printf("����������:");
					c1 = getchar();
					if ((97 <= c1) && (c1 <= 122))
					{
						c2 = c1 - 32;
						break;
					}
					printf("��д��ĸΪ%c", c2);
				}
	}*/
		
}
