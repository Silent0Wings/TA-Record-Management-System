#include "TA_Record_Management_System.h"

int main()
{
	//to repeat the program without closing the console or putting another nested loop 
	// Vector of Ta's
	std::vector <TA> TA_vec;
	TA_vec.clear();
	//This try block is designed to catch errors during the (A)&(B)&(C) phase.
	try
	{
		//Part (A)
		loading_Behavior(TA_vec);

		//Part (B) & (C)
		user_Interaction(TA_vec);

	}
	catch (const char* error)
	{
		log_Error(error);// Handle exceptions with a character array message
	}
	catch (const std::runtime_error& e)
	{
		log_Error(static_cast<std::string>(e.what())); // Handle runtime exceptions 
	}
	catch (const std::exception& e)
	{
		log_Error(static_cast<std::string>(e.what()));// Handle exceptions 
	}

}

/* Functions */

void filterInvalidTAs(const std::string Path, std::vector <TA>& TA_vec)
{
	// This method invokes the auto_Load and auto_Save behavior by creating the input and output files,
	// ensuring that all elements are accounted for, including error handling.

	// Implement loading and building the file
	manual_Load(Path, TA_vec);// Load data from the file
	if (!TA_vec.empty())
	{
		// Implement saving and building the file
		std::ofstream outfile;
		outfile.open(Path);
		if (!outfile.is_open() || TA_vec.empty())
		{
			std::string temp = "";
			if (!outfile)
				temp += "Found while opening output file \n";// Handle opening error
			if (TA_vec.empty())
				temp += "Found Empty TA vector \n"; //Handle empty vector
			throw std::runtime_error(temp);// Handle closing error
		}
		else
		{
			Current_Path = Path;
			auto_Save(outfile, TA_vec);// Save data to the file
		}

	}
}

void loading_Behavior(std::vector <TA>& TA_vec)
{
	//counter of how many input errors
	int attemptCount = 0;
	while (TA_vec.empty())
	{
		attemptCount++;
		if (attemptCount > INPUT_ERROR_TOLERANCE)
		{
			log_Error("-To many wrong file names entered-");
			std::cout << std::endl << "-*[({Program Terminated})]*-" << std::endl << std::endl;
			std::exit(0);
			return;
		}
		// This try block is designed to catch errors during the (A) phase.
		// Repeating the try allows the program to keep attempting
		// until the user enters the correct file name.
		try
		{
			std::string Path;//the path of the file is stored here
			std::string test = string_Input("Enter the name of the file: ");

			// This part adds FILE_EXTENSION in case the user doesn't specify the format of the file
			// and ensures it is present if it's not already specified.
			if (test.find(FILE_EXTENSION) == std::string::npos)
			{
				Path = test + FILE_EXTENSION;
			}
			else
			{
				Path = test;
			}
			// Read a file, parse the data, and store it in a vector of type TA.
			// Then auto_Save the filtered files in the same original position.
			filterInvalidTAs(Path, TA_vec);
			if (TA_vec.empty())
			{
				throw Empty_Vector();

			}
			else
			{
				pause_Input();
				screen_Clear();
				break;
			}
		}
		catch (const char* error)
		{
			log_Error(error);// Handle exceptions with a character array message
		}
		catch (const std::runtime_error& e) {
			// Handle the exception thrown when failing to close the input file
			log_Error(static_cast<std::string>(e.what())); // Handle the exception thrown when failing to close the input file

		}
		catch (const std::out_of_range& e)
		{
			log_Error(static_cast<std::string>(e.what()));// Handle exceptions 
		}
		catch (const std::exception& e)
		{
			log_Error(static_cast<std::string>(e.what()));// Handle exceptions 
		}
	}
}

