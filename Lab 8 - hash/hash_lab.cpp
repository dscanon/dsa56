#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int hash(string,int);
bool isPrime(int);
int newTBSize(int);

struct node
{
	string data;
	node* next;
	node()
	{
		data="";
		next=NULL;
	}
	node(string input){
		data=input;
		next=NULL;
	}
};

class SpellChecker
{
private:
	
	node* table;
public:
	int collide;
	int colision;
	int expansion;
	int count;
	double loadFactor;
	int size;

	SpellChecker()
	{
		colision=0;
		expansion=0;
		loadFactor=0;
		count=0;
		collide=0;
		size=7001;
		table=new node[size];
	}

	void add(string word)
	{
		int index=hash(word,size);
//		cout<<index<<" > "<<word<<endl;
		if(table[index].data!="")
		{
			//cout<<expansion<<":colision"<<" : "<<table[index].data<<"\t";
			node* ptr=table+index;
			int colCount=0;
			collide++;
			while(ptr->next!=NULL)
			{
				//cout<<ptr->data<<"  ";
				colCount++;

				ptr=ptr->next;
			}
			if(colCount>colision)
				cout<<word<<" C : "<<colCount<<endl;
			colision=colCount>colision?colCount:colision;

			ptr->next=new node(word);
			//cout<<ptr->next->data<<"/"<<endl;
		}
		else
		{
			table[index]=word;
		}
		count++;
		loadFactor=(double)count/size;
		if(loadFactor>0.5)
		{
			reHash();
		}
	}

	void reHash()
	{
		int newSize=newTBSize(size*2);
		node* newTable=new node[newSize];
		//swap array
		node* tmp=table;
		table=newTable;
		newTable=tmp;
		//swap size
		int oldSize=size;
		size=newSize;
		newSize=oldSize;
		//REHASH
		expansion++;
		loadFactor=0;
		count=0;
		for(int i=0;i<newSize;i++)
		{
			if(newTable[i].data!="")
			{
				if(newTable[i].next!=NULL)
				{
					node* ptr=newTable+i;
					while(ptr->next!=NULL)
					{
						add(ptr->data);
						ptr=ptr->next;
					}
					add(ptr->data);
				}
				else
				{
					add(newTable[i].data);
				}
			}
		}
		//release allocate memory
		delete[] newTable;
	}
	bool hashSearch(string word){
		int key=hash(word,size);
		node* ptr=table+key;
		if(ptr->data!=word)
		{
			while(ptr!=NULL)
			{
				if(ptr->data==word)
				{
					return true;
				}
				ptr=ptr->next;
			}
			return false;
		}
		else
			return true;
	}
	void possibleWord(string word)
	{
		string tmp;
		cout<<"Possible correction are :";
		for(int i=0;i<word.length();i++)
		{
			for(char ch='a';ch<='z';ch++)
			{
				tmp=word;
				tmp.at(i)=ch;
				if(hashSearch(tmp))
				{
					cout<<" "<<tmp;
				}
			}
		}
		cout<<endl;

	}
};

int main()
{
	const int size=7001; //prime number
	int numbers=0;
	string line;
	SpellChecker book;
	ifstream infile;
	infile.open("full.txt");
	while(!infile.eof())
	{
		infile>>line;
		book.add(line);
		numbers++;
	}
	infile.close();
	infile.open("full.txt");
	//add word finish
	cout<<"---------------"<<endl;
	cout<<"colison : "<<book.colision<<endl;
	cout<<"expansion : "<<book.expansion<<endl;
	cout<<"count : "<<book.count<<endl;
	cout<<"loadFactor : "<<book.loadFactor<<endl;
	cout<<"size : "<<book.size<<endl;
	cout<<"collide : "<<book.collide<<endl;
	cout<<"---------------"<<endl;




	//---
	cout<<"Enter your word : ";
	while(cin>>line)
	{
		cout<<"\""<<line<<"\" is ";
		if(book.hashSearch(line))
		{
			cout<<"correctly spelled"<<endl;
		}else
		{
			cout<<"not in the dictionary"<<endl;
			book.possibleWord(line);
		}
		cout<<endl<<"Enter your word : ";
	}

}

int hash(string key,int tbSize)
{
	int hashVal=0;
	for(int i=0;i<key.length();i++)
	{
		hashVal=37*hashVal+key.at(i);
	}
	hashVal%=tbSize;
	if(hashVal < 0)
		hashVal+=tbSize;
	return hashVal;
}

bool isPrime(int n)
{
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
			count++;
		if(count>2)
			return false;
	}
	if(count==2)
		return true;
	else
		return false;
}

int newTBSize(int i)
{
	while(!isPrime(i))
		i++;
	return i;
}