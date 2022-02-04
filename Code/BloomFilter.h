#include "HashTable.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
const int HASH_TABLE_SIZE = 673; // have a load factor of 1.5, choose nearest prime

class BloomFilter
{
    public:
    BloomFilter(float p, int m, float c, float d);
    void insert(std::string element);
    bool search(std::string target) const ;
    void remove(std::string target);

    void print(); // debugging only, used to check bloomFilterSize and hashFunctionSize
    private:
    int calculateBloomFilterSize(float p, int m, float c) const ;
    int calculateHashFunctionSize(int n, int m, float d) const ;
    unsigned int hash(unsigned int key, int index) const;

    const int bloomFilterSize;
    const int hashFunctionSize;
    std::vector<bool> filter; // each bool is 1 bit, see reference 1
    HashTable removedElement;
};
