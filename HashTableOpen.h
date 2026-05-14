#ifndef HASH_TABLE_OPEN_H
#define HASH_TABLE_OPEN_H

class HashTableOpen {
    private:
        struct Cell {
            int key;
            int value;
            int state;
        };

        Cell* table;
        int capacity;

    public:
        HashTableOpen(int tableCapacity);
        ~HashTableOpen();

        void print();

        bool insert(int key, int value);

        bool find(int key, int& value);
        bool remove(int key);
};

#endif