#include<bits/stdc++.h>
using namespace std;
//A simple Node structure for a singly linked list

struct Node {
	int data{}; //value stored in the node
	Node* next{};   //pointer to the next node

//constructor

Node(int d):data(d),next(nullptr){} 
};
class Linked_list
{
private:
	Node* head;
	Node* tail;
	int len;
public:
Linked_list():head(nullptr),tail(nullptr),len(0){}
void insert_end(int value) {
	Node* temp = new Node(value);
	if (!head)head = tail = temp;
	else {
		tail->next = temp;
		tail = temp;
	}
	len++;
}
int getlenght()const { return len; }
};
int main()
{
Linked_list list;

list.insert_end(4);
list.insert_end(5);
list.insert_end(6);
cout << list.getlenght() << '\n';


}
