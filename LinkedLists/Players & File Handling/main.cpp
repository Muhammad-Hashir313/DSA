#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class DLL {
private:
	struct Node {
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
		newNode->name = n;
		newNode->age = a;
		newNode->score = s;
		if (head == NULL)
		{
			newNode->left = NULL;
			newNode->right = NULL;
			head = newNode;
		}
		else {
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

	void display() {
		ifstream inFile("players.txt");  // Open file for reading
		if (inFile.is_open()) {
			string name;
			int age, score;
			cout << "Displaying players from file:" << endl;
			while (inFile >> name >> age >> score) {
				cout << "Name: " << name << ", Age: " << age << ", Score: " << score << endl;
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
	dll.insert("John Doe", 18, 85);
	dll.insert("Jane Smith", 19, 90);
	dll.insert("Bob Johnson", 20, 88);
	dll.display();
	return 0;
}