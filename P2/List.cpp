#include <iostream>
#include "Node.h"
#include "Iterator.h"
#include "List.h"

void List::push_front(const int &d) {
    Node *temp = new Node(d);                               
    if(head == nullptr) {                              
       tail = temp;                                    
    } else {
        temp->next = head;                              
        head->prev = temp;                                
    }             
    head = temp;
    return;
}

void List::push_back(const int &d) {
    if(head == nullptr) {                              
        push_front(d);
        return;
    }
    Node *temp = new Node(d);                                                          
    tail->next = temp;                                                       
    temp->prev = tail;                                     
    tail = temp;
    return;
}

void List::pop_front() {
    if(head == nullptr) { return; }                    
    Node *temp = head;                                 
    head = head->next;                            
    delete temp;
    temp = nullptr;                                            
    if(head != nullptr) {                              
        head->prev = nullptr;                         
    } else {                                                
        tail = nullptr;                                
    }
    return;
}

void List::pop_back() {
    if(tail == nullptr) { return; }                    
    if(tail == head) {                            
        pop_front();
        return;
    }
    Node *temp = tail;                                 
    tail = tail->prev;                             
    tail->next = nullptr;                                
    delete temp;
    temp = nullptr;
    return;    
}

void List::print() {
    Iterator itr = begin();
    while (itr.hasNext()) {
        Node *a = itr.current;
        a->print();
        itr.next();
    }
    std::cout << "\n";
    return;
}

void List::printRev() {
    Iterator itr = rbegin();
    while (itr.hasPrev()) {
        Node *a = itr.current;
        a->print();
        itr.prev();
    }
    std::cout << "\n";
    return;
}

Iterator List::find(const int &d) {
    Iterator term = begin();
    while (term.hasNext()) {
        if (term.getData() == d) {return term;}
        term.next();
    }
    return Iterator(nullptr);
}

void List::insert(Iterator place, const int &input) {
    if (place.current == nullptr) {return;}
    if (head == nullptr || place.current == head) {push_front(input);}
    Node *temp = new Node(input);
    temp->next = place.current;                               
    temp->prev = place.current->prev;                         
    temp->prev->next = temp;                                
    temp->next->prev = temp;

}

void List::erase(Iterator place) {
    if(place.current == nullptr || head == nullptr) { return;}  
    if(head == place.current) {                          
        pop_front();                                            
    } else if(tail == place.current) {                                      
        pop_back();
    }
    Node *temp = place.current;
    temp->next->prev = temp->prev;                          
    temp->prev->next = temp->next;                          
    place.next();                                             
    delete temp;
    temp = nullptr;                                            
    return;
}

