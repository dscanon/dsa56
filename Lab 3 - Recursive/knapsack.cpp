#include <iostream>
using namespace std;

int list[]={0,0,0,0,0};
void sack(int *price,int money,int start,int end,int sum,int n){
	if(sum<money){
		for(int i=start;i<end;i++){
			list[n]=price[i];
			sack(price,money,i+1,end,sum+price[i],n+1);
		}
	}
	else if(sum==20){
		for(int i=0;i<5;i++){
			if(list[i]==0)break;
			cout<<list[i]<<",";
		}
		cout<<endl;
	}
	else{
		list[n]=0;
	}


}


int main(){
	int b[]={20,10,5,5,3,2,20,10};
	sack(b,20,0,8,0,0);
	cin.get();


}