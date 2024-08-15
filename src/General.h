#pragma once

#include "CustomExceptions.h"
#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <algorithm>
#include <vector>
#include "TA.h"

/*-(Members)*/

// Accepted FILE_EXTENSION for saving and loading
const std::string FILE_EXTENSION = ".txt";

// Error tolerance for how many wrong inputs users are allowed to make
const size_t INPUT_ERROR_TOLERANCE = 8;

// Enum containing all the commands available for the user
enum All_Commands
{
	COMMAND_PRINT = 0,
	COMMAND_ADD_TA = 1,
	COMMAND_SORT = 2,
	COMMAND_SAVE = 3,
	COMMAND_LOAD = 4,
	COMMAND_TERMINATE = 5
};

// Enum containing all the possible sorting orders of the columns for TAs
enum SortingColumn
{
	WORKING_HOURS = 1,
	STATUS = 2,
	FIRST_NAME = 3,
	STUDENT_ID = 4,
	DEPT = 5
};

/*-(General Methods)*/

// Verify if a string contains a number or not
bool is_Numeric(const std::string& str);

// Exception handling for casting string to int
bool verify_Int(const std::string& input);

/* (Console manipulations) */

// Handle logging errors using cerr
void log_Error(const std::string& val);

// Display all available commands
void print_Command();

// Allows clearing the console for Windows and others
void screen_Clear();

// A method that demands a random input to continue the program to implement a pausing behavior
void pause_Input();

// Read an input from the user and return a string
std::string string_Input(const std::string& Message);

// Read an input from the user and return an integer
int integer_Input(const std::string& Message);

/* (Ta manipulations) */

// Determines whether we already have a TA with the same Student Id 
bool ta_Duplicate(const std::vector<TA>& tas, const int student_ID);

// Delete TAs with identical data or similar student id
void delete_Ta_Duplicate(std::vector<TA>& TA_vec);

// Display TA information in a table layout
void print_Ta_Data(const TA& val);

// Display TAs in the vector in a table layout
void print_Vector(const std::vector<TA>& TA_vec, bool pause = true);