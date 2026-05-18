#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include "HashTableList.h"
#include "Research.h"

using namespace std;
using namespace std::chrono;

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

void Research::writeCsvHeader(ofstream& file) {
    file << "structure,operation,size,series_count,copies,avg_time_ns" << endl;
}

void Research::run() {
    int testSizes[TEST_SIZES_COUNT] = {
        5000, 10000, 25000, 50000, 100000
    };

    ofstream file("results_summary.csv");

    if (!file.is_open()) {
        cout << "Nie udalo sie otworzyc pliku results_summary.csv" << endl;
        return;
    }

    writeCsvHeader(file);

    cout << "Rozpoczynam badania..." << endl;

    for (int i = 0; i < TEST_SIZES_COUNT; i++) {
        int size = testSizes[i];

        cout << "HashTableList insert, size = " << size << endl;

        double avgTime = measureListInsert(size);

        writeSummaryResult(file, "HashTableList", "insert", size, avgTime);
    }

    cout << "Zakonczono badania. Wyniki zapisano do results_summary.csv" << endl;
}

void Research::writeSummaryResult(ofstream& file, const char* structureName, const char* operationName, int size, double avgTime) {
    file << structureName<<","
        << operationName<<","
        << size <<","
        << SERIES_COUNT << ","
        << COPIES_COUNT << ","
        << avgTime << endl;
}

double Research::measureListInsert(int size) {
    long long totalTime = 0;

    for (int series = 0; series < SERIES_COUNT; series++) {
        int seed = BASE_SEED + series;

        TestElement* data = new TestElement[size];
        generateData(data, size, seed);

        TestElement newElement;

        do{
            newElement.key = generateRandomNumber();
        } while (keyExists(data, size, newElement.key));

        newElement.value = generateRandomNumber();

        for (int copy = 0; copy < COPIES_COUNT; copy++) {
            HashTableList table(size * 2);

            for (int i = 0; i < size; i++) {
                table.insert(data[i].key, data[i].value);
            }

            auto start = high_resolution_clock::now();

            table.insert(newElement.key, newElement.value);

            auto end = high_resolution_clock::now();

            totalTime += duration_cast<nanoseconds>(end - start).count();
        }

        delete[] data;
    }

    return static_cast<double>(totalTime) / (SERIES_COUNT * COPIES_COUNT);
}
