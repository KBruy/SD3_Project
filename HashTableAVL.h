#ifndef HASH_TABLE_AVL_H
#define HASH_TABLE_AVL_H

#include "AVLTree.h"

class HashTableAVL {
    private:
        AVLTree* buckets;
        int capacity;

    public:
        HashTableAVL(int tableCapacity);
        ~HashTableAVL();

        void print();
};

#endif