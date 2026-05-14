#ifndef HASH_TABLE_LIST_H
#define HASH_TABLE_LIST_H

class HashTableList {
    private:
        struct Node {
            int key;
            int value;
            Node* next;

        };

        Node** buckets; //wskaznik na tablice wskaznikow
        int capacity;

    public:
        HashTableList(int tableCapacity);
        ~HashTableList();

        void print();

        void insert(int key, int value);
};

#endif