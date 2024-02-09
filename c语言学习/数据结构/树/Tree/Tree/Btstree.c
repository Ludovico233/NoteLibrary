#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

//����������(BTS)
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* GetNewNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = GetNewNode(data);
	}
	else if(data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(Node* root, int data) {
	if (root == NULL) return false;
	else if (data == root->data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}

//����ʵ��,�Ҷ��������ֵ����Сֵ
int FindMin1(Node* root) {
	if (root == NULL) {
		printf("���󣺶�����Ϊ�գ�");
		return -1;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}

int FindMax1(Node* root) {
	if (root == NULL) {
		printf("���󣺶�����Ϊ�գ�");
		return -1;
	}
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

//�ݹ�ʵ�֣��Ҷ��������ֵ����Сֵ
int FindMin2(Node* root) {
	if (root == NULL) {
		printf("���󣺶�����Ϊ�գ�");
		return -1;
	}
	else if (root->left == NULL) {
		return root->data;
	}
	return FindMin2(root->left);
}

int FindMax2(Node* root) {
	if (root == NULL) {
		printf("���󣺶�����Ϊ�գ�");
		return -1;
	}
	else if (root->right == NULL) {
		return root->data;
	}
	return FindMax2(root->right);
}

//����������߶�
int FindHight(Node* root) {
	if (root == NULL) {
		return -1;
	}
	return max(FindHight(root->left), FindHight(root->right)) + 1;
}

int main() {
	Node* root = NULL;
	root = Insert(root, 3);
	root = Insert(root, 5);
	root = Insert(root, 9);
	root = Insert(root, 7);
	root = Insert(root, 4);
	printf("������Ҫ��ѯ��ֵ��");
	int x;
	scanf("%d", &x);
	if (Search(root, x)) printf("�ҵ��ˣ�");
	else printf("û�ҵ���");
	printf("\n\n��������");
	printf("\n��Сֵ��%d", FindMin1(root));
	printf("\n���ֵ��%d", FindMax1(root));
	printf("\n\n�ݹ鷽��");
	printf("\n��Сֵ��%d", FindMin2(root));
	printf("\n���ֵ��%d", FindMax2(root));
	printf("\n\n�������߶ȣ�%d", FindHight(root));
	return 0;
}