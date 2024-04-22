#include <iostream>

class Math {
private:
    int num;
public:
    Math(): num(1) {}
    static int floor(double d);                 // static keyword required for declarations
    static int ceil(double d);  
    static int add(Math &m1, Math &m2);                            
};

int Math::floor(double d) {                     // static keyword NOT required for definitions
    return static_cast<int>(d);
} 
int Math::ceil(double d) {
    return static_cast<int>(d) + 1;
}  
int Math::add(Math &m1, Math &m2) {
    return m1.num + m2.num;
}   

int main() {
    std::cout << std::endl;

    std::cout << Math::floor(5.35) << "\n";     // static functions do not require an object to exist, therefore they can be called by the classname                      
    std::cout << Math::ceil(5.35) << "\n"; 

    Math m1, m2;

    std::cout << Math::add(m1, m2) << "\n";     // static functions can have instances of the class as parameters
    
    std::cout << std::endl;
    return 0;
}