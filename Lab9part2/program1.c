#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* ptr;
	char str[10];
	ptr = fopen("inputfile.txt", "a+");

	if (NULL == ptr)
	{
		printf("file can't be opened \n");
	}

	// read values from file and store in array
	char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	float salesNums[12];
	int count = 0;
	while (fgets(str, 50, ptr) != NULL)
	{
		salesNums[count] = atof(str);
		count++;
	}

	// print monthly sales report
	printf("\nMonthly sales report for 2022:\n\n");
	printf("%-12s%-12s\n", "Month:", "Sales:");

	for (int i = 0; i < 12; i++)
	{
		printf("%-12s$%-12.2f\n", months[i], salesNums[i]);
	}

	// print sales summary
	printf("\nSales summary:\n\n");
	int minSales = 0;
	int maxSales = 0;
	float totalSales = 0;

	for (int i = 0; i < 12; i++)
	{
		if (salesNums[i] < salesNums[minSales])
		{
			minSales = i;
		}
		if (salesNums[i] > salesNums[maxSales])
		{
			maxSales = i;
		}
		totalSales += salesNums[i];
	}

	printf("%-18s$%-12.2f(%s)\n", "Minimum sales:", salesNums[minSales], months[minSales]);
	printf("%-18s$%-12.2f(%s)\n", "Maximum sales:", salesNums[maxSales], months[maxSales]);
	printf("%-18s$%-12.2f\n", "Average sales:", (totalSales/12));

	// print moving average
	printf("\nSix-Month Moving Average Report:\n\n");

	for (int i = 0; i < 7; i++)
	{
		float sixMonthSales = 0;
		for (int j = i; j < (i+6); j++)
		{
			sixMonthSales += salesNums[j];
		}
		printf("%-12s%-5s%-12s$%-12.2f\n", months[i], "-", months[i+5], (sixMonthSales/6));
	}

	// print highest sales
	printf("\nSales Report (Highest to Lowest):\n\n");
	printf("%-12s%-12s\n", "Month:", "Sales:");

	int usedMonths[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	int highMonths[12];

	// 12 times
	for (int i = 0; i < 12; i++)
	{
		int highestSales = 0;
		// for every month
		for (int j = 0; j < 12; j++)
		{
			// check if highest month and not already used
			if (salesNums[j] > salesNums[highestSales] && usedMonths[j] == 0)
			{
				highestSales = j;
			}
		}
		// add highest month to array and mark as used
		usedMonths[highestSales] = 1;
		highMonths[i] = highestSales;
	}

	// print highest months in order
	for (int i = 0; i < 12; i++)
	{
		printf("%-12s$%-12.2f\n", months[highMonths[i]], salesNums[highMonths[i]]);
	}

	fclose(ptr);
	return 0;
}