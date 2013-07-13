#include <iostream>

using namespace std;
template<class t>
struct node
{
	t data;
	node *next;
	node(t in){
		data=in;
		next=NULL;
	}
};

template<class t>
void addNewNode(node<t>* &h,t *arr,int size){
	h=new node<t>(arr[0]);
	node<t> *p=h;
	for(int i=1;i<size;i++){
		p->next=new node<t>(arr[i]);
		p=p->next;
	}
}

template<class t>
void print(node<t> *head){
	if(head!=NULL){
		cout<<head->data<<"  ";
		print(head->next);
	}
}

node<int>* merge(node<int> *h1,node<int> *h2){
	int size=0;
	for(node<int> *cp=h1;cp!=NULL;cp=cp->next,size++);
	for(node<int> *cp=h2;cp!=NULL;cp=cp->next,size--);
	node<int> *h11,*h22,*h3=h1;
	if(size>=0){
		h11=h1;
		h22=h2;
	}else{
		h11=h2;
		h22=h1;
	}
	node<int> *h11n=h11->next,*h22n=h22->next;
	while(h11!=NULL){
		if(h22!=NULL){
			if(((h11->data)<(h22->data))){
				if((h11n->data)>(h22->data)){
					h11->next=h22;
					if(h11n->data<h22n->data)
						h22->next=h11n;

					h22=h22n;
					if(h22!=NULL)
						h22n=h22->next;
					if(h22->next==NULL){
						if(h22->data<h11n->data){
							h22->next=h11n;
						}
					}
					if(h22!=NULL)
						h22n=h22->next;
					
				}


			}
			
		}
		h11=h11n;
		if(h11!=NULL)
			h11n=h11->next;
	}
	return h1;

}

int main(){
	cout << "--- create & print list ------\n"; 
	int a1[] = {1,3,5,6,9,10};
	int a2[] = {2,4,7,8};
	node<int> *h1,*h2;
	addNewNode<int>(h1,a1,sizeof(a1)/sizeof(a1[0]));
	addNewNode<int>(h2,a2,sizeof(a2)/sizeof(a2[0]));
	print<int>(h1);cout<<endl;
	print<int>(h2);cout<<endl;

	cout << "--- merge list ------\n"; 
	node<int> *h3;
	cout<<"h1 = "; print(h1); cout<<endl;
	cout<<"h2 = "; print(h2); cout<<endl;
	h3 = merge(h1,h2); cout<<"merging:h1+h2=h3\n"; 
	cout<<"h3 = "; print(h3); cout<<endl;
	cout<<"h1 = "; print(h1); cout<<endl;
	cout<<"h2 = "; print(h2); cout<<endl;
}