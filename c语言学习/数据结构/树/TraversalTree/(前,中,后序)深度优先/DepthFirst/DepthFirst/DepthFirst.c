#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
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

Node* Insert(Node* root,int data) {
	if (root == NULL) {
		root = GetNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left,data);
	}
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

void ProOrder(Node* root) {
	if (root == NULL) return;
	printf("%d ", root->data);
	ProOrder(root->left);
	ProOrder(root->right);
}

void InOrder(Node* root) {
	if (root == NULL) return;
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(Node* root) {
	if (root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root ->data);
}

int main() {
	Node* root = NULL;
	root = Insert(root, 5);
	root = Insert(root, 3);
	root = Insert(root, 7);
	root = Insert(root, 1);
	root = Insert(root, 9);
	root = Insert(root, 4);
	root = Insert(root, 6);
	printf("前序遍历：\n");
	ProOrder(root);
	printf("\n\n中序遍历：\n");
	InOrder(root);
	printf("\n\n后序遍历：\n");
	PostOrder(root);
	return 0;
}