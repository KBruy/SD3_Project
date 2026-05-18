#ifndef RESEARCH_H
#define RESEARCH_H

#include <fstream>

class Research {
    private:
        static const int MAX_VALUE = 16777215;
        static const int BASE_SEED = 12345;
        static const int SERIES_COUNT = 10;
        static const int COPIES_COUNT = 100;
        static const int TEST_SIZES_COUNT = 5;

        struct TestElement
        {
            int key;
            int value;
        };

        int generateRandomNumber();
        bool keyExists(TestElement* data, int currentSize, int key);
        void generateData(TestElement* data, int size, int seed);

        void writeCsvHeader(std::ofstream& file);
        void writeSummaryResult(std::ofstream& file, const char* structureName, const char* operationName, int size, double avgTime);


        double measureListInsert(int size);
        double measureListRemove(int size);
        

        double measureOpenInsert(int size);
        double measureOpenRemove(int size);

        double measureAVLInsert(int size);
        double measureAVLRemove(int size);

        
    public:
        void run();
};

#endif