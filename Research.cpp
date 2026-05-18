#include <iostream>
#include <cstdlib>
#include "Research.h"

using namespace std;

int Research::generateRandomNumber() {
    return rand() % (MAX_VALUE + 1);
}

bool Research::keyExists(TestElement* data, int currentSize, int key) {
    for (int i = 0; i < currentSize; i++) {
        if (data[i].key == key) {
            return true;
        }
    }

    return false;
}

void Research::generateData(TestElement* data, int size, int seed) {
    srand(seed);

    for (int i = 0; i < size; i++ ) {
        int key;

        do {
            key = generateRandomNumber();
        } while (keyExists(data, i, key));

        data[i].key = key;
        data[i].value = generateRandomNumber();
    }
}

void Research::run() {
    int size = 10;
    int seed = BASE_SEED;

    TestElement* data = new TestElement[size];

    generateData(data, size, seed);

    cout << endl;
    cout << "Test generowania danych do badan: "<< endl;

    for (int i = 0; i < size; i++) {
        cout << i << ": key = " << data[i].key <<", value = " << data[i].value << endl;
    }

    delete[] data;
}

