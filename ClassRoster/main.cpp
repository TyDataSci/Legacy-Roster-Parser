#include "student.h"
#include "roster.h"
#include "degree.h"




int main() {

	const std::string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Tyler,Sanders,tsanders140@wgu.edu,29,17,14,25,SOFTWARE" };

	Roster roster;

	std::cout << std::endl << '\t' << "Course Title: SCRIPTING AND PROGRAMMING - APPLICATIONS - C867" << std::endl;
	std::cout << '\t' << "Programming Language: C++" << std::endl;
	std::cout << '\t' << "Student ID: #001230176" << std::endl;
	std::cout << '\t' << "Student Name: Tyler Sanders" << std::endl << std::endl;


	roster.parse(studentData);
	roster.printAll();
	roster.printInvalidEmails();
	for (int i = 0; i <= roster.Roster::ARR_INDEX; i++) {
		roster.printAverageDaysInCourse(roster.Roster::classRosterArray[i]->GetId());
	}
	roster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	roster.remove("A3");
	roster.printAll();
	roster.remove("A3");

}
