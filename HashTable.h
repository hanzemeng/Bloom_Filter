#include <string>
#include <iostream>
#include "LinkedList.h"
unsigned int strToInt(std::string element);

class HashTable
{
    public:
    HashTable(int q);
    ~HashTable();
    void insert(std::string target);
    bool search(std::string target) const;
    void remove(std::string target);

    private:
    const int primeSize;
    LinkedList* table;
};
