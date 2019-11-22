#include <stdio.h>
#include <stdlib.h>

#define ISSUES 5
#define RATINGS 10

void recordResponse(int i, int res);
void highestRatings();
void lowestRatings();
float aveRating(int issue);
void displayResults();
int res[ISSUES][RATINGS];
const char *topics[ISSUES] = { "Global Warning ","The Economy","War","Health care","Education" };

int main()
{
	int resx, i;
	do 
	{
		printf("Please rare the following topics on a scale from 1-10\n 1 = least important, 10 = most important\n");
		for (i = 0; i < ISSUES; i++)
		{
			do 
			{
				printf("%s?", topics[i]);
				scanf_s("%d", &resx);
			} while (resx < 1 || resx>10);
			recordResponse(i, resx);
		}
		printf("Enter 1 to stop. Enter 0 to rate the issues again.");
		scanf_s("%d", &resx);
	} while (resx != 1);
	displayResults();
	system("PAUSE");
	return 0;
}

void recordResponse(int iss, int rating)
{
	res[iss][rating - 1]++;
}

void lowestRatings()
{
	int i, j, hira = 0, hito = 0;
	for (i = 0; i < ISSUES; i++)
	{
		int toRa = 0;
		for (j = 0; j < RATINGS; j++)
		{
			toRa += res[i][j] * (j + 1);
		}
		if (i == 0)
		{
			hira = toRa;
		}
		if (hira > toRa)
		{
			hira = toRa;
			hito = i;
		}
	}
	printf("The lowest rated topic was %s with a total rating of %d\n", topics[hito], hira);
}


void highestRatings()
{
	int i, j, hira = 0, hito = 0;
	for (i = 0; i < ISSUES; i++)
	{
		int toRa = 0;
		for (j = 0; j < RATINGS; j++)
		{
			toRa += res[i][j] * (j + 1);
		}
		if (hira < toRa)
		{
			hira = toRa;
			hito = i;
		}
	}
	printf("The highest rated topic was %s with a total rating of %d\n", topics[hito], hira);
}

float aveRating(int iss)
{
	float total = 0;
	int counter = 0, j;
	for (j = 0; j < RATINGS; j++)
	{
		if (res[iss][j] != 0)
		{
			total += res[iss][j] * (j + 1);
			counter += res[iss][j];
		}
	}
	return total / counter;
}

void displayResults()
{
	int i, j;
	printf("%20s", "Topic");
	for (i = 1; i <= RATINGS; i++)
	{
		printf("%4d", i);
	}
	printf("%20s\n", "Average Rating");
	for (i = 0; i < ISSUES; i++)
	{
		printf("%20s", topics[i]);
		for (j = 0; j < RATINGS; j++)
		{
			printf("%4d", res[i][j]);
		}
		printf("%20.2f\n", aveRating(i));
	}
	highestRatings();
	lowestRatings();
}