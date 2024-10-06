#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

int main()
{
    string name;

    cout << "Enter text: ";
    getline(cin, name);

    int len = name.length();

    Stack str1, str2;
    for (int i = 0; i < len; i++)
    {
        str1.Push(name[i]);
    }
    cout << "pushed\n";
    str1.showStack();

    for (int i = 0; i < len; i++)
    {
        str2.Push(str1.Pop());
    }
    cout << "popped\n";
    str2.showStack();

    for (int i = 0; i < len; i++)
    {
        if (str2.arr[i] != name[i])
        {
            cout << "Not Palindrome\n";
            exit(1);
        }
    }
    cout << "Palindrome\n";
}
