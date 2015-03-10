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
public:
	List(void):m_Head(0), m_Tail(0), m_count(0) {}

	//print list regular or reversed
	void print(bool reversed);

	//get count
	int getCount(void) {
		return m_count;
	}

	//remove from end and return data
	int pop(void) {
		if (getCount() == 0) {
			throw "Can't delete what does not exist.";
		}
		Node* temp = m_Tail;
		delete m_Tail;
		m_count--;
		return temp->getData();
	}
	//remove from head and return data
	int del(void) {
		if (getCount() == 0) {
			throw "Can't delete what does not exist.";
		}
		Node* temp = m_Head;
		m_Head = m_Head->getNext();
		m_count--;
		return temp->getData();
	}
	//remove from index and return data
	int removeFromIndex(int index);

	//add at start of list
	void push(int data);
	//add at end of list
	void insert(int i);
	//insert data at index
	void insertAtIndex(int data, int index);

	//get object from index
	int getFromIndex(int index);
	//find by value and return index
	int findValue(int data);

	//delete all content of list
	void clearList(void);
	//generate list
	void generateList(int size, int min = 0, int max = 9999);
};

#endif //list.h