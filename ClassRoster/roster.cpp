#include "roster.h"
#include <sstream> 



//constructor
Roster::Roster(){
	
}
//deconstructor
Roster::~Roster(){
	std::cout << std::endl << '\t' << "Deallocating..." << std::endl;
		for (int i = 0; i <= ARR_INDEX; i++) {
			std::cout << '\t' << classRosterArray[i]->GetId() << std::endl;
			delete classRosterArray[i];
		}
		std::cout << '\t' << "Memory is free." << std::endl;
}
//methods
void Roster::parse(const std::string studentData[]) {
	//Using ',' as a delimiter, parse iterates through the array of data and extracts each token of information
	for (int i = 0; i < CLASS_SIZE; i++) {
		std::string data = studentData[i];
		std::string delimiter = ",";
		size_t str_pos = 0;
		std::string token, ID, fname, lname, email;
		int count = 0, age = 0, days1 = 0, days2 = 0, days3 = 0, temp = 0;
		DegreeProgram degree = DegreeProgram::NETWORK;
		// Order of value type is known so a case switch can be used
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

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeProgram) {
	if (ARR_INDEX < CLASS_SIZE) {
		int temp[3] = { days1, days2,days3 };
		//As a new Student object is added, ARR_INDEX will incrementally increase
		classRosterArray[++ARR_INDEX] = new Student(studentID, firstName, lastName, emailAddress, age, temp, degreeProgram);
	}
	
	
}
void Roster::remove(std::string studentID) {
	std::cout << '\t' << "Removing Student ID: " << studentID << std::endl << std::endl;
	bool removal = false;
	bool last = false;
	//As a new Student object is removed, ARR_INDEX will incrementally decrease
	for (int i = 0; i <= ARR_INDEX; i++) {
		if (classRosterArray[i]->GetId() == studentID) {
			if (i < ARR_INDEX) {
				ARR_INDEX--;
				for (int j = i; j <= ARR_INDEX; j++) {
					classRosterArray[j] = classRosterArray[j + 1];
					removal = true;
				}
			}
			else if (i == ARR_INDEX && ARR_INDEX != 0) {
					ARR_INDEX--;
					removal = true;
					
			}
			//Check for last element in array
			else if (i == ARR_INDEX && ARR_INDEX == 0) {
					last = true;
					classRosterArray[ARR_INDEX] = nullptr;
			}
		}

	}
	//Output for element removed in an array
	if (removal) {
		classRosterArray[ARR_INDEX + 1] = nullptr;
		this->printAll();	
	}
	//Output for last element removed in an array
	else if (last) {
		std::cout << '\t' << "NO DATA TO DISPLAY" <<std::endl; 
	}
	else {
	//Output for element not found in an array

		std::cout << '\t' << studentID << " not found." << std::endl;
	}

}

void Roster::printAll() {
	std::cout << '\t' << "Displaying all students:" << std::endl <<std::endl; 
	for (int i = 0; i <= ARR_INDEX; i++) {
		classRosterArray[i]->Student::print();
	}
	std::cout << std::endl;
}
void Roster::printAverageDaysInCourse(std::string studentID) {
	int j = 0;
	for (int i = 0; i <= ARR_INDEX; i++) {
		if (classRosterArray[i]->GetId() == studentID) {
			//If first element in an array, will output heading of function
			if (i == 0) {
				std::cout << '\t' << "Displaying students average time to complete a course:" << std::endl << std::endl;
				int sum = 0;
				sum = classRosterArray[i]->GetDaysToComplete()[0];
				sum += classRosterArray[i]->GetDaysToComplete()[1];
				sum += classRosterArray[i]->GetDaysToComplete()[2];
				std::cout << '\t' << "Student ID: " << classRosterArray[i]->GetId() << ", ";
				std::cout << "averages " << sum / 3 << " days in a course.";
				j = i;
			}
			else {
				int sum = 0;
				sum = classRosterArray[i]->GetDaysToComplete()[0];
				sum += classRosterArray[i]->GetDaysToComplete()[1];
				sum += classRosterArray[i]->GetDaysToComplete()[2];
				std::cout << '\t' << "Student ID: " << classRosterArray[i]->GetId() << ", ";
				std::cout << "averages " << sum / 3 << " days in a course.";
				j = i;
			}
		}
	}

	//If last element of an array, will output double space 
	if (j == ARR_INDEX) {
		std::cout << std::endl << std::endl;
	}
	else {
		std::cout << std::endl; 
	}
}

void Roster::printInvalidEmails() {
	std::string email;
	std::cout << '\t' << "Displaying invalid emails:" << std::endl << std::endl;
	for (int i = 0; i <= ARR_INDEX; i++) {
		email = classRosterArray[i]->GetEmail();
		
		if (email.find(' ') != std::string::npos) {
			std::cout << '\t' << "Email: " << email << '\t' << "Invalid Reason: No spaces are allowed" << std::endl;
		}
		if (email.find('@') == std::string::npos)
			std::cout << '\t' << "Email: " << email << '\t' << "Invalid Reason: Missing an @ symbol" << std::endl;
		if (email.find('.') == std::string::npos) {
			std::cout << '\t' << "Email: " << email << '\t' << "Invalid Reason: Missing a period" << std::endl;
		}
	}
	std::cout << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
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
	std::cout << '\t' << "Displaying students in Degree Program: " << program << std::endl << std::endl;
	for (int i = 0; i <= ARR_INDEX; i++) {
		if (classRosterArray[i]->GetDegree() == program) {

			classRosterArray[i]->Student::print();
		}
		
	} std::cout << std::endl;
};
