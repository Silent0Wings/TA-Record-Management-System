#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class TA
{
private:
	// Member variables
	int Working_Hours;    // Number of working hours
	std::string Status;   // Status of the TA (Alum, UGrad, Grad)
	std::string First_Name;  // First name of the TA
	int Student_Id;       // Student ID of the TA
	std::string Dept;     // Department of the TA (All Caps)

public:
	/*(Constructors)*/

	// Default constructor
	TA();
	// Parameterized constructor (List Initialization)
	TA(int wh, std::string s, std::string fn, int si, std::string dp);

	/* (Member functions)*/

	// Check if TA is an alumni
	bool is_Alum() const;

	// Return a formatted string containing TA information
	std::string output_Ta() const;

	// Print TA information with formatting
	void print(int) const;

	// Check if Data Integrity is Ok 
	bool data_Integrity() const;

	// Overload the == operator to be able to know if two TAS are equal or not
	friend bool operator==(const TA& lhs, const TA& rhs);

	/*(Getters)*/

	// Get the number of working hours
	int get_Working_Hours() const;

	// Get the status of the TA
	std::string get_Status() const;

	// Get the first name of the TA
	std::string get_First_Name() const;

	// Get the student ID of the TA
	int get_Student_Id() const;

	// Get the department of the TA
	std::string get_Dept() const;

	/*(Setters)*/

	// Set the number of working hours (non-negative)
	void set_Working_Hours(const int);

	// Set the status of the TA
	void set_Status(const std::string);

	// Set the first name of the TA
	void set_First_Name(const std::string);

	// Set the student ID of the TA (non-negative)
	void set_Student_Id(const int);

	// Set the department of the TA
	void set_Dept(const std::string);
};