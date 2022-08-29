#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
constexpr const unsigned long long ToStringId64(const char* str);
void printMenu();
bool CheckWord(char* filename, char* search);

#define EXIT exit(0)
#define SID(str) ToStringId64(str)

#pragma warning (disable: 4307)


int main() {

    printMenu();

    return 0;
}

constexpr const unsigned long long ToStringId64(const char* str) {
    unsigned long long base = 0xCBF29CE484222325;
    if(*str) {
        // generating an FNV-1 Hash
        do {
            base = 0x100000001B3 * (base ^ *str++);
        } while(*str);
    }
    return base;
}

void printMenu() {
    std::cout << "Look up corresponding string ID of specified string (unquoted).\n";
    std::cout << "--list: list all string IDs and corresponding strings" << std::endl;
    std::cout << "--clean: remove all string IDs and corresponding strings" << std::endl;
    std::cout << "--save: save all string IDs and corresponding strings to file" << std::endl;
    std::cout << "--convert: convert string to a FNV-1 Hash" << std::endl;
    std::cout << "--load: load all string IDs and corresponding strings from file" << std::endl;
    std::cout << "--exit: exit program" << std::endl;
    std::cout << "--help: print this help" << std::endl;

    char input[10];
    std::cout << "> ";
    std::cin >> input;

    if(strcmp(input, "--list") == 0) {
        std::cout << "Listing all string IDs and corresponding strings" << std::endl;
        FILE* f = fopen("strings.txt", "r");
        if(f == NULL) {
            std::cout << "Error: file not found" << std::endl;
            return;
        }
        char line[100];
        while(fgets(line, 100, f)) {
            std::cout << line;
        }
        fclose(f);
    } else if(strcmp(input, "--clean") == 0) {
        std::cout << "Cleaning all string IDs and corresponding strings" << std::endl;
        FILE* f = fopen("strings.txt", "w");
        fclose(f);
    } else if(strcmp(input, "--save") == 0) {

        FILE* f = fopen("strings.txt", "a");
        if(f == NULL) {
            std::cout << "Error opening file" << std::endl;
            EXIT;
        }

        std::cout << "Enter string to save: ";
        char str[20];
        std::cin >> str;

        fprintf(f, "%s -> %llu\n", str, SID(str));

        fclose(f);

    } else if(strcmp(input, "--convert") == 0) {
        std::cout << "Enter string to convert: ";
        char str[20];
        std::cin >> str;
        std::cout << "String ID: " << SID(str) << std::endl;
    }
    else if(strcmp(input, "--load") == 0) {
        std::cout << "Loading all string IDs and corresponding strings from file" << std::endl;
    } else if(strcmp(input, "--exit") == 0) {
        std::cout << "Exiting program" << std::endl;
        EXIT;
    } else if(strcmp(input, "--help") == 0) {
        printMenu();
    } else {
        std::cout << "Invalid input" << std::endl;
    }
}

bool CheckWord(char* filename, char* search) {
    int offset;
    std::string line;
    std::ifstream Myfile;
    Myfile.open (filename);

    if (Myfile.is_open())
    {
        while (!Myfile.eof())
        {
            getline(Myfile,line);
            if ((offset = line.find(search, 0)) != std::string::npos)
            {
                std::cout << "found '" << search << "' in '" << line << "'" << std::endl;
                Myfile.close();
                return true;
            }
            else
            {
                std::cout << "Not found" << std::endl;
            }
        }
        Myfile.close();
    }
    else
        std::cout << "Unable to open this file." << std::endl;

    return false;
}
