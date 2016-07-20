#include <bits/stdc++.h>

using namespace std;

int matrix[2][2],d,mod,a,b,N,m;

void calc(int n){

    if(n==1) return;
    if(n%2==0){
        calc(n/2);
        int temp[2][2];
        memset(temp,0,sizeof(temp));
        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++){
                for(int k=0;k<d;k++) {temp[i][j]+=matrix[i][k]*matrix[k][j];temp[i][j]%=mod;}
            }
        }
        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++){
                matrix[i][j]=temp[i][j];
            }
        }
        return;
    }else{
        int temp[2][2],t2[2][2];
        temp[0][1]=matrix[0][1];temp[0][0]=matrix[0][0];temp[1][1]=matrix[1][1];temp[1][0]=matrix[1][0];
        calc(n/2);

        memset(t2,0,sizeof(t2));

        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++){
                for(int k=0;k<d;k++) {t2[i][j]+=matrix[i][k]*matrix[k][j];t2[i][j]%=mod;}
            }
        }

        memset(matrix,0,sizeof(matrix));
        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++){
                for(int k=0;k<d;k++) {matrix[i][j]+=temp[i][k]*t2[k][j];matrix[i][j]%=mod;}
            }
        }

    }
    return ;
}

int main(){

    int kases,i,j;
    scanf("%d",&kases);

    for(i=1;i<=kases;i++){

        matrix[0][0]=1;matrix[0][1]=1;
        matrix[1][0]=1;matrix[1][1]=0;
        d=2;

        scanf("%d%d%d%d",&a,&b,&N,&m);
        if(N==0){
            printf("Case %d: %d\n",i,a);
        }else if(N==1){
            printf("%Case d: %d\n",i,b);
        }else{
            mod=(int)(pow(10,m)+0.5);
            calc(N-1);

            /*for( i=0;i<2;i++){
                for( j=0;j<2;j++) printf("%d ",matrix[i][j]);
                printf("\n");
            }*/
            printf("Case %d: %d\n",i,(matrix[0][1]*a+matrix[0][0]*b)%mod);
        }
    }

    return 0;
}
