#include <iostream>
#include "HashTableList.h"

using namespace std;

int hashFunction(int key, int capacity){
    if (key < 0) {
        key = -key;
    }

    return key % capacity;
}

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

void HashTableList::insert(int key, int value) {
   int index = hashFunction(key, capacity);

   Node* current = buckets[index];

   while ( current != nullptr) {
    if (current->key == key){
        current->value = value;
        return;
    }

    current = current->next;
   }

   Node* newNode = new Node;
   newNode->key = key;
   newNode->value = value;
   newNode->next = buckets[index];

   buckets[index] = newNode;
}

bool HashTableList::find(int key, int& value) {
    int index = hashFunction(key, capacity);

    Node* current = buckets[index];

    while (current != nullptr) {
        if (current->key == key) {
            value = current->value;
            return true;
        }
        current = current->next;
    }

    return false;
}

