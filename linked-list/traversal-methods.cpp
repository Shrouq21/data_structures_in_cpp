#include<bits/stdc++.h>
using namespace std;
//A simple Node structure for a singly linked list

struct Node {
int data; //value stored in the node
Node* next;   //pointer to the next node

//constructor

Node(int d):data(d),next(nullptr){} 
};


//print all nodes starting from 'node'

void print(Node* node) {
	while (node) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << '\n';
}

//Recursive printing (normal order)

void Recursive(Node* node) {
	if (!node) {
		cout << '\n';
		return;
	}
	cout << node->data << " ";
	Recursive(node->next);
}

// Recursive printing (reverse order)

void Reversed(Node* node) {
	if (!node) {
		return;
	}
	Reversed(node->next);
	cout << node->data << " ";
}

//Iterative printing (alternative to while loop)

void Iterative(Node* node) {
	for (Node* curr = node; curr; curr = curr->next) {
		cout << curr->data<<" ";
		cout << '\n';
}

}
int main()
{
//create individual nodes
Node* node = new Node(3);
Node* node1 = new Node(2);
Node* node2 = new Node(5);

//link nodes together 3 -> 2 -> 5
node->next = node1;
node1->next = node2;
node2->next = nullptr;


// print list
print(node);
Recursive(node);
Reversed(node);
cout << '\n';
Iterative(node);

//free memory
//start from the last node
delete node2;
delete node1;
delete node;

}
