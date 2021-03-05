//#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class student
{
private:
	string _name;
	double _gpa;
public:
	student();
	student(string);
	student(string, double);
	string getname();
	double getgpa();
	void setname(string);
	void setgpa(double);
};

student::student() { setname("");  setgpa(0.0); }
student::student(string name) { setname(name);  setgpa(0.0); }
student::student(string name,double gpa) { setname(name);  setgpa(gpa); }
string student::getname() { return _name; } 
double student::getgpa() { return _gpa; } 
void student::setname(string name) { _name=name; } 
void student::setgpa(double gpa) { _gpa=gpa; }

class studentlist
{
private:
	vector<student> _SL;
public:
	studentlist();
	int count();
	int addnew(student);
	int addnew(string, double);
	student operator[] (int);
};

studentlist::studentlist() {}
int studentlist::count() { return _SL.size(); } 
int studentlist::addnew(student s) { _SL.push_back(s);  return _SL.size(); }
int studentlist::addnew(string name, double gpa) { _SL.push_back(student(name,gpa));  return _SL.size(); }
student studentlist::operator[] (int index) { return _SL[index]; }

int main()
{
	studentlist SL;

	cout << "There are currently " << SL.count() << " students.\n";

	student Maggie, Bart("Bart"), Lisa("Lisa",4.0);

	cout << "There are currently " << SL.addnew(Maggie) << " students.\n";
	cout << "There are currently " << SL.addnew(Bart) << " students.\n";
	cout << "There are currently " << SL.addnew(Lisa) << " students.\n";
	cout << "There are currently " << SL.addnew("Homer",1.5) << " students.\n";

	cout << "The middle student is " << SL[2].getname() << endl; 

	cout << "\n\n\n";
	system("pause");
	return 0;
}

