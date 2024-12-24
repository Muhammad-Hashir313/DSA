#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node* left, * right;

    Node(char character, int frequency, Node* leftNode = nullptr, Node* rightNode = nullptr)
        : ch(character), freq(frequency), left(leftNode), right(rightNode) {}
};

// Compare function for priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Recursive function to generate Huffman codes
void generateCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (!root)
        return;

    // Leaf node
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to build Huffman Tree and generate codes
Node* buildHuffmanTree(const string& text, unordered_map<char, int>& freqTable) {
    // Create a priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters and their frequencies into the priority queue
    for (auto& entry : freqTable) {
        pq.push(new Node(entry.first, entry.second));
    }

    // Build the Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with frequency equal to the sum of two nodes
        pq.push(new Node('\0', left->freq + right->freq, left, right));
    }

    // Return the root of the tree
    return pq.top();
}

// Encode the input string using Huffman codes
string encode(const string& text, const unordered_map<char, string>& huffmanCodes) {
    string encodedString;
    for (char ch : text) {
        encodedString += huffmanCodes.at(ch);
    }
    return encodedString;
}

// Decode the encoded string using the Huffman Tree
string decode(const string& encodedString, Node* root) {
    string decodedString;
    Node* currentNode = root;
    for (char bit : encodedString) {
        if (bit == '0') {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }

        // Leaf node
        if (!currentNode->left && !currentNode->right) {
            decodedString += currentNode->ch;
            currentNode = root;
        }
    }
    return decodedString;
}

int main() {
    string text;
    cout << "Enter a string: ";
    getline(cin, text);

    // Frequency table
    unordered_map<char, int> freqTable;
    for (char ch : text) {
        freqTable[ch]++;
    }

    // Display frequency table
    cout << "\nFrequency Table:\n";
    for (auto& entry : freqTable) {
        cout << entry.first << " : " << entry.second << "\n";
    }

    // Build Huffman Tree
    Node* root = buildHuffmanTree(text, freqTable);

    // Generate Huffman codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Display Huffman codes
    cout << "\nHuffman Codes:\n";
    cout << "Character | Frequency | Code\n";
    for (auto& entry : huffmanCodes) {
        cout << entry.first << "\t\t" << freqTable[entry.first] << "\t\t" << entry.second << "\n";
    }

    // Encode the input string
    string encodedString = encode(text, huffmanCodes);
    cout << "\nEncoded String: " << encodedString << "\n";

    // Decode the encoded string
    string decodedString = decode(encodedString, root);
    cout << "Decoded String: " << decodedString << "\n";

    // Compression analysis
    cout << "\nCompression Analysis:\n";
    cout << "Original size: " << text.size() * 8 << " bits\n";
    cout << "Encoded size: " << encodedString.size() << " bits\n";
    cout << "Compression Ratio: " << (float)encodedString.size() / (text.size() * 8) * 100 << "%\n";

    return 0;
}