#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 4 
int main(void)                                                                 //initializes the code
{
	int i, high, low, highDay, lowDay;                                     //define variables
	int highestT = 0, lowestT = 0;                                         //variables set to 0 to store values
	float mean, totHigh = 0, totLow = 0, meanHigh, meanLow;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++) {                            

		printf("Enter the high value for day %d: ", i+1);              //printf to ask user entry; "i+1" to start from 1
		scanf("%d", &high);                                            //scanf_s to accept user entry
		printf("\n");
		printf("Enter the low value for day %d: ", i+1);
		scanf("%d", &low);
		printf("\n");

		while (high > 40 || low < -40 || high < low)                   //condition in nested while
		{
			printf("Incorrect values, temperatures must be in the range");
			printf("-40 to 40, high must be greater than low.\n\n");

			printf("Enter the high value for day %d: ", i+1);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i+1);
			scanf("%d", &low);
			printf("\n");
			}
 
		totHigh += high;                                                //storing the high temperatures
		totLow += low;                                                  //storing the low temperatures

		if (high > highestT) {                                          //if the temp entered is higher than the previous one,
			                                                        //it is stored in highestT (replaces it)
			highestT = high;    
            highDay = i+1;                                                      //shows the day in which the highest temp occured
		}

		if (low < lowestT) {                                            //if the temp entered is lower than the previous one, it is stored in lowestT
			lowestT = low;
	        lowDay = i+1;
		}
	} 

	mean = (totHigh + totLow) / (NUMS * 2);                                 //calculates the mean temperature
	meanHigh = totHigh / NUMS;                                              //calculates the mean for the high temperatures
	meanLow = totLow / NUMS;                                                //calculates the mean for the low temperatures
	
	printf("The average (mean) LOW temperature was: %.2f\n", meanLow);
	printf("The average (mean) HIGH temperature was: %.2f\n", meanHigh);
	printf("The average (mean) temperature was: %.2f\n", mean);
	printf("The highest temperature was %d, on day %d\n", highestT, highDay);
	printf("The lowest temperature was %d, on day %d\n", lowestT, lowDay);

	return 0;                                                               //ends code
}

/* OUTPUT
---=== IPC Temperature Analyzer ===---
Enter the high value for day 1: 8

Enter the low value for day 1: -2

Enter the high value for day 2: 9

Enter the low value for day 2: -4

Enter the high value for day 3: 5

Enter the low value for day 3: 11

Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.

Enter the high value for day 3: 11

Enter the low value for day 3: 5

Enter the high value for day 4: 10

Enter the low value for day 4: 3

The average (mean) LOW temperature was: 0.50
The average (mean) HIGH temperature was: 9.50
The average (mean) temperature was: 5.00
The highest temperature was 11, on day 3
The lowest temperature was -4, on day 2

*/
