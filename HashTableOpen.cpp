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

int hashOpenFunction(int key, int capacity) { //funckja haszująca
    if ( key < 0) {
        key = -key;
    }

    return key % capacity;
}

bool HashTableOpen::insert(int key, int value) {
    int index = hashOpenFunction(key, capacity);

    for (int i = 0; i<capacity; i++) {
        int currentIndex = (index + i) % capacity;

        if (table[currentIndex].state == 1 && table[currentIndex].key == key){
            table[currentIndex].value = value;
            return true;
        }

        if (table[currentIndex].state == 0 || table[currentIndex].state == 2) {
            table[currentIndex].key = key;
            table[currentIndex].value = value;
            table[currentIndex].state = 1;
            return true;
        }
     }

     return false;
}

bool HashTableOpen::find(int key, int& value){
    int index = hashOpenFunction(key, capacity);

    for (int i = 0; i < capacity; i++) {
        int currentIndex = (index + i) % capacity;

        if (table[currentIndex].state == 0) {
            return false;
        }

        if (table[currentIndex].state == 1 && table[currentIndex].key == key) {
            value = table[currentIndex].value;
            return true;
        }
    }

    return false;
}

bool HashTableOpen::remove(int key) {
    int index = hashOpenFunction(key, capacity);

    for (int i = 0; i < capacity; i++) {
        int currentIndex = (index + i) % capacity;

        if (table[currentIndex].state == 0) {
            return false;
        }

        if (table[currentIndex].state == 1 && table[currentIndex].key == key) {
            table [currentIndex].state = 2;
            return true;
        }
    }

    return false;
}