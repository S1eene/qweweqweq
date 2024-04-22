#include <iostream>
#include "Node.h"
#include "Iterator.h"
#include "List.h"
int main() {
    
	std::cout << std::endl;

    List list; 

    std::cout << "PUSH FRONT/BACK\n";
    list.push_front(400);
    list.push_front(200);  
    list.push_front(100);
    list.push_back(600);  
    list.push_back(800); 
    list.push_back(1000);
    list.push_back(1200);                                                                                                                  
    list.print(); 
    list.printRev();

    std::cout << "\nPOP FRONT/BACK\n";
    list.pop_front();
    list.pop_back();
    list.pop_back();
    list.print();
    list.printRev();    

    std::cout << "\nFRONT/BACK" << std::endl;
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;

    Iterator itr = list.begin();                              

    std::cout << "\nFIND/INSERT\n";
    itr = list.find(200);
    list.insert(itr, 100);                                   
    itr = list.find(400);
    list.insert(itr, 300);                                      
    itr = list.find(800);
    list.insert(itr, 700);                                       
    list.print();
    list.printRev();    

    std::cout << "\nFIND/ERASE\n";   
    //itr = list.find(100);
    //list.erase(itr);                                             
    itr = list.find(300);
    list.erase(itr);                                         
    itr = list.find(800);
    list.erase(itr);                                              
    list.print();
    list.printRev();                            

    std::cout << std::endl;
    return 0;
	
	

	return 0;
}