#include <iostream>
#include <vector>

using namespace std;

const int MIN = 0;
const int MAX = 1000000;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int data) {
    if (!root) {
        root = new Node(data);
        return;
    }
    if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

void buildTree(Node*& root, const vector<int>& preorder, int& index, int min, int max) {
    if (index == preorder.size()) {
        return;
    }
    int data = preorder[index];
    if (data < min || data > max) {
        return;
    }
    root = new Node(data);
    index++;
    buildTree(root->left, preorder, index, min, data);
    buildTree(root->right, preorder, index, data, max);
}

void printPostOrder(Node* root) {
    if (!root) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << '\n';
}

int main() {
    vector<int> preorder;
    int value;
    while (cin >> value) {
        preorder.push_back(value);
    }
    
    Node* root = nullptr;
    int index = 0;
    buildTree(root, preorder, index, MIN, MAX);
    
    printPostOrder(root);
    
    return 0;
}
