//============================================================================
// Name        : Employee.cpp
// Author      : Devesh Bhogre 203242 CSE-B B3 OOPL
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Employee
{
	double empid,incom,age;
	string city,name;
	char citve;
	public:
			Employee();
			Employee(double,double,double,string,char,string);
			void display();
};
Employee::Employee()
{
	empid=incom=age=0;
	name=city="Nil";
	citve='n';
}
Employee::Employee(double e,double i,double a,string n,char c,string c1)
{
	empid=e;
	incom=i;
	age=a;
	name=n;
	citve=c;
	city=c1;
}
void Employee::display()
{
	cout<<"The details of Employee are:";
	cout<<"\nName        :"<<name;
	cout<<"\nEmployee ID :"<<empid;
	cout<<"\nAge         :"<<age;
	cout<<"\nIncome      :"<<incom;
	cout<<"\nCity        :"<<city;
	cout<<"\n4-w Vehicle :"<<citve;
}
int main() {
	int cnt=0,n=1;
	double age,incom,empid;
	string name,city;
	char citve;
	do
	{
	try
	{
		cnt=0;
		cout<<"\n\nEnter the details of Employee:";
		cout<<"\nName        :";cin>>name;
		cout<<"Employee ID :";cin>>empid;
		cout<<"Age         :";cin>>age;
		if(age>=18 && age<=55)
		{cnt++;n=0;}
		else
		  throw(age);
		cout<<"Income      :";cin>>incom;
		if(incom>=50000 && incom<=100000)
		{cnt++;n=0;}
		else
		  throw(incom);
		cout<<"City        :";cin>>city;
		if(city=="Pune"||city=="Mumbai"||city=="Banglore"||city=="Chennai")
		{cnt++;n=0;}
		else
		  throw(city);
		cout<<"4-w Vehicle :";cin>>citve;
		if(citve=='y')
		{cnt++;n=0;}
		else
		  throw(citve);
	}
	catch(double a){n=1;cout<<"Exception Error in age!!!\n";}
	catch(double b){n=1;cout<<"Exception Error in Income!!!\n";}
	catch(string &c){n=1;cout<<"Exception Error in City!!!\n";}
	catch(char c1){n=1;cout<<"Exception Error in Vehicle type!!!\n";}
	}while(n==1);
	if(cnt==4)
	{
		Employee E(empid,incom,age,name,citve,city);
		E.display();
	}
}


/*OUTPUT:
 *

Enter the details of Employee:
Name        :Devesh
Employee ID :203242
Age         :17
Exception Error in age!!!


Enter the details of Employee:
Name        :Devesh
Employee ID :203242
Age         :18
Income      :40000
Exception Error in age!!!


Enter the details of Employee:
Name        :Devesh
Employee ID :203242
Age         :18
Income      :60000
City        :Surat
Exception Error in City!!!


Enter the details of Employee:
Name        :Devesh
Employee ID :203242
Age         :18
Income      :60000
City        :Pune
4-w Vehicle :n
Exception Error in Vehicle type!!!


Enter the details of Employee:
Name        :Devesh
Employee ID :203242
Age         :18
Income      :60000
City        :Pune
4-w Vehicle :y

The details of Employee are:
Name        :Devesh
Employee ID :203242
Age         :18
Income      :60000
City        :Pune
4-w Vehicle :y
 */
