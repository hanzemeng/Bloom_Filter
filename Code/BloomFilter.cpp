#include "BloomFilter.h"

BloomFilter::BloomFilter(float p, int m, float c, float d) : 
bloomFilterSize(calculateBloomFilterSize(p, m, c)),
hashFunctionSize(calculateHashFunctionSize(bloomFilterSize, m, d)),
filter(bloomFilterSize, false),
removedElement(HASH_TABLE_SIZE) 
{}

void BloomFilter::print() // debugging only
{
    std::cout << "bloomFilterSize: " << filter.size() << std::endl;
    std::cout << "hashFunctionSize: " << hashFunctionSize << std::endl;
    for(bool b : filter)
    {
        std::cout << b;
    }
    std::cout << std::endl;
}

void BloomFilter::insert(std::string element)
{
    removedElement.remove(element);
    unsigned int key = strToInt(element);

    for(int i=0; i<hashFunctionSize; i++)
    {
        filter[hash(key, i+1)] = true;
    }
}
bool BloomFilter::search(std::string target) const
{
    if(removedElement.search(target))
    {
        return false;
    }
    unsigned int key = strToInt(target);

    for(int i=0; i<hashFunctionSize; i++)
    {
        if(!filter[hash(key, i+1)])
        {
            return false;
        }
    }
    return true;
}
void BloomFilter::remove(std::string target)
{
    if(search(target))
    {
        removedElement.insert(target);
    }
}

int BloomFilter::calculateBloomFilterSize(float p, int m, float c) const
{
    return -1 * m * std::log(p) / std::log(2) / std::log(2) * c;
}
int BloomFilter::calculateHashFunctionSize(int n, int m, float d) const
{
    return n * std::log(2) / m * d;
}

unsigned int BloomFilter::hash(unsigned int key, int index) const
{
    double a = 0.6180339887498949; // golden ratio, see reference 2
    unsigned int k = key*index;

    double frac = a*k;
    double temp;
    frac = std::modf(frac, &temp); // get the fractional part, see reference 3

    return bloomFilterSize*frac;
}
