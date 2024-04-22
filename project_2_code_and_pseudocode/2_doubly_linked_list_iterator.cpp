// S. Trowbridge 2024
#include <iostream>

struct Node {
    int data;                                                  
    Node *next;
    Node *prev; 
    Node(): data(0), next(nullptr), prev(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr), prev(nullptr) {}                                
};

struct Iterator {
    Node *current;                                      
    Iterator(Node *n): current(n) {                     
    }
    void next() {                                       
        current = current->next;
    }
    void prev() {                                       
        current = current->prev;
    }
    bool hasNext() {                                    
        if(current != nullptr) { 
            return true; 
        } else {
            return false;
        }
    }
    bool hasPrev() {                                    
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
    Iterator rbegin() {                                 
        return Iterator(tail);
    }                    
    Iterator rend() {                                    
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
    if(list.head == nullptr) {                              
       list.tail = temp;                                    
    } else {
        temp->next = list.head;                              
        list.head->prev = temp;                                
    }             
    list.head = temp;                                       
}
void push_back(List &list, const int &d)                    
{
    if(list.head == nullptr) {                              
        push_front(list, d);
        return;
    }
    Node *temp = new Node(d);                                                          
    list.tail->next = temp;                                                       
    temp->prev = list.tail;                                     
    list.tail = temp;                                       
}
void pop_front(List &list) {
    if(list.head == nullptr) { return; }                    
    Node *temp = list.head;                                 
    list.head = list.head->next;                            
    delete temp;                                            
    if(list.head != nullptr) {                              
        list.head->prev = nullptr;                          
    } else {                                                
        list.tail = nullptr;                                
    }
}
void pop_back(List &list) {
    if(list.tail == nullptr) { return; }                    
    if(list.tail == list.head) {                            
        pop_front(list);
        return;
    }
    Node *temp = list.tail;                                 
    list.tail = list.tail->prev;                             
    list.tail->next = nullptr;                                
    delete temp;                                            
}
Iterator insert(List &list, Iterator itr, const int &d)     
{
    if(itr.current == nullptr) { return itr; }              
    if(list.head == nullptr || itr.current == list.head) {  
        push_front(list, d);
        return list.begin();
    }
    Node *temp = new Node(d);                               
    temp->next = itr.current;                               
    temp->prev = itr.current->prev;                         
    temp->prev->next = temp;                                
    temp->next->prev = temp;                                
    return Iterator(temp);
}
Iterator erase(List &list, Iterator itr)                    
{
    if(itr.current == nullptr || list.head == nullptr) { return itr; }  
    if(list.head == itr.current) {                          
        pop_front(list);                    
        return list.begin();                        
    } else if(list.tail == itr.current) {                                      
        pop_back(list);
        return list.end();
    }
    Node *temp = itr.current;
    temp->next->prev = temp->prev;                          
    temp->prev->next = temp->next;                          
    itr.next();                                             
    delete temp;                                            
    return itr;                                             
}
void print(List &list) {                                                                     
    for(Iterator itr=list.begin(); itr.hasNext(); itr.next()) { 
        std::cout << itr.getData() << " ";                      
    }  
    std::cout << "\n";
}
void printRev(List &list) {                                 
    Iterator itr = list.rbegin();                           
    while(itr.hasPrev()) {                                  
        std::cout << itr.getData() << " ";                  
        itr.prev();                                         
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

    std::cout << "PUSH FRONT/BACK\n";
    push_front(list, 400);
    push_front(list, 200);  
    push_front(list, 100);
    push_back(list, 600);  
    push_back(list, 800); 
    push_back(list,1000);
    push_back(list,1200);                                                                                                                  
    print(list); 
    printRev(list);

    std::cout << "\nPOP FRONT/BACK\n";
    pop_front(list);
    pop_back(list);
    pop_back(list);
    print(list);
    printRev(list);    

    std::cout << "\nFRONT/BACK" << std::endl;
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;

    Iterator itr = list.begin();                              

    std::cout << "\nFIND/INSERT\n";
    itr = find(list, 200);
    insert(list, itr, 100);                                   
    itr = find(list, 400);
    insert(list, itr, 300);                                      
    itr = find(list, 800);
    insert(list, itr, 700);                                       
    print(list);
    printRev(list);    

    std::cout << "\nFIND/ERASE\n";   
    itr = find(list, 100);
    erase(list, itr);                                             
    itr = find(list, 300);
    erase(list, itr);                                         
    itr = find(list, 800);
    erase(list, itr);                                              
    print(list);
    printRev(list);                            

    std::cout << std::endl;
    return 0;
}



