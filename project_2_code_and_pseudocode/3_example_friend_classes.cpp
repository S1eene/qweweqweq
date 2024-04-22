#include <iostream>

class Person {
private:
    int age;
public:
    Person(): age(10) {}
    friend class School;                                    // class School has access to the private area of Person
};

class School {
public:
    School() {}
    void func(Person &p) { std::cout << p.age << "\n"; }    // School member function has direct access to Person objects private area
};

int main() {
    std::cout << std::endl;

    Person p;
    School s;

    s.func(p);                                               // School member function can print Persons private information  

    std::cout << std::endl;
    return 0;
}