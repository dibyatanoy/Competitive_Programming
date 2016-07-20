#include <stdio.h>

int main ()
{

	int t,n = 0; 
	float t1, t2, ans1 = 0, ans2 = 0;
	
	scanf("%d",&t);
	
	for (n=0; n<t;n++)
	{
		scanf("\n%f %f",&t1,&t2);
		if (t1 != t2 && t1 !=0 && t2 != 0)
		{ans1 = (1 / t1) - (1 / t2);
		 ans2 = 1 / ans1;
		}
		 if (ans2<0 || ans1 == 0)
		{
			printf("Case %d: impossible\n",n+1);

		}else{
		
		printf("Case %d: %.5f\n",n+1,ans2);
		}


	}
	return 0;
}