#include <stdio.h>
#define SIZE 5  // Maximum size of circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element
void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Queue is Full!\n");
    } else {
        if (front == -1)  // If queue is empty
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;  // Move rear circularly

        queue[rear] = value;
        printf("%d inserted into the circular queue.\n", value);
    }
}

// Function to delete an element
void dequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("%d deleted from the circular queue.\n", queue[front]);
        if (front == rear) {
            // Queue has only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;  // Move front circularly
        }
    }
}

// Function to display the queue
void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        int i = front;
        printf("Circular Queue elements are: ");
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;  // Move circularly
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
