#ifndef _READFWORDS_H
#define _READFWORDS_H

using namespace std;
#include <string>
#include "ReadWords.h"

class ReadFilteredWords: public ReadWords
{   public:

        ReadFilteredWords(const char *fname): ReadWords(fname)
        {
        }

        virtual bool filter(string word)=0;

        string getNextFilteredWord();
 };

 #endif
