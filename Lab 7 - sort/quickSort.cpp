#include <iostream>
#include <fstream>


using namespace std;

void printA(int* a, int size){
	cout<<"array"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void qSort(int*,int,int);

int main ()
{
	const int size =100000;
	int a[size];
	int line;
	int no=0;
	ifstream infile;
	infile.open("rnd.txt");
	while(!infile.eof())
	{
		infile>>line;
		a[no++]=line;
	}
	qSort(a,0,size-1);
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<"\t";
		if(i%10==0)
			cout<<endl;
	}

}

void qSort(int* a,int left, int right)
{
	if(left<right)
	{
		int pivot=a[left];
		int i=left+1,j=right;
//		cout<<"PIVOT : "<<pivot<<" / "<<left<<" / "<<right<<endl;
		while(i<j){
//			cout<<pivot<<"/"<<i<<"/"<<j<<endl;
//			cout<<"Left cursor ";
			while(a[i]<pivot)
			{
//				cout<<a[i]<<" ";
				i++;
			}
//			cout<<endl<<"right cursor ";
			while(a[j]>pivot)
			{
//				cout<<a[j]<<" ";
				j--;
			}
			if(i<j)
			{
//				cout<<a[i]<<" > "<<a[j]<<endl;
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
			else
			{
				break;
			}
//			printA(a,10);
			i++;
			j--;
//			cin.get();
//			cout<<endl<<endl;
		}
//		cout<<"----------------------"<<endl;
		int tmp=a[j];
		a[j]=a[left];
		a[left]=tmp;
//		printA(a,10);
		qSort(a,left,j-1);
		qSort(a,j+1,right);
	}
}
