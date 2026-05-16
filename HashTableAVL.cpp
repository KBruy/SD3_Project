#include <iostream>
#include "HashTableAVL.h"

using namespace std;

HashTableAVL::HashTableAVL(int tableCapacity) {
    capacity = tableCapacity;
    buckets = new AVLTree[capacity];
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

