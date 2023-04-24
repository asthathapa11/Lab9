#include <stdio.h>

int main()
{
	int score = -1;

	while(score !=0 && score !=1)
	{
		printf("\nEnter 0 or 1 to STOP\n");
		printf("Enter the NFL score: ");
		fflush(stdout);
		scanf("%d", &score);

		if (score == 0 || score == 1)
		{
			break;
		}

		printf("possible combinations of scoring plays:\n");

		for (int a=0; a<100; a++)
		{
			for (int b=0;b<100;b++)
			{
				if (((a*8) + (b*7)) > score)
				{
					break;
				}
				for (int c=0; c<100; c++)
				{
					if (((a*8) + (b*7) + (c*6)) > score)
					{
						break;
					}
					for (int d=0; d<100; d++)
					{
						if (((a*8) + (b*7) + (c*6) + (d*3)) > score)
						{
							break;
						}
						for (int e=0; e<100; e++)
						{
							if (((a*8) + (b*7) + (c*6) + (d*3) + (e*2)) > score)
							{
								break;
							}
							else if (((a*8) + (b*7) + (c*6) + (d*3) + (e*2)) == score)
							{
								printf("%d (TD + 2pt), %d (TD + 1pt), %d (TD), %d (FG), %d (Safety)\n", a,b,c,d,e);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}