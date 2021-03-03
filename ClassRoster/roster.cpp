#include "roster.h"
#include <sstream> 


//constructor
roster::roster(){
	
}
//deconstructor
roster::~roster(){
	cout << endl <<  "Deallocating..." << endl;
	for (int i = 0; i <= ARR_INDEX; i++) {
		cout << '\t' << classRosterArray[i]->GetId() << endl;
		delete classRosterArray[i];
	}

	cout << "Memory is now free." << endl;
}
//methods
void roster::parse(const string studentData[]) {
	for (int i = 0; i < CLASS_SIZE; i++) {
		string data = studentData[i];
		string delimiter = ",";
		size_t str_pos = 0;
		string token, ID, fname, lname, email;
		int count = 0, age = 0, days1 = 0, days2 = 0, days3 = 0, temp = 0;
		DegreeProgram degree = DegreeProgram::NETWORK;

		while ((str_pos = data.find(delimiter)) != string::npos) {
			token = data.substr(0, str_pos);
			count++;
			data.erase(0, str_pos + delimiter.length());
			stringstream buffer(token);
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
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeProgram) {
	int temp[3] = { days1, days2,days3};
	
	classRosterArray[++ARR_INDEX] = new student(studentID, firstName, lastName, emailAddress, age, temp, degreeProgram);
	
}
void roster::remove(string studentId) {
	cout << "Removing Student ID: " << studentId << endl << endl;
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
		cout << studentId << " not found." << endl;
	}
		
	
}

void roster::printAll() {
	cout << "Displaying all students:" << endl <<endl; 
	for (int i = 0; i <= ARR_INDEX; i++) {
		classRosterArray[i]->student::print();
	}
	cout << endl;
}
void roster::printAverageDaysInCourse() {
	for (int i = 0; i <= ARR_INDEX; i++) {
		int sum= 0;
		sum = classRosterArray[i]->GetDaysToComplete()[0];
		sum += classRosterArray[i]->GetDaysToComplete()[1];
		sum += classRosterArray[i]->GetDaysToComplete()[2];
		cout << "Student ID: " << classRosterArray[i]->GetId() << ", ";
		cout << "averages " << sum / 3 << " days in a course." << endl; 
	}
	cout << endl; 
}
void roster::printInvalidEmails() {
	string email;
	cout << "Displaying invalid emails:" << endl << endl;
	for (int i = 0; i <= ARR_INDEX; i++) {
		email = classRosterArray[i]->GetEmail();
		
		if (email.find(' ') != string::npos) {
			cout << "Email: " << email << " - No spaces are allowed." << endl;
		}
		if (email.find('@') == string::npos)
			cout << "Email: " << email << " missing an @ symbol" << endl;
		if (email.find('.') == string::npos) {
			cout << "Email: " << email << " missing a period." << endl;
		}
	}
	cout << endl;
}

void roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	string program;
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
	cout << "Displaying student in Degree Program: " << program << endl << endl;
	for (int i = 0; i <= ARR_INDEX; i++) {
		if (classRosterArray[i]->GetDegree() == program) {

			classRosterArray[i]->student::print();
		}
	}
};
