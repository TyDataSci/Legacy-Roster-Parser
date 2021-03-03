#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class student
{
public:
static const int NUM_SIZE = 3;


private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[NUM_SIZE] = {0,0,0};
	DegreeProgram degree;

public:
	//constructors
	student();
	student(string ID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degree);
	//deconstructor
	~student();
	//getters
	string GetId();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	int* GetDaysToComplete();
	string GetDegree();
	


	//setters
	void SetId(string ID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string email);
	void SetAge(int age);
	void SetDaysToComplete(int *days);
	void SetDegree(DegreeProgram degree);

	//methods
	void print();
	string DegreeToString();
};

