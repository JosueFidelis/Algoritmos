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
    if (node == NULL) {
        return 0;
    }
    return height(node->right) - height(node->left);
}

Node *rightRotation(Node *node) {
    Node *x = node->left;
    Node *T2 = x->right;
    x->right = node;
    node->left = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    node->height = 1 + max(height(node->left), height(node->right));
    return x;
}

Node *leftRotation(Node *node) {
    Node *x = node->right;
    Node *T2 = x->left;
    x->left = node;
    node->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    node->height = 1+ max(height(node->left), height(node->right));
    return x;
}

Node *insert(Node *node, int key) {
    if (node == NULL) {
        return new Node(key);
    } else if (key > node-> key) {
        node->right =  insert(node->right, key);
    } else if (key < node->key) {
        node->left =  insert(node->left, key);
    } else {
        return node;
    }
    node->height = max(height(node->right), height(node->left));
    int balance = Balance(node);
    //left left case
    if (balance < -1 && key < node->left->key) {
        return rightRotation(node);
    } //left right case  || double left
    if (balance < -1 && key > node->left->key) {
         node->left = leftRotation(node->left);
         return rightRotation(node);
    } // right right case
    if (balance > 1 && key > node->right->key) {
        return leftRotation(node);
    } // right left case || double right
    if (balance > 1 && key < node->right->key) {
        node->right =rightRotation(node->right);
        return leftRotation(node); 
    }
    return node;
}

void preorder(Node *node) {
    if(node != NULL) {
        cout << node->key << endl;
        preorder(node->left);
        preorder(node->right);
    }
}

int main () {
    Node *node = NULL;
    node = insert(node, 10);
    node = insert(node, 20);
    node = insert(node, 30);
    node = insert(node, 40);
    node = insert(node, 50);
    node = insert(node, 25);
    preorder(node);
    return 0;
}