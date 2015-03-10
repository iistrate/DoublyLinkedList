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
	GENERATE_LIST,
	FIND_VALUE,
	GET_FROM_INDEX
};

int inputToInt(string message);

int main() {
	bool running = true;
	int uInput;
	bool reversed = false;
	int removed = -1;
	int console = -1;
	string error;

	List Doubly;

	while (running) {
		cout << "MENU: " << endl;
		/*
		 * Menu
		*/
		cout << "0- Quit\n1- Insert at beginning\n2- Insert at end\n3- Insert at index\n";
		cout << "4- Remove from beggining\n5- Remove from end\n6- Remove from index\n";
		cout << "7- Clear List\n8- Print list as entered\n9- Print list in reverse\n10- Generate list\n";
		cout << "11- Find Value\n12- Get Value at Index" << endl;

		cout << endl;
		cout << "List of size(" << Doubly.getCount() << ") is: ";
		Doubly.print(reversed);
		if (reversed) {
			cout << " in reverse";
		}
		cout << endl;
		if (removed != -1) {
			cout << "Last item removed " << removed << endl;
		}
		cout << "Last Error: " << error << endl;
		if (console != -1) {
			cout << "Console message: " << console << endl;
		}
		cout << endl;
		uInput = inputToInt("Enter option: ");
		switch (uInput) {
		case QUIT:
			running = false;
			break;
		case PUSH:
			Doubly.push(inputToInt("Enter number: "));
			break;
		case POP:
			try {
				removed = Doubly.pop();
			}
			catch (const char* err) {
				error = err;
			}
			break;
		case INSERT:
			Doubly.insert(inputToInt("Enter number: "));
			break;
		case DELETE:
			try {
				removed = Doubly.del();
			}
			catch (const char* err) {
				error = err;
			}
			break;
		case INSERT_AT_INDEX:
			try {
				Doubly.insertAtIndex(inputToInt("Enter data: "), inputToInt("Enter index: "));
			}
			catch (const char* err) {
				error = err;
			}
			break;
		case REMOVE_FROM_INDEX:
			try {
				removed = Doubly.removeFromIndex(inputToInt("Enter index: "));
			}
			catch (const char* err) {
				error = err;
			}
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
			try {
				Doubly.generateList(inputToInt("Enter list size: "), inputToInt("Enter min: "), inputToInt("Enter max: "));
			}
			catch (const char* err) {
				error = err;
			}
			break;
		case GET_FROM_INDEX:
			try {
				console = Doubly.getFromIndex(inputToInt("Enter index: "));
			}
			catch (const char* err) {
				error = err;
			}
			break;
		case FIND_VALUE:
			try {
				console = Doubly.findValue(inputToInt("Enter value: "));
			}
			catch (const char* err) {
				error = err;
			}
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