/*
 * student.h
 *
 *      Author: Charles Plett
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include "degree.h"
using namespace std;

class Student {
public:
	const static int daysArraySize = 3; // size of array is visible to all
protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysArray[daysArraySize];
	DegreeProgram degreeType;
public:
	// getters
	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemail();
	int getage();
	int* getdays(); // pointer used to store the address of the array
	DegreeProgram getdegreeType();

	// setters
	void setstudentID(string ID);
	void setfirstName(string first);
	void setlastName(string last);
	void setemail(string email);
	void setage(int age);
	void setdays(int days[]);

	// constructor
	Student(); // empty constructor
	Student(string ID, string first, string last, string email, int age, int days[], DegreeProgram degreeType); // overloaded constructor

	void print();

	// destructor
	~Student();
};



#endif /* STUDENT_H_ */
