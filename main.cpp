#include <iostream>
#include <stdexcept>

class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;

public:
    Queue(int size) : capacity(size), front(-1), rear(-1) {
        arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (rear == capacity - 1) {
            throw std::overflow_error("Queue overflow!");
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = value;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            throw std::underflow_error("Queue underflow!");
        }
        return arr[front++];
    }

    int peek() {
        if (front == -1 || front > rear) {
            throw std::underflow_error("Queue is empty!");
        }
        return arr[front];
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }
};

int main() {
    Queue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    std::cout << "Front element: " << queue.peek() << std::endl;
    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;
    std::cout << "Front element: " << queue.peek() << std::endl;
    return 0;
}