void user_Interaction(std::vector <TA>& TA_vec)
{

	bool terminate = false;
	// Main program loop
	while (!terminate) // If terminate is false, then the loop continues; if not, it terminates.
	{

		// helps stops infinite loop from wrong input into a cin
		std::cin.clear();

		std::string command_input = " ";
		int command = 0;

		screen_Clear();
		print_Command();
		if (!TA_vec.empty())// this to alwayse go back to the loading behavior in case the vector is empty
		{
			std::cout << std::string(' ', 5);
			command_input = string_Input("Enter a command : ");
			if (command_input.length() == 1 && is_Numeric(command_input) && verify_Int(command_input))
			{
				command = std::stoi(command_input);
			}
		}
		else
		{
			command = All_Commands::COMMAND_LOAD;
		}

		std::cout << std::endl << "*" << std::endl << std::endl;

		// This is the command comparison part
		try {
			std::cout << "Path : " << Current_Path << std::endl;

			switch (command)
			{
			case (All_Commands::COMMAND_PRINT):
			{
				print_Vector(TA_vec);// Display the contents of TA_vec

				break;
			}
			case (All_Commands::COMMAND_ADD_TA):
			{
				addNewTA(TA_vec);	//	Allow the user to add a new TA
				std::ofstream outfile(Current_Path);
				auto_Save(outfile, TA_vec);
				pause_Input();
				break;
			}
			case (All_Commands::COMMAND_SORT):
			{
				sort_Ta_By_Column(TA_vec); // Allow the user to sort TAs based on a selected column
				std::ofstream outfile(Current_Path);
				auto_Save(outfile, TA_vec);
				pause_Input();

				break;
			}
			case (All_Commands::COMMAND_SAVE):
			{
				manual_Save(TA_vec);
				pause_Input();
				screen_Clear();
				break;
			}
			case (All_Commands::COMMAND_LOAD):
			{
				std::string delete_com = " ";
				if (!TA_vec.empty())
				{
					delete_com = string_Input("\nAll current Tas will be deleted (enter \"del\" to proceed): \n");

					if (delete_com == "del")
					{
						TA_vec.clear();
						std::cout << std::endl << "All TAS are deleted ." << std::endl << std::endl;
					}

					else
					{
						std::cout << std::endl << "You entered |" << delete_com << "| please enter \"del\"" << std::endl << std::endl;
					}

				}

				if (TA_vec.empty())
				{
					loading_Behavior(TA_vec);
				}


				break;
			}
			case (All_Commands::COMMAND_TERMINATE):
			{
				terminate = true;// Set terminate to true to exit the program
				std::cout << std::endl << "-*[({Program Terminated})]*-" << std::endl << std::endl;
				break;
			}
			default:
			{
				continue;
			}
			}
		}
		catch (const char* error)
		{
			log_Error(error);// Handle exceptions with a character array message
		}
		catch (const std::runtime_error& e)
		{
			log_Error(static_cast<std::string>(e.what())); // Handle runtime exceptions 
		}
		catch (const std::out_of_range& e)
		{
			log_Error(static_cast<std::string>(e.what()));// Handle exceptions 
		}
		catch (const std::exception& e)
		{
			log_Error(static_cast<std::string>(e.what()));// Handle exceptions 
		}
	}

}

