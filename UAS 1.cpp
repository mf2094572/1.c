#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;


struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};


struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};


Node* buildHuffmanTree(const string& input) {
    unordered_map<char, int> freqMap;
    for (char ch : input) freqMap[ch]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* combined = new Node('\0', left->freq + right->freq);
        combined->left = left;
        combined->right = right;
        pq.push(combined);
    }

    return pq.top();
}


void buildHuffmanCodes(Node* root, unordered_map<char, string>& huffmanCodes, string code) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }
    buildHuffmanCodes(root->left, huffmanCodes, code + "0");
    buildHuffmanCodes(root->right, huffmanCodes, code + "1");
}


string encode(const string& input, unordered_map<char, string>& huffmanCodes) {
    string encodedStr = "";
    for (char ch : input) {
        encodedStr += huffmanCodes[ch];
    }
    return encodedStr;
}


string decode(Node* root, const string& encodedStr) {
    string decodedStr = "";
    Node* current = root;
    for (char bit : encodedStr) {
        current = (bit == '0') ? current->left : current->right;
        if (!current->left && !current->right) {
            decodedStr += current->ch;
            current = root;
        }
    }
    return decodedStr;
}

int main() {
    cout << "MUHAMMAD FADHIL RIFKY: "<<endl;
    string input;
    cout << "Masukkan string untuk dikompresi: ";
    cin >> input;
    

    Node* root = buildHuffmanTree(input);
    unordered_map<char, string> huffmanCodes;
    buildHuffmanCodes(root, huffmanCodes, "");

    cout << "\nKode Huffman untuk setiap karakter:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    string encodedStr = encode(input, huffmanCodes);
    cout << "\nString terkompresi: " << encodedStr << endl;

    string decodedStr = decode(root, encodedStr);
    cout << "String hasil dekompresi: " << decodedStr << endl;

    return 0;
}
