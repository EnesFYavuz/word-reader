#include "ReadFilteredWords.h"

class HasLetterAndPunctuation: public ReadFilteredWords {
    
public:
    HasLetterAndPunctuation(const char *fname): ReadFilteredWords(fname){
    }
    bool filter(string word) override;
};


#include "ReadFilteredWords.h"