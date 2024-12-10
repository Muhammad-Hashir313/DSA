#include<iostream>
#include<string>
#include<fstream>
#include <algorithm> 

using namespace std;

int getValidInt() {
	int value;
	while (!(cin >> value)) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input. Please enter an integer: ";
	}
	return value;
}

class List {
private:
    struct Node {
        string name;
        int testSeries = 0;
        int ODI = 0;
        int T20 = 0;
        Node* next = nullptr;
        Node* previous = nullptr;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    void insertAtHead(string playerName, int playerTestSeries, int playerODI, int playerT20, bool writeToFile = true) {
        Node* newNode = new Node();
        newNode->name = playerName;
        newNode->testSeries = playerTestSeries;
        newNode->ODI = playerODI;
        newNode->T20 = playerT20;
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        count++;

        if (writeToFile) {
            string fileName = playerName + "_File.txt";
            ofstream outFile(fileName);
            if (outFile.is_open()) {
                outFile << playerName << " " << playerTestSeries << " " << playerODI << " " << playerT20;
                outFile.close();
            }
            ofstream playerFile("players_list.txt", ios::app);
            if (playerFile.is_open()) {
                playerFile << playerName << "\n";
                playerFile.close();
            }
        }
    }

    void Remove(string playerName) {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            if (current->name == playerName) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr) head->previous = nullptr;
                }
                else if (current == tail) {
                    tail = current->previous;
                    if (tail != nullptr) tail->next = nullptr;
                }
                else {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                }
                delete current;
                count--;

                string fileName = playerName + "_File.txt";
                remove(fileName.c_str());
                ifstream inFile("players_list.txt");
                ofstream outFile("temp_players_list.txt");
                string line;
                while (getline(inFile, line)) {
                    if (line != playerName) {
                        outFile << line << "\n";
                    }
                }
                inFile.close();
                outFile.close();
                remove("players_list.txt");
                rename("temp_players_list.txt", "players_list.txt");
                return;
            }
            current = current->next;
        }
        cout << "Player " << playerName << " not found in the list.\n";
    }

    void update(string playerName) {
        Node* current = head;
        while (current != nullptr) {
            if (current->name == playerName) {
                cout << "Updating information for " << playerName << ":\n";
                cout << "Enter new number of ODI: ";
                current->ODI = getValidInt();
                cout << "Enter new number of Test Series: ";
                current->testSeries = getValidInt();
                cout << "Enter new number of T20: ";
                current->T20 = getValidInt();

                string fileName = playerName + "_File.txt";
                ofstream outFile(fileName);
                if (outFile.is_open()) {
                    outFile << "Player Name: " << current->name << "\nODI: " << current->ODI
                        << "\nTest Series: " << current->testSeries << "\nT20: " << current->T20;
                    outFile.close();
                }
                return;
            }
            current = current->next;
        }
        cout << "Player " << playerName << " not found in the list.\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "No matches recorded yet.\n";
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << "\n---------------------\n";
            cout << "Name: " << current->name << "\nODI: " << current->ODI
                << "\nTest Series: " << current->testSeries << "\nT20: " << current->T20;
            current = current->next;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int getCount() const {
        return count;
    }

    void initializeFromFiles() {
        ifstream playersFile("players_list.txt");
        if (!playersFile.is_open()) return;

        string playerName;
        while (getline(playersFile, playerName)) {
            string fileName = playerName + "_File.txt";
            ifstream file(fileName);
            if (file.is_open()) {
                string name;
                int odi, testSeries, t20;
                file >> name >> testSeries >> odi >> t20;
                insertAtHead(name, testSeries, odi, t20, false);
                file.close();
            }
        }
        playersFile.close();
    }
};



int main() {
	List players;
	players.initializeFromFiles();
	int choice, odi, t20, testseries;
	string name;
	while (true) {
		cout << "\nMenu:\n1. Insert New Player \n2. Delete Player \n3. Update Player \n";
		cout << "4. Display All Players \n5. Exit\n";
		cout << "Enter choice: ";
		choice = getValidInt();

		if (choice == 5) break;
		switch (choice) {
		case 1:
			if (players.getCount() >= 20) {
				cout << "Cannot add more players. Maximum limit of players reached.\n";
				break;
			}
			cout << "Enter Name for Player: \n";
			cin.ignore();
			getline(cin, name);
			transform(name.begin(), name.end(), name.begin(), toupper);
			cout << "Enter number of ODI: \n";
			odi = getValidInt();
			cout << "Enter number of test series: \n";
			testseries = getValidInt();
			cout << "Enter number of T20: \n";
			t20 = getValidInt();
			players.insertAtHead(name, testseries, odi, t20);
			cout << "player inserted sucessfully";
			break;
		case 2:
			cout << "Enter player you want to delete: ";
			cin.ignore();
			getline(cin, name);
			transform(name.begin(), name.end(), name.begin(), toupper);
			players.Remove(name);
			break;
		case 3:
			cout << "Enter player you want to update: ";
			cin.ignore();
			getline(cin, name);
			transform(name.begin(), name.end(), name.begin(), toupper);
			players.update(name);
			break;
		case 4:
			cout << "List of players: \n";
			players.display();
			break;
		default:
			cout << "Invalid choice, please enter a number from 1 to 5.\n";
		}
	}
	return 0;
}
