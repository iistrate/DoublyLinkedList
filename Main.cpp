#include <iostream>
#include <string>
#include "List.h"


using std::cin;
using std::string;

enum MENU {
	QUIT = 0,
	PUSH,
	INSERT,
	INSERT_AT_INDEX,
	DELETE,
	POP,
	REMOVE_FROM_INDEX,
	CLEAR_LIST,
	PRINT_NORMAL,
	PRINT_REVERSE,
	GENERATE_LIST
};

int inputToInt(void);

int main() {
	bool running = true;
	int uInput;
	bool reversed = false;

	List Doubly;

	while (running) {
		cout << "MENU: " << endl;
		/*
		 * Menu
		*/
		cout << "0- Quit\n1- Insert at beginning\n2- Insert at end\n3- Insert at index\n";
		cout << "4- Remove from beggining\n5- Remove from end\n6- Remove from index\n";
		cout << "7- Clear List\n8- Print list as entered\n9- Print list in reverse\n10- Generate list" << endl;

		cout << endl;
		cout << "List is: ";
		if (reversed) {
			Doubly.printReverse();
		}
		else {
			Doubly.print();
		}
		if (reversed) {
			cout << " in reverse";
		}
		cout << endl << endl;

		cout << "Enter option: ";
		uInput = inputToInt();
		switch (uInput) {
		case QUIT:
			running = false;
			break;
		case PUSH:
			cout << "Enter number: ";
			Doubly.push(inputToInt());
			break;
		case POP:
			Doubly.pop();
			break;
		case INSERT:
			cout << "Enter number: ";
			Doubly.insert(inputToInt());
			break;
		case DELETE:
			Doubly.del();
			break;
		case CLEAR_LIST:
			Doubly.clearList();
			break;
		case PRINT_NORMAL:
			reversed = false;
			break;
		case PRINT_REVERSE:
			reversed = true;
			break;
		case GENERATE_LIST:
			break;
		}
		system("cls");
	}
	return 0;
}
//get input from user and turn it into an integer
int inputToInt(void) {
	string s;
	cin >> s;
	return atoi(s.c_str());
}