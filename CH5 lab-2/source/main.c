#include<stdio.h>
#include<stdlib.h>

#define Issue 5
#define ratings 10

void rR(int issue, int rating);
void highest();
void lowest();
float avg(int issue);
void displayresult();
int responses[Issue][ratings];
const char *topics[Issue] = { "Global warning","The Economy","War","Health Care","Education" };
int main() {
	int response, i;
	do
	{
		printf("Please rate the following topics on a scale from 1-10""\n 1 = least important, 10 = important\n");
		for (i=0; i < Issue; i++)
		{
			do
			{
				printf("%s?", topics[i]);
				scanf_s("%d", &response);
			} while (response<1 || response>10);
			rR(i, response);
		}

		printf("Enter 1 to stop. Enter 0 to rate the issues again.");
		scanf_s("%d", &response);
	} while (response!=1);
	displayresult();
	system("pause");
	return 0;
}
void rR(int issue, int rating)
{
	responses[issue][rating - 1]++;
}
void highest()
{
	int hightrating = 0;
	int hightopic = 0;
	int i, j;

	for ( i = 0; i < Issue; i++)
	{
		int topicrating = 0;
		for ( j = 0; j < ratings; j++)
		{
			topicrating += responses[i][j] * (j + 1);
		}
		if (hightrating < topicrating)
		{
			hightrating = topicrating;
			hightopic = i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s", topics[hightopic]);
	printf("with a total rating of %d\n", hightrating);
}


void lowest()
{
	int lowrating = 0;
	int lowtopic = 0;
	int i, j;

	for (i = 0; i < Issue; i++)
	{
		int topicrating = 0;
		for (j = 0; j < ratings; j++)
		{
			topicrating += responses[i][j] * (j + 1);
		}
		if (i == 0)
			lowrating = topicrating;

		if (lowrating > topicrating)
		{
			lowrating = topicrating;
			lowrating = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topics[lowtopic]);
	printf("with a total rating of %d\n", lowrating);
}
float avg(int issue)
{
	float total = 0;
	int counter = 0;
	int i;

	for ( i = 0; i < ratings; i++)
	{
		if (responses[issue][i] != 0)
		{
			total += responses[issue][i] * (i + 1);
			counter += responses[issue][i];
		}
	}
	return total / counter;
}
void displayresult()
{
	int i, j;
	printf("%20s", "Topic");
	for ( i = 1; i <=ratings; i++)
	{
		printf("%4d", i);
	}
	printf("%20s", "Average Rating");
	for ( i = 0; i <Issue; i++)
	{
		printf("%20s", topics[i]);
	
		for ( j = 0; j < ratings; j++)	
		{
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f", avg(i));
	}
	highest();
	lowest();
}