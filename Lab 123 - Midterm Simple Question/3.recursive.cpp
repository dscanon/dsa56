#include <iostream>

using namespace std;
int sum(int *arr,int i,int end){
	if(i!=end)
		return arr[i]+sum(arr,i+1,end);
	return 0;
}
int max(int *arr,int i,int end){
	if(i!=end)
		return arr[i]>=max(arr,i+1,end)?arr[i]:max(arr,i+1,end);
}

int main(){
	int a[]={4,5,2,9,7};
	int b[]={10,50,30};
	cout<<"sum a = "<<sum(a,0,5)<<endl; 
	cout<<"sum b = "<<sum(b,0,3)<<endl; 
	cout<<"max a = "<<max(a,0,5)<<endl; 
	cout<<"max b = "<<max(b,0,3)<<endl;
}