/*
 * Description: This program manages TA records, including filtering alumni TAs, adding new TAs, and sorting TAs.
 */

#include "load_save.h"

// This function is the entry point of the program
int main();

// Filter out alumni students from a text file and then output the corrected data back to the original file from the class TA
void filterInvalidTAs(const std::string Path, std::vector<TA>& TA_vec);

// This function handles the loading process, reading data from a file into a vector of TAs while parsing
void loading_Behavior(std::vector<TA>& TA_vec);

// The Console loop that interacts with the user after the loading phase and allows command selection
void user_Interaction(std::vector<TA>& TA_vec);

// Allow the user to input data for a new TA and to verify that data before processing
void addNewTA(std::vector <TA>& TA_vec);

// Function to order TAs based on a selected column either ascending or descending
void sort_Ta_By_Column(std::vector<TA>& tas);