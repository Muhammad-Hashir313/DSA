#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertAtStart(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    void deleteFromStart()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void insertAtMiddle(int value, int position)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *current = head;
        for (int i = 1; i < position - 1 && current != NULL; i++)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteFromMiddle(int position)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (position == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        for (int i = 1; i < position - 1 && current->next != NULL; i++)
        {
            current = current->next;
        }

        if (current->next == NULL)
        {
            cout << "Position out of bounds\n";
            return;
        }

        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *current = head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    }
    void display()
    {
        Node *current = head;
        if (current == NULL)
        {
            cout << "List empty\n";
            return;
        }

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

void menu()
{
    cout << "========== MENU ==========\n";
    cout << "1. Insert at Start\n";
    cout << "2. Delete from Start\n";
    cout << "3. Insert at Middle\n";
    cout << "4. Delete from Middle\n";
    cout << "5. Insert at End\n";
    cout << "6. Delete from End\n";
    cout << "7. Display\n";
    cout << "0. Exit\n";
}

int main()
{
    LinkedList list;
    string input;
    int choice;

    do
    {
        menu();
        while (true)
        {
            cout << "Enter your choice: ";
            cin >> input;

            // Check if the input contains only digits
            bool valid = true;
            for (char ch : input)
            {
                if (!isdigit(ch))
                {
                    valid = false;
                    break;
                }
            }

            if (!valid)
            {
                cout << "Invalid input. Enter a valid number!\n";
                continue;
            }

            // Convert the input to an integer after validation
            choice = stoi(input);
            break;
        }
        int value, position;
        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert at the start: ";
            cin >> value;
            list.insertAtStart(value);
            break;
        case 2:
            list.deleteFromStart();
            break;
        case 3:
            cout << "Enter the value to insert at the middle: ";
            cin >> value;
            cout << "Enter the position: ";
            cin >> position;
            list.insertAtMiddle(value, position);
            break;
        case 4:
            cout << "Enter the position to delete from middle: ";
            cin >> position;
            list.deleteFromMiddle(position);
            break;
        case 5:
            cout << "Enter the value to insert at the end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            list.display();
            break;
        case 0:
            exit(1);
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (true);

    return 0;
}