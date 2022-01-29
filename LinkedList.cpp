#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
}
LinkedList::~LinkedList()
{
    while(head)
    {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}
void LinkedList::prepend(std::string target)
{
    Node* newNode = new Node{target, nullptr};
    if(!head)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
bool LinkedList::search(std::string target) const
{
    Node* temp = head;
    while(temp)
    {
        if(temp->val == target)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
bool LinkedList::remove(std::string target)
{
    if(!head)
    {
        return false;
    }
    if(head && head->val == target)
    {
        Node* newHead = head->next;
        delete head;
        head = newHead;
        return true;
    }

    Node* current = head->next;
    Node* prev = head;
    while(current && current->val != target)
    {
        current = current->next;
        prev = prev->next;
    }
    if(current)
    {
        prev->next = current->next;
        delete current;
        return true;
    }
    
    return false;
}

void LinkedList::print() const
{
    Node* temp = head;
    while(temp)
    {
        std::cout << temp->val << std::endl;
        temp = temp->next;
    }
}
