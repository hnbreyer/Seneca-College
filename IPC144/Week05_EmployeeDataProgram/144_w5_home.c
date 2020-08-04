// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements

#define _CRT_SECURE_NO_WARNINGS
// Define Number of Employees "SIZE" to be 2
#define SIZE 4		

#include <stdio.h>


// Declare Struct Employee 
struct Employee
{
	int ID_no;
	int age;
	double sal;
};

/* main program */
int main(void)
{


	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee	emp[SIZE] = { {0} };
	int i, valEmp = 0, idSelected, option = 0;
	

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		//	option = 0;
			// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{

		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0

			for (i = 0; i < SIZE; i++) {

				if (emp[i].ID_no > 0)
					printf("%6d%9d%11.2lf\n", emp[i].ID_no, emp[i].age, emp[i].sal);
			}
			printf("\n");
			break;

		case 2:	// Adding Employee
				// @IN-LAB

			i = 0;
			printf("Adding Employee\n");
			printf("===============\n");
			while (emp[i].ID_no != 0) //condition
				i++;

			if (i < SIZE) {  //checks for empty slots in the array
				printf("Enter Employee ID: ");
				scanf("%d", &emp[i].ID_no);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[i].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[i].sal);
				valEmp++; //increment the number of employees

				printf("\n");
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			break;

		case 3:	// Update Employee Salary

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

		case 4:	// Remove Employee


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
			emp[i].ID_no = 0; //removing id from array
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
