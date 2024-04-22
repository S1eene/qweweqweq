#include <iostream>

class Flight {
    private:
    std::string airline;
    int time;
    public:

    Flight();
    Flight(std::string &a);
    Flight(const int &d);
    Flight(const int &d, std::string &a);
    const std::string getAirline();
    const int getTime();
    void changeTime(const int &d);
    void changeAirline(std::string &a);
    void print();
    ~Flight();

};

bool equivalent(Flight a, Flight b) {
    if (a.getTime() == b.getTime() && a.getAirline() == b.getAirline()) {
        return true;
    }
    return false;
}
bool compare(Flight a, Flight b, bool comparator) {
    if (comparator) {
        if (a.getTime() <= b.getTime()) {
            return true;
        }
    } else {
        if (a.getTime() > b.getTime()) {
            return false;
        }
    }
}