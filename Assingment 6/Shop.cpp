//============================================================================
// Name        : Shop.cpp
// Author      : Devesh Bhogre CSE-B 203242 B3
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class item
{
public:
	   int itm_cd,quant,cost;				//initialising data objects
       string itm_nam;
       void accept();            					//Member functions
       void display();
       void show();
       void add_btw();
       void remove_btw();
       void search(int n);
       //for sorting
       bool operator <(const item & iobj)const		//operator < overloading
       {
       	return itm_cd < iobj.itm_cd;
       }
       //for searching
       bool operator==(const item & iobj1)const    //operator == overloading
		{
       	return itm_cd==iobj1.itm_cd;
		}
};
item I;
list<item> l;
list<item> :: iterator it;

void item::accept()
{
	cout<<"\nEnter details of the item:\n";
	cout<<"Item code:";cin>>itm_cd;
	cout<<"Item name:";cin>>itm_nam;
	cout<<"Quantity :";cin>>quant;
	cout<<"Cost     :";cin>>cost;
}
void item::display()
{
	cout<<"\n---------------------------";
	cout<<"\nItem code:"<<itm_cd;
	cout<<"\nItem name:"<<itm_nam;
	cout<<"\nQuantity :"<<quant;
	cout<<"\nCost     :"<<cost;
}
void item::show()
{
	for(it=l.begin();it!=l.end();++it)
	{
		it -> display();
	}
}
void item::add_btw()
{
	int i,n;
	cout<<"\nEnter the position to add item in the list:";cin>>n;
	it=l.begin();
	for(i=0;i<n-1;i++)
	{
		it++;
	}
	I.accept();
	l.insert(it,I);
}
void item::remove_btw()
{
	int i,n;
	cout<<"\nEnter the position to remove item from the list:";cin>>n;
	it=l.begin();
	for(i=0;i<n-1;i++)
	{
		it++;
	}
	l.erase(it);
}
void item::search(int n)
{
	I.itm_cd=n;
	it=(find(l.begin(),l.end(),I));
	if(it!=l.end())
	{
		cout<<"\nItem found";
		I.display();
	}
	else
	{
		cout<<"/nItem doesn't Exist!!";
	}
}
int main()
{
int ch;
do
{
	cout<<"\n\nEnter choice to perform operation form the following";
	cout<<"\n 1.Add item in front";
	cout<<"\n 2.Add item in Back";
	cout<<"\n 3.Remove item from front";
	cout<<"\n 4.Remove item from back";
	cout<<"\n 5.Add item in Between";
	cout<<"\n 6.Remove item from Between";
	cout<<"\n 7.Sorting item";
	cout<<"\n 8.Search item";
	cout<<"\n 9.Show all item";
	cout<<"\n10.Quit";
	cout<<"\n\nChoice:";
	cin>>ch;
	switch(ch)
	{
	case 1:I.accept();
		   l.push_front(I);
		   I.show();
		   break;
	case 2:I.accept();
		   l.push_back(I);
		   I.show();
		   break;
	case 3:l.pop_front();
		   I.show();
		   break;
	case 4:l.pop_back();
		   I.show();
		   break;
	case 5:I.add_btw();
		   I.show();
		   break;
	case 6:I.remove_btw();
		   I.show();
		   break;
	case 7:l.sort();
		   I.show();
		   break;
	case 8:cout<<"\nEnter the item code to search item:";
			int n;cin>>n;
		   I.search(n);
		   break;
	case 9:I.show();
		   break;
	case 10:exit(0);
	default:cout<<"Please enter the correct choice!!!";
			break;
	}
}while(ch!=10);
return 0;
}

/*OUTPUT:
 *

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:11
Please enter the correct choice!!!

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:1

Enter details of the item:
Item code:1
Item name:Pen
Quantity :4
Cost     :5

---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:2

Enter details of the item:
Item code:2
Item name:Pencil
Quantity :6
Cost     :10

---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5
---------------------------
Item code:2
Item name:Pencil
Quantity :6
Cost     :10

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:1

Enter details of the item:
Item code:5
Item name:Book
Quantity :5
Cost     :20

---------------------------
Item code:5
Item name:Book
Quantity :5
Cost     :20
---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5
---------------------------
Item code:2
Item name:Pencil
Quantity :6
Cost     :10

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:3

---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5
---------------------------
Item code:2
Item name:Pencil
Quantity :6
Cost     :10

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:4

---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:1

Enter details of the item:
Item code:7
Item name:Tree
Quantity :10
Cost     :45

---------------------------
Item code:7
Item name:Tree
Quantity :10
Cost     :45
---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:2

Enter details of the item:
Item code:2
Item name:Book
Quantity :4
Cost     :70

---------------------------
Item code:7
Item name:Tree
Quantity :10
Cost     :45
---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5
---------------------------
Item code:2
Item name:Book
Quantity :4
Cost     :70

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:5

Enter the position to add item in the list:3

Enter details of the item:
Item code:3
Item name:Pencil
Quantity :4
Cost     :5

---------------------------
Item code:7
Item name:Tree
Quantity :10
Cost     :45
---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5
---------------------------
Item code:3
Item name:Pencil
Quantity :4
Cost     :5
---------------------------
Item code:2
Item name:Book
Quantity :4
Cost     :70

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:1

Enter details of the item:
Item code:10
Item name:Redgear
Quantity :7
Cost     :100

---------------------------
Item code:10
Item name:Redgear
Quantity :7
Cost     :100
---------------------------
Item code:7
Item name:Tree
Quantity :10
Cost     :45
---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5
---------------------------
Item code:3
Item name:Pencil
Quantity :4
Cost     :5
---------------------------
Item code:2
Item name:Book
Quantity :4
Cost     :70

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:6

Enter the position to remove item from the list:4

---------------------------
Item code:10
Item name:Redgear
Quantity :7
Cost     :100
---------------------------
Item code:7
Item name:Tree
Quantity :10
Cost     :45
---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5
---------------------------
Item code:2
Item name:Book
Quantity :4
Cost     :70

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:7

---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5
---------------------------
Item code:2
Item name:Book
Quantity :4
Cost     :70
---------------------------
Item code:7
Item name:Tree
Quantity :10
Cost     :45
---------------------------
Item code:10
Item name:Redgear
Quantity :7
Cost     :100

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:8

Enter the item code to search item:10

Item found
---------------------------
Item code:10
Item name:Redgear
Quantity :7
Cost     :100

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:9

---------------------------
Item code:1
Item name:Pen
Quantity :4
Cost     :5
---------------------------
Item code:2
Item name:Book
Quantity :4
Cost     :70
---------------------------
Item code:7
Item name:Tree
Quantity :10
Cost     :45
---------------------------
Item code:10
Item name:Redgear
Quantity :7
Cost     :100

Enter choice to perform operation form the following
 1.Add item in front
 2.Add item in Back
 3.Remove item from front
 4.Remove item from back
 5.Add item in Between
 6.Remove item from Between
 7.Sorting item
 8.Search item
 9.Show all item
10.Quit

Choice:10
 *
 */
