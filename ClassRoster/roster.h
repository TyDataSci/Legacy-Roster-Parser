#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"


class roster
{

public:
	int ARR_INDEX = -1;
	//Create an array of pointers classRosterArray
	const static int CLASS_SIZE = 5;
	student* classRosterArray[CLASS_SIZE];

	//constructor 
	roster();
	//deconstructor
	~roster();

	//methods
	void parse(const std::string studentData[]);
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(std::string studentId);
	void printAll();
	void printAverageDaysInCourse();
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

};