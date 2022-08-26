#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//%llu - unsigned long long

#define EXIT exit(0);

const unsigned long long ToStringId64(const char* str);
void printUsage();

#define SID ToStringId64

int main(int argc, char const *argv[])
{

    /*printUsage();
    char userInput[20];
    scanf("%s", userInput);

    if(strcmp("--list", userInput) == 0) {
      puts("Listring string IDs...");
    } else if(strcmp("--clean", userInput) == 0) {
      puts("Removing all string IDs");
    } else if(strcmp("--save", userInput) == 0) {
      puts("Saving all strings to a file...");
    } else if(strcmp("--exit", userInput) == 0) {
      puts("Exiting...");
      sleep(2);
      EXIT
    } else if(strcmp("--help", userInput) == 0) {
      puts("Help is on the way...");
    }*/

    //printf("-> %llu \n", SID("hey"));
    // unsigned long long test = SID("play-line");
    // printf("String ID -> %llu\n", test);

    switch (SID("play-line"))
    {
    case SID("play-line"):
        puts("Playing a line of dialogue");
        sleep(5);
      break;
   
    default:
      break;
    }

   
    return 0;
}

const unsigned long long ToStringId64(const char* str) {
	
  unsigned long long base = 0xCBF29CE484222325;
	if(*str)
	{
    // generatring a FNV-1 Hash 
		do{
			base = 0x100000001B3 * (base ^ *str++);
		} while(*str);
	}
	return base;
}

void printUsage() {
  
  puts("Look up corresponding string ID of specified string (unquoted).\n");
  puts("--list: list all string IDs and corresponding strings");
  puts("--clean: remove all string IDs and corresponding strings");
  puts("--save: save all string IDs and corresponding strings to file");
  puts("--load: load all string IDs and corresponding strings from file");
  puts("--exit: exit");
  puts("--help: print this message");
  
}

