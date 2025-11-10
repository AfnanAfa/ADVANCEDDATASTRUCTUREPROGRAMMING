#include <stdio.h>
#define SIZE 5   // maximum size of the stack

int stack[SIZE];  // array to hold stack elements
int top = -1;     // variable to track the top of the stack

// Function to push an element into the stack
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack is Full (Overflow)\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack is Empty (Underflow)\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

// Function to display stack elements
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}