#include "HashTable.h"

unsigned int strToInt(std::string element)
{
    unsigned int res = 0;
    unsigned int x = 29; // 26 lower case English characters, so use 29 (a prime)
    // unsigned int remain = 2147483647; this is 2^31-1, a prime

    for(int i=0; i<element.size(); i++)
    {
        res += x*res + element[i]-'a'+1;
        // res %= remain; decide to not use to reduce false positives, see documentation for explanation
    }
    return res;
}

HashTable::HashTable(int q) : primeSize(q)
{
    table = new LinkedList[primeSize];
}
HashTable::~HashTable()
{
    delete[] table;
}

void HashTable::insert(std::string target)
{
    int index = strToInt(target)%primeSize;
    table[index].prepend(target);
}
bool HashTable::search(std::string target) const
{
    int index = strToInt(target)%primeSize;
    return table[index].search(target);
}
void HashTable::remove(std::string target)
{
    int index = strToInt(target)%primeSize;
    table[index].remove(target);
}
