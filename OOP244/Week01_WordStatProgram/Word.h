#ifndef SDDS_WORD_H
#define SDDS_WORD_H

namespace sdds
{
    const int MAX_WORD_LEN = 21;
    const int MAX_NO_OF_WORDS = 500;
    using namespace std;

    struct Word
    {
        char letters[MAX_WORD_LEN];
        int count;
    };

   void programTitle();

    void toLowerCaseAndAlphabeticCopy(char des[], const char source[]);

    int searchWords(const Word words[], int num, const char word[]);

    void addWord(Word words[], int* index, const char newWord[]);

    void wordStats(bool logOn);
}
   

#endif
