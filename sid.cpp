#include <stdio.h>
#include <stdint.h>
//%llu - unsigned long long

const unsigned long long ToStringId64(const char* str)
{
	unsigned long long base = 0xCBF29CE484222325;
	if(*str)
	{
		do{
			base = 0x100000001B3 * (base ^ *str++);
		}while(*str);
	}
	return base;
}

#define SID ToStringId64

int main(int argc, char const *argv[])
{
    printf("-> %llu \n", SID("hey"));

   
    return 0;
}



