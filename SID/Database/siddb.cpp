#include "sid.h"
#include "siddb.h"

#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h>

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
	file.open("SID_DB.txt", std::fstream::app);

	if(!file.is_open())
	{
		printf("Error: Could not open file\n");
		return;
	}
	
	printf("Enter a string to save to the database: ");
	char input[15];
	std::cin >> input;

	// write to the file
	file << input << " -> " << SID_VAL(input) << std::endl;

	// done with file? close it
	file.close();
	
}

void SID::DB::loadHash()
{
	std::ifstream file("SID_DB.txt");

	if (!file.is_open())
	{
		printf("Error: Could not open file\n");
		return;
	}
	else
	{
		
		std::cout << file.rdbuf() << std::endl;
	}

	
	// done with file? close it
	file.close();
	
}

void SID::DB::cleanHash()
{
	std::ofstream file;
	file.open("SID_DB.txt", std::fstream::trunc);

	if (!file.is_open())
	{
		printf("Error: Could not open file\n");
		return;
	}

	// done with file? close it
	file.close();
}

void SID::DB::shutDown()
{
	printf("Shutting down SID database\n");
		
}