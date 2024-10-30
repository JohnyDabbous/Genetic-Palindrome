#ifndef PALINDROMEFINDER_H
#define PALINDROMEFINDER_H
#include "DNASeq.h"
#include <fstream>
#include <sstream>

class PalindromeFinder{
    private:
        std::string m_file;
    public:
        PalindromeFinder(std::string readFile);
        ~PalindromeFinder();
        std::string determinePalindrome();
        std::string joinWord(std::string word, int x, int y);
};

#endif