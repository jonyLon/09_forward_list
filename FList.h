#pragma once
#include <iostream>
using namespace std;



template <typename T>
struct Node {
	T data;
	Node<T>* next;
	Node(const T& data, Node<T>* next = nullptr) : data{ data }, next{ next }
	{

	}
};

template <typename T>
class FList
{
public:
	FList() = default;
	~FList() {
		while (!isEmpty()) {
			removeHead();
		}
	}
	void print() const {
		auto* tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp->data << "\t";
			tmp = tmp->next;
		}
		cout << endl;
		cout << endl;
	};
	bool isEmpty() const {
		return head == nullptr;
	};
	void removeHead() {
		auto* tmp = head;
		head = head->next;
		if (isEmpty()) {
			tail = nullptr;
			return;
		}
		delete tmp;
		--size;
	}
	void addHead(const T& data) {
		Node<T>* tmp = new Node<T>(data, head);
		if (isEmpty())
		{
			tail = tmp;
		}
		head = tmp;
		++size;
	}
	void clear() {
		while (!isEmpty()) {
			removeHead();
		}
	}
	void addTail(const T& data) {
		Node<T>* tmp = new Node<T>(data);
		if (isEmpty())
		{
			head = tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tmp;
		}
		++size;
	}

	void operator+=(const FList& other) {
		auto* tmp = other.head;
		while (tmp != nullptr)
		{
			addTail(tmp->data);
			tmp = tmp->next;
		}
	}
	FList operator-(const FList& other) const{
		FList newList;
		T* items = new T[size];
		int counter = 0;
		auto* tmp = head;
		auto* ptr = other.head;
		while (tmp != nullptr)
		{
			items[counter++] = tmp->data;
			tmp = tmp->next;
		}
		while (ptr != nullptr)
		{
			for (size_t i = 0; i < counter; i++)
			{
				if (ptr->data == items[i]) {
					newList.addTail(items[i]);
					break;
				};
			}
			ptr = ptr->next;
		}

		return newList;
	}
	FList clone() const {
		FList newList;
		auto* tmp = head;
		while (tmp != nullptr)
		{
			newList.addTail(tmp->data);
			tmp = tmp->next;
		}
		return newList;
	}
	FList operator+(const FList& other) const {
		FList newList;
		auto* tmp = head;
		auto* ptr = other.head;
		while (tmp != nullptr)
		{
			newList.addTail(tmp->data);
			tmp = tmp->next;
		}
		while (ptr != nullptr)
		{
			newList.addTail(ptr->data);
			ptr = ptr->next;
		}
		return newList;
	}

	FList operator*(const FList& other) const {
		FList newList;
		auto* ptr = head;
		while (ptr != nullptr)
		{
			if (other.contains(ptr->data)) {
				newList.addTail(ptr->data);
			}
			ptr = ptr->next;
		}

		return newList;
	}
	
private:
	Node <T>* head = nullptr;
	Node <T>* tail = nullptr;
	size_t size = 0;
	bool contains(const T& data) const {
		auto* current = head;
		while (current != nullptr)
		{
			if (current->data == data) {
				return true;
			}
			current = current->next;
		}
		return false;
	}
};

