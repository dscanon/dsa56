#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <time.h> 
#include <math.h>

using namespace std; clock_t start, stop, elapsed;

void bbSort(int* a,int size)
{
	bool swaped=true;
	cout<<"%";
	for(int i=0;(i<size-1)&&swaped;i++)
	{
		swaped=false;
		if(i%1000==0)
		{
			cout<<"-";
		}
		for(int j=0;j<size-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				swaped=true;
			}
		}
	}
	cout<<endl;
}

void ssSort(int* a,int size)
{
	int n,j,m=0;
	for(int i=0;i<size;i++)
	{
		m=0;
		n=a[m];
		for(int j=0;j<size-i;j++)
		{
			if(n<a[j]){
				n=a[j];
				m=j;
			}

		}
		int tmp=a[size-1-i];
		a[size-1-i]=a[m];
		a[m]=tmp;
	}
}

void isSort(int* a,int size)
{
	for(int i=1;i<size;i++)
	{
		int n=a[i];
	//find pos
		int insertPos=i;
		for(int k=0;k<size;k++)
		{
			if(n<=a[k])
			{
				insertPos=k;
				break;
			}
		}
	//insert
		for(int j=i;j>insertPos;j--)
		{
			a[j]=a[j-1];
		}
		a[insertPos]=n;
	//finish
	}
}


void merge(int numbers[], int tmp[], int left, int left_end, int right, int right_end)
{
	int i, num_elements, tmp_pos;
	tmp_pos = left;
	num_elements = right_end - left + 1;

	//merge sort
	while ((left <= left_end) && (right <= right_end))
	{
		if (numbers[left] <= numbers[right])
			tmp[tmp_pos++] = numbers[left++];
		else
			tmp[tmp_pos++] = numbers[right++];
		
	}

	// append left
	while (left <= left_end)
	{
		tmp[tmp_pos++] = numbers[left++];
	}

	// append right
	while (right <= right_end)
	{
		tmp[tmp_pos++] = numbers[right++];
	}

	//copy to use array
	for (i=0; i <= num_elements; i++)
	{
		numbers[right_end] = tmp[right_end--];
	}
}

void m_sort(int a[], int tmp[], int left, int right) 
{
	int mid;

	if (left < right)
	{
		mid = (right + left) / 2;
		m_sort(a, tmp, left, mid);
		m_sort(a, tmp, mid+1, right);

		merge(a, tmp, left, mid, mid+1, right);
	}
}


void mSort(int numbers[], int tmp[], int size) 
{
	m_sort(numbers, tmp, 0, size - 1);
}

void qSort(int* a, int left, int right) 
{
	if(right-left>=1)
	{
		int pivot=a[left];
		int i=left+1,j=right;
		do
		{
			while(a[i]<pivot)
			{
				i++;
			}
			while(a[j]>pivot)
			{
				j--;
			}
			if(i<j)
			{
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}while(i<j);
		int tmp=a[j];
		a[j]=a[left];
		a[left]=tmp;
		qSort(a,left,j-1);
		qSort(a,j+1,right);
	}
}

int main(){ const int size=100000; //	const int size=1000;
	int a[size];
	int c[size];
	ifstream infile; infile.open("rnd.txt"); //	infile.open("rnd1000.txt");
	int no=0;
	int fs=0; //--------------------
	while(!infile.eof()){
		infile>>a[no++];
		fs++;
	//cout<<a[no-1]<<endl;
	}
	infile.close();
	cout<<"+++++++++++++++++++++++"<<endl;

	int b[10]={4,2,9,6,1,8,0,3,5,7};

	start = clock();
	qSort(a,0,size-1);
	//bbSort(a,size); 
	//ssSort(a,size);	
	//isSort(a,size);
	//mSort(a,c,size);	
	stop = clock();
	elapsed = 1000 * (stop - start) / (CLOCKS_PER_SEC);

	cout<<"PRINT:"<<fs<<endl;

	//for(int i=0;i<10;i++)cout<<b[i]<<" ";

/*	for(int i=0;i<size;i++){
		cout<<a[i]<<"\t";
		if(i%6==0){
			cout<<endl;
		}
	}
*/
	cout<<endl<<"TIME:"<<elapsed<<endl;
//	cout<<"size : "<<fs<<endl;
	return 0;
}
