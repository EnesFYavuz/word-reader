#include "TwoOrMoreDigits.h"

bool TwoOrMoreDigits::filter(string word){
    bool foundDigit = false;
    for(string::iterator it = word.begin(); it!=word.end(); ++it){
        if (isdigit(*it))
		{
            if (foundDigit)
			{
				return true;
            } 
			
			else if (!foundDigit)
			{
                foundDigit = true;
            }
        }
    }
    return false;
}