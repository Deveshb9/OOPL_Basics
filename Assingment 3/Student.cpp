//============================================================================
// Name        : Student.cpp
// Author      : Devesh Bhogre 203242 CSE-B B3 OOPL
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Student
{
	double rollno,fee,age,year;
	string stat,name,div;
	public:
			Student();
			Student(double,double,double,double,string,string,string);
			void display();
};
Student::Student()
{
	year=rollno=fee=age=0;
	div=name=stat="Nil";
}
Student::Student(double y,double e,double i,double a,string n,string c1,string d)
{
	year=y;
	rollno=e;
	fee=i;
	age=a;
	name=n;
	stat=c1;
	div=d;

}
void Student::display()
{
	cout<<"The details of Student are:";
	cout<<"\nName        :"<<name;
	cout<<"\nRoll No.    :"<<rollno;
	cout<<"\nAge         :"<<age;
	cout<<"\nFEES        :"<<fee;
	cout<<"\nState       :"<<stat;
	cout<<"\nDivision    :"<<div;
	cout<<"\nYear        :"<<year;
}
int main() {
	int cnt=0,n=1;
	double age,fee,rollno,year;
	string name,stat,div;
	do
	{
	try
	{
		cnt=0;
		cout<<"\n\nEnter the details of Student:";
		cout<<"\nName        :";cin>>name;
		cout<<"Roll No.    :";cin>>rollno;
		cout<<"Age         :";cin>>age;
		if(age>=17 && age<=23)
		{cnt++;n=0;}
		else
		  throw(age);
		cout<<"FEES        :";cin>>fee;
		if(fee<=260000)
		{cnt++;n=0;}
		else
		  throw(fee);
		cout<<"State       :";cin>>stat;
		if(stat=="Maharastra"||stat=="Gujarat"||stat=="Goa"||stat=="MP")
		{cnt++;n=0;}
		else
		  throw(stat);
		cout<<"Division    :";cin>>div;
		if(div=="CSE-B"||div=="CSE-A")
		  {cnt++;n=0;}
		else
		  throw(div);
		cout<<"Year        :";cin>>year;
		if(year==2)
		  {cnt++;n=0;}
		else
		  throw(year);
	}
	catch(double a){n=1;cout<<"Exception Error in age!!!\n";}
	catch(double b){n=1;cout<<"Exception Error in Fees!!!\n";}
	catch(string &d){n=1;cout<<"Exception Error in state!!!\n";}
	catch(string &e){n=1;cout<<"Exception Error in Division!!!\n";}
	catch(double c){n=1;cout<<"Exception Error in Year!!!\n";}
	catch(...){n=1;cout<<"!!Catching a Default Exception error!!";}
	}while(n==1);
	if(cnt==5)
	{
		Student E(year,rollno,fee,age,name,stat,div);
		E.display();
	}
}


