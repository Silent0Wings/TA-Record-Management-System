# TA Record Management System

## Overview
Project Repport .[here](https://github.com/Silent0Wings/TA-Record-Management-System/blob/a5e4376687cc96c13b8f3afed047920d05505c35/Github.pdf).
The TA Record Management System is a C++ program designed to manage records of Teaching Assistants (TAs) in a department. The system allows for the filtering of invalid records, adding new TA records, and sorting the existing records based on various criteria.

## Features

- **Filtering Invalid Records**: The system filters out records of TAs who have graduated (classified as "Alum") and removes them from the list.
- **Adding New Records**: Users can add new TA records to the system. The program ensures that no duplicate Student IDs are added.
- **Sorting Records**: The program allows users to sort TA records by different columns, such as Working Hours, Status, First Name, Student ID, and Department, in either ascending or descending order.

## How to Run

1. **Compile the Program**: 
   - Ensure that you have a C++ compiler installed.
   - Compile the code using your preferred C++ compiler. For example:
     ```bash
     g++ -std=c++11 main.cpp -o ta_record_management
     ```

2. **Run the Program**:
   - Execute the compiled binary:
     ```bash
     ./ta_record_management
     ```

3. **Interact with the Program**:
   - Follow the on-screen prompts to load TA records, filter them, add new records, or sort the existing records.
   - The program will guide you through each step and ensure that your inputs are valid.

## Structure

- **Main Program**: Manages the flow of the application, including initializing data, handling errors, and directing user interaction.
- **Filtering Invalid Records**: Reads TA data from a file, removes invalid records, and saves the updated list.
- **Adding New TAs**: Prompts the user to input new TA details, ensuring data integrity and uniqueness.
- **Sorting Records**: Allows the user to sort TA records based on selected criteria and saves the sorted list.

## Error Handling
The program includes robust error handling for:
- Invalid file names or paths.
- Duplicate Student IDs during the addition of new records.
- Invalid inputs for sorting or other operations.

## Requirements
- A C++11 or later compiler.

## Notes
- The program uses a simple text file to store and manage TA records. Ensure that the file is in the correct format as expected by the program.
- Make sure the file path and name are correctly provided when prompted.

## License
This project is for educational purposes and does not carry a specific license.
