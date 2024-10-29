#include <iostream>

using namespace std;

class DLL
{
private:
    struct Node
    {
        int score;
        Node *right, *left;
    };
    Node *head;
    string ERROR = "No matches recorded yet\n";

public:
    DLL()
    {
        head = NULL;
    }

    void insertAtHead(int value)
    {
        Node *newNode = new Node;
        newNode->score = value;

        if (head == NULL)
        {
            newNode->right = newNode->left = NULL;
            head = newNode;
            return;
        }

        newNode->right = head;
        newNode->left = NULL;
        head->left = newNode;
        head = newNode;
    }

    void insertAtTail(int value)
    {
        Node *newNode = new Node;
        newNode->score = value;

        if (head == NULL)
        {
            newNode->right = newNode->left = NULL;
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->right != NULL)
        {
            current = current->right;
        }
        newNode->right = current->right;
        newNode->left = current;
        current->right = newNode;
    }

    void deleteScores(int value)
    {
        if (head == NULL)
        {
            cout << ERROR;
            return;
        }

        Node *current = head;
        while (current != NULL)
        {
            if (current->score == value)
            {
                Node *temp = current;

                if (current == head)
                {
                    head = head->right;
                    if (head != NULL)
                    {
                        head->left = NULL;
                    }
                }
                else if (current->right != NULL)
                {
                    current->left->right = current->right;
                    current->right->left = current->left;
                }
                else
                {
                    current->left->right = NULL;
                }
                current = current->right;
                delete temp;
            }
            else
            {
                current = current->right;
            }
        }
    }

    void displayForward()
    {
        if (head == NULL)
        {
            cout << ERROR;
            return;
        }

        Node *current = head;
        while (current != NULL)
        {
            cout << current->score;
            if (current->right != NULL)
                cout << ", ";
            current = current->right;
        }
        cout << endl;
    }

    void displayReverse()
    {
        if (head == NULL)
        {
            cout << ERROR;
            return;
        }

        Node *current = head;
        while (current->right != NULL)
        {
            current = current->right;
        }

        while (current != NULL)
        {
            cout << current->score;
            if (current->left != NULL)
                cout << ", ";
            current = current->left;
        }
        cout << endl;
    }

    void sorted()
    {
        if (head == NULL)
        {
            cout << ERROR;
            return;
        }

        bool swapped;
        Node *current;
        Node *lastSorted = NULL;

        do
        {
            swapped = false;
            current = head;

            while (current->right != lastSorted)
            {
                if (current->score > current->right->score)
                {
                    int temp = current->score;
                    current->score = current->right->score;
                    current->right->score = temp;
                    swapped = true;
                }
                current = current->right;
            }
            lastSorted = current;
        } while (swapped);

        displaySorted();
    }

    void displaySorted()
    {
        if (head == NULL)
        {
            cout << ERROR;
            return;
        }

        Node *current = head;
        while (current != NULL)
        {
            cout << current->score;
            if (current->right != NULL)
                cout << ", ";
            current = current->right;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~DLL()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->right;
            delete temp;
        }
    }
};

int main()
{
    DLL list;
    int s, choice;

    list.insertAtTail(4);
    list.insertAtTail(2);
    list.insertAtTail(1);
    list.insertAtTail(6);

    while (true)
    {

        system("cls");
        cout << "========== MENU ==========\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete all Scores of same value\n";
        cout << "4. Show Scores\n";
        cout << "5. Show Scores in Reverse Order\n";
        cout << "6. Show Scores in sorted order (highest to lowest)\n";
        cout << "0. Exit\n";

        while (true)
        {
            cout << "Enter choice: ";
            cin >> choice;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter valid choice\n";
                continue;
            }
            break;
        }

        switch (choice)
        {
        case 1:
            system("cls");
            while (true)
            {
                cout << "Insert score: ";
                cin >> s;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter valid Score\n";
                    continue;
                }
                break;
            }
            list.insertAtHead(s);
            cout << "Inserted at start successfully\n";
            system("pause");
            break;

        case 2:
            system("cls");
            while (true)
            {
                cout << "Insert score: ";
                cin >> s;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter valid Score\n";
                    continue;
                }
                break;
            }
            list.insertAtTail(s);
            cout << "Inserted at end successfully\n";
            system("pause");
            break;

        case 3:
            system("cls");
            while (true)
            {
                cout << "Insert score: ";
                cin >> s;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter valid Score\n";
                    continue;
                }
                break;
            }
            list.deleteScores(s);
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "========== SCORES IN SEQUENCE ==========\n";
            list.displayForward();
            system("pause");
            break;

        case 5:
            system("cls");
            cout << "========== SCORES IN REVERSE ==========\n";
            list.displayReverse();
            system("pause");
            break;

        case 6:
            system("cls");
            cout << "========== SCORES SORTED ==========\n";
            list.sorted();
            system("pause");
            break;

        case 0:
            cout << "Exiting....\n";
            exit(1);

        default:
            cout << "Invalid value\n";
            system("pause");
            break;
        }
    }
}