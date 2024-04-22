#include <iostream>

struct Thing {
    int num;
    Thing(): num(0) {}
    Thing(int n): num(n) {}
};
void print(Thing *t, int size) 
{
    for(int i=0; i<size; ++i) { std::cout << t[i].num << " ";}
    std::cout << "\n";
}
bool compare(const Thing &t1, const Thing &t2, bool comparator) 
{
    if(comparator == true) {
        return t1.num <= t2.num;
    } else  {
        return t1.num > t2.num;
    }
}
void sort(Thing *t, int size, bool comparator)                  // insertion sort with a boolean comparator to determine order
{         
    Thing v;
    int index;                         
    for(int i=1; i<size; ++i) {           
        v = t[i];                         
        index = i;                        

        while(index>0 && compare(v, t[index-1], comparator)) {  // if v < t[index-1] and comparator true OR v > t[index-1] and comparator false
            t[index] = t[index-1];        
            --index;                      
        }
        t[index] = v;                     
    }
}

int main() {
    std::cout << std::endl;

    const int size = 10;
    Thing a[size];

    a[0] = Thing(20);
    a[1] = Thing(30);
    a[2] = Thing(10);
    a[3] = Thing(50);
    a[4] = Thing(25);
    a[5] = Thing(5);   
    a[6] = Thing(45);
    a[7] = Thing(23);
    a[8] = Thing(15);
    a[9] = Thing(32);

    std::cout << "Original\n";
    print(a, size);

    std::cout << "\nSort small to large:\n";
    sort(a, size, true); 
    print(a, size);

    std::cout << "\nSort large to small:\n"; 
    sort(a, size, false); 
    print(a, size);    

    std::cout << std::endl; 
    return 0;

}