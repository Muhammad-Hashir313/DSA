#pragma once

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Stack
{
    int top;
    string arr[100];

public:
    Stack() : top(-1) {}

    bool isEmpty()
    {
        return top == -1;
    }

    void push(string val)
    {
        if (top >= 99)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = val;
    }

    string pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return "";
        }
        return arr[top--];
    }

    string peek()
    {
        if (isEmpty())
            return "";
        return arr[top];
    }
};