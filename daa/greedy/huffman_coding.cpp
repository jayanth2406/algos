#include<bits/stdc++.h>
using namespace std;

/***
 * Huffman Encoding and Decoding
 * 
 * @problem:
 *    Given a text, we need to encode the text using Huffman encoding and decode the encoded text.
 * 
 * @pseudo_code:
 *   1. Build a Huffman tree using the given text.
 *      a. Create a frequency map of each character in the text.
 *      b. Create a priority queue of nodes where each node contains a character and its frequency.
 *      c. Repeat the following steps until there is only one node in the priority queue:
 *          i. Pop two nodes from the priority queue.
 *          ii. Create a new node with the sum of the frequencies of the two nodes and push it back to the priority queue.
 *      d. The last node in the priority queue is the root of the Huffman tree.
 * 
 *   2. Encode the text using the Huffman tree.
 *      a. Create a map of characters and their corresponding Huffman codes.
 *      b. Traverse the Huffman tree and assign '0' for the left child and '1' for the right child.
 * 
 *   3. Decode the encoded text using the Huffman tree.
 *      a. Traverse the Huffman tree based on the encoded text.
 * 
 * @time_complexity:
 *   O(nlogn) where n is the number of characters in the text.
 */


struct  Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq)
    : ch(ch), freq(freq), left(nullptr), right(nullptr) {}

    Node(char ch, int freq, Node *left, Node *right)
    : ch(ch), freq(freq), left(left), right(right) {}
};

struct compare {
    bool operator()(Node *l, Node *r) {
        return l->freq > r->freq;
    }
};

void encode(Node *root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(Node *root, int &top_index, string str) {
    if (root == nullptr) return;
    if (!root->left && !root->right) {
        cout << root->ch;
        return;
    }
    top_index++;
    if(str[top_index] == '0') {
        decode(root->left, top_index, str);
    } else {
        decode(root->right, top_index, str);
    }
}

Node* buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }
    Node *root = pq.top();
    return root;
}

int main() {
    string text = "Huffman coding is a data compression algorithm.";
    Node *root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);
    cout << "Huffman Codes are:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    string str = "";
    for (char ch : text) {
        str += huffmanCode[ch];
    }
    cout << "\nEncoded string is: " << str << endl;

    cout << "\nDecoded string is: ";
    int top_index = -1;
    while (top_index < (int)str.size() - 2) {
        decode(root, top_index, str);
    }

    return 0;
}