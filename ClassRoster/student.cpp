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

student::student(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int days[], DegreeProgram degree) {
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
std::string student::GetId() {
	return studentId;
}
std::string student::GetFirstName() {
	return firstName;
}
std::string student::GetLastName()
{
	return lastName;
}
std::string student::GetEmail() {
	return emailAddress;
}
int student::GetAge() {
	return age;
}
int* student::GetDaysToComplete() {
	return this->daysToComplete;
}

std::string student::GetDegree() {
	return this->DegreeToString();
}

//setters
void student::SetId(std::string ID) {
	 this->studentId = ID;
}
void student::SetFirstName(std::string firstName) {
	this->firstName = firstName;
}
void student::SetLastName(std::string lastName) {
	this->lastName = lastName;
}
void student::SetEmail(std::string email) {
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
	std::cout << this->GetId() << '\t';
	std::cout << "First Name: " << this->GetFirstName() << '\t';
	std::cout << "Last Name: " << this->GetLastName() << '\t';
	std::cout << "Email: " << this->GetEmail() << '\t';
	std::cout << "Age: " << this->GetAge() << "yr" << '\t';
	std::cout << "Course days: {" << this->GetDaysToComplete()[0] << "d" << ',';
	std::cout << this->GetDaysToComplete()[1] << "d" << ',';
	std::cout << this->GetDaysToComplete()[2] << "d" << "}" << '\t';
	std::cout << "Degree: " << this->GetDegree() << '\t';
	std::cout << std::endl;

}
std::string student::DegreeToString() {
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



