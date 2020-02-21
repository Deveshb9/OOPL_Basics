//============================================================================
// Name        : Employee.cpp
// Author      : Devesh Bhogre SY-BTECH CSE-B 203242 B3
// Version     : 3
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

class Employee{
protected:
			string fn,ln,ssn; //first name, last name ,social security no.
public:
			Employee();
			Employee(string , string , string);
			Employee(Employee &E);
			void setfname(string);
			void setlname(string);
			void setssn(string);
			string getfname();                   //A get function
			string getlname();					//A set function
			string getssn();
			void earning();
			void accept();
			virtual void display();
			virtual double earnings()=0;         //Pure Virtual Function
			~Employee();						//destructor
};

Employee::Employee()
{
	fn="nil";
	ln="nil";
	ssn="nil";
}
Employee::Employee(string first,string last,string SSNo)     //Parameterised Construtor
{
	fn=first;
	ln=last;
	ssn=SSNo;
}
void Employee::accept()
{
	cout<<"Enter your First name:";
	cin>>fn;
	cout<<"Enter your Last name:";
	cin>>ln;
	cout<<"Enter your Social Security no.:";
	cin>>ssn;
}
Employee::Employee(Employee &E)								//Copy Constructor
{
	fn=E.fn;
	ln=E.ln;
	ssn=E.ssn;
}
void Employee::setfname(string first){
   fn=first;
}
void Employee::setlname(string last){
   ln=last;
}
void Employee::setssn(string SSNo){
   ssn=SSNo;
}
string Employee::getfname(){
    return fn;
}
string Employee::getlname(){
    return ln;
}
string Employee::getssn(){
    return ssn;
}
void Employee::display(){
    cout<<"---------------------------------------------------------\n";
	cout<<"Name of Employee   :"<<getfname()<<" "<<getlname()<<endl;
    cout<<"Social Security No.:"<<getssn();
}
Employee::~Employee()								//Destructor
{
	cout<<"\nDestroying object of Base class Employee";
}

class Salaried_emp: public Employee{                    //Single Inheritance publicly derived
protected:
			double ws; //weekly salary
public:
			Salaried_emp();
			Salaried_emp(string,string,string,double);
			Salaried_emp(Salaried_emp &S);
			void setsalary(double);
			double getsalary();
			void display();
			void accept();
			double earnings();
			~Salaried_emp();			//Destructor
};
Salaried_emp::Salaried_emp()
{
	ws=0;
}
Salaried_emp::Salaried_emp(string first,string last,string SSNo,double sal): Employee(first,last,SSNo)  //Inheriting base class Employee
{
	ws=sal;
}
Salaried_emp::Salaried_emp(Salaried_emp &S): Employee(S)           //Copy constructor with inheriting Employee
{
	ws=S.ws;
}
void Salaried_emp::accept()
{
	Employee::accept();
	cout<<"Enter Weekly Salary:";
	cin>>ws;
}
void Salaried_emp::setsalary(double sal){
	ws=sal;
}
double Salaried_emp::getsalary(){
   return ws;
}
void Salaried_emp::display(){
    Employee::display();
    cout<<"\nEmployee type      :Weekly Salaried Employee";
    cout<<"\nWeekly Salary      :"<<getsalary();
    cout<<"\n---------------------------------------------------------\n";
}
double Salaried_emp::earnings(){
	return getsalary();
}
Salaried_emp::~Salaried_emp()
{
	cout<<"\nDestroying object of Derived class Salaried Employee";
}

class hourly_emp: public Employee{						//Single Inheritance publicly derived
protected:
			double wg,hr; //wages,hours
public:
		hourly_emp();
		hourly_emp(string,string,string,double,double);
		hourly_emp(hourly_emp &H);
		double getwg();
		double gethr();
		void setwg(double);
		void sethr(double);
		void display();
		void accept();
		double earnings();
		~hourly_emp();
};
hourly_emp::hourly_emp()
{
	wg=hr=0;
}
hourly_emp::hourly_emp(string first,string last,string SSNo,double wag,double hrs):Employee(first,last,SSNo)  //Inheriting base class Employee
{
	wg=wag;
	hr=hrs;
}
hourly_emp::hourly_emp(hourly_emp &H):Employee(H)		//Copy constructor with inheriting Employee
{
	wg=H.wg;
	hr=H.hr;
}
void hourly_emp::accept()
{
	Employee::accept();
	cout<<"Enter hourly Wages:";
	cin>>wg;
	cout<<"Enter hours worked:";
	cin>>hr;
}
void hourly_emp::setwg(double wag)
{
	wg=wag;
}
void hourly_emp::sethr(double hrs)
{
	hr=hrs;
}
double hourly_emp::getwg()
{
	return wg;
}
double hourly_emp::gethr()
{
	return hr;
}
void hourly_emp::display()
{
	Employee::display();
	cout<<"\nEmployee type      :Hourly Employee";
	cout<<"\nHourly Salary      :"<<earnings();
	cout<<"\n---------------------------------------------------------\n";
}
double hourly_emp::earnings()
{
	double temp;
	if(hr<=40)
	{temp=wg*hr;}
	else
	{
	temp=40*wg+((hr-40)*wg*1.5);
	}
	return temp;
}

