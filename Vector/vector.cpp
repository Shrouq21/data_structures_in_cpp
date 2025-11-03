#include<bits/stdc++.h>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
class Vector {
private:
	int size{};
	int capacity = 1;
	int* arr{ nullptr };
public:
	Vector(){
		size = 0;
		capacity = 2;
		arr = new int[capacity];
	}
	Vector(int s) :size(s)
	{
		capacity = 2 * size;
		arr = new int[capacity];
	}
	void expand_capacity() {
		capacity *= 2;
		int* arr1 = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			arr1[i] = arr[i];
		}
		swap(arr, arr1);
		delete[]arr1;
		arr1 = nullptr;
	}
	void push_back(int val) {
		if (size == capacity)expand_capacity();
		arr[size++] = val;
	}
	void insert(int index, int val) {
		if (size == capacity)expand_capacity();
		for (int i = size - 1; i >= index; i--) {
			arr[i + 1] = arr[i];
		}
		arr[index] = val;
	}
	void pop_back() {
		if (size > 0)size--;
	}
	void print() {
		for (int i = 0; i < size; i++)cout << arr[i] << " ";
		cout << endl;
	}
	int back() {
		assert(size > 0);
		return arr[size - 1];
	}
	int front()
	{
		assert(size > 0);
		return arr[0];
	}
	int get_size() {
		return size;
	}
	void clear() {
		size = 0;
		capacity = 1;
		delete[]arr;
		arr = nullptr;
	}
	int at(int index) {
		assert(index >= 0 && index < size);
		return arr[index];
	}
	int find(int val)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == val)return i;
		}
		return -1;
	}
	~Vector() {
		delete[]arr;
		arr = nullptr;
	}
};
int main()
{
	vector<int>c;
	Vector v;
	for (int i = 0; i < 5; i++)v.push_back(i);
	v.print();
	v.at(1);
	cout << v.find(9) << endl;
}
