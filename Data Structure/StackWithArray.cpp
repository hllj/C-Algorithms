#include <stdio.h>
const int NMAX      =   1e5;
struct Stack {
    int items[NMAX];
    int top;
    Stack() {
        top = 0;
    }
    bool isEmpty() {
        return (top == 0) ? 1 : 0;
    }
    bool isFull() {
        return (top == NMAX - 1) ? 1 : 0;
    }
    void push(int value) {
        if (isFull()) {
            printf("Stack is full!\n");
            return;
        }
        items[top++] = value;
    }
    int get() {
        return items[top - 1];
    }
    void pop() {
        if (isEmpty()) {
            printf("Stack is empty!\n");
            return;
        }
        top--;
    }
};
int main() {
    Stack* myStack = new Stack;
    myStack->push(2);
    myStack->push(3);
    myStack->push(1);
    myStack->push(4);
    while (!myStack->isEmpty()) {
        printf("%d ", myStack->get());
        myStack->pop();
    }
    return 0;
}