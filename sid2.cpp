#include <iostream>
#include <string.h>
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

class StringID {
public:
    const char* str;

    StringID(const char* str) : str(str) {} // constructor

    constexpr const unsigned long long GetValue() const {
        return ToStringId64(str);
    }

};

// expand macro to generate a StringID
#define SID(str) StringID(str)
#define SID_VAL(str) ToStringId64(str)

int main()
{

   



    // exit the program.
    return 0;
}