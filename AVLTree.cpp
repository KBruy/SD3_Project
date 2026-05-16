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

void AVLTree::printInOder(Node* node) {
    if (node == nullptr) {
        return;
    }

    printInOder(node->left);
    cout << "(" << node->key << ", " << node->value<<") ";
    printInOder(node->right);
}

void AVLTree::print() {
    printInOder(root);
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
}