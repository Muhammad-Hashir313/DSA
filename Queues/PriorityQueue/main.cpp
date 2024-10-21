#include <iostream>
#include <string>

using namespace std;

class Queue
{
private:
    int size;
    int front, rear;
    string *arr;

public:
    Queue(int capacity)
    {
        size = capacity;
        front = rear = -1;
        arr = new string[capacity];
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % size == front);
    }

    void insert(string val)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot insert" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
        cout << "Inserted Successfully\n";
    }

    void remove(string val)
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot remove" << endl;
            return;
        }
        if (arr[front] == val)
        {
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
            cout << "Removed Successfully\n";
        }
        else
        {
            cout << "Element not found in queue\n";
            return;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            return;
        }
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << " "; // To print the last element
    }
};

void menu()
{
    system("cls");
    cout << "---------- MENU ----------\n";
    cout << "1. Insert\n";
    cout << "2. Remove\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";
}

bool checkIfString(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Queue admin(5), faculty(5), student(5);
    int choice;
    string name;
    while (true)
    {

        do
        {
            menu();
            while (true)
            {
                cout << "Enter Choice: ";
                cin >> choice;

                if (choice < 1 || choice > 4)
                {
                    cout << "Invalid choice. Please choose a valid option.\n";
                    continue;
                }
                break;
            }

            switch (choice)
            {
            case 1:
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                if (!checkIfString(name))
                {
                    cout << "Invalid input. Only alphabetic characters are allowed." << endl;
                    continue;
                }
                break;

            case 2:
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                if (!checkIfString(name))
                {
                    cout << "Invalid input. Only alphabetic characters are allowed." << endl;
                    continue;
                }
                break;

            case 3:
                admin.display();
                faculty.display();
                student.display();
                cout << endl;
                system("pause");
                break;

            case 4:
                cout << "Exiting....\n";
                exit(1);
            }
        } while (choice != 1 && choice != 2);

        system("cls");
        cout << "Where to add this name?\n";
        cout << "1. Admin\n";
        cout << "2. Faculty\n";
        cout << "3. Student\n";

        int option;
        while (true)
        {
            cout << "Enter Option: ";
            cin >> option;

            if (option < 1 || option > 3)
            {
                cout << "Invalid option. Please choose a valid option.\n";
                continue;
            }
            break;
        }

        switch (option)
        {
        case 1:
            if (choice == 1)
            {
                admin.insert(name);
            }
            else if (choice == 2)
            {

                admin.remove(name);
            }

            system("pause");
            break;

        case 2:
            if (choice == 1)
            {
                faculty.insert(name);
            }
            else if (choice == 2)
            {

                faculty.remove(name);
            }
            system("pause");
            break;

        case 3:
            if (choice == 1)
            {
                student.insert(name);
            }
            else if (choice == 2)
            {

                student.remove(name);
            }
            system("pause");
            break;
        }
    }
    return 0;
}