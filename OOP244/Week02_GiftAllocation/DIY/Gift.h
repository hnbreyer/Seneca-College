// Gift.h

#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H

namespace sdds
{
	const int MAX_DESC = 15;
	const int MAX_PAT = 20;
	const double MAX_PRICE = 999.99;

	using namespace std;                                                            //included for cin and cout functions in Gift.cpp

	struct Gift
	{
		char g_description[MAX_DESC + 1] = { 0 };
		double g_price;
		int g_units;
		int wrap_layers;
		struct Wrapping* wrap;

	};

	struct Wrapping
	{
		char* pattern;
	};

	void gifting(char* giftName);

	void gifting(double& price);

	void gifting(int& units);

	void gifting(Gift& gift);                                                       //new gifting function

	void display(const Gift& gifts);

	bool wrap(Gift& gifts);

	bool unwrap(Gift& gifts);
	


}


#endif
