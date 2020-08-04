#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 3
int main(void)                                                          //initializes the code
{
	int i, high, low;                                                    //define variables

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 1; i <= NUMS; i++) {                                        //for loop
		
			printf("Enter the high value for day %d: ", i);                 //printf to ask user entry
			scanf("%d", &high);                                             // scanf_s to accept user entry
			printf("\n");
			printf("Enter the low value for day %d: ", i);
			scanf("%d", &low);
			printf("\n");

		while (high > 40 || low < -40 || high < low)                      //condition in nested while
		{
			printf("Incorrect values, temperatures must be in the range");
                        printf("-40 to 40, high must be greater than low.\n\n"); 

			printf("Enter the high value for day %d: ", i);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i);
			scanf("%d", &low);		
			printf("\n");
		}		
	}
	return 0;                                                           //ends code
}
