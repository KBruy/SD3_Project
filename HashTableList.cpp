#include <iostream>
#include "HashTableList.h"

using namespace std;

HashTableList::HashTableList(int tableCapacity) {
    capacity = tableCapacity;
    buckets = new Node*[capacity];

    for (int i = 0; i < capacity; i++) {
        buckets[i] = nullptr;

    }
}

HashTableList::~HashTableList() {
    for (int i = 0; i < capacity; i++) {
        Node* current = buckets[i];

        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    delete[] buckets;
}

void HashTableList::print() {
    cout << endl;
    cout << "HashTableList: " << endl;

    for (int i = 0; i < capacity; i++) {
        cout <<i<<": ";

        Node* current = buckets[i];

        while (current != nullptr) {
            cout << "(" << current->key<<", " << current->value<<") -> ";
            current = current-> next;
        }
        cout << "nullptr" << endl;
    }
}