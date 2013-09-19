#include <iostream>
#include <string>

using namespace std;

void possibleWord(string word){
	string tmp;
	for(int i=0;i<word.length();i++)
	{
		for(char ch='a';ch<='z';ch++)
		{
			tmp=word;
			tmp.at(i)=ch;
			cout<<tmp<<endl;
		}

	}

}


int main()
{
	string line;
	line="bird";
	possibleWord(line);


}