#include <iostream>

using namespace std;

class Queue
{
private:
    int front, rear, capacity, size, *arr;

public:
    Queue(int c)
    {
        front = rear = -1;
        capacity = c;
        arr = new int[c];
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = val;
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue" << endl;
            return -1;
        }
        int temp = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        size--;
        return temp;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }

    void show()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements are: ";
        for (int i = front; i != rear; i = (i + 1) % capacity)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.show();
    cout << "Dequeued element: " << q.dequeue() << endl;
    q.show();
    cout << "Dequeued element: " << q.dequeue() << endl;
    q.show();

    q.enqueue(1);
    q.enqueue(2);
    q.show();

    return 0;
}