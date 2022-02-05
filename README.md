# Programming assignment 1: Bloom Filter
This project is for CMPSC 130A's programming assignment 1.

## If you want to run the program
Go to the directory named "Code".
In your terminal:
1. Type "make PA1" or "make" to build the program
2. Type "make run" or "./PA1 setup.txt input.txt successfulSearch.txt failedSearch.txt remove.txt" to run the program
3. Type "make clean" to remove all of the generated files

## If you want to read the program output for different values of c and d
Go to the directory named "Output".

## If you want to read the documentation
Go to the directory named "Document".
"Report" talks about design choice and analyze how c and d affects the false positive probability.
"False Positive Probability" summarizes the data found in "Output". It also has plots to visualize how change of c and d affects false positive probability.

## Reference
1. https://en.cppreference.com/w/cpp/container/vector_bool
2. https://www.cs.auckland.ac.nz/software/AlgAnim/hash_func.html
3. https://en.cppreference.com/w/cpp/numeric/math/modf
