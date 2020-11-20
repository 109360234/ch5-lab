#include<stdio.h>
#include<stdlib.h>
#define st 3
#define ex 4
void minnum(int grades[][ex], int pu, int tests);
void maxnum(int grades[][ex], int pu, int tests);
void average(int grades[][ex], int pu, int tests);
void printarray(int grades[][ex], int pu, int tests);
void printmenu();
int main()
{
	int stgrades[st][ex] = { {77,68,86,73},{96,87,89,78},{70,90,86,81} };

	void(*processgrades[4])(int[st][ex], int, int) = { printarray,minnum,maxnum,average };


	int choice = 0;
	while (choice !=4)
	{
		do
		{
			printmenu();
			scanf_s("%d", &choice);
		} while (choice<0 || choice>4);
		if (choice !=4)
		{
			(*processgrades[choice])(stgrades, st, ex);
		}
		else
		{
			printf("\tProgram Ended.  \n");
		}
	}
	system("pause");
	return 0;
}
void minnum(int grades[][ex], int pu, int tests)
{
	int i, j;
	int lowgrade = 100;
	for ( i = 0; i < pu; i++)
	{
		for (j= 0; j < tests; j++)
		{
			if (grades[i][j] < lowgrade)
				lowgrade = grades[i][j];
		}
	}
	printf("\n\tThe lowest grade is %d", lowgrade);
	printf("\n");
}
void maxnum(int grades[][ex], int pu, int tests)
{
	int i, j;
	int highgrade = 0;
	for (i = 0; i < pu; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] > highgrade)
				highgrade = grades[i][j];
		}
	}
	printf("\n\tThe highest grade is %d", highgrade);
	printf("\n");
}
void average(int grades[][ex], int pu, int tests)
{
	int i, j,total;
	for (i = 0; i < pu; i++)
	{
		total = 0;
		for (j = 0; j < tests; j++)
		{
			total += grades[i][j];
		}
	printf("\n\tThe average grade for student  %d is %.1f", i+1,(double)total/tests);
	}
	
	printf("\n");
}
void printarray(int grades[][ex], int pu, int tests)
{
	int i, j;
	printf("\n\t\t\t[0]       [1]       [2]      [3]");
	for ( i = 0; i < pu; i++)
	{
		printf("\n\tstudentGrades[%d]", i);
		for (j = 0; j < tests; j++)
		{
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}
void printmenu()
{
	printf("\n");
	printf("\tEnter a choice:\n");
	printf("\t0 Print the array of grades\n");
	printf("\t1 Find the minnum grade\n");
	printf("\t2 Find the maxnum grade\n");
	printf("\t3 Print the array of grades\n"); 
	printf("\t4 End program\n");
	printf("choice\n");


}