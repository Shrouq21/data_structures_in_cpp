#include<bits/stdc++.h>
using namespace std;
//A simple Node structure for a singly linked list

struct Node {
	int data{}; //value stored in the node
	Node* next{};   //pointer to the next node

	//constructor

	Node(int d) :data(d), next(nullptr) {}
};
class Linked_list
{
private:
	Node* head;
	Node* tail;
	int len;
public:
	Linked_list() :head(nullptr), tail(nullptr), len(0) {}
	void print() {
		Node* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << '\n';
	}

	// Insert node at the end

	void insert_end(int value) {
		Node* temp = new Node(value);
		if (!head)head = tail = temp;
		else {
			tail->next = temp;
			tail = temp;
		}
		len++;
	}

	// Get pointer to the nth node

	Node* get_nth(int idx) {
		assert(idx <= len && idx > 0);
		if (idx == 1)return head;
		if (idx == len)return tail;
		int i = 1;
		for (Node* curr = head; curr; curr = curr->next, i++) {
			if (i == idx)return curr;
		}
		return nullptr; //safety
	}

	//search for a value , return its index or -1

	int search(int value) {
		int idx = 1;
		for (Node* curr = head; curr; curr = curr->next, idx++) {
			if (curr->data == value)return idx;
		}
		return -1;
	}

	// Move-to-front optimization v0: swap found node with previous

	int search_improved_v0(int value) {
		int idx = 1;
		Node* prv = nullptr;
		for (Node* curr = head; curr; curr = curr->next, idx++) {
			if (curr->data == value) {
				if (idx == 1)return idx; //Already at front
				swap(prv->data, curr->data);  //Move to front
				return idx - 1;
			}
			prv = curr;
		}
		return -1;
	}

	// Move-to-front optimization v1: cleaner for loop verion

	int search_improved_v1(int value) {
		int idx = 1;
		for (Node* curr = head, *prv = nullptr; curr; prv = curr, curr = curr->next, idx++) {
			if (curr->data == value) {
				if (!prv)return idx;         //Already at front
				swap(prv->data, curr->data);  // Move to front
				return idx - 1;
			}
		}
		return -1;
	}

	// Return length for the list

	int getlength()const { return len; }

	// Destructor: free all nodes
	~Linked_list() {
		Node* curr = head;
		while (curr) {
			Node* next = curr->next;
			delete curr;
			curr = next;
		}
		head = tail = nullptr;
		cout << "Free Memory\n";
	}
};
void test1() {
	Linked_list list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	Node* t1 = list.get_nth(1);
	cout <<'\n' << t1->data << '\n';

	list.print();
	int idx = list.search(3);
	int idx1 = list.search_improved_v0(3); // Moves 3 one step closer to front
	int idx2 = list.search_improved_v0(3);  // one step closer again
	int idx3 = list.search(4);
	int idx4 = list.search_improved_v0(4);

	cout << idx << " " << idx1 << " " << idx2 << " " << idx3 << " " << idx4 << '\n';

	int idx5 = list.search(8);
	(idx5 != -1) ? cout << idx5 << '\n' : cout << "Not Existed\n";

	//print final list state

	list.print();
}
int main()
{
	test1();


}
