#include "CustomExceptions.h"

Failed_To_Open::Failed_To_Open(const std::string& _Message) : runtime_error(_Message + "Failed to open file.") {};

Failed_To_Close::Failed_To_Close(const std::string& _Message) : runtime_error(_Message + "Failed to close file.") {};

Empty_Vector::Empty_Vector(const std::string& _Message) : runtime_error(_Message + "Empty Vector.") {};

Too_Many_Attempts::Too_Many_Attempts(const std::string& _Message) : runtime_error(_Message + "Too Many Attempts.") {};

Duplicate_Element::Duplicate_Element(const std::string& _Message) : runtime_error(_Message + "Duplicated Ta Found.") {};

Ta_File_Out_Of_Range::Ta_File_Out_Of_Range(const std::string& _Message) : out_of_range(_Message + "Ta File Out Of Range > 100.") {};

File_Is_Empty::File_Is_Empty(const std::string& _Message) : runtime_error(_Message + "The file inputted is empty.") {};

Failed_To_Save::Failed_To_Save(const std::string& _Message) : runtime_error(_Message + "Failed to save File.") {};