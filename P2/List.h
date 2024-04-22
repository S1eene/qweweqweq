#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include "Iterator.h"
class List {   
    private:
    Node *head;                                                                                     
    Node *tail;  
    public:                                                                                   
    List(): head(nullptr), tail(nullptr) {}             
    ~List()                                             
    {
        Node *temp = head;
        Node *next;
        while(temp != nullptr) {
            next = temp;
            temp = temp->next;
            delete next;
        }
        head = tail = nullptr;        
    } 
    bool empty() {return(head==nullptr);};
    Iterator begin(){return Iterator(head);};
    Iterator end() {return Iterator(nullptr);};
    Iterator rbegin(){return Iterator(tail);};
    Iterator rend() {return Iterator(nullptr);};
    int& front() {return head->number();};
    int& back() {return tail->number();};
    void push_front(const int &d);
    void push_back(const int &d);
    void pop_front();
    void pop_back();
    void print();
    void printRev();
    void insert(Iterator place,const int &input);
    void erase(Iterator place);
    Iterator find(const int &d);
    
};

#endif