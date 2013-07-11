#include <iostream>

using namespace std;

template<class T>
struct node
{
	T		i;
	node<T>	*next;
	node(int in){
		i=in;
	}
};

template<class T>
void createListWithNodeNo(node<T> *&head,node<T> *&tail,int i,int n){
	if(i!=n){
		node<int> *p;
		p=new node<int>(i);
		p->next=NULL;
		if(head==NULL)
			head=tail=p;
		else {
			tail->next=p;
			tail=p;
		}

		createListWithNodeNo(head, tail, i+1, n);
	}

}

template<class T>
void print(node<T> *&head){
	if(head!=NULL){
		cout<<head->i<<endl;
		print(head->next);
	}
}

template<class T>
void revPrint(node<T> *&pt){
	if(pt!=NULL){
		node<T> *cp=pt;
		revPrint(cp->next);
		cout<<cp->i<<endl;

	}
}



int main(){
	node<int> *h, *p, *t;
	h = t = NULL;
	createListWithNodeNo(h, t, 1, 5);
	cout << "print: ";cout << endl;
	print(h);
	cout << "\nrevPrint: "<<endl;
	revPrint(h);

}