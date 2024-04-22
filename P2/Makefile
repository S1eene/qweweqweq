prog: driver.o Node.o Iterator.o List.o
	g++ -std=c++17 -o prog driver.o Node.o Iterator.o List.o

Node.o: Node.h
	g++ -std=c++17 -c Node.cpp

Iterator.o: Iterator.h Node.h
	g++ -std=c++17 -c Iterator.cpp

List.o: List.h Iterator.h Node.h
	g++ -std=c++17 -c List.cpp

driver.o: List.h Iterator.h Node.h
	g++ -std=c++17 -c driver.cpp

clean:
	rm driver.o Node.o Iterator.o List.o
	rm prog