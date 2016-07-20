#include <stdio.h>
#include<math.h>




int is_prime(int n)
{
    int i,b;






     if(n==2)
     {
         return 1;
     }
    if(n%2==0)
    {
        return 0;
    }


          b=(int)sqrt(n);


        for (i=3 ; i<=b; i=i+2)
        {


            if( n % i== 0 )
            {
                return 0;
            }




        }


            return 1;
}




int main()
{
     int n,t,j;


    scanf("%d", &t);  /*case no*/


    for(j=1 ; j<=t ; j++)
    {
           scanf("%d", & n);


           if( 1 == is_prime(n) )
           {
               printf("%d is a prime\n",n);
           }


                else
                {
                           printf("%d is not a prime\n",n);
                }




       }
    return 0;


}