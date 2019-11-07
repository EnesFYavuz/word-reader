#include <string>
#include "ReadFilteredWords.h"

string ReadFilteredWords::getNextFilteredWord(){
    string thisWord = this->getNextWord();
    while (!this->filter(thisWord)){
        thisWord = this->getNextWord();
        if (!isNextWord()){
            return "";
        }
    }
    return thisWord;
}