#include "HashTable.h"

unsigned int strToInt(std::string element)
{
    unsigned int res = 0;
    unsigned int x = 31;
    for(int i=0; i<element.size(); i++)
    {
        res += x*res + element[i]-'a';
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