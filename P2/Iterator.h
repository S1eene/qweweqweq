#ifndef ITERATOR_H
#define ITERATOR_H
#include "Node.h"
class Iterator{
private:
    Node *current;
public:
    friend class List;
    Iterator(Node *n): current(n) {};
    void next() {current = current->getnext();}
    void prev() {current = current->getprev();}
    bool hasNext() {if (current != nullptr){return true;}return false;}
    bool hasPrev() {if (current != nullptr){return true;}return false;}
    int getData() {return current->data;}
};
#endif