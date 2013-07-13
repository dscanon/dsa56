#include <iostream>

using namespace std;
template<class T, int MAX=20> 
class stack{ 
	T item[MAX]; 
	int top; 
public: 
	stack():top(-1){} 
	void push(const T& i){if(top<MAX-1) item[++top] = i;} 
	T pop(){if(top!=-1) return item[top--];} 
	void print(){ 
		for(int i=0;i<=top;i++) 
			cout<<item[i]<<" "; 
		cout<<"\n"; 
	} 
	void addItem(stack sec,stack &to){
		to.top=-1;
		for(int i=0;i<MAX;i++){
			if((i<=top)&&(i<=sec.top)){
				to.push(item[i]+sec.item[i]);
			}else 
			if(top<sec.top){
				to.push(sec.item[i]);
			}else if(sec.top<top){
				to.push(item[i]);
			}
		}
		to.top=top>sec.top?top:sec.top;
	}
}; 

int main(){
	//---- Stack : addItem --- 
	cout<<"----addItem---\n"; 
	stack<int,10> s1,s2,s3,s4; // สแตกของ int ขนาด10
	for(int i=0; i<5; i++) 
		s1.push(i); 
	cout<<"s1: "; s1.print();
	for(int i=0; i<7; i++) 
		s2.push(i); 
	cout<<"s2: "; s2.print();
	cout<<"s3: "; s3.print(); 
	cout<<"s4: "; s4.print(); 
	s1.addItem(s2,s3); cout<<"s1.addItem(s2,s3); s3: "; s3.print();
	s4.addItem(s1,s3); cout<<"s4.addItem(s1,s3); s3: "; s3.print();
	s4.addItem(s4,s3); cout<<"s4.addItem(s4,s3); s3: "; s3.print();
	s2.addItem(s2,s3); cout<<"s2.addItem(s2,s3); s3: "; s3.print();

}
