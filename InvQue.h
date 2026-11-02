#ifndef INVQUE_H
#define INVQUE_H
#include <iostream>
using namespace std;
template <class T>
class InvQue
{
private:
    T* queue;
    int front;
    int rear;
    int size;
    int capacity;

public:

    InvQue(int cap = 10)
    {
        capacity = cap;
        queue = new T[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    // Destructor
    ~InvQue()
    {
        delete[] queue;
    }

    void enqueue(T item)
    {
        if (size == capacity)
        {
            return;
        }

        queue[rear] = item;
        rear = (rear + 1) % capacity;
        size++;
    }


    void dequeue(T& item)
    {
        if (isEmpty())
        {
            return;
        }

        item = queue[front];
        front = (front + 1) % capacity;
        size--;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "The queue is empty.\n";
            return;
        }

        cout << "\nContents of the Queue:\n";

        int index = front;

        for (int i = 0; i < size; i++)
        {
            cout << "Item " << i + 1 << ":\n";
            cout << "\tSerial number: "
                << queue[index].getSerialNum() << endl;
            cout << "\tManufacture date: "
                << queue[index].getManufactDate() << endl;

            index = (index + 1) % capacity;
        }
    }
};

#endif