void addNewTA(std::vector <TA>& TA_vec)
{
	//This method facilitates the addition of a new Teaching Assistant(TA) by taking user input
	//  and simultaneously ensuring the integrity of the entered data.
	//local variable that are matched to the class TA
	TA newTa;

	int Main_attemptCount = 0;
	//string variable for all inputs in this method
	std::string input = "";
	// this inputs the user for the amount of working hours
	int attemptCount = 0;
	input = "";
	input = string_Input("-Enter the amount of working hours (int)) >=0\n");
	while (attemptCount < INPUT_ERROR_TOLERANCE)
	{
		if (attemptCount > INPUT_ERROR_TOLERANCE)
		{
			throw Too_Many_Attempts();
		}
		if (attemptCount != 0)
		{
			input = "";
			input = string_Input("-Enter the amount of working hours (int) >=0\n");
		}
		if (verify_Int(input))
		{
			int number = std::stoi(input);
			newTa.set_Working_Hours(number);
			break;
		}
		attemptCount++;

	}

	// this inputs the user for the Status
	attemptCount = 0;
	input = "";
	input = string_Input("-Enter the Status (string: Alum/UGrad/Grad)\n");
	while (attemptCount < INPUT_ERROR_TOLERANCE)
	{
		if (attemptCount > INPUT_ERROR_TOLERANCE)
		{
			throw Too_Many_Attempts();
		}
		if (attemptCount != 0)
		{
			input = "";
			input = string_Input("-Enter the Status (string: Alum/UGrad/Grad)\n");

		}
		if (input == "Alum" || input == "UGrad" || input == "Grad")
		{
			newTa.set_Status(input); // Set TA status
			break;
		}
		attemptCount++;
	}

	// this inputs the user for the first name
	attemptCount = 0;
	input = "";
	input = string_Input("-Enter the first name (string)\n");

	while (attemptCount < INPUT_ERROR_TOLERANCE)
	{
		if (attemptCount > INPUT_ERROR_TOLERANCE)
		{
			throw Too_Many_Attempts();
		}
		if (attemptCount != 0)
		{
			input = "";
			input = string_Input("-Enter the first name (string)\n");
		}
		if (input != "")
		{
			newTa.set_First_Name(input); // Set TA first name
			break;
		}
		attemptCount++;
	}

	// this inputs the user for the student id
	attemptCount = 0;
	input = "";
	input = string_Input("-Enter the student id (int) >=0\n");
	while (attemptCount < INPUT_ERROR_TOLERANCE)
	{
		if (attemptCount > INPUT_ERROR_TOLERANCE)
		{
			throw Too_Many_Attempts();
		}
		if (attemptCount != 0)
		{
			input = "";
			input = string_Input("-Enter the student id (int) >=0\n");
		}
		if (input != "" && verify_Int(input))
		{
			int number = std::stoi(input);
			if (ta_Duplicate(TA_vec, number))
			{
				std::cout << "Student Id already exist" << std::endl;
				input = "";
				continue;
			}
			newTa.set_Student_Id(number);
			break;
		}
		attemptCount++;
	}

	// this inputs the user for the department name
	attemptCount = 0;
	input = "";
	input = string_Input("-Enter the name of the department (string)\n");
	while (attemptCount < INPUT_ERROR_TOLERANCE)
	{
		if (attemptCount > INPUT_ERROR_TOLERANCE)
		{
			throw Too_Many_Attempts();
		}
		if (attemptCount != 0)
		{
			input = string_Input("-Enter the name of the department (string)\n");
		}
		if (input != "")
		{
			newTa.set_Dept(input); // Set TA department
			break;
		}
		attemptCount++;
	}

	//clearing the screen
	screen_Clear();

	// Print TA information
	print_Ta_Data(newTa);

	// input the user to check wether they want to repeat the process
	input = "";
	std::cout << "-Confirm if the data entered is correct (if it is not you will be returned to the main menu):" << std::endl;
	input = string_Input("( yes = 1 | No = [ any value other than 1 ] ):\n");
	if (input == "1")
	{
		std::cout << "new Ta being processed" << std::endl;
	}
	else
	{
		return;
	}

	if (newTa.data_Integrity())// if the data integrity of the values entered are acceptable then we proceed
	{
		//adding the ta to vector
		if (newTa.data_Integrity())	//	data integrity of the added Ta
		{
			if (ta_Duplicate(TA_vec, newTa.get_Student_Id()))
			{
				throw Duplicate_Element();// Handle closing error
			}
			else
			{
				TA_vec.push_back(newTa);// Add the new TA to the vector
			}
		}
		else
		{
			log_Error("Failed to add Ta due to bad input");
		}
	}
	else
	{
		log_Error("Data Entered is invalid please try again"); // Handle bad input
	}
}

