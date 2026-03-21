#include <iostream>
#include <vector>

using namespace std;

class ArrayQueue
{
private:
    int maxSize;
    int currSize;
    int front;
    int rear;
    int *queueArray;

public:
    ArrayQueue()
    {
        queueArray = new int[10];
        front = -1;
        rear = -1;
        currSize = 0;
        maxSize = 10;
    }

    void enqueue(int x)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        if (rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxSize;
        }

        queueArray[rear] = x;
        currSize++;
    }

    int pop()
    {
        if (front == -1)
        {
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        int popped = queueArray[front];
        if (currSize == 1)
        {
            front = -1;
            rear = -1;
        }

        else
        {
            front = (front + 1) % maxSize;
        }

        currSize--;
        return popped;
    }

    int peek()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }

        return queueArray[front];
    }

    bool isEmpty()
    {
        return (currSize == 0);
    }
};

int main()
{

    ArrayQueue queue;
    vector<string> commands = {"ArrayQueue", "push", "push",
                               "peek", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "push")
        {
            queue.enqueue(inputs[i][0]);
            cout << "null ";
        }
        else if (commands[i] == "pop")
        {
            cout << queue.pop() << " ";
        }
        else if (commands[i] == "peek")
        {
            cout << queue.peek() << " ";
        }
        else if (commands[i] == "isEmpty")
        {
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        }
        else if (commands[i] == "ArrayQueue")
        {
            cout << "null ";
        }
    }

    return 0;
}