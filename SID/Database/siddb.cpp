// exclude from build in the IDE
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

// header files for socket connection and file I/O
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>

// header files for string ID
#include "sid.h"
#include "siddb.h"

DB::DB()
{
	printf("Connected to SID database\n");
}

DB::~DB()
{
	printf("Disconnected from SID database\n");
}

// Todo: save hash to file
void DB::saveHash()
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

void DB::loadHash()
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

void DB::cleanHash()
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

void DB::shutDown()
{
	printf("Shutting down SID database\n");
		
}
