#include "roster.h"
#include <sstream> 



//constructor
roster::roster(){
	
}
//deconstructor
roster::~roster(){
	std::cout << std::endl <<  "Deallocating..." << std::endl;
	for (int i = 0; i <= ARR_INDEX; i++) {
		std::cout << '\t' << classRosterArray[i]->GetId() << std::endl;
		delete classRosterArray[i];
	}

	std::cout << "Memory is now free." << std::endl;
}
//methods
void roster::parse(const std::string studentData[]) {
	for (int i = 0; i < CLASS_SIZE; i++) {
		std::string data = studentData[i];
		std::string delimiter = ",";
		size_t str_pos = 0;
		std::string token, ID, fname, lname, email;
		int count = 0, age = 0, days1 = 0, days2 = 0, days3 = 0, temp = 0;
		DegreeProgram degree = DegreeProgram::NETWORK;

		while ((str_pos = data.find(delimiter)) != std::string::npos) {
			token = data.substr(0, str_pos);
			count++;
			data.erase(0, str_pos + delimiter.length());
			std::stringstream buffer(token);
			switch (count) {
			case 1:
				ID = token;
			case 2:
				fname = token;
			case 3:
				lname = token;
			case 4:
				email = token;
			case 5:
				buffer >> age;
			case 6:
				buffer >> days1;
			case 7:
				buffer >> days2;
			case 8:
				buffer >> days3;
			}
			if (data == "NETWORK") {
				degree = DegreeProgram::NETWORK;
			}
			else if (data == "SECURITY") {
				degree = DegreeProgram::SECURITY;
			}
			else {
				degree = DegreeProgram::SOFTWARE;
			}
		}
		add(ID, fname, lname, email, age, days1, days2, days3, degree);
	}


}
void roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeProgram) {
	int temp[3] = { days1, days2,days3};
	
	classRosterArray[++ARR_INDEX] = new student(studentID, firstName, lastName, emailAddress, age, temp, degreeProgram);
	
}
void roster::remove(std::string studentId) {
	std::cout << "Removing Student ID: " << studentId << std::endl << std::endl;
	bool removal = false;
	for (int i = 0; i <= ARR_INDEX; i++) {
		if (classRosterArray[i]->GetId() == studentId) {
			if (i <= ARR_INDEX) {
				ARR_INDEX--;
				for (int j = i; j <= ARR_INDEX; j++) {
					classRosterArray[j] = classRosterArray[j + 1];
					removal = true;
				}
			}
			
		}
		
	} 
	if (removal) {
		this->printAll();
	}
	else {
		std::cout << studentId << " not found." << std::endl;
	}
		
	
}

void roster::printAll() {
	std::cout << "Displaying all students:" << std::endl <<std::endl; 
	for (int i = 0; i <= ARR_INDEX; i++) {
		classRosterArray[i]->student::print();
	}
	std::cout << std::endl;
}
void roster::printAverageDaysInCourse() {
	for (int i = 0; i <= ARR_INDEX; i++) {
		int sum= 0;
		sum = classRosterArray[i]->GetDaysToComplete()[0];
		sum += classRosterArray[i]->GetDaysToComplete()[1];
		sum += classRosterArray[i]->GetDaysToComplete()[2];
		std::cout << "Student ID: " << classRosterArray[i]->GetId() << ", ";
		std::cout << "averages " << sum / 3 << " days in a course." << std::endl; 
	}
	std::cout << std::endl; 
}
void roster::printInvalidEmails() {
	std::string email;
	std::cout << "Displaying invalid emails:" << std::endl << std::endl;
	for (int i = 0; i <= ARR_INDEX; i++) {
		email = classRosterArray[i]->GetEmail();
		
		if (email.find(' ') != std::string::npos) {
			std::cout << "Email: " << email << '\t' << "Invalid Reason: No spaces are allowed" << std::endl;
		}
		if (email.find('@') == std::string::npos)
			std::cout << "Email: " << email << '\t' << "Invalid Reason: Missing an @ symbol" << std::endl;
		if (email.find('.') == std::string::npos) {
			std::cout << "Email: " << email << '\t' << "Invalid Reason: Missing a period" << std::endl;
		}
	}
	std::cout << std::endl;
}

void roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	std::string program;
	switch (degreeProgram) {
	case DegreeProgram::NETWORK:
		program = "NETWORK";
		break;
	case DegreeProgram::SECURITY:
		program = "SECURITY";
		break;
	case DegreeProgram::SOFTWARE:
		program = "SOFTWARE";
		break;
	default:
		break;
	}
	std::cout << "Displaying student in Degree Program: " << program << std::endl << std::endl;
	for (int i = 0; i <= ARR_INDEX; i++) {
		if (classRosterArray[i]->GetDegree() == program) {

			classRosterArray[i]->student::print();
		}
	}
};
