#include "DNASeq.h"

dnaSeq::dnaSeq(){ //default constructor
    m_string = "ATCCTA";
    for (int i = 0; i < m_string.size(); ++i){
        curSeq.addBack(m_string[i]);
    }
}

dnaSeq::~dnaSeq(){ //destructor

}

dnaSeq::dnaSeq(std::string charString){ //overloaded constructor
    m_string = charString;
    for (int i = 0; i < m_string.size(); ++i){
        curSeq.addBack(m_string[i]);
    }
}

//checks to see if something is a palindrome
bool dnaSeq::isGeneticPalindrome(){
    int i = 0; //loop starting from the front
    int j = curSeq.size() - 1; //loop starting from the back
    if (compSeq.size() > 0){
        if (m_string.size() % 2 == 0){
        //loop until i and j equal each other
            while (i <= j){
                if (curSeq.get(i) == compSeq.get(j)){
                    ++i;
                    --j;
                }
                else{
                    return false;
                }
            }
            return true;
        }
        else {
            int middle;
            //gets the middle value
            middle = j / 2;
            while (i < middle && j > middle){
                if (curSeq.get(i) == compSeq.get(j)){
                    ++i;
                    --j;
                }
                else{
                    return false;
                }
            }
            return true;
        }
    }
    else {
        return false;
    }
}

//converts your string into a compliment
DblList<char> dnaSeq::complement(){
    DblList<char> seqComp;
    for (int i = 0; i < curSeq.size(); ++i){
        switch (curSeq.get(i)){
            case 'A':
                seqComp.addBack('T');
                break;
            case 'T':
                seqComp.addBack('A');
                break;
            case 'C':
                seqComp.addBack('G');
                break;
            case 'G':
                seqComp.addBack('C');
                break;
            default: //if the letter does not match the any of the compliments
                DblList<char> empty;
                compSeq = empty;
                return empty;
                break;
        }
    }
    compSeq = seqComp;
    return seqComp;
}

//returns a linked list with of the substring with the given indices
DblList<char> dnaSeq::subString(int startingS, int endingE){
    DblList<char> sub;
    if (endingE < m_string.size() && startingS >= 0){
        for (int i = startingS; i < endingE; ++i){
            sub.addBack(m_string[i]);
        }
        curSeq = sub;
        this->complement();
        return sub;
    }
    else{
        //returns an empty sequence for going out of bounds
        return sub;
    }
}

std::string dnaSeq::toString(){
    std::string s = "";
    for (int i = 0; i < curSeq.size(); ++i){
        s += curSeq.get(i);
        s += "\n";
    }
    s += "Complement";
    s += "\n";
    if (compSeq.size() > 0){
        for (int i = 0; i < compSeq.size(); ++i){
            s += compSeq.get(i);
            s += "\n";
        }
    }
    return s;
}