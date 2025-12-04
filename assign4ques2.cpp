// time complexity: O(n)
// space complexity: O(n)


#include <iostream>
using namespace std;

#define SIZE 5
int cqueue[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Circular Queue Overflow!" << endl;
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    cqueue[rear] = value;
    cout << value << " enqueued." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Circular Queue Underflow!" << endl;
        return;
    }
    cout << cqueue[front] << " dequeued." << endl;
    if (front == rear) { // queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Circular Queue is empty!" << endl;
        return;
    }
    cout << "Front element: " << cqueue[front] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Circular Queue is empty!" << endl;
        return;
    }
    cout << "Circular Queue elements: ";
    int i = front;
    while (true) {
        cout << cqueue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int choice, value;
    while (true) {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