hourly_emp::~hourly_emp()
{
	cout<<"\nDestroying object of Derived class hourly Employee";
}

class Commision_emp: public Employee{					//Single Inheritance publicly derived
protected:
			double gs,cs; //gross salary,commision salary
public:
			Commision_emp();
			Commision_emp(string ,string ,string ,double ,double);
			Commision_emp(Commision_emp &C);
			void display();
			void accept();
			double earnings();
			~Commision_emp();
};
Commision_emp::Commision_emp()
{
	gs=cs=0;
}
Commision_emp::Commision_emp(string first,string last,string SSNo,double grs,double cos):Employee(first,last,SSNo)    //Inheriting base class Employee
{
	gs=grs;
	cs=cos;
}
Commision_emp::Commision_emp(Commision_emp &C):Employee(C)		//Copy constructor with inheriting Employee
{
	gs=C.gs;
	cs=C.cs;
}
void Commision_emp::accept()
{
	Employee::accept();
	cout<<"Enter Gross rates:";
	cin>>gs;
	cout<<"Enter Commission rate:";
	cin>>cs;
}
double Commision_emp::earnings()
{

	return (cs*gs);
}
void Commision_emp::display()
{
	Employee::display();
	cout<<"\nEmployee type      :Commission  Employee";
	cout<<"\nCommission Salary  :"<<earnings();
	cout<<"\n---------------------------------------------------------\n";
}
Commision_emp::~Commision_emp()
{
	cout<<"\nDestroying object of Derived class Commision Employee";
}
class BasepCommision_emp: public Commision_emp{						//multilevel Inheritance publicly derived
protected:
			double bs;//base salary
public:
			BasepCommision_emp();
			BasepCommision_emp(string,string,string,double,double,double);
			BasepCommision_emp(BasepCommision_emp &B);
			void accept();
			void display();
			double earnings();
			~BasepCommision_emp();
};
BasepCommision_emp::BasepCommision_emp()
{
	bs=0;
}
BasepCommision_emp::BasepCommision_emp(string first,string last,string SSNo,double grs,double cos,double bas):Commision_emp(first,last,SSNo,grs,cos)  //Inheriting derived class Comision_emp
{
	bs=bas;
}
BasepCommision_emp::BasepCommision_emp(BasepCommision_emp &B):Commision_emp(B)	//Copy constructor with inheriting Employee
{
	bs=B.bs;
}
void BasepCommision_emp::accept()
{
	Commision_emp::accept();
	cout<<"Enter Base Salary:";
	cin>>bs;
}
double BasepCommision_emp::earnings()
{
	double z,t;
	z=Commision_emp::earnings();
	t=z+bs;
	return t;
}
void BasepCommision_emp::display()
{
	Employee::display();
	cout<<"\nEmployee type      :Base+Commission  Employee";
	cout<<"\n(Base+Com) Salary  :"<<earnings();
	cout<<"\n---------------------------------------------------------\n";
}
BasepCommision_emp::~BasepCommision_emp()
{
	cout<<"\nDestroying object of Derived class Base+Commision Employee";
}
int main() {

	/*BasepCommision_emp S1("Devesh","Bhogre","1513095-D",7000,10,1000);
	Commision_emp S2("Samarth","Bhogre","1513645-E",6000,10);
	Salaried_emp S3("Pratyush","Bhawsar","2345222-A",80000);
	hourly_emp S4("Anand","Karva","454443-Z",2000,24);
	BasepCommision_emp S;
	*/
	int ch,p=2,ch1;
	Employee *e;
	do
	{
	cout<<"\n\n\nEnter The type of employee:";
	cout<<"\n1.Salaried Employee";
	cout<<"\n2.Hourly Employee";
	cout<<"\n3.Commission Employee";
	cout<<"\n4.Base+Commission Employee";
	cout<<"\n5.Create New Employee";
	cout<<"\n6.Exit";
	cout<<"\nChoice:";
	cin>>ch;
	switch(ch){
	case 1:
	{
		Salaried_emp S3("Pratyush","Bhawsar","2345222-A",80000);
		e=&S3;
		e->earnings();
		e->display();

		break;
	}
	case 2:
	{
		hourly_emp S4("Anand","Karva","454443-Z",2000,24);
		e=&S4;
		e->earnings();
		e->display();
		break;
	}

	case 3:
	{
		Commision_emp S2("Samarth","Bhogre","1513645-E",6000,10);
		e=&S2;
		e->earnings();
		e->display();
		break;
	}

	case 4:
	{
		BasepCommision_emp S1("Devesh","Bhogre","1513095-D",7000,10,1000);
		e=&S1;
		e->earnings();
		e->display();
		break;
	}
	case 5:
	{
		cout<<"\n\n\nEnter The type of employee:";
		cout<<"\n1.Salaried Employee";
		cout<<"\n2.Hourly Employee";
		cout<<"\n3.Commission Employee";
		cout<<"\n4.Base+Commission Employee";
		cout<<"\nChoice:";
			cin>>ch1;
			switch(ch1){
			case 1:
			{
					Salaried_emp S;
					e=&S;
					e->accept();
					e->earnings();
					e->display();
					break;
			}
			case 2:
			{
					hourly_emp H;
					e=&H;
					e->accept();
					e->earnings();
					e->display();
					break;
			}
			case 3:
			{
					Commision_emp C;
					e=&C;
					e->accept();
					e->earnings();
					e->display();
					break;
			}
			case 4:
			{
					BasepCommision_emp B;
					e=&B;
					e->accept();
					e->earnings();
					e->display();
					break;
			}
			default:
					cout<<"\nPlease enter correct choice!!!!";
			}
	}
	case 6:
	{
		p=1;
		break;
	}
	default:
			cout<<"\nPlease enter correct choice!!!!";
}
}while(p!=1);
	return 0;
}

