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