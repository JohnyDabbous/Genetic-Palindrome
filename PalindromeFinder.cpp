#include "PalindromeFinder.h"

PalindromeFinder::PalindromeFinder(std::string readFile){
    m_file = readFile;
}

PalindromeFinder::~PalindromeFinder(){

}

std::string PalindromeFinder::joinWord(std::string word, int x, int y){
    std::string s = "";
    for (int i = x; i < y; ++i){
        s += word[i];
    }
    return s;
}

std::string PalindromeFinder::determinePalindrome(){
    std::string s = "";
    std::string readVar = "";
    std::string holdingVar = "";
    std::string other = "";
    //reads from a file into some holding variable
    std::ifstream file;
    file.open(this->m_file);
    if (file.is_open()){
        //uses the string stream to read to the read variable and assigns its value to the holding variable
        while (getline(file, readVar)){
            holdingVar += readVar + "\n";
        }
        file.close();
    }
    else {
        s += "File did not open.";
        s += "\n";
        return s;
    }

    std::stringstream stream(holdingVar);
    while (stream >> other){
        if (other == "END"){
            break;
        }
        //creates a dnaSeq object to check for palindromes
        dnaSeq DNA(other);
        //assigns a linked list to the complement
        DblList<char> holding = DNA.complement();
        if (holding.size() == 0){
            s += other;
            s += " - INVALID";
            s += "\n";
            continue;
        }
        if (DNA.isGeneticPalindrome()){
            s += other;
            s += " - Genetic Palindrome";
            s += "\n";
            //make sure the sequence does not have length 4
            if (other.size() <= 4){
                continue;
            }
            else {
                //checkiing for substring
                int j = 0;
                int k = other.size() - 2; //2 because we already checked the whole string
                //loops until it reaches all substrings of the word that are greater than or equal to 4
                while ((k - j) >= 4){
                    std::string joinedString = joinWord(other, j, k);
                    DNA.subString(j, k);
                    DNA.complement();
                    if (DNA.isGeneticPalindrome()){
                        s += "      Substring ";
                        s += joinedString;
                        s += " - Genetic Palindrome";
                        s += "\n";
                        ++j;
                        //--k;
                    }
                    else {
                        ++j;
                        //--k;
                        continue;
                    }
                }
            }
        }
        else {
            s += other;
            s += " - Not a Genetic Palindrome";
            s += "\n";
            //make sure the sequence does not have length 4
            if (other.size() <= 4){
                continue;
            }
            else {
                //checking for substring
                int j = 0;
                int k = other.size() - 2; //2 because we already checked the whole string
                //loops until it reaches all substrings of the word that are greater than or equal to 4
                while ((k - j) >= 4){
                    std::string joinedString = joinWord(other, j, k);
                    DNA.subString(j, k);
                    DNA.complement();
                    if (DNA.isGeneticPalindrome()){
                        s += "      Substring ";
                        s += joinedString;
                        s += " - Genetic Palindrome";
                        s += "\n";
                        //++j;
                        --k;
                    }
                    else {
                        //++j;
                        --k;
                        continue;
                    }
                }
            }
        }
    }

    return s;
}