#include "PalindromeFinder.h"
#include <iostream>

int main(int argc, char** argv){
    PalindromeFinder finder(argv[1]);
    std::cout << finder.determinePalindrome() << std::endl;
    return 0;
}