#include "UpperAndLowerCase.h"

bool UpperAndLowerCase::filter(string word){
    bool hasUps = false;
    bool hasLow = false;
    for(string::iterator it = word.begin(); it!=word.end(); ++it)
	{
        if (isupper(*it))
		{
            hasUps = true;
        }
		
        if (islower(*it))
		{
            hasLow = true;
        }
    }

    if(hasLow && hasUps)
	{
        return true;
    }
	
	else
	{
        return false;
    }
}
