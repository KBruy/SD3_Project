#include <iostream>
#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    deleteTree(root);
}

void AVLTree::deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

void AVLTree::printInOrder(Node* node) {
    if (node == nullptr) {
        return;
    }

    printInOrder(node->left);
    cout << "(" << node->key << ", " << node->value << ") ";
    printInOrder(node->right);
}

void AVLTree::print() {
    printInOrder(root);
    cout << endl;
}

int AVLTree::getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return node->height;
}

int AVLTree::maxValue(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);
}

AVLTree::Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = maxValue(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxValue(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLTree::Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = maxValue(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxValue(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLTree::Node* AVLTree::insertNode(Node* node, int key, int value) {
    if (node == nullptr) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->height = 1;
        newNode->left = nullptr;
        newNode->right = nullptr;

        return newNode;
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key, value);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key, value);
    } else {
        node->value = value;
        return node;
    }

    node->height = maxValue(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }

    // Right Right
    if (balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }

    // Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(int key, int value) {
    root = insertNode(root, key, value);
}

bool AVLTree::findNode(Node* node, int key, int& value) {
    if (node == nullptr) {
        return false;
    }

    if (key == node->key) {
        value = node->value;
        return true;
    }

    if (key < node->key) {
        return findNode(node->left, key, value);
    }

    return findNode(node->right, key, value);
}

bool AVLTree::find(int key, int& value) {
    return findNode(root, key, value);
}

AVLTree::Node* AVLTree::findMin(Node* node) {
    Node* current = node;

    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

AVLTree::Node* AVLTree::removeNode(Node* node, int key, bool& removed) {
    if (node == nullptr) {
        return nullptr;
    }

    if ( key < node->key) {
        node->left = removeNode(node-> left, key, removed);
    } else if (key > node->key) {
        node->right = removeNode(node->right, key, removed);
    } else {
        removed = true;

        if (node->left == nullptr || node->right == nullptr) {
            Node* temp;

            if (node->left != nullptr) {
                temp = node->left;
            } else {
                temp = node->right;
            }

            delete node;
            return temp;
        } else {
            Node* temp = findMin(node->right);

            node->key = temp->key;
            node->value = temp->value;

            node->right = removeNode(node->right, temp->key, removed);
        }
    }

    node->height = maxValue(getHeight(node->left), getHeight(node->right)) +1;
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) {
        return rotateRight(node);
    }

    if (balance > 1 && getBalance(node->right) <= 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0) {
        return rotateLeft(node);
    }

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

bool AVLTree::remove(int key) {
    bool removed = false;
    root = removeNode(root, key, removed);
    return removed;
}