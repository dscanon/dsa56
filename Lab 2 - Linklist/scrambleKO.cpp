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
	int rotateNumber;
	int shuffleNumber;
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
			head=cp; // กรณีที่เพิ่มข้อมูลตัวแรก
		tail=cp;
		size++;
	}
	void rotate(int n){
		while(n>=100){//ในกรณีที่ใส่เลขมาเกิน 100 ให้รับค่าใหม่
			cout<<"Enter New Rotate Percent :";
			cin>>n;
		}
		int position=(int)(n*size/100.0);//คำนวณหาว่า % ที่ได้มาคือตัวที่เท่าไร
		rotateNumber=position;//เก็บค่าไว้เพื่อการ"ตัดกลับ""
		node* head2=head;
		node* tail2=tail;
		tail=head;
		for(int i=1;i<position;i++,tail=tail->next);
		head=tail->next;
		tail2->next=head2;
		tail->next=NULL;
		print();
	}
	void rotate2(){
		int position=size-rotateNumber;// ตัดกลับด้วย สัดส่วนตรงกันข้ามกับตอนตัดมา เช่น ตัด 40 ตัดกลับด้วย 60,ตัด 70 ตัดกลับด้วย 30
		node* head2=head;
		node* tail2=tail;
		tail=head;
		for(int i=1;i<position;i++,tail=tail->next);
		head=tail->next;
		tail2->next=head2;
		tail->next=NULL;
		print();

	}

	void shuffle(int n){
		while(n>=100){//ในกรณีที่ใส่เลขมาเกิน 100 ให้รับค่าใหม่
			cout<<"Enter New Shuffle Percent :";
			cin>>n;
		}
		int position=(int)(n*size/100.0);
		shuffleNumber=position;

		//วนลูปเพื่อให้ pointer ไปชี้อยู่ในตำแหน่งที่ต้องการ
		node *head2=head, *tail2=tail;
		for(int i=1;i<position;i++,head2=head2->next){}
		tail=head2;
		head2=head2->next;

		//เตรียมการสลับ
		node *headTmp=head; //สร้าง pointer มาชี้ตัวแรกไว้ ไม่ให้หาย
		node *tmp=head->next,*tmp2=head2->next; // ใช้ tmp ชี้ล่วงหน้า เพราะถ้าใช้ head->link=xxx แล้ว จะทำให้ชี้ตัวถัดไปไม่ถูก เช่นว่า ปกติ 1->2 แต่ถ้าสั่งให้ 1->5 แล้วเราจะเอา pointer ไปชี้ที่ 2 อีกไม่ได้
		for(int i=1;(i<=size-position)&&(i<=position);i++){
			head->next=head2;//ย้ายตัวชี้ครึ่งบน
			if(head==tail){
				break;
			}
			head2->next=tmp;//ย้ายตัวชี้ครึ่งล่าง
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
		for(int i=1;(i<size-shuffleNumber)&&(i<shuffleNumber);i++){
			head->next=head->next->next;
			head=head->next;
			head2->next=head2->next->next;
			head2=head2->next;
		}
		if(shuffleNumber>size/2){
			head->next=head->next->next;
			head2->next=NULL;
			tail->next=head2tmp;
			tail=head2tmp;
		}
		else{
			head->next=head2tmp;
		}
		head=headtmp;
		shuffleNumber=0;
		tail=head;
		while(tail->next!=NULL){tail=tail->next;}
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