/*OUTPUT:



Enter The type of employee:
1.Salaried Employee
2.Hourly Employee
3.Commission Employee
4.Base+Commission Employee
5.Create New Employee
6.Exit
Choice:1
---------------------------------------------------------
Name of Employee   :Pratyush Bhawsar
Social Security No.:2345222-A
Employee type      :Weekly Salaried Employee
Weekly Salary      :80000
---------------------------------------------------------

Destroying object of Derived class Salaried Employee
Destroying object of Base class Employee


Enter The type of employee:
1.Salaried Employee
2.Hourly Employee
3.Commission Employee
4.Base+Commission Employee
5.Create New Employee
6.Exit
Choice:2
---------------------------------------------------------
Name of Employee   :Anand Karva
Social Security No.:454443-Z
Employee type      :Hourly Employee
Hourly Salary      :48000
---------------------------------------------------------

Destroying object of Derived class hourly Employee
Destroying object of Base class Employee


Enter The type of employee:
1.Salaried Employee
2.Hourly Employee
3.Commission Employee
4.Base+Commission Employee
5.Create New Employee
6.Exit
Choice:3
---------------------------------------------------------
Name of Employee   :Samarth Bhogre
Social Security No.:1513645-E
Employee type      :Commission  Employee
Commission Salary  :60000
---------------------------------------------------------

Destroying object of Derived class Commision Employee
Destroying object of Base class Employee


Enter The type of employee:
1.Salaried Employee
2.Hourly Employee
3.Commission Employee
4.Base+Commission Employee
5.Create New Employee
6.Exit
Choice:4
---------------------------------------------------------
Name of Employee   :Devesh Bhogre
Social Security No.:1513095-D
Employee type      :Base+Commission  Employee
(Base+Com) Salary  :71000
---------------------------------------------------------

Destroying object of Derived class Base+Commision Employee
Destroying object of Derived class Commision Employee
Destroying object of Base class Employee


Enter The type of employee:
1.Salaried Employee
2.Hourly Employee
3.Commission Employee
4.Base+Commission Employee
5.Create New Employee
6.Exit
Choice:5



Enter The type of employee:
1.Salaried Employee
2.Hourly Employee
3.Commission Employee
4.Base+Commission Employee
Choice:4
Enter your First name:Parimal
Enter your Last name:Dani
Enter your Social Security no.:23455E
---------------------------------------------------------
Name of Employee   :Parimal Dani
Social Security No.:23455E
Employee type      :Base+Commission  Employee
(Base+Com) Salary  :0
---------------------------------------------------------

Destroying object of Derived class Base+Commision Employee
Destroying object of Derived class Commision Employee
Destroying object of Base class Employee
