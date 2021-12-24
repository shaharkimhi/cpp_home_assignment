//Question 4 - Filesystem & args

// Task: Implement the code as described in the main body, make sure to handle cases when the requested file is not found or the "files" directory doesn't exists and you have to create it
// Prefer modern solutions over classic C style solutions and keep in mind that this code should be able to run in other windows, linux and other platforms (hint: '/' and '\' in file paths)


#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{

	//If user passed "create" argument
	//		Create (or overwrite) a file named *argument2.txt*  with the text "Hello from *argument3*" in a folder named "files" under the current working directory
	//else if user passed "read" argument
	//		read a file named* argument2* from a folder named "files" under the current working directory and print it to the console

	//Execution example (assuming working directory c:\code): question04.exe create test1 Nir - should create the file c:\code\files\test1.txt with the content "Hello from Nir"
	//Execution example (assuming working directory c:\code): question04.exe read test1  - should print "Hello from Nir" in the console (assuming the previous command was executed)

	std::string command = argv[1];
	std::string file_name = argv[2];
	if (command == "create")
	{
		std::string output_str = argv[3];
		int files_folder = mkdir("files", 0777); // create files folder if doesn't exist
		std::ofstream new_file("files/" + file_name + ".txt"); // create new file
		new_file << "Hello from " + output_str;
		new_file.close();
	}
	else if (command == "read")
	{
		std::fstream file;
		file.open("files/" + file_name + ".txt", std::ios::in);
		if (!file) // if the require file doesn't exist
		{
			std::cout << "No such file";
		}
		else
		{
			std::string line;
			while (file.good())
			{
				std::getline(file, line);
				std::cout << line << '\n'; // prints the current line
			}
		}
		file.close();
	}
	std::cout << "Press enter to exit" << std::endl;
	getchar();
	return 0;
}
