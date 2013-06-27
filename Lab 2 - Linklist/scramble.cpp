#include <iostream>
#include <string>

using namespace std;
template<class Type>
class scramble{
private:
	struct node{
		Type data;
		node* next;
	};
	node* head;
	node* tail;
	int size;
	int rot;
	int shu;
public:
	scramble(){
		head=tail=NULL;
		size=0;
	}
	void insert(Type i){
		node *cp=new node();
		cp->data=i;
		cp->next=NULL;
		if(head!=NULL)
			tail->next=cp;
		else
			head=cp;
		tail=cp;
		size++;
	}
	void rotate(int n){
		/*while(n>=100){
		cout<<"Rotate percent :";
		cin>>n;
		}*/
		int no=(int)(n*size/100.0);
		rot=n;
		cout<<"R"<<no<<endl;
		node* head2=head;
		node* tail2=tail;
		tail=head;
		for(int i=1;i<no;i++,tail=tail->next);
		head=tail->next;
		tail2->next=head2;
		tail->next=NULL;
		print();
	}
	void rotate2(){
		rotate(100-rot);
		rot=0;
	}

	void shuffle(int n){
		/*while(n>=100){
		cout<<"Shuffle percent :";
		cin>>n;
		}*/
		int no=(int)(n*size/100.0);
		shu=no;
		cout<<"R"<<no<<endl;
		node *head2=head, *tail2=tail;
		for(int i=1;i<no;i++,head2=head2->next){}
		tail=head2;
		head2=head2->next;
		node *headTmp=head;
		node *tmp=head->next,*tmp2=head2->next;
		/*cout<<"H \t"<<head->data<<endl;
		cout<<"T \t"<<tail->data<<endl;
		cout<<"H2 \t"<<head2->data<<endl;
		cout<<"T2 \t"<<tail2->data<<endl;*/
		for(int i=1;(i<=size-no)&&(i<=no);i++){
			head->next=head2;
			if(head==tail){
				break;
			}
			head2->next=tmp;
			head=tmp;
			head2=tmp2;
			tmp=tmp->next;
			if(tmp2!=NULL)
				tmp2=tmp2->next;
		}

		if(n>50)
			tail->next=NULL;
		else
			tail=tail2;
		head=headTmp;
		print();
	}

	void shuffle2(){
		node *headtmp,*head2,*head2tmp;
		headtmp=head;
		head2=head->next;
		head2tmp=head2;
		for(int i=1;(i<size-shu)&&(i<shu);i++){
			head->next=head->next->next;
			head=head->next;
			head2->next=head2->next->next;
			head2=head2->next;
		}
		if(shu>size/2){
			head->next=head->next->next;
			head2->next=NULL;
			tail->next=head2tmp;
			tail=head2tmp;
		}
		else{
			head->next=head2tmp;
		}
		head=headtmp;
		shu=0;
		print();
	}
	void print(){
		cout<<"---------------------"<<endl;
		node* cursor=head;
		int i=1;
		while(cursor!=NULL){
			cout<<i<<"---> \t"<<cursor->data<<endl;
			cursor=cursor->next;
			i++;
		}


	}
};



int main(){
	scramble<string> s1;
	string input;
	int percent=0;
	while(cin>>input){
		s1.insert(input);
	}
	cin.clear();

	cout<<"ENCODE"<<endl;

	cout<<"Rotate percent : ";
	cin>>percent;
	s1.rotate(percent);
	cout<<"Shuffle percent : ";
	cin>>percent;
	s1.shuffle(percent);
	
	cout<<"DECODE"<<endl;
	s1.shuffle2();     
	s1.rotate2();
	
	return 0;
}