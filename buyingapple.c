# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
int min(int a,int b)
{
    if(a<=b)
        return a;
    return b;
}

int main(void)
{
    int t;
    int a[101][101];
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int *price=calloc(k,sizeof(int));
        int i=0,j=0;
        for(i=0;i<k;i++)
        {
            scanf("%d",&j);
            price[i]=j;
        }
        int min_value[101];
        for(i=0;i<=100;i++)
            min_value[i]=-1;
        min_value[0]=0;
        for(i=0;i<=k;i++)
            a[i][0]=0;
        for(i=1;i<=k;i++)
        {
            if(price[0]==-1)
                a[0][i]=-1;
            else
                a[0][i]=i*price[0],min_value[i]=i*price[0];   
        }
        for(i=1;i<=k-1;i++)
        {
            for(j=1;j<=k;j++)
            {
                if(j<=i)
                {
                    a[i][j]=min_value[j];
                    continue;
                }
                if(price[i]==-1)
                    a[i][j]=min_value[j];
                else
                {
                     if(min_value[j]==-1 && min_value[j-i-1]==-1)
                        a[i][j]=-1;
                    else if(min_value[j]==-1 && min_value[j-i-1]>=0)
                    {
                        a[i][j]=price[i]+min_value[j-i-1];
                        min_value[j]=a[i][j];
                    }
                    else if(min_value[j]>=0 && min_value[j-i-1]==-1)
                        a[i][j]=min_value[j];
                    else
                    {
                        a[i][j]=min(price[i]+min_value[j-i-1],min_value[j]);
                        min_value[j]=a[i][j];
                    }
                }
            }
        }
        printf("%d\n",a[k-1][k]);
    }
    return 0;
}
