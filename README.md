# word-reader
A c++ program that analyses the text of a large file, and provides output based on given filters

In this repository you will find a ReadWords class. It has member functions getNextWord (which returns the next word from the file whose name is supplied as an argument to its constructor) and isNextWord (which returns a boolean value indicating if there is another word in the file). The latter function has been declared as protected, so it can be accessed only in the member functions of the class and its subclasses. The getNextWord function calls a private function called fix to remove all leading and trailing punctuation from a word; hence it may return an empty string if the “word” contains nothing but punctuation. In this program a “word” does not have to contain a letter and no case-conversion is to be performed.

There is also a header file for an abstract class called ReadFilteredWords, which uses a base class for developing three derived classes. This is declared as a subclass of ReadWords and contains a pure virtual function called filter which is used to select which words are accepted and which are rejected using some criterion. Implementations of this in the derived classes take a word (as returned by getNextWord) as an argument and return true if the word satisfies the criterion. The class declaration contains a function called getNextFilteredWord – which returns the next word from the input (obtained by calling getNextWord) that satisfies the criterion, or
an empty string if there are no more words that satisfy it. (It is assumed that an empty string will never satisfy a filter, so it cannot be returned if there are more words that satisfy the filter.) This function is implemented in the ReadFilteredWords.cpp file.

Three derived classes are given, each with a different version of filter to override the virtual function.

In the first derived class the filter function returns true if its argument is a string that contains at least one upper-case letter and at least one lower-case letter. In the second class the filter function returns true if its argument is a string containing two or more adjacent digits (i.e. digits that occur in adjacent positions in the word, they may be the same or different digits). In the third class the filter function returns true if its argument is a string that contains at least one letter and at least one punctuation character (as defined by the function ispunct declared in the header file <cctype>).

The three derived classes are written in separate .cpp files, each with an associated .h file.

In the main function of WordReader.cpp the user can specify a file name and select which derived class should be used, the function will then create an object of that class using the supplied file name as the argument to its constructor. The program then processes the whole file, repeatedly calling getNextFilteredWord until an empty string is returned, keeping track of the number of occurrences of each filtered word returned by the function using a map.
  
After the processing of the file is complete the program outputs the total number of occurrences of filtered words, the number of distinct filtered words, the number of entries in the map and the three words with the largest occurrence counts (along with their counts). If there is more than one equally third-most frequent word the program will output all of them, unless there are more than 10 in which case the program will output the first ten followed by something “and ... more words”.

A sample text file and word list is provided in this repository to allow for the testing of this program.
