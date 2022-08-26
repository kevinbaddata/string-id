#include <iostream>
#include <string>

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
    std::cout << "--load: load all string IDs and corresponding strings from file" << std::endl;
    std::cout << "--exit: exit program" << std::endl;
    std::cout << "--help: print this help" << std::endl;

}
#define EXIT exit(0)
#define SID(str) ToStringId64(str)

int main() {

    printMenu();
   

    return 0;
}
