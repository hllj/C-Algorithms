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
    int get(int &Success) {
        if (isEmpty()) {
            printf("Stack is empty!\n");
            Success = 0;
            return 0;
        }
        else {
            Sucess = 1;
            return items[top - 1];
        }
    }
    void push(int value) {
        if (isFull()) {
            printf("Stack is full!\n");
        }
        else items[++top] = value;
    }
    int pop(int &Success) {
        if (isEmpty()) {
            printf("Stack is empty!\n");
            Success = 0;
            return 0;
        }
        else {
            int result = items[top - 1];
            top--;
            Success = 1;
            return result;
        }
    }
};
int main() {
    Stack* myStack = new Stack;

    return 0;
}