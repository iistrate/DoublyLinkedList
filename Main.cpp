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

int inputToInt(string message);

int main() {
	bool running = true;
	int uInput;
	bool reversed = false;
	int removed = -1;

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
		cout << "List of size(" << Doubly.getCount() << ") is: ";
		if (reversed) {
			Doubly.printReverse();
		}
		else {
			Doubly.print();
		}
		if (reversed) {
			cout << " in reverse";
		}
		cout << endl;
		if (removed != -1) {
			cout << "Last item removed " << removed << endl;
		}
		uInput = inputToInt("Enter option: ");
		switch (uInput) {
		case QUIT:
			running = false;
			break;
		case PUSH:
			Doubly.push(inputToInt("Enter number: "));
			break;
		case POP:
			removed = Doubly.pop();
			break;
		case INSERT:
			Doubly.insert(inputToInt("Enter number: "));
			break;
		case DELETE:
			removed = Doubly.del();
			break;
		case INSERT_AT_INDEX:
			Doubly.insertAtIndex(inputToInt("Enter data: "), inputToInt("Enter index: "));
			break;
		case REMOVE_FROM_INDEX:
			removed = Doubly.removeFromIndex(inputToInt("Enter index: "));
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
			Doubly.generateList(inputToInt("Enter list size: "), inputToInt("Enter min: "), inputToInt("Enter max: "));
			break;
		}
		system("cls");
	}
	return 0;
}
//get input from user and turn it into an integer
int inputToInt(string message) {
	cout << message;
	string s;
	cin >> s;
	return atoi(s.c_str());
}