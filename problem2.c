#include <stdio.h>
int main()
{
	int score;
	printf("Enter 0 or 1 to STOP\n");
	printf("Enter the NFL score:");
	scanf("%d",&score);

	if (score > 1)
	{
		for(int a=0;a<score;a++)
		{
			for(int b=0;b<score;b++)
			{
				for(int c=0;c<score;c++)
				{
					for(int d=0;d<score;d++)
					{
						for(int e=0;e<score;e++)
						{
							if(8*a+7*b+6*c+3*d+2*e==score)
							{
								printf("%d TD+2pt, %d TD+FG,%d TD,%d 3ptFG,%d Safety\n",a,b,c,d,e);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
