#include <iostream>
#include "flight.h"
/*
Flight::Flight() 
Flight::Flight(std::string &a)
Flight::Flight(const int &d)
Flight::Flight(const int &d, std::string &a)
*/
Flight::const std::string getAirline() {return airline;}
Flight::const int getTime() {return time;}
Flight::void changeTime(const int &d) {time = d;}
Flight::void changeAirline(std::string &a) {airline = a;}
Flight::void print() {std::cout << airline << " " << time <<std::endl;}
Flight::~Flight()