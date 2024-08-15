#include "Load_Save.h"




void manual_Load(const std::string Path, std::vector <TA>& TA_vec)
{
	// This function reads lines from an input file, converts each line into a string,
	//  and collects these strings in a vector.The function then returns this vector, as indicated by its return type.

	std::ifstream Infile;
	Infile.open(Path);
	if (!Infile.is_open())
	{
		throw Failed_To_Open();
	}
	if (Infile.peek() == std::ifstream::traits_type::eof()) {
		throw File_Is_Empty();
	}

	Current_Path = Path;

	int num;
	Infile >> num;
	if (num > 100)
	{
		throw Ta_File_Out_Of_Range();
	}
	int const size = num;

	std::string line;
	while (getline(Infile, line))
	{
		if (line.empty())
			continue; // Skip empty lines
		// parsing the string
		std::vector<std::string> tem_vec = separate_String(line);
		if (tem_vec.size() == 5)
		{
			TA temp_Ta(stoi(tem_vec.at(0)), tem_vec.at(1), tem_vec.at(2), stoi(tem_vec.at(3)), (tem_vec.at(4)));
			TA_vec.push_back(temp_Ta); // Add TA to the vector
		}
		else if (tem_vec.size() == 6)
		{
			TA temp_Ta(stoi(tem_vec.at(0)), tem_vec.at(1), tem_vec.at(2) + " " + tem_vec.at(3), stoi(tem_vec.at(4)), (tem_vec.at(5)));
			TA_vec.push_back(temp_Ta); // Add TA to the vector
		}
	}
	Infile.close(); //close the intput file
	// remove duplicates from ta vector
	delete_Ta_Duplicate(TA_vec);
	print_Vector(TA_vec, false);
}

void auto_Save(std::ofstream& outfile, const std::vector<TA>& TA_vec)
{
	//This function requires an output file and a vector of tasks as parameters.It utilizes the already
	//	open output file to write the count of tasks that are not associated with alumni.It then utilizes the
	//	output_Ta function within each task to print the data in a single line and appends it to the file.
	int size_Of_Non_Alum = 0;
	if (TA_vec.empty())
	{
		throw Empty_Vector();
	}
	for (size_t i = 0; i < TA_vec.size(); i++)
	{
		size_Of_Non_Alum += (TA_vec[i].is_Alum() == false) ? 1 : 0; // Count non-alumni TAs
	}

	outfile << std::to_string(size_Of_Non_Alum) + "\n"; // Output the number of non alumni students
	for (int i = 0; i < TA_vec.size(); i++)
	{
		if (TA_vec.at(i).is_Alum() == false)
		{
			// This allows avoiding having a line at the end of the file that contains nothing
			if (i == (int)(TA_vec.size() - 1))
			{
				outfile << TA_vec[i].output_Ta(); // Output TA data to the file
			}
			else
			{
				outfile << TA_vec[i].output_Ta() << std::endl; // Output TA data to the file
			}
		}
	}

	if (outfile.tellp() == 0) {
		throw Failed_To_Save();
	}
	outfile.close(); //close the output file

	if (outfile.is_open() == true)
		throw Failed_To_Close(); // Handle closing error
}

void manual_Save(const std::vector<TA>& TA_vec)
{
	if (TA_vec.empty())
	{
		throw Empty_Vector();
	}

	//	This function requires a vector of tasks as parameters.It open output file
	//	then call the auto save method
	int attemptCount = 0;
	while (true)
	{
		attemptCount++;
		if (attemptCount > INPUT_ERROR_TOLERANCE)
		{
			log_Error("-To many wrong file names entered-");
			return;
		}
		//  Repeatedly input the user the try allows the program to keep attempting
		// until the user enters the correct file name.
		try
		{
			std::string Path;//the path of the file is stored here
			std::string test = string_Input("Enter the name of the file : ");
			if (test.find(FILE_EXTENSION) == std::string::npos)
			{
				Path = test + FILE_EXTENSION;
			}
			else
			{
				Path = test;
			}
			// open output file;
			std::ofstream outfile(Path);
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
				outfile.close(); //closing the file
				if (outfile.is_open())
					throw Failed_To_Close();// Handle closing error
				std::cout << std::endl << "-File Saved-" << std::endl;
				break;

			}
			continue;
		}
		catch (const char* error)
		{
			log_Error(error);// Handle exceptions with a character array message
		}
		catch (const std::runtime_error& e)
		{
			log_Error(static_cast<std::string>(e.what())); // Handle the exception thrown when failing to close the input file
		}
		catch (const std::exception& e)
		{
			log_Error("Error: " + *e.what()); // Handle the exception thrown when failing to close the input file
		}
	}
}

std::vector<std::string> separate_String(const std::string& source)
{
	//This function takes a string as input.It iterates through the characters of the string,
	//and whenever it encounters a tab character('\t'), it appends the built string to a vector,
	//resets the string, and continues building.This process continues until it reaches the end of the string,
	//where it appends the final string to the vector.

	std::vector<std::string> vec;
	std::string temp = "";
	for (size_t i = 0; i < source.length(); i++)
	{
		if (source[i] == '\t')// checks for tab character
		{
			// if a tab character is detected the string temp value is added to the vector
			vec.push_back(temp);
			temp = "";
		}
		else
		{
			temp += source[i];
			if (i == (source.length() - 1))
			{
				// if end of string is detected is detected the string temp value is added to the vector
				vec.push_back(temp);
			}
		}
	}
	return vec; // Return the vector containing separated strings
}