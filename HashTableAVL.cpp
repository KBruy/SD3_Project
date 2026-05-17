#include <iostream>
#include "HashTableAVL.h"

using namespace std;

int hashAVLFunction(int key, int capacity) {
    if (key < 0) {
        key = -key;
    }

    return key % capacity;
}

HashTableAVL::HashTableAVL(int tableCapacity) {
    capacity = tableCapacity;
    buckets = new AVLTree[capacity];
}

void HashTableAVL::insert(int key, int value) {
    int index = hashAVLFunction(key, capacity);

    buckets[index].insert(key, value);
}



HashTableAVL::~HashTableAVL() {
    delete[] buckets;
}

void HashTableAVL::print(){
    cout << endl;
    cout << "HashTableAVL: "<<endl;

    for (int i = 0; i<capacity; i++) {
        cout << i << ": ";
        buckets[i].print();
    }
}

bool HashTableAVL::find(int key, int& value) {
    int index = hashAVLFunction(key, capacity);

    return buckets[index].find(key, value);
}

bool HashTableAVL::remove(int key) {
    int index = hashAVLFunction(key, capacity);

    return buckets[index].remove(key);
}