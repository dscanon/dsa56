#include <iostream>
using namespace std;
template<class Type>
struct node<Type>
{
	Type i;
	node *next;
};

int main() {
	node<int> *h, *p, *t;
	h = t = new node<int>(1);
	for(int i=2; i<=4; i++){//creat list
		p = new node<int>(i);
		t->next = p;
		t = p;
	}
	/*
	h = t = NULL;
	createListWithNodeNo(h, t, 1, 5);
	*/
	cout << endl; cout << "print: ";
	print(h);
	cout << "\nrevPrint: ";
	revPrint(h);
	return 0;
}