//============================================================================
// Name        : Item.cpp
// Author      : Devesh Bhogre CSE-B 203242 B3
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

class Item
{
  public:
		 double itm_cd,cost,quant;
		 string itm_nam;
		 void accept();
		 void display();
		 void search(double);
};
void Item::accept()
{
	cout<<"Enter the details of Item:\n";
	cout<<"Name      :";cin>>itm_nam;
	cout<<"Code      :";cin>>itm_cd;
	cout<<"Quantity  :";cin>>quant;
	cout<<"Cost/item :";cin>>cost;
}
void Item::display()
{
	cout<<"The details of Item:\n";
	cout<<"Name      :"<<itm_nam;
	cout<<"\nCode      :"<<itm_cd;
	cout<<"\nQuantity  :"<<quant;
	cout<<"\nCost/item :"<<cost;
}
void Item::search(double n)
{
	if(itm_cd==n)
		display();
	else
		cout<<"\nItem not found!!!";
}
int main()
{
	fstream fin,fout;
	double n;
	Item I[2];
	fout.open("items.dat",ios::binary|ios::app);
	for(int i=0;i<2;i++)
	{
		cout<<"\nItem no."<<i+1<<":"<<endl;
		I[i].accept();
		fout.write((char*)&I[i],sizeof(I[i]));
	}
	fout.close();
	fin.open("item.dat",ios::binary|ios::in);
	for(int i=0;i<2;i++)
	{
		fin.read((char*)&I[i],sizeof(I[i]));
		cout<<"\n\nItem no."<<i+1<<":"<<endl;
		I[i].display();
	}
	cout<<"\nEnter the item code to search for item:\n";
	cin>>n;
	for(int i=0;i<2;i++)
	{
		I[i].search(n);
	}
	fin.close();
	return 0;
}
