#include "ReadFilteredWords.h"

class UpperAndLowerCase: public ReadFilteredWords {
    
public:
    UpperAndLowerCase(const char *fname): ReadFilteredWords(fname) {
    }
    bool filter(string word) override;
};


