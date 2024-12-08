#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class DLL {
private:
	struct Node {
		int ID;
		string name;
		int age, score;
		Node* left;
		Node* right;
	};
	typedef Node* Nodeptr;
	Nodeptr head;

public:
	DLL() {
		head = NULL;
	}

	void insert(string n, int a, int s) {
		Nodeptr newNode = new Node;
		int id = rand() % 10000;
		newNode->name = n;
		newNode->age = a;
		newNode->score = s;
		if (head == NULL)
		{
			newNode->ID = id;
			newNode->left = NULL;
			newNode->right = NULL;
			head = newNode;
		}
		else {
			Nodeptr current = head;
			newNode->right = head;
			head->left = newNode;
			newNode->left = NULL;
			head = newNode;
		}

		// Write the new player's information to the file
		ofstream outFile("players.txt", ios::app);
		if (outFile.is_open()) {
			outFile << "Name: " << n << ", Age: " << a << ", Score: " << s << endl;
			outFile.close();
		}
		else {
			cout << "Unable to open file for writing." << endl;
		}
	}

	void searchUsingName(string n) {
		Nodeptr current = head;
		while (current != NULL) {
			if (current->name == n) {
				cout << "ID: " << current->ID << ", Name: " << current->name << ", Age: " << current->age << ", Score: " << current->score;
				cout << endl;
			}
			current = current->right;
		}
	}

	void searchUsingId(int id) {
		Nodeptr current = head;
		while (current != NULL) {
			if (current->ID == id) {
				cout << "ID: " << current->ID << ", Name: " << current->name << ", Age: " << current->age << ", Score: " << current->score;
				cout << endl;
				return;
			}
			current = current->right;
		}
		cout << "Player not Found\n";
	}

	void display() {
		ifstream inFile("players.txt");
		if (inFile.is_open()) {
			string line;
			cout << "Displaying players from file:" << endl;
			while (getline(inFile, line)) {
				cout << line << endl;
			}
			inFile.close();
		}
		else {
			cout << "Unable to open file for reading." << endl;
		}
	}
};

int main() {
    DLL dll;
    int choice;

    do {
        cout << "\n=====================================\n";
        cout << "        PLAYER MANAGEMENT MENU       \n";
        cout << "=====================================\n";
        cout << "1. Insert a new player\n";
        cout << "2. Remove a player\n";
        cout << "3. Search for a player by Name\n";
        cout << "4. Search for a player by ID\n";
        cout << "5. Display all players\n";
        cout << "6. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice (1-6): ";

        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "Invalid input! Please enter a number between 1 and 6: ";
            cin.clear();
            cin.ignore(10000, '\n');   
        }

        cout << endl;

        switch (choice) {
            case 1: {
                string name;
                int age, score;

                cin.ignore();
                cout << "Enter player's name: ";
                getline(cin, name);

                cout << "Enter player's age: ";
                while (!(cin >> age) || age < 1) {
                    cout << "Invalid age! Please enter a value between 1 and 120: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                cout << "Enter player's score: ";
                while (!(cin >> score) || score < 0) {
                    cout << "Invalid score! Please enter a value between 0 and 100: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                dll.insert(name, age, score);
                cout << "Player added successfully!\n";
                break;
            }

            case 2: {
                cout << "Feature not implemented yet. Stay tuned!\n";
                break;
            }

            case 3: {
                cin.ignore();
                string name;
                cout << "Enter player's name to search: ";
                getline(cin, name);

                cout << "Searching for player...\n";
                dll.searchUsingName(name);
                break;
            }

            case 4: {
                int id;
                cout << "Enter player's ID to search: ";
                while (!(cin >> id) || id < 0) {
                    cout << "Invalid ID! Please enter a positive integer: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                cout << "Searching for player...\n";
                dll.searchUsingId(id);
                break;
            }

            case 5: {
                cout << "Displaying all players:\n";
                dll.display();
                break;
            }

            case 6: {
                cout << "Exiting the program. Goodbye!\n";
                exit(1);
                break;
            }
        }
    } while (choice != 6);

    return 0;
}