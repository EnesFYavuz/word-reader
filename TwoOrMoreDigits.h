#ifndef
#define

#include "ReadFilteredWords.h"

class TwoOrMoreDigits: public ReadFilteredWords {
    
public:
    TwoOrMoreDigits(const char *fname): ReadFilteredWords(fname) {
    }
    bool filter(string word) override;
};


#endif
