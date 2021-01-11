/*
 * roster.cpp
 *
 *      Author: Charles Plett
 */

#include <iostream>
#include <iomanip>
#include "roster.h"
using namespace std;

void Roster::parse(string inData){ // parse input string
	int rhs = inData.find(","); // find the comma
	string sID = inData.substr(0, rhs); // first value is the studentID

	int lhs = rhs + 1; // lhs is the character following the comma
	rhs = inData.find(",", lhs); // update int rhs to the next comma. Start from lhs
	string fn = inData.substr(lhs, rhs-lhs); // value is the firstname

	lhs = rhs + 1; // update lhs with the position of the next value
	rhs = inData.find(",", lhs);
	string ln = inData.substr(lhs, rhs-lhs); // value is the lastname

	lhs = rhs + 1;
	rhs = inData.find(",", lhs);
	string eml = inData.substr(lhs, rhs-lhs); // value is the email

	lhs = rhs + 1;
	rhs = inData.find(",", lhs);
	int ag = stoi(inData.substr(lhs, rhs-lhs)); // value is the age. Convert to integer

	lhs = rhs + 1;
	rhs = inData.find(",", lhs);
	int d1 = stoi(inData.substr(lhs, rhs-lhs)); // value is the daysInCourse1

	lhs = rhs + 1;
	rhs = inData.find(",", lhs);
	int d2 = stoi(inData.substr(lhs, rhs-lhs)); // value is the daysInCourse2

	lhs = rhs + 1;
	rhs = inData.find(",", lhs);
	int d3 = stoi(inData.substr(lhs, rhs-lhs)); // value is the daysInCourse3

	char dpv = inData.back(); // Get the last character of string to identify DegreeProgram
	DegreeProgram dp = SECURITY; // Default value
	if (dpv == 'K'){
		dp = NETWORK; // update value
	} else if (dpv == 'E') {
		dp = SOFTWARE;
	}

	add(sID, fn, ln, eml, ag, d1, d2, d3, dp); // call add method with the parsed data from the temporary variables
}

void Roster::add(string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1, // daysInCourse will become an array but the values arrive individually from parse method.
	int daysInCourse2,
	int daysInCourse3,
	DegreeProgram degreeprogram)
{
	int daysArr[3] = {daysInCourse1,daysInCourse2,daysInCourse3}; // Create an array from our daysInCourse values
	this->classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArr, degreeprogram);
}

void Roster::remove(string studentID){
	bool found = false; // assume we will not find the studentID to delete
	for (int i = 0; i <= lastIndex; i++){
		if (classRosterArray[i]->getstudentID() == studentID){
			found = true;
			if (i < rosterSize - 1){ // if this is not the last student in the array
				classRosterArray[i] = classRosterArray[rosterSize - 1]; // overwrite student with the last student in the array
			}
			classRosterArray[rosterSize - 1] = NULL; // NULL the final value in the array
			delete classRosterArray[rosterSize - 1]; // Delete the final value in the array
			lastIndex--; // remove access to last item in the array. Cleanup will be done in the destructor
			cout << "Removed " << studentID << endl;
		}
	}
	if (found == false){ // if we did not find the studentID
		cout << studentID << " does not exist" << endl;
	}
}

void Roster::printHeader(){
	cout << "Student" << "\t" << "First" << "\t" << left << setw(8) << "Last" << "\t" << left << setw(22) << "Email" << "\t" << "Age" << "\t" << left << setw(12) << "Days in Course"  << "\t" << "Degree" << endl;
	cout << "ID" << "\t" << "Name" << "\t" << left << setw(8) << "Name" << "\t" << left << setw(22) << "Address" << "\t" << " " << "\t" << left << setw(12) << ""  << "\t" << "Program" << endl;
}

void Roster::printAll(){
	// Print Header
	this->printHeader();

	for(int i = 0; i <= lastIndex; i++){
		classRosterArray[i]->print(); // print each Student using the print function from Student class.
	}
}

void Roster::printAverageDaysInCourse(string studentID){
	for (int i = 0; i <= lastIndex; i++){
		if (classRosterArray[i]->getstudentID() == studentID){
			float avg = (classRosterArray[i]->getdays()[0]+classRosterArray[i]->getdays()[1]+classRosterArray[i]->getdays()[2])/3.0;
			cout << classRosterArray[i]->getstudentID() << "\t" << " AverageDaysInCourse: "	<< avg << endl;
		}
	}
}

void Roster::printInvalidEmails(){
	bool ok = true; // assume all email addresses are valid
	for (int i = 0; i <= lastIndex; i++){
		string email = classRosterArray[i]->getemail();
		if (email.find(' ') != email.npos // if there are spaces in the email address before the end
			|| (email.find('@')) == email.npos // or '@' is not found before the end
			|| (email.find('.')) == email.npos) // or '.' is not found before the end
		{
			ok = false; // at least one email address is invalid.
			cout << email << endl; // print invalid email address
		}
	}
	if (ok == true){ // if there are no bad email addresses
		cout << "All email addresses are valid" << endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
	this->printHeader();
	for(int i = 0; i <= lastIndex; i++){
		if (classRosterArray[i]->getdegreeType() == degreeProgram){
			classRosterArray[i]->print(); // print each Student that matches degreeProgram.
		}
	}
}

Roster::~Roster(){
	cout << "Roster Destructor Initiated!" << endl;
	for (int i=0; i < this->rosterSize; i++){
		cout << "Deleting " << i+1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
