#include <iostream>
#include <string>
#include <stack>

#include "stack.h"

using namespace std;

int main()
{
    Stack s;

    while (true)
    {
        int value;
        cout << "Enter a value to push to the stack (-1 to stop): ";
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid input, please enter a valid number!" << endl;
            continue;
        }

        if (value < 0)
        {
            break;
        }

        s.pushMain(value);

        if (s.isMinEmpty() || value < s.topMin())
        {
            s.pushMin(value); // Push the new minimum value
        }
    }

    // Display the final results
    cout << "\nFinal Results:" << endl;
    cout << "Minimum value in the stack: " << s.getMin() << endl;
    cout << "Total elements in the stack: " << s.mainSize() << endl;

    return 0;
}
