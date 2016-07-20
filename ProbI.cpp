#include <stdio.h>

int main ()
{
	int t, n, count1, count2, count3,temp;
	int array[10][10];
	scanf("&d",&t);
	for (count=0;count<t;count++)
	{
		scanf("%d",&n);
		for (count2=0;count2<n;count2++)
		{
			for(count3=0;count3<n;count3++)
			{
				scanf("%d",&temp);
				array[count2][count3] = temp;
			}
		}
		printf("Matrix %d: ",count+1);
		for (count2 = 0;count2<n;count++)
		{
			printf("\n");
			for (count3=0;count3<n;count3++)
			{
				printf("%d",array[count2][count3]);
			}
		}
		printf(");
	
	}



}