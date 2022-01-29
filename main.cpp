#include "BloomFilter.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main(int argc, char** argv)
{
    if(argc != 6)
    {
        cerr << "Wrong number of arguments" << endl;
        exit(1);
    }
    ifstream inputFiles[5];
    for(int i=0; i<5; i++)
    {
        inputFiles[i].open(argv[i+1]);
        if(!inputFiles[i].is_open())
        {
            cerr << "Can't open " << argv[1] << endl;
            exit(1);
        }
    }
    float p, c, d;
    int m;
    inputFiles[0] >> p;
    inputFiles[0] >> m;
    inputFiles[0] >> c;
    inputFiles[0] >> d;

    cout << "Experiment for values of:" << endl;
    cout << "p = " << p << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "q = " << HASH_TABLE_SIZE << endl;
    cout << end;

    BloomFilter b{p, m, c, d};
    
    int totalFalseNegative = 0;
    int totalFalsePositive = 0;
    for(int phaseCount=0; phaseCount<10; phaseCount++)
    {
        vector<string> falsePositiveElements;
        int falseNegative = 0;
        int falsePositive = 0;
        string temp;
        for(int i=0; i<1000; i++)
        {
            temp = "";
            inputFiles[1] >> temp;
            b.insert(temp);
        }
        for(int i=0; i<100; i++)
        {
            temp = "";
            inputFiles[2] >> temp;
            if(!b.search(temp))
            {
                falseNegative++;
            }
        }
        for(int i=0; i<100; i++)
        {
            temp = "";
            inputFiles[3] >> temp;
            if(b.search(temp))
            {
                falsePositiveElements.push_back(temp);
                falsePositive++;
            }
        }
        for(int i=0; i<100; i++)
        {
            temp = "";
            inputFiles[4] >> temp;
            b.remove(temp);
        }
        cout << "Phase: "<< phaseCount+1 << endl;
        cout << "Number of false negatives:" << endl;
        cout << falseNegative << endl;
        cout << "Number of false positive:" << endl;
        cout << falsePositive << endl;
        cout << "Probabilty of false positive:" << endl;
        cout << (double)falsePositive/(double)100 << endl;
        cout << "False positive elements:" << endl;
        for(string& ele : falsePositiveElements)
        {
            cout << ele << endl;
        }
        cout << endl;
        totalFalseNegative += falseNegative;
        totalFalsePositive += falsePositive;
    }

    cout << "Number of total false negatives:" << endl;
    cout << totalFalseNegative << endl;
    cout << "Number of total false positives:" << endl;
    cout << totalFalsePositive << endl;
    cout << "Probabilty of false positive in total:" << endl;
    cout << (double)totalFalsePositive/(double)1000 << endl;

    for(int i=0; i<5; i++)
    {
        inputFiles[i].close();
    }
    return 0;
}