#define _CRT_SECURE_NO_WARNINGS

#define SIZE 4		
#include <stdio.h>

struct Employee                                                                     // Declare Struct Employee 
{
	int ID_no;
	int age;
	double sal;
};

/* main program */
int main(void)
{

	
	struct Employee	emp[SIZE] = { {0} };                                     // Declare a struct Employee array "emp" with SIZE elements 
	int i, valEmp = 0, idSelected, option = 0;                               // initialize all elements to zero
	

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		scanf("%d", &option);                                      	// Capture input to option variable
		printf("\n");

		switch (option)
		{

		case 0:	                                                        // Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1:                                                         // Display Employee Data

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i < SIZE; i++) { 	                        // loop will run for SIZE times 

				if (emp[i].ID_no > 0)                           // and will only display Employee data where the EmployeeID is > 0
					printf("%6d%9d%11.2lf\n", emp[i].ID_no, emp[i].age, emp[i].sal);
			}
			printf("\n");
			break;

		case 2:	                                                       // Adding Employee

			i = 0;
			printf("Adding Employee\n");
			printf("===============\n");
			while (emp[i].ID_no != 0) 
				i++;

			if (i < SIZE) {                                       //checks for empty slots in the array
				printf("Enter Employee ID: ");
				scanf("%d", &emp[i].ID_no);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[i].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[i].sal);
				valEmp++;                                    //increment the number of employees

				printf("\n");
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			break;

		case 3:	                                                    // Update Employee Salary

			printf("Update Employee Salary\n");
			printf("======================\n");



			do {
				i = 0;
				printf("Enter Employee ID: ");
				scanf("%d", &idSelected);
				while (i < SIZE && emp[i].ID_no != idSelected)
					i++;


				if (i == SIZE)
					printf("*** ERROR: Employee ID not found! ***\n");

			} while (i == SIZE);

			printf("The current salary is %.2lf\n", emp[i].sal);
			printf("Enter Employee New Salary: ");
			scanf("%lf", &emp[i].sal);
			printf("\n");

			break;

		case 4:	                                                     // Remove Employee


			printf("Remove Employee\n");
			printf("===============\n");

			do {
				i = 0;
				printf("Enter Employee ID: ");
				scanf("%d", &idSelected);
				while (i < SIZE && emp[i].ID_no != idSelected)
					i++;

				if (i == SIZE)
					printf("*** ERROR: Employee ID not found! ***\n");

			} while (i == SIZE);
			printf("Employee %d will be removed\n", emp[i].ID_no);
			emp[i].ID_no = 0;                                   //removing id from array
			printf("\n");

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0;
}


/* OUTPUT
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 222
Enter Employee Age: 22
Enter Employee Salary: 22222.22

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 333
Enter Employee Age: 33
Enter Employee Salary: 33333.33

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 444
Enter Employee Age: 44
Enter Employee Salary: 44444.44

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 555
Enter Employee Age: 55
Enter Employee Salary: 55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   33333.33
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 123
*** ERROR: Employee ID not found! ***
Enter Employee ID: 321
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
The current salary is 33333.33
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   99999.99
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 789
*** ERROR: Employee ID not found! ***
Enter Employee ID: 987
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
Employee 333 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 666
Enter Employee Age: 66
Enter Employee Salary: 66666.66

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
666       66   66666.66
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!
*/
