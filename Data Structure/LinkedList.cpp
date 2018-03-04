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
    void deleteNodeWithValue(int value) {
        Node* p;
        p = head;
        while (p->pNext != NULL) {
            if (p->pNext->info == value) {
                Node* next = p->pNext->pNext;
                delete(p->pNext);
                p->pNext = next;
            }
            p = p->pNext;
            if (p == NULL) break;
        }
    }
    void reverse() {
        Node* p;
        p = head;
        Node* prev = NULL;
        while (p != NULL) {
            Node* next = p->pNext;
            p->pNext = prev;
            prev = p;
            p = next;
        }
        head = prev;
    }
};
int main() {
    LinkedList* myList = new LinkedList;
    myList->insertNode(2);
    myList->insertNode(3);
    myList->insertNode(4);
    myList->insertNode(3);
    //myList->deleteNodeWithValue(3);
    myList->reverse();
    myList->displayList();
    return 0;
}
