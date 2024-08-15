// Custom exception classes for handling various file and vector-related errors.
// using polymorphism and delegate constructors,

#include <fstream>

// Custom exception class for the case when a file fails to open.
class Failed_To_Open : public std::runtime_error {
public:
	// Delegate constructor inheriting from std::runtime_error.
	Failed_To_Open(const std::string& _Message = "");
};

// Custom exception class for the case when a file fails to close.
class Failed_To_Close : public std::runtime_error {
public:
	// Delegate constructor inheriting from std::runtime_error.
	Failed_To_Close(const std::string& _Message = "");
};

// Custom exception class for the case when a vector is empty.
class Empty_Vector : public std::runtime_error {
public:
	// Delegate constructor inheriting from std::runtime_error.
	Empty_Vector(const std::string& _Message = "");
};

// Custom exception class for the case of too many attempts.
class Too_Many_Attempts : public std::runtime_error {
public:
	// Delegate constructor inheriting from std::runtime_error.
	Too_Many_Attempts(const std::string& _Message = "");
};

// Custom exception class for the case of a duplicate element in the vector.
class Duplicate_Element : public std::runtime_error {
public:
	// Delegate constructor inheriting from std::runtime_error.
	Duplicate_Element(const std::string& _Message = "");
};

// Custom exception class for the case of a 'Ta' file index being out of range.
class Ta_File_Out_Of_Range : public std::out_of_range {
public:
	// Delegate constructor inheriting from std::out_of_range.
	Ta_File_Out_Of_Range(const std::string& _Message = "");
};

// Custom exception class for the case when a file is empty.
class File_Is_Empty : public std::runtime_error {
public:
	// Delegate constructor inheriting from std::runtime_error.
	File_Is_Empty(const std::string& _Message = "");
};

// Custom exception class for the case when saving a file fails.
class Failed_To_Save : public std::runtime_error {
public:
	// Delegate constructor inheriting from std::runtime_error.
	Failed_To_Save(const std::string& _Message = "");
};
