#include "sid.h"
#include "siddb.h"

#include <stdlib.h>
#include <stdio.h>
#include <fstream>


SID::DB::DB()
{
	printf("Connected to SID database\n");
}

SID::DB::~DB()
{
	printf("Disconnected from SID database\n");
}

// Todo: save hash to file
void SID::DB::saveHash()
{
	std::ofstream file;
	file.open("SID_DB.txt");

	if(!file.is_open())
	{
		printf("Error: Could not open file\n");
		return;
	}
	
	std::cout << "Enter a string to save to file: ";
	char input[15];
	std::cin >> input;

	// done with file? close it
	file.close();
	
	
	
}