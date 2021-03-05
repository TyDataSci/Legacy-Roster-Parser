#pragma once
#include <iostream>
#include <string>
#include "degree.h"

class Student
{
public:
static const int NUM_SIZE = 3;


private:
	std::string studentId;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysToComplete[NUM_SIZE] = {0,0,0};
	DegreeProgram degree;

public:
	//constructors
	Student();
	Student(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int days[], DegreeProgram degree);
	//deconstructor
	~Student();
	//getters
	std::string GetId();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetEmail();
	int GetAge();
	int* GetDaysToComplete();
	std::string GetDegree();
	


	//setters
	void SetId(std::string ID);
	void SetFirstName(std::string firstName);
	void SetLastName(std::string lastName);
	void SetEmail(std::string email);
	void SetAge(int age);
	void SetDaysToComplete(int *days);
	void SetDegree(DegreeProgram degree);

	//methods
	void print();
	std::string DegreeToString();
};

