#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <vector>


#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#include "SID/sid.h"
#include "SID/siddb.h"

#define SID(str) (StringID{str})
#define SID_VAL(str) (StringIdHash(str))

#define EXIT exit (0);

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


int main(const char* argv[], int argc)
{	


	EXIT
	// initialize winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		perror("Error, could not initialize winsock");
		return 0;
	}
	else {
		std::cout << "Winsock initialized" << std::endl;
	}

	// create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		perror("Error, could not create socket");
		return 0;
	}

	// bind the ip address and port to a socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY; // could also use inet_pton ...
	
	bind(listening, (sockaddr*)&hint, sizeof(hint));
		
	// tell winsock the socket is for listening
	listen(listening, SOMAXCONN);
	
	// wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);
	
	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST];		// client's remote name
	char service[NI_MAXSERV];	// service (i.e. port) the client is connected on
	
	ZeroMemory(host, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);
	
	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		printf("%s connected on port %s \r ", host, service);
	
	}
	else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		printf("%s connected on port %d \r ", host, ntohs(client.sin_port));
	}
	
	// close listening socket
	closesocket(listening);

	// while loop: accept and echo message back to client
	char buf[4096];
	
	while (true)
	{
		ZeroMemory(buf, 4096);

		// wait for client to send data
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if (bytesReceived == SOCKET_ERROR)
		{
			perror("Error in recv(), exiting...");
			break;
		}

		if (bytesReceived == 0)
		{
			printf("Client disconnected \r ");
			break;
		}

		// echo message back to client
		send(clientSocket, buf, bytesReceived + 1, 0);
	}

	// close the socket
	closesocket(clientSocket);

	// cleanup winsock
	WSACleanup();
	
	char input[10];

	while (1)
	{

		printUsage();
		std::cout << "> ";
		std::cin >> input;

		if (strcmp(input, "--list") == 0)
		{
			DB::loadHash();
		}
		else if ((strcmp(input, "--clean") == 0)) {
		}
		else if (strcmp(input, "--save") == 0) {
			DB::saveHash();
		}
		else if (strcmp(input, "--convert") == 0)
		{
			std::cout << "Enter a string to convert to a FNV-1 Hash: ";
			char input[15];
			std::cin >> input;

			printf("FNV-1 Hash: %llu\n", SID_VAL(input));
		}
		else if (strcmp(input, "--load") == 0)
		{
		}
		else if (strcmp(input, "--exit") == 0)
		{
			return 0;
		}
		else if (strcmp(input, "--help") == 0)
		{
			printUsage();
		}
		else
		{
			printf("Invalid input, please try again.\n");
		}

	}

	

	return 0;
	

}

