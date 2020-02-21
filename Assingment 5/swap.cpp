//============================================================================
// Name        : Assignment-5.cpp
// Author      : Devashish Bote(203235)
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
template <class T>
T swap(T*a, T*b)                            //Template function to swap two numbers using call by reference
{
	T temp=*a;
	*a=*b;
	*b=temp;
}

int main() {
	int x, y;
	cout<<"Enter the two numbers: "<<endl;
	cout<<"x: ";
	cin>>x;
	cout<<"y: ";
	cin>>y;
	swap(&x, &y);							//Function call
	cout<<"After the swapping the numbers are: "<<endl;
	cout<<"x="<<x<<endl;
	cout<<"y="<<y;
	return 0;
}


/* Inputs and Outputs:
 * Enter the two numbers:
x: 6
y: 2
After the swapping the numbers are:
x=2
y=6
*/
