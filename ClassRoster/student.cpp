#include "student.h"
#include "degree.h"

//constructor
student::student() {
	studentId;
	firstName;
	emailAddress;
	age = 0;
	daysToComplete;
	degree = DegreeProgram::NETWORK;
	
}

student::student(string ID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degree) {
	studentId = ID;
	this->firstName = firstName; 
	this->lastName = lastName;
	emailAddress = email; 
	this->age = age;
	for (int i = 0; i < NUM_SIZE; i++) {
		this->daysToComplete[i] = days[i];
	}
	this->degree = degree; 
}



//deconstructor
student::~student() {

};


//getters
string student::GetId() {
	return studentId;
}
string student::GetFirstName() {
	return firstName;
}
string student::GetLastName()
{
	return lastName;
}
string student::GetEmail() {
	return emailAddress;
}
int student::GetAge() {
	return age;
}
int* student::GetDaysToComplete() {
	return this->daysToComplete;
}

string student::GetDegree() {
	return this->DegreeToString();
}

//setters
void student::SetId(string ID) {
	 this->studentId = ID;
}
void student::SetFirstName(string firstName) {
	this->firstName = firstName;
}
void student::SetLastName(string lastName) {
	this->lastName = lastName;
}
void student::SetEmail(string email) {
	this->emailAddress = email;
}
void student::SetAge(int age) {
	this->age = age;
}
void student::SetDaysToComplete(int days[3]) {
	for (int i = 0; i < NUM_SIZE; i++) {
		this->daysToComplete[i] = days[i];
	}
}
void student::SetDegree(DegreeProgram degree) {
	this->degree = degree; 
}
//methods 
void student::print() {
	cout << this->GetId() << '\t';
	cout << "First Name: " << this->GetFirstName() << '\t';
	cout << "Last Name: " << this->GetLastName() << '\t';
	cout << "Email: " << this->GetEmail() << '\t';
	cout << "Age: " << this->GetAge() << "yr" << '\t';
	cout << "Course days: {" << this->GetDaysToComplete()[0] << "d" << ',';
	cout << this->GetDaysToComplete()[1] << "d" << ',';
	cout << this->GetDaysToComplete()[2] << "d" << "}" << '\t';
	cout << "Degree: " << this->GetDegree() << '\t';
	cout << endl;

}
string student::DegreeToString() {
	switch (this->degree) {
	case DegreeProgram::NETWORK:
		return "NETWORK";
		break;
	case DegreeProgram::SECURITY:
		return "SECURITY";
		break;
	case DegreeProgram::SOFTWARE:
		return "SOFTWARE";
		break;
	default:
		return "None";
		break;
	}
	}



