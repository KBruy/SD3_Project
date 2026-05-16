#ifndef AVL_TREE_H
#define AVL_TREE_H

class AVLTree {

    private:
        struct Node {
            int key;
            int value;
            int height;
            Node* left;
            Node* right;
        };

        Node* root;

        void deleteTree(Node* node);
        void printInOder(Node* node);

    public:
        AVLTree();
        ~AVLTree();

        void print();
            
};

#endif