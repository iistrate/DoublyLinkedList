#include <iostream>
#include <string>
#include "List.h"


using std::cin;
using std::string;

enum MENU {
	QUIT = 0,
	INSERT,
	PUSH,
	INSERT_AT_INDEX,
	DELETE,
	POP,
	REMOVE_FROM_INDEX
};

int inputToInt(void);

int main() {
	bool running = true;
	int uInput;

	List Doubly;

	while (running) {
		cout << "List is: ";
		Doubly.print();
		cout << endl;
		cout << "0- Quit\n1- Insert at beginning\n2- Insert at end\n3- Insert at index\n4- Remove from beggining\n5- Remove from end\n6- Remove from index" << endl;
		cout << "Enter option: ";
		uInput = inputToInt();

		switch (uInput) {
		case QUIT:
			running = false;
			break;
		case INSERT:
			cout << "Enter number: ";
			int nr = inputToInt();
			Doubly.insert(nr);
			break;
		}
		system("cls");
	}
	return 0;
}

int inputToInt(void) {
	string s;
	cin >> s;
	return atoi(s.c_str());
}