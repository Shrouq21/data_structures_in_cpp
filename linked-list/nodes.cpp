#include<bits/stdc++.h>
using namespace std;
//A simple Node structure for a singly linked list

struct Node {
int data; //value stored in the node
Node* next;   //pointer to the next node

//constructor
Node(int d):data(d),next(nullptr){} 
};

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


// access data of next nodes
cout << node->next->data << '\n';
cout << node->next->next->data << '\n';


//show pointer meaning
cout << "Memory address  the pointer points to: " << node << '\n';
cout<< "Address of the pointer itself: " << &node << '\n';

//free memory
//start from the last node
delete node2;
delete node1;
delete node;

}
