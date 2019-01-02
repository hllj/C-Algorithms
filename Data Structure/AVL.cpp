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

void updateHeight(NODE* pNode) {
	pNode->height = 1 + max(getHeight(pNode->pLeft), getHeight(pNode->pRight));
}

NODE* leftRotate(NODE* pNode) {
	NODE* Q = pNode->pRight;
	NODE* T = Q->pLeft;
	pNode->pRight = T;
	Q->pLeft = pNode;

	updateHeight(pNode);
	updateHeight(Q);

	return Q;
}
NODE* rightRotate(NODE* pNode) {
	NODE* Q = pNode->pLeft;
	NODE* T = Q->pRight;
	pNode->pLeft = T;
	Q->pRight = pNode;

	updateHeight(pNode);
	updateHeight(Q);

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

	updateHeight(pTree);
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
	int a[13] = { 45, 36, 15, 29, 57, 78, 60, 83, 79, 96, 29, 99, 97};
	for (int i = 0; i < 13; i++)
		Tree = insert(Tree, a[i]);
	traverse(Tree);
	_getch();
	return 0;
}