/*
 * student.cpp
 *
 *      Author: Charles Plett
 */

#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"
using namespace std;

// default constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i=0 ; i<daysArraySize; i++){
		this->daysArray[i] = 0; // instantiate each item in the daysArray to 0
	};
	this->degreeType = SECURITY; // instantiate to 0
}

// overloaded constructor
Student::Student(string ID, string first, string last, string email, int age, int days[], DegreeProgram degreeType) {
	this->studentID = ID;
	this->firstName = first;
	this->lastName = last;
	this->email = email;
	this->age = age;
	for (int i = 0; i < this->daysArraySize; i++){
		this->daysArray[i] = days[i];
	}
	this->degreeType = degreeType;
}

// Destructor
Student::~Student(){
	// Empty destructor. Nothing to cleanup
}

// getters
string Student::getstudentID() {
	return this->studentID;
}

string Student::getfirstName() {
	return this->firstName;
}

string Student::getlastName() {
	return this->lastName;
}

string Student::getemail() {
	return this->email;
}

int Student::getage() {
	return this->age;
}

int* Student::getdays() {
	return this->daysArray;
}

DegreeProgram Student::getdegreeType() {
	return this->degreeType;
}

// setters

void Student::setstudentID(string ID) {
	this->studentID = ID;
}

void Student::setfirstName(string first) {
	this->firstName = first;
}

void Student::setlastName(string last) {
	this->lastName = last;
}

void Student::setemail(string newEmail) {
	this->email = newEmail;
}

void Student::setage(int newAge) {
	this->age = newAge;
}

void Student::setdays(int days[]) {
	for(int i = 0; i < this->daysArraySize; i++){
		this->daysArray[i] = days[i];
	};
}

// Print method
void Student::print(){
	cout << this->studentID << '\t'; // tab separated
	cout << this->firstName << '\t';
	cout << left << setw(8) << this->lastName << '\t'; // setw used to keep longer names aligned
	cout << left << setw(22) << this->email << '\t';
	cout << this->age << '\t';
	cout << '{' << this->daysArray[0] << ", ";
	cout << this->daysArray[1] << ", ";
	cout << this->daysArray[2] << '}' << '\t';
	cout << DegreeStrings[this->degreeType] << endl; // Use DegreeStrings to translate name from enum.
}

