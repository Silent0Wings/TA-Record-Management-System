#include "general.h"

/* Example file :
6
13	Alum	Philip	9114426	MIAE
13	Alum	Thanusan	1666534	ECE
6	Alum	Daksh	5434733	ECE
11	UGrad	Aboubacrys	2252689	MIAE
7	UGrad	Udaipal	4439033	CIS
7	Grad	Charles	9740058	BIS
*/


/*-(General Methods)*/

bool is_Numeric(const std::string& str) {
	for (const char& ch : str) {
		if (!std::isdigit(ch)) {
			return false;
		}
	}
	return true;
}

bool verify_Int(const std::string& input)
{
	//this function converts a string to an integer, handling exceptions. It checks for valid integers,
	//  negative values, invalid arguments, and out-of-range values. If successful, it returns true;
	//  otherwise, it handles and prints relevant error messages and returns false.

	try
	{
		if (!is_Numeric(input))
		{
			throw std::invalid_argument(static_cast<std::string>(input) + " Contains letters.");
		}

		int number = std::stoi(static_cast<std::string>(input));
		if (number < 0)
		{
			throw std::runtime_error(static_cast<std::string>(input) + " Negative values are not allowed."); // Throw out_of_range exception
		}
		else
		{
			return true;
		}
	}
	catch (const std::invalid_argument& e)
	{
		log_Error(static_cast<std::string>(e.what())); // Handle out_of_range exception
	}
	catch (const std::out_of_range& e)
	{
		log_Error(static_cast<std::string>(e.what())); // Handle out_of_range exception
	}
	catch (const char* error)
	{
		log_Error(error); // Handle string error
	}
	catch (const std::runtime_error& e)
	{
		log_Error(static_cast<std::string>(e.what())); // Handle the exception thrown when failing to close the input file
	}
	return false;
}

/* (Console manipulations) */

void log_Error(const std::string& val)
{
	std::cerr << std::endl << val << std::endl;
}

void print_Command()
{
	std::cout << "||Available Commands : ||" << std::endl;
	std::cout << "||" << std::string(15 * 2, '-') << "|| " << std::endl;
	std::cout << "||" << std::setw(3) << All_Commands::COMMAND_PRINT << "|" << std::setw(20) << "-Prints all Ta's" << std::endl;
	std::cout << "||" << std::setw(3) << All_Commands::COMMAND_ADD_TA << "|" << std::setw(20) << "-Add a new Ta" << std::endl;
	std::cout << "||" << std::setw(3) << All_Commands::COMMAND_SORT << "|" << std::setw(20) << "-Sort all Ta's" << std::endl;
	std::cout << "||" << std::setw(3) << All_Commands::COMMAND_SAVE << "|" << std::setw(20) << "-Saving the current data" << std::endl;
	std::cout << "||" << std::setw(3) << All_Commands::COMMAND_LOAD << "|" << std::setw(20) << "-Load a new file" << std::endl;
	std::cout << "||" << std::setw(3) << All_Commands::COMMAND_TERMINATE << "|" << std::setw(20) << "-Terminate program" << std::endl;
	std::cout << "||" << std::string(15 * 2, '-') << "|| " << std::endl;
}

void screen_Clear()
{
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

void pause_Input()
{
	// Press enter to continue behavior (only skips if enter is pressed)
	std::cout << "--{[*Press Enter To Continue*]}--";
	std::cin.ignore();
	std::cin.get();
}

std::string string_Input(const std::string& Message)
{
	if (Message != " ")
		std::cout << Message; // The name of the file is Tas.txt
	std::string test = "";
	std::cin >> test;
	return test;
}

int integer_Input(const std::string& Message)
{
	if (Message != " ")
		std::cout << Message; // The name of the file is Tas.txt
	int test = 0;
	std::cin >> test;
	return test;
}

/* (Ta manipulations) */

bool ta_Duplicate(const std::vector<TA>& tas, const int student_ID)
{
	//This function checks if a Ta with a given Student ID
	//  already exists in a vector of TAs, returning false if found and true otherwise.
	for (size_t i = 0; i < tas.size(); i++)
	{
		if (tas[i].get_Student_Id() == student_ID)
		{
			return true;
		}
	}

	return false;
}

void delete_Ta_Duplicate(std::vector<TA>& TA_vec)
{
	//This function deletes all ta that have are equal or have the same student id (not both only one of them)
	for (size_t i = 0; i < TA_vec.size(); i++)
	{
		for (size_t z = 0; z < TA_vec.size(); z++)
		{
			if ((i != z) && (TA_vec[i] == TA_vec[z] || TA_vec[i].get_Student_Id() == TA_vec[z].get_Student_Id())) {
				TA_vec.erase(TA_vec.begin() + z);
			}
		}
	}
}

void print_Ta_Data(const TA & val)
{
	// Print TA information
	std::cout << std::string(15 * 6 + 4, '-') << '\n';
	std::cout << "| " << " " << " | " << std::setw(15) << "(Working_Hours)" << " | " << std::setw(15) << "(Status)" << " | " << std::setw(15) << "(First_Name)" << " | " << std::setw(15) << "(Student_Id)" << " | " << std::setw(15) << "(Dept)" << " | " << '\n';
	std::cout << std::string(15 * 6 + 4, '-') << '\n';
	std::cout << "| " << " " << " | " << std::setw(15) << std::to_string(val.get_Working_Hours()) << " | " << std::setw(15) << val.get_Status() << " | " << std::setw(15) << val.get_First_Name() << " | " << std::setw(15) << std::to_string(val.get_Student_Id()) << " | " << std::setw(15) << val.get_Dept() << " | " << '\n';
	std::cout << std::string(15 * 6 + 4, '-') << '\n';
}

void print_Vector(const std::vector<TA>& TA_vec, bool pause)
{
	// this function displays information about(TAs) stored in a vector(TA_vec).
	// It iterates through the vector, printing details about each TA using the print method of the class ta
	// also the bool value is to decide wether the screen pauses after printing or not
	std::cout << std::string(15 * 6 + 5, '-') << std::endl;
	std::cout << "| " << " " << " | " << std::setw(15) << "(Working_Hours)" << " | " << std::setw(15) << "(Status)" << " | " << std::setw(15) << "(First_Name)" << " | " << std::setw(15) << "(Student_Id)" << " | " << std::setw(15) << "(Dept)" << " | " << std::endl;
	for (size_t i = 0; i < TA_vec.size(); i++)
	{
		TA_vec[i].print((int)i); // Print TA information
	}
	std::cout << std::string(15 * 6 + 5, '-') << std::endl;
	std::cout << std::endl;
	if (pause)
		pause_Input();
}