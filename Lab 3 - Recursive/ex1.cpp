#include <iostream>
using namespace std;
template<typename T>
void initArrWithInd(T* a,int i,int lastIndex){
	if(i!=lastIndex){
		a[i]=i;
		initArrWithInd(a,i+1,lastIndex);
	}


}


template<typename T>
void print(T *a,int i,int lastIndex){
	if(i!=lastIndex){
		cout<<a[i]<<endl;
		print(a,i+1,lastIndex);

	}

}

template<typename T>
void revPrint(T *a,int i,int lastIndex){
	if(i!=lastIndex){
		cout<<a[lastIndex-++i]<<endl;
		revPrint(a,i,lastIndex);
	}

}


int main() {
	int no[10];
	initArrWithInd(no,0,10);
	print(no,0,10);
	cout<<"_________________"<<endl;
	revPrint(no,0,10);
	return 0;
}