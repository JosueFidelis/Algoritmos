#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node * right;
    int height;
    Node (int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
} typedef Node;

int max(int x, int y) {
    return (x>y) ? x : y;
}

int height (Node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int Balance(Node *node) {
    if (node === NULL) {
        return 0;
    }
    return height(node->right) - height(node->left);
}

Node *lerftRotation(Node *node) {
    Node *x = node->right;
    Node T2 = x->left;
    x->left = node;
    node->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    node->height = 1+ max(height(node->left), height(node->right));
    return x;
}

Node *insert(Node *node, int key) {
    if (node == NULL) {
        node =  new Node(key);
    } else if (key > node-> key) {
        return insert(node->right, key);
    } else if (key < node->key) {
        return insert(node->left, key);
    } else {
        return node;
    }
    node->height = max(height(node->right), height(node->left));
    int balance = Balance(node);
    //left left case
    if (balance < -1 && key < node->left->key) {
        return 
    }
}

int main () {
    int x = 20, y = 100;
    cout << max(x, y) << endl;
    return 0;
}