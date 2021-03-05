#include "student.h"
#include "degree.h"

//constructor
Student::Student() {
	studentId;
	firstName;
	emailAddress;
	age = 0;
	daysToComplete;
	degree = DegreeProgram::NETWORK;
	
}

Student::Student(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int days[], DegreeProgram degree) {
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
Student::~Student() {

};


//getters
std::string Student::GetId() {
	return studentId;
}
std::string Student::GetFirstName() {
	return firstName;
}
std::string Student::GetLastName()
{
	return lastName;
}
std::string Student::GetEmail() {
	return emailAddress;
}
int Student::GetAge() {
	return age;
}
int* Student::GetDaysToComplete() {
	return this->daysToComplete;
}

std::string Student::GetDegree() {
	return this->DegreeToString();
}

//setters
void Student::SetId(std::string ID) {
	 this->studentId = ID;
}
void Student::SetFirstName(std::string firstName) {
	this->firstName = firstName;
}
void Student::SetLastName(std::string lastName) {
	this->lastName = lastName;
}
void Student::SetEmail(std::string email) {
	this->emailAddress = email;
}
void Student::SetAge(int age) {
	this->age = age;
}
void Student::SetDaysToComplete(int days[3]) {
	for (int i = 0; i < NUM_SIZE; i++) {
		this->daysToComplete[i] = days[i];
	}
}
void Student::SetDegree(DegreeProgram degree) {
	this->degree = degree; 
}
//methods 
void Student::print() {
	std::cout <<'\t' << this->GetId() << '\t';
	std::cout << "First Name: " << this->GetFirstName() << '\t';
	std::cout << "Last Name: " << this->GetLastName() << '\t';
	std::cout << "Email: " << this->GetEmail() << '\t';
	std::cout << "Age: " << this->GetAge() << "yr" << '\t';
	std::cout << "Course Days: {" << this->GetDaysToComplete()[0] << "d" << ',';
	std::cout << this->GetDaysToComplete()[1] << "d" << ',';
	std::cout << this->GetDaysToComplete()[2] << "d" << "}" << '\t';
	std::cout << "Degree: " << this->GetDegree() << '\t';
	std::cout << std::endl;

}
//Function to map DegreeProgram enumeration to string value
std::string Student::DegreeToString() {
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



