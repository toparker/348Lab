#include <stdio.h>
int main()
{
	float a[12];
	int i;
	
	a[0] = 23458.01;
	a[1] = 40112.00;
	a[2] = 56011.85;
	a[3] = 37820.88;
	a[4] = 37904.67;
	a[5] = 60200.22;
	a[6] = 72400.31;
	a[7] = 56210.89;
	a[8] = 67230.84;
	a[9] = 68233.12;
	a[10] = 80950.34;
	a[11] = 95225.22;
	
	

	printf("Monthly sales report for 2022\n");
	printf("Month \t\t Sales\n");

	printf("January \t %f\n",a[0]);
	printf("February \t %f\n",a[1]);
	printf("March \t\t %f\n",a[2]);
	printf("April \t\t %f\n",a[3]);
	printf("May \t\t %f\n",a[4]);
	printf("June \t\t %f\n",a[5]);
	printf("July \t\t %f\n",a[6]);
	printf("August \t\t %f\n",a[7]);
	printf("September \t %f\n",a[8]);
	printf("October \t %f\n",a[9]);
	printf("November \t %f\n",a[10]);
	printf("December \t %f\n",a[11]);
	
	float max,min,avg;
	
	max=a[0];
	min=a[0];
	avg = a[0];
	
	for(int i=1;i<12;i++)
	{   
	    avg = avg+a[i];
	    if(a[i]>max)
	    {
	    max = a[i];
	    }
	    if (a[i]<min)
	    {
	    min = a[i];
	    }
	}
	avg = avg/12;
	
	
	printf("Sales summary:\n");
	
	printf("Minimum sales:\t $%f",min);
	for (int i=0;i<12;i++)
	{
	if (a[i]==min)
	{
	switch (i){
	case 0 :printf("(January)\n");break;
	case 1 :printf("(February)\n");break;
	case 2 :printf("(March)\n");break;
	case 3 :printf("(April)\n");break;
	case 4 :printf("(May)\n");break;
	case 5 :printf("(June)\n");break;
	case 6 :printf("(July)\n");break;
	case 7 :printf("(August)\n");break;
	case 8 :printf("(September)\n");break;
	case 9 :printf("(October)\n");break;
	case 10 :printf("(November)\n");break;
	case 11 :printf("(December)\n");break;
	}
	}
	
	}
	
	printf("Maximum sales:\t $%f",max);
	for (int i=0;i<12;i++)
	{
	if (a[i]==max)
	{
	switch (i)
	 {
	case 0: printf("(January)\n");break;
	case 1: printf("(February)\n");break;
	case 2: printf("(March)\n");break;
	case 3: printf("(April)\n");break;
	case 4: printf("(May)\n");break;
	case 5: printf("(June)\n");break;
	case 6: printf("(July)\n");break;
	case 7: printf("(August)\n");break;
	case 8: printf("(September)\n");break;
	case 9: printf("(October)\n");break;
	case 10: printf("(November)\n");break;
	case 11: printf("(December)\n");break;
	}
	}
	}
	printf("\n");
	
	printf("Average sales: \t%f\n",avg);
	printf("Six-Month Moving Average Report:\n");

	for(int i=0;i<6;i++)
	{
		avg = 0;
		for (int j=i;j<i+6;j++)
		{
			avg = avg+a[i];
		}
		avg = avg/6;

		switch (i)
	 {
	case 0: printf("January-July \t%f\n",avg);break;
	case 1: printf("February-August\t%f\n",avg);break;
	case 2: printf("March-September\t%f\n",avg);break;
	case 3: printf("April-October\t%f\n",avg);break;
	case 4: printf("May-November\t%f\n",avg);break;
	case 5: printf("June-December\t%f\n",avg);break;
	 }
	}
	float b[12];
	for (int i=0;i<12;i++)
	{
		b[i]=a[i];
	}
	float temp;
	for(int i=0;i<12;i++)
	{
		for(int j=i;j<12;j++)
		{
			if (b[j]>b[i])
			{
				temp =b[j];
				b[j] =b[i];
				b[i] = temp;
			}
		}
	}
	printf("Sales Report(Highest to Lowest):\n");
	printf(" Month\t\t Sales\n");

	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			if(b[i]==a[j])
			switch (j)
	 {
	case 0: printf("January \t%f\n",b[i]);break;
	case 1: printf("February\t%f\n",b[i]);break;
	case 2: printf("March\t\t%f\n",b[i]);break;
	case 3: printf("April\t\t%f\n",b[i]);break;
	case 4: printf("May\t\t%f\n",b[i]);break;
	case 5: printf("June\t\t%f\n",b[i]);break;
	case 6: printf("July\t\t%f\n",b[i]);break;
	case 7: printf("August\t\t%f\n",b[i]);break;
	case 8: printf("September\t%f\n",b[i]);break;
	case 9: printf("October\t\t%f\n",b[i]);break;
	case 10: printf("November\t%f\n",b[i]);break;
	case 11: printf("December\t%f\n",b[i]);break;
	}
		}
	}

}
