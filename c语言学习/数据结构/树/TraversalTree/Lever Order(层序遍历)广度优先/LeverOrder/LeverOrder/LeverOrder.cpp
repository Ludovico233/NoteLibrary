#define _CRT_SECURE_NO_WARNINGS 1
#include<iosream>;
#include <queue>
using namespace std;

struct Node {
	char data;
	Node* left;
	Node* right;
};


void LeverOrder(Node* root) {
	if (root == nullptr) return;
	queue<Node*> Q;
	Q.push(root);
	while (!Q.empty()) {
		Node* current = Q.front();
		cout << current->data << " ";
		if (current->left != NULL) Q.push(current->left);
		if (current->right != NULL) Q.push(current->right);
		Q.pop();
	}
}

int main() {
	Node* root = nullptr;
	return 0;
}