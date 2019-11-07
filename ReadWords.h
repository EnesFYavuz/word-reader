#ifndef _READWORDS_H
#define _READWORDS_H

using namespace std;
#include <string>
#include <iostream>
#include <fstream>

class ReadWords
{   public:
        ReadWords(const char *fname);

        void close();

        string getNextWord();
        
    protected:
        bool isNextWord();

    private:
        ifstream wordfile;
        bool eoffound;
        string nextword;		

        string fix(string word);
 };

 #endif
