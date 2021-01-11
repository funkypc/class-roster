//============================================================================
// Author      : Charles Plett
// Description : C++ Class Roster Application
//============================================================================

#include <iostream>
#include "roster.h"
using namespace std;

int main() {
	cout << "---------------------------------------------" << endl;
	cout << "C++ Class Roster Application" << endl;
	cout << "---------------------------------------------" << endl << endl;

	const string studentData[] ={
		"A1,John,Doe,John1999@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzy,Erickson,Erickson_1999@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napol,your_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Emmy,Black,Emmy.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jane,Doe,jdoe@gmail.com,35,12,24,11,SOFTWARE"
	};
	const int dataSize = 5; // size of studentData[]

	Roster classRoster; // Create an instance of Roster class called classRoster

	for (int i = 0; i < dataSize; i++){
		classRoster.parse(studentData[i]); //Add each student to classRoster
	}
	cout << endl << "Printing Roster..." << endl;
	classRoster.printAll();
	cout << endl << "Printing Invalid Emails..." << endl;
	classRoster.printInvalidEmails();

	cout << endl << "Printing Average Days in Course..." << endl;
	for (int i=0; i < classRoster.rosterSize; i++){ // loop through classRosterArray and for each element:
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getstudentID()); // print average days in course
	}
	cout << endl << "Printing Roster by Degree Program SOFTWARE..." << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl << "Removing Student A3..." << endl;
	classRoster.remove("A3");
	cout << endl << "Printing Roster..." << endl;
	classRoster.printAll();
	cout << endl << "Removing Student A3..." << endl;
	classRoster.remove("A3");
	cout << endl;

	return 0;
}
