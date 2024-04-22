#include <iostream>
#include "Node.h"

Node::~Node(){ delete prev; delete next;};
void Node::print() {std::cout << data << " ";}
void Node::mutate(const int &a) {data = a;}