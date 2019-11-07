#include <map>
#include <map>
#include "HasLetterAndPunctuation.h"
#include "TwoOrMoreDigits.h"
#include "UpperAndLowerCase.h"
#include "ReadFilteredWords.h"
#include<algorithm>

using namespace std;

bool compare(const pair<string, int> map1, const pair<string, int> &map2)
{ 
    return map1.second<map2.second;
}

template <class T>
void printStuff(T file){
    string thisWord = "l";
    map<string, int> wordOccurences;
	
    while(thisWord != "")
	{
        thisWord = file->getNextFilteredWord();
		
        if(wordOccurences.count(thisWord) == 0)
		{
            pair<string, int> pair1(thisWord, 1);
            wordOccurences.insert(pair1);
        }
		
		else if (wordOccurences.count(thisWord) == 1)
		{
            wordOccurences.at(thisWord) += 1;
        }
    }
	
    int wordCount = 0;
    for(auto it = wordOccurences.begin(); it != wordOccurences.end(); ++it)
	{
        wordCount+=(*it).second;
    }
	
    cout << "Total Filtered Words: " << wordCount << endl;
    cout << "Total Filtered Words (And Entries in the Map): = " << wordOccurences.size() << endl;
	
    int maxN = max_element(wordOccurences.begin(), wordOccurences.end(), compare)->second;
    string maxWord = max_element(wordOccurences.begin(), wordOccurences.end(), compare)->first;
    string secondMaxWord = (++max_element(wordOccurences.begin(), wordOccurences.end(), compare))->first;
    int secondMaxN = (++max_element(wordOccurences.begin(), wordOccurences.end(), compare))->second;
    int thirdMaxN = (++(++max_element(wordOccurences.begin(), wordOccurences.end(), compare)))->second;
    string thirdMaxWord = (++(++max_element(wordOccurences.begin(), wordOccurences.end(), compare)))->first;

    cout << "Most Frequent Word: = "<< maxWord  << " It has appeared " << maxN << " times." << endl;
    cout << "The 2nd Most Frequent Word: "<< secondMaxWord  << " It has appeared " << secondMaxN << " times." << endl;
    cout << "The 2nd Most Frequent Word: "<< thirdMaxWord  << " It has appeared " << thirdMaxN << " times." << endl;

}


int main(){
    
    string fileName;
    cout << "Filename: ";
    cin >> fileName;
    cout << "Which derived class do you want to use?" << endl;
    cout << "'1' for UpperAndLowerCase" << endl;
    cout << "'2' for TwoOrMoreDigits" << endl;
    cout << "'3' for HasLetterAndPunctuation" << endl;
    int option;
    cin >> option;
	
    if (option == 1)
	{
        UpperAndLowerCase temp(fileName.c_str());
        printStuff(&temp);
    }
	
	else if (option == 2)
	{
        TwoOrMoreDigits temp(fileName.c_str());
        printStuff(&temp);
    }
	
	else if (option == 3)
	{
        HasLetterAndPunctuation temp(fileName.c_str());
        printStuff(&temp);
    }
}