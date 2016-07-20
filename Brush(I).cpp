#include<stdio.h>
int main()
{
    int t,n,i,j,s,du;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        
        scanf("%d",&n);
        s=0;
 
        for(j=1;j<=n;j++)
        {
            scanf("%d",&du);
            if(du>=0 && du<100)
             s=s+du;
        }
        printf("Case %d: %d\n",i,s);
    }
 
 
    return 0;
}
