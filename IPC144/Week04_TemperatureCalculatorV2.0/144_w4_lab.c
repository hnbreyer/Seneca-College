#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 10  
int main(void)
{
	int i, j, highTemp[NUMS], lowTemp[NUMS];                                        //variables
	
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");       //asks user entry
	scanf("%d", &i);  //accept user entry
	printf("\n");

	while (i < 3 || i > NUMS)                                                       //while loop to set condition for number of days
	{
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &i);
	}
	printf("\n");
	for (j = 0; j < i; j++) {                                                       //for loop for parallel array
		printf("Day %d - High: ", j + 1);
		scanf("%d", &highTemp[j]);

		printf("Day %d - Low: ", j + 1);
		scanf("%d", &lowTemp[j]);
	}

	printf("\nDay  Hi  Low\n");

	for (j = 0; j < i; j++) {                                                       //for loop to display parallel array
		printf("%d    %d    %d\n", j + 1, highTemp[j], lowTemp[j]);
	}

	return 0;                                                                       //ends code
}

/* OUTPUT
---=== IPC Temperature Calculator V2.0 ===---
Please enter the number of days, between 3 and 10, inclusive: 2

Invalid entry, please enter a number between 3 and 10, inclusive: 4

Day 1 - High: 6
Day 1 - Low: -2
Day 2 - High: 8
Day 2 - Low: -1
Day 3 - High: 7
Day 3 - Low: -3
Day 4 - High: 9
Day 4 - Low: -4

Day  Hi  Low
1    6    -2
2    8    -1
3    7    -3
4    9    -4
*/
