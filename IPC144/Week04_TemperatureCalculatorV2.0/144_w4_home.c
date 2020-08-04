#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 10  
int main(void) 
{
	int days, j, highTemp[NUMS], lowTemp[NUMS], highDay, lowDay, day_avgTemp = 0;       //variables
	int highestT = 0, lowestT = 0;                                                      //variables set to 0 to store values
	double sumTemp = 0;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");           //asks user entry
	scanf("%d", &days);                                                                 //accept user entry
	printf("\n");

	while (days < 3 || days > NUMS)                                                    //while loop to set condition for number of days
	{
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
	}
	printf("\n");
	for (j = 0; j < days; j++) {                                                       //for loop for parallel array
		printf("Day %d - High: ", j + 1);
		scanf("%d", &highTemp[j]);

		if (highTemp[j] > highestT) {
			highestT = highTemp[j];                                           //calculating highest temp
			highDay = j + 1;                                                  // which day the highest temp occured
		}

		printf("Day %d - Low: ", j + 1);
		scanf("%d", &lowTemp[j]);

		if (lowTemp[j] < lowestT) {
			lowestT = lowTemp[j];
			lowDay = j + 1;
		}

	}

	printf("\nDay  Hi  Low\n");

	for (j = 0; j < days; j++) {                                                      //for loop to display parallel array
		printf("%d    %d    %d\n", j + 1, highTemp[j], lowTemp[j]);
	}

	printf("\n");
	printf("The highest temperature was %d, on day %d\n", highestT, highDay);
	printf("The lowest temperature was %d, on day %d\n", lowestT, lowDay);

	printf("\n");
	do {                                                                              //'do-while' loop to accept user entry and set conditions
		printf("Enter a number between 1 and %d to see the average temperature for");
		printf(" the entered number of days, enter a negative number to exit: ", days);
		scanf("%d", &day_avgTemp);
		printf("\n");

		while (day_avgTemp == 0 || day_avgTemp > days)                            //condition for invalid entry
		{
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", days);
			scanf("%d", &day_avgTemp);
			printf("\n");
		}

		if (day_avgTemp > 0) {
			for (j = 0; j <= day_avgTemp - 1; j++)
			{
	
				sumTemp = sumTemp + highTemp[j] + lowTemp[j];             //calculating the sum
		
			}
			double avgTemp = (sumTemp / (day_avgTemp * 2)); //casting to double
			printf("The average temperature up to day %d is: %.2f\n", day_avgTemp, avgTemp);
			printf("\n");
			sumTemp = 0;                                                      //set sum to 0 for each loop
		}
	} while (day_avgTemp >= 0);                                                       //condition for program to run; otherwise it prints the following and ends

	printf("Goodbye!\n");

	return 0;                                                                         //ends code
}

/* OUTPUT
---=== IPC Temperature Calculator V2.0 ===---
Please enter the number of days, between 3 and 10, inclusive: 11

Invalid entry, please enter a number between 3 and 10, inclusive: 5

Day 1 - High: 6
Day 1 - Low: -2
Day 2 - High: 9
Day 2 - Low: -1
Day 3 - High: 7
Day 3 - Low: -3
Day 4 - High: 8
Day 4 - Low: -9
Day 5 - High: 5
Day 5 - Low: -8

Day  Hi  Low
1    6    -2
2    9    -1
3    7    -3
4    8    -9
5    5    -8

The highest temperature was 9, on day 2
The lowest temperature was -9, on day 4

Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: 6

Invalid entry, please enter a number between 1 and 5, inclusive: 7

Invalid entry, please enter a number between 1 and 5, inclusive: 3

The average temperature up to day 3 is: 2.67

Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: 0

Invalid entry, please enter a number between 1 and 5, inclusive: 0

Invalid entry, please enter a number between 1 and 5, inclusive: 1

The average temperature up to day 1 is: 2.00

Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: 2

The average temperature up to day 2 is: 3.00

Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: 5

The average temperature up to day 5 is: 1.20

Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: -8

Goodbye!
*/
