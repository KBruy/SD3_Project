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


        int getHeight(Node* node);
        int getBalance(Node* node);
        int maxValue(int a, int b);

        Node* rotateRight(Node* y);
        Node* rotateLeft(Node* x);

        Node* insertNode(Node* node, int key, int value);

    public:
        AVLTree();
        ~AVLTree();

        void print();
        
        void insert(int key, int value);
};

#endif