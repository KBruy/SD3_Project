#include <iostream>
#include "HashTableOpen.h"

using namespace std;

HashTableOpen::HashTableOpen(int tableCapacity) {
    capacity = tableCapacity;
    table = new Cell[capacity];

    for (int i = 0; i < capacity; i++) {
        table[i].state = 0;
    }
}

HashTableOpen::~HashTableOpen() {
    delete[] table;
}

void HashTableOpen::print() {
    cout << endl;
    cout << "HashTableOpen: "<<endl;

    for (int i = 0; i < capacity; i++) {
        cout << i << ": ";

        if(table[i].state == 0) {
            cout << "EMPTY";

        } else if (table[i].state == 1) {
            cout << "(" << table[i].key << ", " << table[i].value << ")";
        }else if (table[i].state == 2) {
            cout << "DELETED";
        }

        cout << endl;
    }
}