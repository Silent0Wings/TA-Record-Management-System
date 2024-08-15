#include "TA.h"

/*(Constructors)*/

TA::TA()
{
	// Initialize member variables to default values
	Working_Hours = -1;
	Status = " ";
	First_Name = " ";
	Student_Id = -1;
	Dept = " ";
}

TA::TA(int wh, std::string s, std::string fn, int si, std::string dp) : Working_Hours{ wh }, Status{ s }, First_Name{ fn }, Student_Id{ si }, Dept{ dp }
{
	// Set member variables with provided values using list initialisation
}

/* (Member functions)*/

bool TA::is_Alum() const
{
	// Check if the status is "Alum"
	return (Status == "Alum");
}

std::string TA::output_Ta() const
{
	// Create and return a formatted string
	return (std::to_string(Working_Hours) + "\t" + Status + "\t" + First_Name + "\t" + std::to_string(Student_Id) + "\t" + Dept);
}

void TA::print(int val) const
{
	// Print TA information in a formatted way
	std::cout << std::string(15 * 6 + 5, '-') << std::endl;
	std::cout << "| " << val << " | " << std::setw(15) << std::to_string(Working_Hours) << " | " << std::setw(15) << Status << " | " << std::setw(15) << First_Name << " | " << std::setw(15) << std::to_string(Student_Id) << " | " << std::setw(15) << Dept << " | " << std::endl;
}

bool TA::data_Integrity() const
{
	if ((Working_Hours >= 0) && ((Status == "Alum" || Status == "UGrad" || Status == "Grad")) && (First_Name != " " && First_Name != "" && !First_Name.empty()) && (Student_Id >= 0) && (Dept != " " && Dept != "" && !Dept.empty()))
		return true; // Data integrity is maintained
	return false; // Data integrity is compromised
}

bool operator==(const TA& left, const TA& right)
{
	return (left.get_Working_Hours() == right.get_Working_Hours()
		&& left.get_Status() == right.get_Status()
		&& left.get_First_Name() == right.get_First_Name()
		&& left.get_Student_Id() == right.get_Student_Id()
		&& left.get_Dept() == right.get_Dept()) ? true : false;
}

/*(Getters)*/

int TA::get_Working_Hours() const
{
	// Return the value of Working_Hours
	return Working_Hours;
}

std::string TA::get_Status() const
{
	// Return the value of Status
	return Status;
}

std::string TA::get_First_Name() const
{
	// Return the value of First_Name
	return First_Name;
}

int TA::get_Student_Id() const
{
	// Return the value of Student_Id
	return Student_Id;
}

std::string TA::get_Dept() const
{
	// Return the value of Dept
	return Dept;
}

/*(Setters)*/

void TA::set_Working_Hours(const int val)
{
	// Ensure working hours is non-negative
	Working_Hours = (val > 0) ? val : 0;
}

void TA::set_Status(const std::string val)
{
	//check for invalid inputs
	if (val == "" || val == " " || val.empty())
		return;
	// Set the value of Status
	if (val == "Alum" || val == "UGrad" || val == "Grad")
	{
		Status = val;
	}
}

void TA::set_First_Name(const std::string val)
{
	//check for invalid inputs
	if (val == "" || val == " " || val.empty())
		return;
	// Set the value of First_Name
	First_Name = val;
}

void TA::set_Student_Id(const int val)
{
	// Ensure student ID is non-negative
	Student_Id = (val > 0) ? val : 0;
}

void TA::set_Dept(const std::string val)
{
	//check for invalid inputs
	if (val == "" || val == " " || val.empty())
		return;

	// Set the value of Dept in uppercase
	std::string temp = val;
	// Convert any string to upper case
	for (auto& x : temp)
		x = toupper(x);
	Dept = temp;
}