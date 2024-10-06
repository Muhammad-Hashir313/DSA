#pragma once

#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    int top;

public:
    char arr[100];
    Stack()
    {
        top = -1;
    }

    void Push(char value)
    {
        if (top == 99)
        {
            cout << "Stack is full\n";
        }
        else
        {
            arr[++top] = value;
        }
    }

    char Pop()
    {
        char ch;
        if (top == -1)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            ch = arr[top];
            --top;
        }
        return ch;
    }

    void showStack()
    {
        if (top == -1)
        {
            cout << "stack empty\n";
            return;
        }
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
};