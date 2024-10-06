#include <iostream>
#include <string>
#include <cctype>

#include "stack.h"

using namespace std;

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// 1. Infix to Postfix
string infixToPostfix(const string &infix)
{
    Stack stack;
    string postfix = "";

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            stack.push("(");
        }
        else if (ch == ')')
        {
            while (stack.peek() != "(")
            {
                postfix += stack.pop();
            }
            stack.pop(); // Pop '('
        }
        else if (isOperator(ch))
        {
            while (!stack.isEmpty() && precedence(stack.peek()[0]) >= precedence(ch))
            {
                postfix += stack.pop();
            }
            stack.push(string(1, ch));
        }
    }
    while (!stack.isEmpty())
    {
        postfix += stack.pop();
    }
    return postfix;
}

// 2. Postfix Evaluation
int evaluatePostfix(const string &postfix)
{
    Stack stack;

    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            // Convert character digit to integer (e.g., '3' to 3)
            stack.push(string(1, ch));
        }
        else if (isOperator(ch))
        {
            if (stack.isEmpty())
            {
                cout << "Stack Underflow" << endl;
                return -1; // Return an error value
            }
            int operand2 = stoi(stack.pop());
            if (stack.isEmpty())
            {
                cout << "Stack Underflow" << endl;
                return -1; // Return an error value
            }
            int operand1 = stoi(stack.pop());
            int result = 0;
            switch (ch)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '^':
                result = 1;
                for (int i = 0; i < operand2; i++)
                {
                    result *= operand1;
                }
                break;
            }
            stack.push(to_string(result));
        }
    }

    return stack.isEmpty() ? -1 : stoi(stack.pop());
}

string reverseString(const string &str)
{
    string reversed = str;
    int n = reversed.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(reversed[i], reversed[n - i - 1]);
    }
    return reversed;
}

string infixToPrefix(const string &infix)
{
    string reversedInfix = reverseString(infix);

    for (int i = 0; i < reversedInfix.length(); i++)
    {
        if (reversedInfix[i] == '(')
            reversedInfix[i] = ')';
        else if (reversedInfix[i] == ')')
            reversedInfix[i] = '(';
    }

    string postfix = infixToPostfix(reversedInfix);
    return reverseString(postfix);
}

// 4. Power Implementation (x^y)
int power(int base, int exp)
{
    Stack stack;
    stack.push(to_string(base));
    int result = 1;

    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

// 5. Multiplication (x*y)
int multiply(int x, int y)
{
    Stack stack;
    return x * y;
}

void menu()
{
    int choice;
    do
    {
        cout << "Choose an option:\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Postfix Evaluation\n";
        cout << "3. Infix to Prefix\n";
        cout << "4. Power Implementation (x^y)\n";
        cout << "5. Multiplication (x * y)\n";
        cout << "0. Exit\n";
        cin >> choice;

        if (choice == 1)
        {
            string infix;
            cout << "Enter infix expression: ";
            cin >> infix;
            cout << "Postfix: " << infixToPostfix(infix) << endl;
        }
        else if (choice == 2)
        {
            string postfix;
            cout << "Enter postfix expression: ";
            cin >> postfix;
            cout << "Evaluation Result: " << evaluatePostfix(postfix) << endl;
        }
        else if (choice == 3)
        {
            string infix;
            cout << "Enter infix expression: ";
            cin >> infix;
            cout << "Prefix: " << infixToPrefix(infix) << endl;
        }
        else if (choice == 4)
        {
            int base, exp;
            cout << "Enter base: ";
            cin >> base;
            cout << "Enter exponent: ";
            cin >> exp;
            cout << base << "^" << exp << " = " << power(base, exp) << endl;
        }
        else if (choice == 5)
        {
            int x, y;
            cout << "Enter two numbers to multiply: ";
            cin >> x >> y;
            cout << x << " * " << y << " = " << multiply(x, y) << endl;
        }
        else if (choice == 0)
        {
            cout << "Exiting..." << endl;
            exit(1);
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    } while (true);
}

int main()
{
    menu();
    return 0;
}
