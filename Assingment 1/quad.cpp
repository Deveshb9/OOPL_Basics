//============================================================================
// Name        : quad.cpp
// Author      : Devesh
// Version     :
// Copyright   : Your copyright notice
// Description :Quadratic equation in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

class quad
{
public:
	    int a,b,c;
	    float x,r,s1,s2; //x is value of x,R result after input x, s1,s2 roots
	    quad();
	    quad(int d,int e,int f,float y,float t,float p1,float p2);
	    void acc();
	    void disp();
	    void add(quad Q1);
	    void sub(quad Q1);
	    void cal1();  //to calculate the value of quadratic eq. for x=?
	    void cal2();  //to calculate the roots
};
quad::quad()
{a=b=c=x=r=s1=s2=0;}
quad::quad(int d,int e,int f,float y,float t,float p1,float p2)
{a=d;b=e;c=f;x=y;r=t;s1=p1;s2=p2;}
void quad::acc()
{

	cout<<"For quadratic equation ax^2+bx+c enter the values of a,b,c:";
	cout<<"\na:";cin>>a;
	cout<<"b:";cin>>b;
	cout<<"c:";cin>>c;
}
void quad::disp()
{
	cout<<"The quadratic equation is:";
	if(b>0&&c>0)
	  cout<<a<<"x^2+"<<b<<"x+"<<c;
	else if(b<0&&c>0)
		cout<<a<<"x^2"<<b<<"x+"<<c;
	else if(b>0&&c<0)
		cout<<a<<"x^2+"<<b<<"x"<<c;
	else
		cout<<a<<"x^2"<<b<<"x"<<c;
}
void quad::add(quad Q1)
{
	a=a+Q1.a;
	c=c+Q1.b;
	c=c+Q1.c;
}
void quad::sub(quad Q1)
{
	a=a-Q1.a;
	c=c-Q1.b;
	c=c-Q1.c;
}
void quad::cal1()
{
	cout<<"Enter x to calculate value of quadratic equation:";
	cin>>x;
	r=(a*x*x)+(b*x)+c;
	cout<<"\nResult for x="<<x<<" is:"<<r;
}
void quad::cal2()
{
	s1=(-b+sqrt((b*b)-(4*a*c)))/(2*a);
	s2=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
	cout<<"\nRoots of the equation are:";
	cout<<"\nroot 1="<<s1;
	cout<<"\nroot 2="<<s2;
}
int main() {
	quad Q1,Q2;
	int n,ch;
	do               // do while loop for multiple operation
	{
	 n=2;
	cout<<"\nWhich operation would you perform:";
	cout<<"\n1.Find value by putting x";
	cout<<"\n2.Find roots";
	cout<<"\n3.Addition of 2 quadratic eq.";
	cout<<"\n4.Subtraction of 2 quadratic eq.";
	cout<<"\nEnter choice:";
	cin>>ch;
	switch(ch)        //Switch case for menu drawn
	{
	case 1: Q1.acc();
			Q1.cal1();
	 	    break;
	case 2: Q1.acc();
			Q1.cal2();
			break;
	case 3: Q1.acc();
	        Q2.acc();
	        Q2.add(Q1);
	        Q2.disp();
	        break;
	case 4: Q1.acc();
		    Q2.acc();
		    Q2.sub(Q1);
		    Q2.disp();
		    break;
	default:cout<<"Wrong no. input!!!\n";
	}
	cout<<"\n\nDo you want to perform more operation(y/n):";
	char ch1;
	cin>>ch1;
	if(ch1=='n')
	{n=1;}
	}while(n!=1);
	return 0;
}
