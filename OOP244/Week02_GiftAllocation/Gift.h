//Gift.h

#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H

namespace sdds
{
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.99;
	using namespace std;

	struct Gift
	{
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
	};

	void gifting(char *giftName);

	void gifting(double &price);

	void gifting(int &units);

	void display(const Gift &gifts);

}


#endif
