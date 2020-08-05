#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>

#include "Word.h"
#include "Tools.h"

namespace sdds
{

    void programTitle() {
        cout <<
            "This program reads a text file from the standard input and analyzes and reports" << endl <<
            "the number of words and their occurrences in the text file." << endl;
    }

    void toLowerCaseAndAlphabeticCopy(char des[], const char source[]) {
        int i = 0, j = 0;
        char lower;
        for (; source[i] != 0; i++) {
            lower = tolower(source[i]);
            if (lower >= 'a' && lower <= 'z') {
                des[j++] = tolower(source[i]);
            }
        }
        des[j] = 0;
    }

    int searchWords(const Word words[], int num, const char word[]) {
        int i;
        int foundIndex = -1;                                                                 // will be set to found index; if not found sould be less than 0
        for (i = 0; foundIndex == -1 && i < num; i++) {                                      // while not found and i is less than number of words
            if (strcmp(words[i].letters, word) == 0) {                                       // if word is already read and found in the list of previous words
                foundIndex = i;                                                              // set the index to be returned.
            }
        }
        return foundIndex;
    }

    void addWord(Word words[], int* index, const char newWord[]) {
        strcpy(words[*index].letters, newWord);
        words[*index].count++;
        (*index)++;
    }

    void wordStats(bool logOn) {
        Word words[MAX_NO_OF_WORDS] = { {"",0} };
        char word[MAX_WORD_LEN];
        char lowerCaseWord[MAX_WORD_LEN];
        int NoOfWords = 0;
        int maxLen = 0;
        int foundIndex = 0;
        while (!cin.fail()) {
            cin >> word;
            toLowerCaseAndAlphabeticCopy(lowerCaseWord, word);
            if (lowerCaseWord[0] != 0) {
                if (maxLen < (int)strlen(lowerCaseWord)) {
                    maxLen = strlen(lowerCaseWord);
                }
                if (NoOfWords == 0) {
                    addWord(words, &NoOfWords, lowerCaseWord);
                }
                else {
                    foundIndex = searchWords(words, NoOfWords, lowerCaseWord);
                    if (foundIndex < 0) {                                                  // word not found in list; so word is new and never read before
                        foundIndex = NoOfWords;
                        addWord(words, &NoOfWords, lowerCaseWord);
                    }
                    else {
                        words[foundIndex].count++;
                    }
                }
                if (logOn) {
                    print(&words[foundIndex], false);
                    cout << " read so far." << endl;
                }
            }
        }
        cout << "---------------------------------------------------" << endl << "End of data" << endl << "---------------------------------------------------" << endl;
        cout << "Sorting data " << endl;
        sort(words, NoOfWords);
        cout << "Sort ended" << endl;
        report(words, NoOfWords, maxLen);
    }
}
