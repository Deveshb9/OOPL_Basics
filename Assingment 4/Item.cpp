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
		 int itm_cd,cost,quant;
		 string itm_nam;
		 void add_itm();
		 void accept();
		 void display();
		 void display_itm();
		 void search();
		 void delete_itm();
};
void Item::accept()
{
	cout<<"\nEnter the details of Item:\n";
	cout<<"Name      :";cin>>itm_nam;
	cout<<"Code      :";cin>>itm_cd;
	cout<<"Quantity  :";cin>>quant;
	cout<<"Cost/item :";cin>>cost;
}
void Item::display()
{
	cout<<"\nThe details of Item:\n";
	cout<<"Name      :"<<itm_nam;
	cout<<"\nCode      :"<<itm_cd;
	cout<<"\nQuantity  :"<<quant;
	cout<<"\nCost/item :"<<cost;
}
void Item::add_itm()
{
	int i,n;
	ofstream fout;
	cout<<"\nEnter the number of items to be inserted:";
	cin>>n;
	Item I;
	fout.open("item.dat",ios::binary|ios::out);
	for(i=0;i<n;i++)
	{
		I.accept();
		fout.write((char*)&I,sizeof(I));
	}
	fout.close();
}
void Item::display_itm()
{
	ifstream fin;
	Item I;
	fin.open("item.dat",ios::binary|ios::in);
	fin.read((char*)&I,sizeof(I));
	while(!fin.eof())
	{
		I.display();
		fin.read((char*)&I,sizeof(I));
	}
	fin.close();
}
void Item::search()
{
	int num,q;
	int f=0;
	cout<<"\n\nEnter item code to search for an item:";
	cin>>num;
	ifstream fin;
	Item I;
	fin.open("item.dat",ios::in|ios::binary);
	while(fin)
	{
		fin.read((char*)&I,sizeof(I));
		if(num==I.itm_cd)
		{
			I.display();
			f=0;
			break;
		}
		else
			f=1;
	}
	if(f==1)
	{
		cout<<"\nItem not found!!\n";
	}
	else
	{
		cout<<"\nEnter the quantity you want:";
		cin>>q;
		if(q<=I.quant)
		{
			cout<<"\nTotal cost of the item:"<<I.quant*I.cost;
		}
		else
		{
			cout<<"\nQuantity entered is not in stock!!";
		}
	}
	fin.close();
}
void Item::delete_itm()
{
	int num;
	cout<<"\n\nEnter item code to delete that item:";
	cin>>num;
	Item I;
	fstream fin,fout;
	fin.open("item.dat",ios::in|ios::binary);
	fout.open("temp.dat",ios::out|ios::binary);
	while(!fin.eof())
	{
		fin.read((char*)&I,sizeof(I));
		if(num!=I.itm_cd)
		{
			fout.write((char*)&I,sizeof(I));
		}
	}
	rename("temp.dat","item.dat");
	fin.close();
	fout.close();
}
int main()
{
	Item i;
	i.add_itm();
	i.display_itm();
	//i.search();
	i.delete_itm();
	i.display_itm();
	return 0;
}
/*OUTPUT:

Enter the number of items to be inserted:5

Enter the details of Item:
Name      :Pen
Code      :1
Quantity  :5
Cost/item :5

Enter the details of Item:
Name      :Pencil
Code      :2
Quantity  :4
Cost/item :10

Enter the details of Item:
Name      :Book
Code      :3
Quantity  :6
Cost/item :20

Enter the details of Item:
Name      :Ereaser
Code      :4
Quantity  :5
Cost/item :10

Enter the details of Item:
Name      :tail
Code      :2
Quantity  :10
Cost/item :20

The details of Item:
Name      :Pen
Code      :1
Quantity  :5
Cost/item :5
The details of Item:
Name      :Pencil
Code      :2
Quantity  :4
Cost/item :10
The details of Item:
Name      :Book
Code      :3
Quantity  :6
Cost/item :20
The details of Item:
Name      :Ereaser
Code      :4
Quantity  :5
Cost/item :10
The details of Item:
Name      :tail
Code      :2
Quantity  :10
Cost/item :20

Enter item code to search for an item:4

The details of Item:
Name      :Ereaser
Code      :4
Quantity  :5
Cost/item :10
Enter the quantity you want:3

Total cost of the item:30
*/
