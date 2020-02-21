//============================================================================
// Name        : file.cpp
// Author      : Devesh Bhogre CSE-B 203242 B3
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream fin,fout;
	string ch;
	fin.open("info.txt",ios::in);
	fout.open("copy.txt",ios::out);
	if(!fin.is_open())
	{
		cout<<"Cannot open file";
	}
	else
	{
		cout<<"Copied data is:\n";
		while(!fin.eof())
		{
		  getline(fin,ch);
		  fout<<ch<<endl;
		  cout<<ch<<endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}
