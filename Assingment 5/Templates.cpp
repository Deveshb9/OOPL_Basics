//============================================================================
// Name        : Templates.cpp
// Author      : Devesh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#define MAX 5
#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class stack
{
	public:
			int top;
			T itm[MAX],data;
			stack();
			void push();
			void pop();
			void display();
};
template <class T>
stack<T>::stack()
{
	int i;
	top=-1;
	for(i=0;i<MAX;i++)
	{
		itm[i]="";
	}
}
template <class T>
void stack<T>::push()
{
	if(top==MAX-1)
	{
		cout<<"\nStack is full!!";
	}
	else
	{
		top++;
		cout<<"\nEnter data in stack:";
		cin>>data;
		itm[top]=data;
	}
}
template <class T>
void stack<T>::pop()
{
	if(top==-1)
	{
		cout<<"\nStack is empty!!!";
	}
	else
	{
		data=itm[top];
		itm[top]="";
		top--;
		cout<<"\n\nThe item deleted is:"<<data;
	}
}
template <class T>
void stack<T>::display()
{
	cout<<"\n-----------------------------------------------";
	cout<<"\nDisplaying the stack:\n";
	int i;
	for(i=top;i>=0;i--)
		cout<<itm[i]<<endl;
}
int main()
{
	stack <string> S;
	char c='y';
	int j;
	do
	{
	cout<<"\n-----------------------------------------------";
	cout<<"\nEnter choice to perform operation:";
	cout<<"\n1.Push      ";
	cout<<"\n2.Pop       ";
	cout<<"\n3.Show Stack";
	cout<<"\n4.Exit      ";
	cout<<"\nChoice:";
	cin>>j;
	switch(j)
	{
	case 1:S.push();
	       S.display();
	       break;
	case 2:S.pop();
	       S.display();
	       break;
	case 3:S.display();
		   break;
	case 4:exit(0);
	default:cout<<"\nWrong input inserted!!!";
	}
	}while(c=='y');
	return 0;
}

/*OUTPUT:
-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:1

Enter data in stack:Devesh

-----------------------------------------------
Displaying the stack:
Devesh

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:1

Enter data in stack:Devasish

-----------------------------------------------
Displaying the stack:
Devasish
Devesh

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:1

Enter data in stack:Gaurav

-----------------------------------------------
Displaying the stack:
Gaurav
Devasish
Devesh

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:1

Enter data in stack:Balaji

-----------------------------------------------
Displaying the stack:
Balaji
Gaurav
Devasish
Devesh

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:1

Enter data in stack:bote

-----------------------------------------------
Displaying the stack:
bote
Balaji
Gaurav
Devasish
Devesh

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:1

Stack is full!!
-----------------------------------------------
Displaying the stack:
bote
Balaji
Gaurav
Devasish
Devesh

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:2


The item deleted is:bote
-----------------------------------------------
Displaying the stack:
Balaji
Gaurav
Devasish
Devesh

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:2


The item deleted is:Balaji
-----------------------------------------------
Displaying the stack:
Gaurav
Devasish
Devesh

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:2


The item deleted is:Gaurav
-----------------------------------------------
Displaying the stack:
Devasish
Devesh

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:2


The item deleted is:Devasish
-----------------------------------------------
Displaying the stack:
Devesh

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:2


The item deleted is:Devesh
-----------------------------------------------
Displaying the stack:

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:2

Stack is empty!!!
-----------------------------------------------
Displaying the stack:

-----------------------------------------------
Enter choice to perform operation:
1.Push
2.Pop
3.Show Stack
4.Exit
Choice:4
*/

