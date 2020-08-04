#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 4 //define macro - THIS IS THE ONE CHANGE (change from 3 to 4)
int main(void) //initializes the code
{
	int i, high, low, highDay, lowDay; //define variables
	int highestT = 0, lowestT = 0; //variables set to 0 to store values
	float mean, totHigh = 0, totLow = 0, meanHigh, meanLow;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++) {                            //for loop

		printf("Enter the high value for day %d: ", i+1); //printf to ask user entry; "i+1" to start from 1
		scanf("%d", &high);                           // scanf_s to accept user entry
		printf("\n");
		printf("Enter the low value for day %d: ", i+1);
		scanf("%d", &low);
		printf("\n");

		while (high > 40 || low < -40 || high < low)      //condition in nested while
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");

			printf("Enter the high value for day %d: ", i+1);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i+1);
			scanf("%d", &low);
			printf("\n");
			}

		totHigh += high;  //storing the high temperatures
		totLow += low;    //storing the low temperatures

		if (high > highestT) {  //if the temp entered is higher than the previous one, it is stored in highestT (replaces it)
			highestT = high;    
            highDay = i+1;   //shows the day in which the highest temp occured
		}

		if (low < lowestT) {  //if the temp entered is lower than the previous one, it is stored in lowestT
			lowestT = low;
	        lowDay = i+1;
		}
	} 

	mean = (totHigh + totLow) / (NUMS * 2);  //calculates the mean temperature
	meanHigh = totHigh / NUMS;  //calculates the mean for the high temperatures
	meanLow = totLow / NUMS;    //calculates the mean for the low temperatures
	
	printf("The average (mean) LOW temperature was: %.2f\n", meanLow);
	printf("The average (mean) HIGH temperature was: %.2f\n", meanHigh);
	printf("The average (mean) temperature was: %.2f\n", mean);
	printf("The highest temperature was %d, on day %d\n", highestT, highDay);
	printf("The lowest temperature was %d, on day %d\n", lowestT, lowDay);

	return 0; //ends code
}
