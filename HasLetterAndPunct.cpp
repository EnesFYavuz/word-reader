#include "HasLetterAndPunctuation.h"
#include <cctype>

bool HasLetterAndPunctuation::filter(string word) {
    bool hasPunctuation = false;
    bool hasLetter = false;
	
    for(string::iterator it = word.begin(); it!=word.end(); ++it)
	{
        if(ispunct(*it))
		{
            hasPunctuation = true;
        }
		
        if(isalpha(*it))
		{
            hasLetter = true;
        }
    }

    if(hasLetter && hasPunctuation)
	{
        return true;
    }
	else 
	{
        return false;
    }
}