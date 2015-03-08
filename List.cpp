#include "List.h"

void List::print(bool reversed) {
	if (m_count == 0) {
		cout << "<empty>";
		return;
	}
	cout << "H ";
	Node* navigator = reversed == false ? m_Head : m_Tail;
	while (navigator != 0) {
		cout << navigator->getData() << " ";
		navigator = reversed == false ? navigator->getNext() : navigator->getPrev();
	}
	cout << "E";
}

int List::removeFromIndex(int index) {
	if (index > getCount()) {
		throw "Index does not exist.";
	}
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

void List::push(int data) {
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
void List::insert(int i) {
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

void List::insertAtIndex(int data, int index) {
	if (index > getCount()) {
		throw "Index does not exist.";
	}
	if (index > m_count || index < 0) {
		cout << "Index value not right" << endl;
		return;
	}
	//if index is 0 or last reuse functions
	if (index == 0) {
		push(data);
		return;
	}
	else if (index == m_count) {
		insert(data);
		return;
	}

	Node* newNode = new Node(data);
	Node* navigator = m_Head;
	int counter = 0;
	while (navigator != 0) {
		if (counter == index) {
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

void List::clearList(void) {
	Node* navigator = m_Head;
	while (navigator != 0) {
		Node* temp = navigator->getNext();
		delete navigator;
		navigator = temp;
		m_count--;
	}
}

void List::generateList(int size, int min, int max) {
	if (min > max) {
		throw "Min can't be bigger than max";
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