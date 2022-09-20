#include<bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};

class Solution {
	private:
		Node *head, *tail;

	public:
		Solution() {
			this -> head = NULL;
		}

		void addNode(int data) {
			Node *node = new Node(data);
			if (head == NULL) {
				head = node;
				tail = node;
				return;
			} 
			tail -> next = node;
			tail = node;
		}

		void printIterative() {
			Node *ptr = head;
			cout << "Linked list: ";
			while (ptr) {
				cout << ptr -> data << " ";
				ptr = ptr -> next;
			}
			cout << endl;
		}

		void printRecursiveUtil(Node *ptr) {
			if (!ptr) return;
			printRecursiveUtil(ptr -> next);
			cout << ptr -> data << " ";
		}

		void printRecursive() {
			cout << "Linked list: ";
			printRecursiveUtil(head);
			cout << endl;
		}

};


int main() {
	Solution s;
	for (int i = 1; i <= 5; i ++) s.addNode(i);
	s.printIterative();
	s.printRecursive();
}
