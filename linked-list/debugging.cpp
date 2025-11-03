#include<bits/stdc++.h>
using namespace std;
//A simple Node structure for a singly linked list

struct Node {
	int data{}; //value stored in the node
	Node* next{};   //pointer to the next node

//constructor

Node(int d):data(d),next(nullptr){}
~Node() {
	cout << "Destroy value: " << data << '\n' << "at address: " << this << '\n';
}
};
class Linked_list
{
private:
	Node* head;
	Node* tail;
	int len;
	vector<Node*>debug_data;
public:
Linked_list():head(nullptr),tail(nullptr),len(0){}
Linked_list(const Linked_list&) = delete;
Linked_list& operator=(const Linked_list& another) = delete;


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
	add_node(temp);
	if (!head)head = tail = temp;
	else {
		tail->next = temp;
		tail = temp;
	}
	
}

//Insert node at the beginning

void insert_front(int value) {
	Node* node = new Node(value);
	if (len == 0)head = tail = node;
	else
	{
		node->next = head;
		head = node;
	}
	add_node(node);
	debug_verify_data_integrity();
}

// Get pointer to the nth node

Node* get_nth(int idx) {
	assert(idx <= len && idx > 0);
	if (idx == 1)return head;
	if (idx == len )return tail;
	int i = 1;
	for (Node* curr = head; curr; curr = curr->next,i++) {
		if (i == idx)return curr;
	}
	return nullptr; //safety
}

//search for a value , return its index or -1

int search(int value) {
	int idx = 0;
	for (Node* curr = head; curr; curr = curr->next,idx++) {
		if (curr->data == value)return idx;
	}
	return -1;
}

// Move-to-front optimization v0: swap found node with previous

int search_improved_v0(int value) {
	int idx = 0;
	Node* prv = nullptr;
	for (Node* curr = head; curr; curr = curr->next, idx++) {
		if (curr->data == value) {
			if (!prv)return idx; //Already at front
				swap(prv->data, curr->data);  //Move to front
				return idx ;
		}
		prv = curr;
	}
	return -1;
}

// Move-to-front optimization v1: cleaner for loop verion

int search_improved_v1(int value) {
	int idx = 0;
	for (Node* curr = head, *prv = nullptr; curr; prv = curr, curr = curr->next, idx++) {
		if (curr->data == value) {
			if (!prv)return idx;         //Already at front
				swap(prv->data, curr->data);  // Move to front
				return idx ;
		}
	}
	return -1;
}

// Return length for the list

int getlength()const { return len; }



// delete operations

void delete_first() {
	if (!head) {
		cout << "It's deleted\n";
		return;
	}
	Node* curr = head;
	if (head == tail)head = tail = nullptr;
	else 
		head = head->next;
	delete_node(curr);
	debug_verify_data_integrity();
	
}
void delete_last() {
	if (len <= 1) {
		delete_first();
		return;
	}
	Node* curr = tail;
		Node* prv = get_nth(len - 1);
		prv->next = nullptr;
	delete_node(curr);
	tail = prv;
	debug_verify_data_integrity();
}
void delete_nth_node(int idx) {
	if (idx<=0 or idx>len) {
		cout << "Error. No such nth node\n";
		return;
	}
 if (idx == 1) {
		delete_first();
		return;
	}
	 if (idx == len ) {
		delete_last();
		return;
	}
		Node* prv = get_nth(idx-1);
		Node* curr = get_nth(idx);
		prv->next = curr->next;
		delete_node(curr);

		debug_verify_data_integrity();
}

// debugging

//verifies internal consistency of the list
void debug_verify_data_integrity() {
	if (len == 0) {
		assert(head == nullptr);
		assert(tail == nullptr);
		return;
}
	if (len == 1) {
		assert(head == tail);
		assert(tail->next == nullptr);
	}
	else {
		if (len == 2) 
			assert(head->next == tail);
		else if (len == 3) {
			assert(head->next->next == tail);
		}
		assert(head != tail);
	}
	int length = 0;
	Node* prev = nullptr;
	for (Node* curr = head; curr; curr = curr->next,length++) {
		assert(length < 10000);
		prev = curr;
	}
	assert(length == len);
	assert(prev == tail);
	assert(length == debug_data.size());
}
void debug_remove_node(Node* node) {
	auto it = find(debug_data.begin(), debug_data.end(), node);
	if (it == debug_data.end()) {
		cout << "No such a node\n";
	}
	else {
		debug_data.erase(it);

	}
}

void debug_print_node(Node* node) {
	if (node == nullptr) {
		cout << "nullptr\n";
		return;
	}
	if (node == head)cout << "head: " << node->data << " ";
	if (node->next)cout << node->next->data << " ";
	else
		cout << "X\n";
	if (node == tail)cout << "tail: " << node->next << '\n';
}

void debug_print_list() {
	for (int i = 0; i < debug_data.size(); i++) {
		debug_print_node(debug_data[i]);
	}
}

void debug_add_node(Node* node) { debug_data.push_back(node); }

string to_string() {
	ostringstream oss;
	for (Node* curr = head; curr; curr = curr->next) {
		oss << curr->data;
		if (curr->next)oss << " ";
	}
	return oss.str();
}
// Node tracking helpers
void add_node(Node* node) {
	debug_add_node(node);
	len++;
}

void delete_node(Node* node) {
	debug_remove_node(node);
	len--;
	delete node;
}




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
void Test2() {

	Linked_list list;

list.insert_front(2);
list.insert_front(3);
list.insert_front(4);
list.insert_front(5);
list.print();
list.delete_last();
list.print();
list.delete_first();
list.print();
cout<<list.to_string()<<'\n';
}
int main()
{
//	test1();
	Test2();


}
