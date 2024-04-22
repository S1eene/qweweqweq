#ifndef NODE_H
#define NODE_H
class Node {
private:
	Node *next;
	Node *prev;
	int data;
public:
	friend class Iterator;
	friend class List;
	Node() : data(0), prev(nullptr), next(nullptr) {};
	Node(const int &input): data(input), prev(nullptr), next(nullptr) {};
	int &number() { return data; }
	Node* getprev() { return prev; }
	Node* getnext() { return next; }
	void mutate(const int &a);
	void print();
	~Node();
};

#endif