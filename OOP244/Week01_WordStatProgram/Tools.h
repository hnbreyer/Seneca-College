#ifndef SDDS_TOOLS_H
#define SDDS_TOOLS_H

namespace sdds
{


	void title();

	void endList();

	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);

	void print(const Word* w, bool gotoNextLine);

	void report(const Word words[], int noOfWords, int longestWord);

	void swap(Word* p1, Word* p2);

	void sort(Word words[], int cnt);

	void programTitle();
}


#endif
