#include <stdio.h>
#include <limits.h>
#define ERROR -INT_MAX
struct Node {
	int val;
	Node* pNext;
};
struct LinkedList {
	Node* head; 
	bool sFull; 
	bool sEmpty;
	int size; 
	LinkedList() { 
		head = NULL;
		size = 0;
		sFull = 0;
		sEmpty = 0;
	}
    bool isFull() {
	    if (sFull)
		    printf("Khong the cap phat them bo nho !");
	    return sFull;
    }
    bool isEmpty() {
	    if (sEmpty)
		    printf("Danh sach da rong !");
	    return sEmpty;
    }

    Node* getNode(int value) {
	    Node* p = new Node;
	    if (p == NULL) return 0;
	    p->val = value;
	    p->pNext = NULL;
	    return p;
    }

    Node* addNode(int i, int value) {
	    Node* newNode = getNode(value);
	    if (newNode == NULL) {
		    sFull = 1;
		    isFull();
		    return 0;
	    }
	    if (i < 0 || i > size) {
		    printf("Khong ton tai vi tri i !");
		    return 0;
	    }
	    if (i == 0) {
		    size++;
		    return addFirst(value);
	    }
	    if (i == size) {
		    size++;
		    return addLast(value);
	    }
	    Node* p = head->pNext;
	    Node* prev = head;
	    int pos = 1;
	    while (p != NULL) {
		    if (pos == i) {
			    prev->pNext = newNode;
			    newNode->pNext = p;
			    size++;
			    break;
		    }   
		    prev = p;
		    p = p->pNext;
	    }
	    return newNode;
    }

    Node* addFirst(int value) {
	    Node* newNode = getNode(value);
	    if (newNode == NULL) {
		    sFull = 1;
		    isFull();
		    return 0;
	    }
	    newNode->pNext = head;
	    head = newNode;
	    return newNode;
    }

    Node* addLast(int value) {
	    Node* newNode = getNode(value);
	    if (newNode == NULL) {
		    sFull = 1;
		    isFull();
		    return 0;
	    }
	    if (head == NULL) {
		    head = newNode;
		    return head;
	    }
	    Node* p = head;
	    while (p->pNext != NULL)
		    p = p->pNext;
	    p->pNext = newNode;
	    return newNode;
    }

    void displayList() {
	    Node* p = head;
	    while (p != NULL) {
		    printf("%d ", p->val);
		    p = p->pNext;
	    }
    }

    void del(int i) {
	    if (i < 0 || i > size) {
		    printf("Khong ton tai vi tri!");
		    return;
	    }
	    if (i == 0) {
		    Node* p = head;
		    head = p->pNext;
		    delete(p);
		    size--;
	    }
	    else {
		    Node* prev = head;
		    Node* p = prev->pNext;
		    int pos = 1;
		    while (p != NULL) {
			    if (pos == i) {
				    prev->pNext = p->pNext;
				    delete(p);
				    size--;
				    break;
			    }
			    prev = p;
			    p = p->pNext;
		    }
	    }
	    if (head == NULL) sEmpty = 1;
    }

    int getFirst() {
	    if (!isEmpty()) return head->val;
	    return ERROR;
    }

    int getLast() {
	    if (!isEmpty()) {
		    Node* p = head;
		    while (p->pNext != NULL) p = p->pNext;
		    return p->val;
		    delete(p);
	    }
	    return ERROR;
    }
};
struct Stack {
	LinkedList* List; 
	Stack() { 
		List = new LinkedList; 
	}
    void push(int value) {
	    List->addNode(0, value);
    }
    void pop() {
	    List->del(0);
    }
    int get() {
	    return List->getFirst();
    }
    bool isEmpty() {
	    return List->sEmpty;
    }
    bool isFull() {
	    return List->sFull;
    }
};
int main() {
    Stack* myStack = new Stack;
    myStack->push(3);
    myStack->push(1);
    myStack->push(4);
    myStack->push(5);
    while (!myStack->isEmpty()) {
        printf("%d ", myStack->get());
        myStack->pop();
    }
    return 0;
}