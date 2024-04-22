// S. Trowbridge 2024
#include <iostream>

struct Node {
    int data ;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

struct Iterator {
    Node *current;                                      
    Iterator(Node *n): current(n) {                     
    }
    void next() {                                       
        current = current->next;
    }
    bool hasNext() {                                    
        if(current != nullptr) { 
            return true; 
        } else {
            return false;
        }
    } 
    int& getData() {                                    
        return current->data;
    }
};

struct List {                                               
    Node *head;                                                                                    
    Node *tail;                                         
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
    bool empty() {
        return head == nullptr;
    } 
    Iterator begin() {                                  
        return Iterator(head);
    } 
    Iterator end() {                                    
        return Iterator(nullptr);
    } 
    int& front() {
        return head->data;                              
    }
    int& back() {
        return tail->data;                              
    }                     
};
void push_front(List &list, const int &d)                   
{
    Node *temp = new Node(d);                                                              
    temp->next = list.head;                                      
    list.head = temp;                                   
    if(list.tail == nullptr) { list.tail = temp; }      
}
void push_back(List &list, const int &d)                    
{
    if(list.head == nullptr) {                          
        push_front(list, d);
        return;
    }
    Node *temp = new Node(d);                              
    list.tail->next = temp;                                                 
    list.tail = temp;                                  
}
void pop_front(List &list) 
{
    if(list.head == nullptr) { return; }                
    Node *temp = list.head;                             
    list.head = list.head->next;                        
    delete temp;                                       
    if(list.head == nullptr) { list.tail = nullptr; }   
}
Iterator insertAfter(List &list, Iterator itr, const int &d) 
{
    if(itr.current == nullptr || list.head == nullptr) { return itr; }   
    Node *temp = new Node(d);                           
    if(itr.current == list.tail) { list.tail = temp; }  
    temp->next = itr.current->next;                     
    itr.current->next = temp;                           
    return Iterator(temp);
}
Iterator eraseAfter(List &list, Iterator itr)           
{
    if(list.head == nullptr || itr.current == nullptr || list.tail == itr.current) { return itr; }  
    Node *temp = itr.current->next;                     
    itr.current->next = temp->next;                     
    if(list.tail == temp) { list.tail = itr.current; }  
    delete temp;                                        
    return itr;                                          
}
void print(List &list) {                                
    for(Iterator itr=list.begin(); itr.hasNext(); itr.next()) { 
        std::cout << itr.getData() << " ";                      
    }  
    std::cout << "\n";
}
Iterator find(List &list, int d)                        
{
    Iterator itr = list.begin();                        
    while( itr.hasNext() ) {                            
        if( itr.getData() == d ) { return itr; }        
        itr.next();                                     
    }   
    return Iterator(nullptr);                           
}

int main() {
    std::cout << std::endl;

    List list; 

    std::cout << "PUSH BACK/FRONT\n";
    push_front(list, 200);
    push_front(list, 100);
    push_back(list, 400);     
    push_back(list, 600);
    push_back(list, 800);                                                                                                                   
    print(list); 

    std::cout << "\nPOP FRONT\n";
    pop_front(list);
    print(list);

    std::cout << "\nFRONT/BACK" << std::endl;
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;

    Iterator itr = list.begin();

    std::cout << "\nFIND/INSERT AFTER\n";
    itr = find(list, 200);
    insertAfter(list, itr, 300);                                   
    itr = find(list, 400);
    insertAfter(list, itr, 500);                      
    itr = find(list, 800);
    insertAfter(list, itr, 900);                    
    print(list);

    std::cout << "\nFIND/ERASE AFTER\n";    
    itr = find(list, 300);
    eraseAfter(list, itr);                          
    itr = find(list, 800);
    eraseAfter(list, itr); 
    print(list);                           

    std::cout << std::endl;
    return 0;
}