#include "HashTable.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
const int HASH_TABLE_SIZE = 1429; // have a load factor of 0.7, choose nearest prime

class BloomFilter
{
    public:
    BloomFilter(float p, int m, float c, float d);
    void insert(std::string element);
    bool search(std::string target);
    void remove(std::string target);

    void print();
    private:
    int calculateBloomFilterSize(float p, int m, float c);
    int calculateHashFunctionSize(int n, int m, float d);
    unsigned int hash(unsigned int key, int index);

    const int bloomFilterSize;
    const int hashFunctionSize;
    std::vector<bool> filter;
    HashTable removedElement;
};
