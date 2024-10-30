#ifndef DNASEQ_H
#define DNASEQ_H
#include "dblList.h"
#include <string>

class dnaSeq {
    public:
        dnaSeq();
        ~dnaSeq();
        //overloaded constructor
        dnaSeq(std::string charString);
        bool isGeneticPalindrome();
        DblList<char> complement();
        DblList<char> subString(int startingS, int endingE);
        std::string toString();
    private:
        std::string m_string;
        DblList<char> curSeq;
        DblList<char> compSeq;
};

#endif