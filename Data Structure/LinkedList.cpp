#include <stdio.h>
struct Node {
    int info;
    Node* pNext;
};
struct LinkedList {
    Node* head;
    LinkedList() {
        head = NULL;
    }
    void insertNode(int value) {
        Node* newNode = new Node;
        newNode->info = value;
        newNode->pNext = NULL;
        if (head == NULL) head = newNode;
        else {
            Node* p;
            p = head;
            while (p->pNext != NULL) {
                p = p->pNext;
            }
            p->pNext = newNode;
        }
    }
    void displayList() {
        Node* p;
        p = head;
        while (p != NULL) {
            printf("%d ", p->info);
            p = p->pNext;
        }
    }
};
int main() {
    LinkedList* myList = new LinkedList;
    myList->insertNode(2);
    myList->insertNode(3);
    myList->insertNode(4);
    myList->displayList();
    return 0;
}