void sort_Ta_By_Column(std::vector<TA>& tas)
{
	//This function allows the user to order a vector of Teaching Assistants(tas) based on a selected column
	//  and sorting order.The user inputs the column and sorting order, with error - checking loops for invalid
	//  inputs.The function then uses a switch statement to determine the selected column and sorts the TAs accordingly.
	// and in the end it calls the print_Vector function to display the sorted TAs.

	// to check if a the vector has 1 or less element since that dose not need to be sorted
	if (tas.empty() || tas.size() <= 1)
	{
		return;
	}
	//this inputs the user for which column to sort
	std::cout << "Select a column to order by " << std::endl << "(";
	std::cout << SortingColumn::WORKING_HOURS << ": Working_Hours, " << std::endl;
	std::cout << SortingColumn::STATUS << ": Status, " << std::endl;
	std::cout << SortingColumn::FIRST_NAME << ": First_Name, " << std::endl;
	std::cout << SortingColumn::STUDENT_ID << ": Student_Id, " << std::endl;
	std::cout << SortingColumn::DEPT << ": Dept): " << std::endl;

	int choice = -1;
	int attemptCount = 0;
	while ((choice <= 0 || choice >= 6)) // loop for in case of mistakes during input phase
	{
		if (attemptCount >= INPUT_ERROR_TOLERANCE)
		{
			throw Too_Many_Attempts();
		}

		std::cin.ignore();
		choice = integer_Input("Enter the right column to order order (1 to 5): ");
		if ((choice <= 0 || choice >= 6))
			std::cout << std::endl << "Invalid input (" << choice << ").";
		attemptCount++;
	}

	//this inputs the user for which order
	std::string sortOrder = " ";
	std::cout << "Enter sorting order (asc or desc): ";
	attemptCount = 0;
	while ((sortOrder != "asc" && sortOrder != "desc")) // loop for in case of mistakes during input phase
	{
		if (attemptCount >= INPUT_ERROR_TOLERANCE)
		{
			throw Too_Many_Attempts();
		}
		sortOrder = string_Input("Enter sorting order (asc or desc): ");
		if ((sortOrder != "asc" && sortOrder != "desc"))
			std::cout << std::endl << "Invalid input (" << sortOrder << ").";
		attemptCount++;
	}

	// Display the un_sorted TAs
	std::cout << std::endl << "-Before : " << std::endl;
	print_Vector(tas, false); // Display the sorted TAs without pausing

	// this proccess the sorting behavior using the algorithm library
	switch (choice)
	{
	case SortingColumn::WORKING_HOURS: // Sort Ta's by working hours (int)
		std::sort(tas.begin(), tas.end(), [&](const TA& a, const TA& b) {
			return sortOrder == "asc" ? a.get_Working_Hours() < b.get_Working_Hours() : a.get_Working_Hours() > b.get_Working_Hours();
			});
		break;
	case SortingColumn::STATUS: // Sort Ta's by status (string)
		std::sort(tas.begin(), tas.end(), [&](const TA& a, const TA& b) {
			return sortOrder == "asc" ? a.get_Status() < b.get_Status() : a.get_Status() > b.get_Status();
			});
		break;
	case SortingColumn::FIRST_NAME: // Sort Ta's by first name (string)
		std::sort(tas.begin(), tas.end(), [&](const TA& a, const TA& b) {
			return sortOrder == "asc" ? a.get_First_Name() < b.get_First_Name() : a.get_First_Name() > b.get_First_Name();
			});
		break;
	case SortingColumn::STUDENT_ID: // Sort Ta's by student id (int)
		std::sort(tas.begin(), tas.end(), [&](const TA& a, const TA& b) {
			return sortOrder == "asc" ? a.get_Student_Id() < b.get_Student_Id() : a.get_Student_Id() > b.get_Student_Id();
			});
		break;
	case SortingColumn::DEPT: // Sort Ta's by department (string)
		std::sort(tas.begin(), tas.end(), [&](const TA& a, const TA& b) {
			return sortOrder == "asc" ? a.get_Dept() < b.get_Dept() : a.get_Dept() > b.get_Dept();
			});
		break;
	default: // wrong input
		std::cerr << std::endl;
		log_Error("Invalid choice.");
		return;
	}

	// Display the sorted TAs
	std::cout << std::endl << "-After : " << std::endl;
	print_Vector(tas, false); // Display the sorted TAs without pausing
}