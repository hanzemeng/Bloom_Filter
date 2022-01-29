#include "BloomFilter.h"

BloomFilter::BloomFilter(float p, int m, float c, float d) : 
bloomFilterSize(calculateBloomFilterSize(p, m, c)),
hashFunctionSize(calculateHashFunctionSize(bloomFilterSize, m, d)),
filter(bloomFilterSize, false),
removedElement(HASH_TABLE_SIZE) 
{}

void BloomFilter::print()
{
    std::cout << "bloomFilterSize: " << filter.size() << std::endl;
    std::cout << "hashFunctionSize: " << hashFunctionSize << std::endl;
    
}

void BloomFilter::insert(std::string element)
{
    removedElement.remove(element);
    unsigned int key = strToInt(element);

    for(int i=0; i<hashFunctionSize; i++)
    {
        //std::cout << hash(key, i+1) << std::endl;
        filter[hash(key, i+1)] = true;
    }
}
bool BloomFilter::search(std::string target)
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

int BloomFilter::calculateBloomFilterSize(float p, int m, float c)
{
    return -1 * m * std::log(p) / std::log(2) / std::log(2) * c;
}
int BloomFilter::calculateHashFunctionSize(int n, int m, float d)
{
    return n * std::log(2) / m * d;
}

unsigned int BloomFilter::hash(unsigned int key, int index)
{
    double a = 0.6180339887498949; // golden ratio
    unsigned int k = key*index;

    double frac = a*k;
    double temp;
    frac = std::modf(frac, &temp);

    return bloomFilterSize*frac;
}