#include<iostream>

using namespace std;

class Tree {
private:
	struct Node {
		int num;
		Node* left, * right;
	};

	Node* root;

public:
	Tree() {
		root = NULL;
	}

	bool isEmpty() {
		return (root == NULL);
	}

	// Insert to Tree
	void insertItem(int n) {
		insertHelper(root, n);
	}

	void insertHelper(Node*& ptr, int n) {
		if (ptr == NULL) {
			ptr = new Node;
			ptr->num = n;
			ptr->right = ptr->left = NULL;
		}

		else if (n > ptr->num) {
			insertHelper(ptr->right, n);
		}

		else if (n < ptr->num) {
			insertHelper(ptr->left, n);
		}
		else {
			cout << "Can't add duplicate in tree\n";
		}
	}

	//Display in PreOrder
	void preOrder() {
		if (!isEmpty())
		{
			preOrderHelper(root);
		}
		else {
			cout << "Tree Empty\n";
		}
	}

	void preOrderHelper(Node* ptr) {
		if (ptr == NULL) {
			return;
		}
		cout << ptr->num << " ";
		preOrderHelper(ptr->left);
		preOrderHelper(ptr->right);
	}

	//Display in Post Order
	void postOrder() {
		if (!isEmpty())
		{
			postOrderHelper(root);
		}
		else {
			cout << "Tree Empty\n";
		}
	}

	void postOrderHelper(Node* ptr) {
		if (ptr == NULL) {
			return;
		}
		postOrderHelper(ptr->left);
		postOrderHelper(ptr->right);
		cout << ptr->num << " ";
	}

	//Display in In Order
	void inOrder() {
		if (!isEmpty()) {
			inOrderHelper(root);
		}
		else {
			cout << "Tree Empty\n";
		}
	}

	void inOrderHelper(Node* ptr) {
		if (ptr == NULL)
		{
			return;
		}
		inOrderHelper(ptr->left);
		cout << ptr->num << " ";
		inOrderHelper(ptr->right);
	}
};

int main() {
	Tree t;
	int choice, value;

	while (true) {
		system("cls");
		cout << "\n========= MENU =========\n";
		cout << "1. Insert Item\n";
		cout << "2. Display InOrder\n";
		cout << "3. Display PreOrder\n";
		cout << "4. Display PostOrder\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";

		// Input validation for choice
		if (!(cin >> choice)) {
			cout << "Invalid input! Please enter a valid choice.\n";
			cin.clear();  // Clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
			continue;
		}

		switch (choice) {
		case 1: 
			cout << "Enter the number to insert: ";
			if (!(cin >> value)) {
				cout << "Invalid input! Please enter a valid number.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			t.insertItem(value);
			cout << value << " inserted successfully.\n";
			break;

		case 2: // Display InOrder
			cout << "InOrder: ";
			t.inOrder();
			cout << "\n";
			break;

		case 3: // Display PreOrder
			cout << "PreOrder: ";
			t.preOrder();
			cout << "\n";
			break;

		case 4: // Display PostOrder
			cout << "PostOrder: ";
			t.postOrder();
			cout << "\n";
			break;

		case 5: // Exit
			cout << "Exiting program...\n";
			exit(1);

		default:
			cout << "Invalid choice. Please select a valid option.\n";
		}

		system("pause");  // Pause the program for user to continue
	}

	return 0;
}
