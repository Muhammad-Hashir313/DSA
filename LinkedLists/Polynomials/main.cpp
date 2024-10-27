#include <iostream>
#include <cmath>

using namespace std;

class Polynomial
{
private:
    struct Node
    {
        int coefficient, exponent;
        Node *next;
    };
    Node *head;

public:
    Polynomial() : head(nullptr) {}

    void insert(int coefficient, int exponent)
    {
        if (coefficient == 0)
            return; // Skip terms with a coefficient of 0
        Node *newNode = new Node();
        newNode->coefficient = coefficient;
        newNode->exponent = exponent;
        newNode->next = head;
        head = newNode;
    }

    void insertTerm(int coefficient, int exponent)
    {
        if (coefficient == 0)
            return; // Skip terms with coefficient 0

        if (exponent < 0) // Validate exponent is non-negative
        {
            cout << "Error: Exponent should be a non-negative integer.\n";
            return;
        }

        if (head == nullptr || exponent > head->exponent)
        {
            insert(coefficient, exponent);
            return;
        }

        Node *current = head;
        Node *prev = nullptr;

        // Find the right place for the new term
        while (current != nullptr && current->exponent > exponent)
        {
            prev = current;
            current = current->next;
        }

        if (current != nullptr && current->exponent == exponent) // Merge if exponent already exists
        {
            current->coefficient += coefficient;
        }
        else
        {
            Node *newNode = new Node();
            newNode->coefficient = coefficient;
            newNode->exponent = exponent;
            newNode->next = current;

            if (prev == nullptr)
                head = newNode;
            else
                prev->next = newNode;
        }
    }

    Polynomial operator+(Polynomial &other)
    {
        Polynomial result;
        Node *current1 = head;
        Node *current2 = other.head;

        while (current1 != nullptr && current2 != nullptr)
        {
            if (current1->exponent == current2->exponent)
            {
                result.insertTerm(current1->coefficient + current2->coefficient, current1->exponent);
                current1 = current1->next;
                current2 = current2->next;
            }
            else if (current1->exponent > current2->exponent)
            {
                result.insertTerm(current1->coefficient, current1->exponent);
                current1 = current1->next;
            }
            else
            {
                result.insertTerm(current2->coefficient, current2->exponent);
                current2 = current2->next;
            }
        }

        while (current1 != nullptr)
        {
            result.insertTerm(current1->coefficient, current1->exponent);
            current1 = current1->next;
        }

        while (current2 != nullptr)
        {
            result.insertTerm(current2->coefficient, current2->exponent);
            current2 = current2->next;
        }

        return result;
    }

    Polynomial operator-(Polynomial &other)
    {
        Polynomial result;
        Node *current1 = head;
        Node *current2 = other.head;

        while (current1 != nullptr && current2 != nullptr)
        {
            if (current1->exponent == current2->exponent)
            {
                result.insertTerm(current1->coefficient - current2->coefficient, current1->exponent);
                current1 = current1->next;
                current2 = current2->next;
            }
            else if (current1->exponent > current2->exponent)
            {
                result.insertTerm(current1->coefficient, current1->exponent);
                current1 = current1->next;
            }
            else
            {
                result.insertTerm(-current2->coefficient, current2->exponent);
                current2 = current2->next;
            }
        }

        while (current1 != nullptr)
        {
            result.insertTerm(current1->coefficient, current1->exponent);
            current1 = current1->next;
        }

        while (current2 != nullptr)
        {
            result.insertTerm(-current2->coefficient, current2->exponent);
            current2 = current2->next;
        }

        return result;
    }

    Polynomial operator*(Polynomial &other)
    {
        Polynomial result;
        Node *current1 = head;

        while (current1 != nullptr)
        {
            Node *current2 = other.head;

            while (current2 != nullptr)
            {
                result.insertTerm(current1->coefficient * current2->coefficient, current1->exponent + current2->exponent);
                current2 = current2->next;
            }
            current1 = current1->next;
        }

        return result;
    }

    int evaluate(int x)
    {
        int result = 0;
        Node *current = head;

        while (current != nullptr)
        {
            result += current->coefficient * pow(x, current->exponent);
            current = current->next;
        }

        return result;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "0" << endl;
            return;
        }

        Node *current = head;
        bool isFirstTerm = true;

        while (current != nullptr)
        {
            if (current->coefficient != 0)
            {
                if (!isFirstTerm)
                {
                    cout << (current->coefficient > 0 ? " + " : " - ");
                }
                else if (current->coefficient < 0)
                {
                    cout << "-";
                }

                if (abs(current->coefficient) != 1 || current->exponent == 0)
                    cout << abs(current->coefficient);

                if (current->exponent > 0)
                {
                    cout << "x";
                    if (current->exponent > 1)
                        cout << "^" << current->exponent;
                }
                isFirstTerm = false;
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Polynomial p1, p2;
    int coefficient, exponent;
    cout << "Enter the first polynomial (coefficient, exponent): ";
    while (true)
    {
        cout << "Coefficient: ";
        while (!(cin >> coefficient))
        {
            cout << "Invalid input. Enter an integer for coefficient: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (coefficient == -1)
            break;

        cout << "Exponent: ";
        while (!(cin >> exponent) || exponent < 0) // Check that exponent is non-negative
        {
            cout << "Invalid input. Enter a non-negative integer for exponent: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        p1.insertTerm(coefficient, exponent);
    }

    cout << "Enter the second polynomial (coefficient, exponent): ";
    while (true)
    {
        cout << "Coefficient: ";
        while (!(cin >> coefficient))
        {
            cout << "Invalid input. Enter an integer for coefficient: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (coefficient == -1)
            break;

        cout << "Exponent: ";
        while (!(cin >> exponent) || exponent < 0)
        {
            cout << "Invalid input. Enter a non-negative integer for exponent: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        p2.insertTerm(coefficient, exponent);
    }

    cout << "First polynomial: ";
    p1.display();
    cout << "Second polynomial: ";
    p2.display();
    cout << "Sum: ";
    (p1 + p2).display();
    cout << "Difference: ";
    (p1 - p2).display();
    cout << "Product: ";
    (p1 * p2).display();

    int x;
    cout << "Enter an x value to evaluate the polynomial: ";
    while (!(cin >> x)) // Input validation for x
    {
        cout << "Please enter a valid integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Value of the first polynomial at x=" << x << ": " << p1.evaluate(x) << endl;
    cout << "Value of the second polynomial at x=" << x << ": " << p2.evaluate(x) << endl;

    return 0;
}