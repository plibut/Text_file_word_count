#include <fstream> // used to read files 
#include <iostream>
#include <string>

int main() {
	std::ifstream file("example.txt"); //std::ifstream file opens a file     |     inside the folder of the executable programm

	bool weiter_machen = false; // will be set to true when user wants to start the programm

	if (file.is_open()) // .is_open() is a fuction of the std::ifstream class its used to check if the file is open the () indecated that this is a fuction call not just a name could also use file.good() function, does almost do the same
	{
		std::cout << "file opend sucsesfully!";

		bool vailed_input = false;
		bool has_it_looped = false;

		while (vailed_input == false) // loops this fuction untill it returns vailed_input = true
		{
			char yes_or_no; // could also use std::string "char" can only be 1 letter nor more

			if (has_it_looped == true)
			{
				std::cout << "\nInvailed input please try again! \n";
			}

			std::cout << "\n" << "Would you like to continue with the world counting?" << "\n" << "(Y)es or (N)o \n";
			std::cin >> yes_or_no;


			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// this pice of shit tell the program that all user input above 1 is just seen as 1 carackter 
			// this is doe so the code dosnt loop many times over if this didnt exist the code would loop many times over if the user input was for example "2888221"


			yes_or_no = std::toupper(yes_or_no); // std::toupper converts all user input into capslog
			// std::toupper must be used after the imput so before yes_or_no is defined so it knows what to put uppercase

			if (yes_or_no == 'Y') // To ehck for letters you need to use '' instead of ""
			{
				std::cout << "ok lets start than :p";
				vailed_input = true;
				weiter_machen = true;
			}
			else if (yes_or_no == 'N')
			{
				std::cout << "okay... program will not read your file and now has nothing to do :c \n";
				vailed_input = true;
			}
			else
			{
				has_it_looped = true;
			}

		}
	}
	else
	{
		std::cout << "There was a problem while opening the file!";
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (weiter_machen == true) // This is where the real function happens everything above is just a fance way of useless shit 
	{
		std::string words; // now that the programm knows "words" is a string so more than 1 carackter it will only count things as words that are also strings because i have defined words as srings
		int wordCount = 0;

		while (file >> words) // >> extracs the words from the file and puts them into the variable words that uses numbers 
		{
			wordCount = wordCount + 1; // increments wordCount by 1 whenever loop is active 
		}
		std::cout << "\n \n" << "Your file has " << wordCount << " words :o \n";

		if (wordCount > 100)
		{
			std::cout << "\nwow thats a lot of words :3 \n";
		}
		else if (wordCount < 15)
		{
			std::cout << "\nand you needed a program to count that? >.< \n";
		}
	}








	return 0;
}