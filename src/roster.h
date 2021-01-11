/*
 * roster.h
 *
 *      Author: Charles Plett
 */

#ifndef ROSTER_H_
#define ROSTER_H_

#include <iostream>
#include "student.h"
using namespace std;

class Roster {
protected:
	int lastIndex = -1; // initialize to -1. add() will increment by 1 before adding the first record.
public:
	const static int rosterSize = 5; // Array size will be fixed
	Student* classRosterArray[rosterSize];
	void parse(string inData); // used to parse input string
	void add(string studentID,
			string firstName,
			string lastName,
			string emailAddress,
			int age,
			int daysInCourse1, // daysInCourse will become an array but the values come in individually after parsing.
			int daysInCourse2,
			int daysInCourse3,
			DegreeProgram degreeprogram);
	void remove(string studentID);
	void printHeader();
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};



#endif /* ROSTER_H_ */
