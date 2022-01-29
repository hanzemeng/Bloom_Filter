#include <string>
#include <iostream>

struct Node
{
    std::string val;
    Node* next;
};

class LinkedList
{
    public:
    LinkedList();
    ~LinkedList();
    void prepend(std::string target);
    bool search(std::string target) const;
    bool remove(std::string target);
    void print() const;

    private:
    Node* head;
};
