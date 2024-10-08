#pragma once

#include <iostream>
#include <stack>

using namespace std;

class Stack
{
private:
    stack<int> mainStk;
    stack<int> minStk;

public:
    // Main stack operations
    void pushMain(int value)
    {
        mainStk.push(value);
    }

    void popMain()
    {
        if (!mainStk.empty())
        {
            mainStk.pop();
        }
        else
        {
            cout << "Main Stack is Empty!" << endl;
        }
    }

    int topMain()
    {
        return mainStk.top();
    }

    int mainSize()
    {
        return mainStk.size();
    }

    // Min stack operations
    void pushMin(int value)
    {
        minStk.push(value);
    }

    void popMin()
    {
        if (!minStk.empty())
        {
            minStk.pop();
        }
        else
        {
            cout << "Min Stack is Empty!" << endl;
        }
    }

    int topMin()
    {
        return minStk.top();
    }

    bool isMinEmpty()
    {
        return minStk.empty();
    }

    // Get the current minimum value
    int getMin()
    {
        if (!minStk.empty())
        {
            return minStk.top();
        }
        else
        {
            cout << "No minimum value, Min Stack is empty!" << endl;
            return -1; // Return -1 if there's no minimum value
        }
    }
};