#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <random>
#include <string>

using std::cout;
using std::endl;
using std::string;

//list containing nodes
class List {
private:
	class Node {
	private:
		Node* m_Next;
		Node* m_Prev;
		int m_data;
	public:
		Node(void):m_data(0), m_Next(0), m_Prev(0) {}
		Node(int data):m_data(data), m_Next(0), m_Prev(0) {}

		Node* getNext(void) {
			return m_Next;
		}
		Node* getPrev(void) {
			return m_Prev;
		}
		int getData(void) {
			return m_data;
		}

		void setNext(Node* node) {
			m_Next = node;
		}
		void setPrev(Node* node) {
			m_Prev = node;
		}
		void setData(int data) {
			m_data = data;
		}
	};

	Node* m_Head;
	Node* m_Tail;
	int m_count;
	string m_consoleMessage;
public:
	List(void):m_Head(0), m_Tail(0), m_count(0) {}

	//print list
	void print(void) {
		if (m_count == 0) {
			cout << "<empty>";
			return;
		}
		cout << "H ";
		Node* navigator = m_Head;
		while (navigator != 0) {
			cout << navigator->getData() << " ";
			navigator = navigator->getNext();
		}
		cout << "E";
	}
	//print list in reverse
	void printReverse(void) {
		if (m_count == 0) {
			cout << "<empty>";
			return;
		}
		cout << "H ";
		Node* navigator = m_Tail;
		while (navigator != 0) {
			cout << navigator->getData() << " ";
			navigator = navigator->getPrev();
		}
		cout << "E";
	}

	//remove from end and return data
	int pop(void) {
		Node* temp = m_Tail;
		delete m_Tail;
		m_count--;
		return temp->getData();
	}
	//remove from head and return data
	int del(void) {
		Node* temp = m_Head;
		m_Head = m_Head->getNext();
		m_count--;
		return temp->getData();
	}
	//remove from index and return data
	int removeFromIndex(int index) {
		Node* navigator = m_Head;
		int counter = 0;
		while (navigator != 0) {
			if (counter == index) {
				Node* temp = navigator;
				temp->getPrev()->setNext(temp->getNext());
				temp->getNext()->setPrev(temp->getPrev());
				m_count--;
				return temp->getData();
			}
			navigator = navigator->getNext();
			counter++;
		}
	}

	//add at start of list
	void push(int data) {
		Node* node = new Node(data);
		if (m_count == 0) {
			m_Head = node;
			m_Tail = m_Head;
		}
		else if (m_count == 1) {
			m_Tail = m_Head;
			m_Head = node;
			m_Head->setNext(m_Tail);
			m_Tail->setPrev(m_Head);
		}
		else {
			Node* temp = m_Head;
			m_Head = node;
			m_Head->setNext(temp);
			temp->setPrev(m_Head);
		}
		m_count++;
	}
	//add at end of list
	void insert(int i) {
		Node* node = new Node(i);
		if (m_count == 0) {
			m_Head = node;
			m_Tail = m_Head;
		}
		else if (m_count == 1) {
			m_Tail = node;
			m_Head->setNext(m_Tail);
			m_Tail->setPrev(m_Head);
		}
		else {
			Node* temp = m_Tail;
			m_Tail = node;
			temp->setNext(m_Tail);
			m_Tail->setPrev(temp);
		}
		m_count++;
	}
	//insert data at index
	void insertAtIndex(int d, int i) {
		if (i > m_count || i < 0) {
			cout << "Index value not right" << endl;
			return;
		}
		//if index given is 0 or 1 re use methods
		if (i == 0 || i == 1) {
			insert(d);
			return;
		}
		Node* newNode = new Node(d);
		Node* navigator = m_Head;
		int counter = 0;
		while (navigator != 0) {
			if (counter == i) {
				Node* temp = navigator;
				Node* prev = navigator->getPrev();
				prev->setNext(newNode);
				newNode->setPrev(prev);
				navigator = newNode;
				newNode->setNext(temp);
				temp->setPrev(newNode);
			}
			navigator = navigator->getNext();
			counter++;
		}
		m_count++;
	}

	//get count
	int getCount(void) {
		return m_count;
	}
	//delete all content of list
	void clearList(void) {
		Node* navigator = m_Head;
		while (navigator != 0) {
			Node* temp = navigator->getNext();
			delete navigator;
			navigator = temp;
			m_count--;
		}
	}
	//generate list
	void generateList(int size, int min = 0, int max = 9999) {
		if (min > max) {
			m_consoleMessage = "Min can't be bigger than max";
			return;
		}
		//setup dice roll
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(min, max);
		//clear current list
		clearList();
		for (int i = 0; i < size; i++) {
			//roll dice
			insert(distribution(generator));
		}
	}
	string getConsoleMessage(void) {
		return m_consoleMessage;
	}
};

#endif //list.h