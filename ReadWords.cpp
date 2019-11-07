#include "ReadWords.h"
#include <cstdlib>
#include <cctype>

ReadWords::ReadWords(const char *fname)
{   wordfile.open(fname);//open file
    if (!wordfile)
    {   cout << "cannot open " << fname << endl;
        exit(1);
    }
    wordfile >> nextword;
    eoffound = false;
}

void ReadWords::close()
{   wordfile.close();
}

bool ReadWords::isNextWord()
{   return !eoffound;
}

string ReadWords::fix(string word)
{   string s=word;
    int len = s.size();
    string answer = "";

    bool t = false;
    for (int i=0; i<len; ++i)
    {   if(isalnum(s[i]))
            t=true;

        if(t)
            if(!ispunct(s[i]))
                answer += s[i];
            else if(i!=0 && i!=len-1)
               answer += s[i];
    }

    if(answer.size()>0)
    {   int length = answer.size();
        while(ispunct(answer[--length]))
            answer.erase(length,1);
    }

    return answer;
}

string ReadWords::getNextWord()
{    string word = nextword;
     wordfile >> nextword;

     if(wordfile.eof())
         eoffound=true;

     return  fix(word);
}
