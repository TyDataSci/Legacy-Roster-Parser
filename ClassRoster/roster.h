#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"


class Roster
{

public:
	int ARR_INDEX = -1;
	//classRosterArray is an array of pointers to Student object 
	const static int CLASS_SIZE = 5;
	Student* classRosterArray[CLASS_SIZE] = {};

	//constructor 
	Roster();
	//deconstructor
	~Roster();

	//methods
	void parse(const std::string studentData[]);
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

};