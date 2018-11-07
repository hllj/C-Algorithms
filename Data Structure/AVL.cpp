#include <iostream>
#include <algorithm>
#include <vector>
#include <conio.h>
using namespace std;
struct NODE {
	int key;
	NODE* pLeft;
	NODE* pRight;
	int height;
};
void init(NODE* Tree) {
	Tree = NULL;
}
NODE* createNode(int key) {
	NODE* res = new NODE;
	res->key = key;
	res->pLeft = res->pRight = NULL;
	res->height = 1;
	return res;
}
int getHeight(NODE* pTree) {
	if (pTree == NULL) return 0;
	else
		return pTree->height;
}
int getBalance(NODE* pTree) {
	return getHeight(pTree->pRight) - getHeight(pTree->pLeft);
}

NODE* leftRotate(NODE* pNode) {
	NODE* Q = pNode->pRight;
	NODE* T = Q->pLeft;
	pNode->pRight = T;
	Q->pLeft = pNode;
	return Q;
}
NODE* rightRotate(NODE* pNode) {
	NODE* Q = pNode->pLeft;
	NODE* T = Q->pRight;
	pNode->pLeft = T;
	Q->pRight = pNode;
	return Q;
}
NODE* insert(NODE*& pTree, int key) {
	if (pTree == NULL) {
		pTree = createNode(key);
		return pTree;
	}
	if (key > pTree->key) {
		pTree->pRight = insert(pTree->pRight, key);
	}
	if (key < pTree->key) {
		pTree->pLeft = insert(pTree->pLeft, key);
	}

	pTree->height = 1 + max(getHeight(pTree->pLeft), getHeight(pTree->pRight));
	int bal = getBalance(pTree);

	if (bal > 1 && key > pTree->pRight->key) {
		pTree = leftRotate(pTree);
	}
	if (bal > 1 && key < pTree->pRight->key) {
		pTree->pRight = rightRotate(pTree->pRight);
		pTree = leftRotate(pTree);
	}
	if (bal < -1 && key < pTree->pLeft->key) {
		pTree = rightRotate(pTree);
	}
	if (bal < -1 && key > pTree->pLeft->key) {
		pTree->pLeft = leftRotate(pTree->pLeft);
		pTree = rightRotate(pTree);
	}
	return pTree;
}
void traverse(NODE* pTree) {
	if (pTree != NULL) {
		traverse(pTree->pLeft);
		cout << pTree->key << " ";
		traverse(pTree->pRight);
	}
}
int main() {
	NODE* Tree = NULL;
	init(Tree);
	int a[10] = { 2, 5, 4, 6, 9, 4, 12, 16, 8, 20 };
	for (int i = 0; i < 10; i++)
		insert(Tree, a[i]);
	traverse(Tree);
	_getch();
	return 0;
}