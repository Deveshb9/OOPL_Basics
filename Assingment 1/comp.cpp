//============================================================================
// Name        : Complex.cpp
// Author      : Devesh Bhogre CSE-B 203242 Batch B3
// Version     : 3
// Copyright   : Your copyright notice
// Description : Operation in Complex no. in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Complex
{
public:
			float a,b; // a=real part b=imaginary part
			Complex(); // default constructor
			Complex(int c,int d); //parameterised constructor
			//void acc();             //to accept the complex no.
			//void disp();            //to display the complex no.
			Complex operator +(Complex C1);
			Complex operator -(Complex C1);
			Complex operator *(Complex C1);
			Complex operator /(Complex C1);
			friend ostream&  operator <<(ostream&,Complex&);
			friend istream&  operator >>(istream&,Complex&);
};
Complex::Complex()
{
	a=0;
	b=0;
}
Complex::Complex(int c,int d)
{
	a=c;
	b=d;
}
istream& operator >>(istream &in,Complex &C)          //operator overloading to accept the value
{
	    cout<<"Enter complex no.";
		cout<<"\nEnter real part=";
		in>>C.a;
		cout<<"Enter imaginary part=";
		in>>C.b;
		return (in);
}
ostream& operator <<(ostream &out,Complex &C)        //
{

		if(C.b<0)
		{
		 cout<<"The complex no. is=";
		 out<<C.a<<C.b;
		 cout<<"i"<<endl;
		}
		else
		{
		  cout<<"The complex no. is=";
		  out<<C.a;
		  cout<<"+";
		  out<<C.b;
		  cout<<"i"<<endl;
	    }
		return(out);
}
/*void Complex::acc()
{

	cout<<"Enter complex no.";
	cout<<"\nEnter real part=";
	cin>>a;
	cout<<"Enter imaginary part=";
	cin>>b;
}
void Complex::disp()
{
	if(b<0)
	  cout<<"The complex no. is="<<a<<b<<"i"<<endl;
	else
	  cout<<"The complex no. is="<<a<<"+"<<b<<"i"<<endl;
}*/
Complex Complex::operator+(Complex C1) //Addition Function
{
    Complex C;
	C.a=C1.a+a;
	C.b=C1.b+b;
	return C;
}
Complex Complex::operator-(Complex C1)  //Subtraction Function
{
	Complex C;
	C.a=C1.a-a;
	C.b=C1.b-b;
	return C;
}
Complex Complex::operator*(Complex C1)//Multiplication Function
{
	Complex C;
	C.a=a*C1.a-b*C1.b;
	C.b=a*C1.b+b*C1.a;
	return C;
}
Complex Complex::operator/(Complex C1) // Division Function
{
	Complex C;
	C.a=(a*C1.a-b*C1.b)/(C1.a*C1.a-C1.b*C1.b);
	C.b=(a*C1.b+b*C1.a)/(C1.a*C1.a-C1.b*C1.b);
	return C;
}
int main()
{
	Complex C1,C2,C3;
	int n,ch;
	cin>>C1>>C2;//C1.acc();
	//C2=Complex(3,5); //Parameterized constructor call explicitly
	cout<<C1<<C2;//C1.disp();;//C2.disp();
	do               // do while loop for multiple operation
	{
	 n=2;
	cout<<"Which operation would you perform:";
	cout<<"\n1.Addition";
	cout<<"\n2.Subtraction";
	cout<<"\n3.Multiplication";
	cout<<"\n4.Division";
	cout<<"\nEnter choice:";
	cin>>ch;
	switch(ch)        //Switch case for menu drawn Calculator
	{
	case 1:C3=C1+C2;
	       cout<<C3;//C3.disp();
	 	    break;
	case 2:C3=C1-C2;
	       cout<<C3;//C3.disp();
			break;
	case 3:C3=C1*C2;
	       cout<<C3;//C3.disp();
			break;
	case 4:C3=C1/C2;
	       cout<<C3;//C3.disp();
			break;
	default:cout<<"Wrong no. input!!!\n";
	}
	cout<<"Do you want to perform more operation(y/n):";
	char ch1;
	cin>>ch1;
	if(ch1=='n')
	{n=1;}
	}while(n!=1);
	return 0;
}

/*OUTPUT:
Enter complex no.
Enter real part=1
Enter imaginary part=3
Enter complex no.
Enter real part=5
Enter imaginary part=7
The complex no. is=1+3i
The complex no. is=5+7i
Which operation would you perform:
1.Addition
2.Subtraction
3.Multiplication
4.Division
Enter choice:1
The complex no. is=6+10i
Do you want to perform more operation(y/n):y
Which operation would you perform:
1.Addition
2.Subtraction
3.Multiplication
4.Division
Enter choice:2
The complex no. is=4+4i
Do you want to perform more operation(y/n):y
Which operation would you perform:
1.Addition
2.Subtraction
3.Multiplication
4.Division
Enter choice:3
The complex no. is=-16+22i
Do you want to perform more operation(y/n):y
Which operation would you perform:
1.Addition
2.Subtraction
3.Multiplication
4.Division
Enter choice:4
The complex no. is=0.666667-0.916667i
Do you want to perform more operation(y/n):n
 */

