#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>

#include "SID/sid.h"
#include "SID/siddb.h"

#define SID(str) (StringID{str})
#define SID_VAL(str) (StringIdHash(str))


void printUsage()
{
	std::cout << "Usage: SID_Client.exe <string>" << std::endl;
	std::cout << "--list: list all string IDs and corresponding strings" << std::endl;
	std::cout << "--clean: remove all string IDs and corresponding strings" << std::endl;
	std::cout << "--save: save all string IDs and corresponding strings to file" << std::endl;
	std::cout << "--convert: convert string to a FNV-1 Hash" << std::endl;
	std::cout << "--load: load all string IDs and corresponding strings from file" << std::endl;
	std::cout << "--exit: exit program" << std::endl;
	std::cout << "--help: print this help" << std::endl;
}

int main()
{

	printUsage();
	char input[10];
	std::cout << "> ";
	std::cin >> input;

	if (strcmp(input, "--save") == 0) {
		SID::DB::saveHash();
	}
	else if (strcmp(input, "--convert") == 0)
	{
		std::cout << "Enter a string to convert to a FNV-1 Hash: ";
		char input[15];
		std::cin >> input;

		printf("FNV-1 Hash: %llu\n", SID_VAL(input));
		
	}

	
	return 0;

}

