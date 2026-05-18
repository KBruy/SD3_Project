#ifndef RESEARCH_H
#define RESEARCH_H

class Research {
    private:
        static const int MAX_VALUE = 16777215;
        static const int BASE_SEED = 12345;

        struct TestElement
        {
            int key;
            int value;
        };

        int generateRandomNumber();
        bool keyExists(TestElement* data, int currentSize, int key);
        void generateData(TestElement* data, int size, int seed);
        
    public:
        void run();
};

#endif