# include <bits/stdc++.h>
# define min(a,b) (a<=b)?a:b
# define INT_MAX 1000000000
using namespace std;
int main(void)
{
    int test;
    scanf("%d",&test);
    int e,f;
    while(test--)
    {
        scanf("%d%d",&e,&f);
        int w=f-e;
        int n;
        if(w==0)
        {
            cout<<"This is impossible."<<endl;
            continue;
        }
        scanf("%d",&n);
        int *value=(int *)calloc(n+1,sizeof(int));
        int *weight=(int *)calloc(n+1,sizeof(int));
        for(int i=1;i<=n;i++)
            scanf("%d%d",value+i,weight+i);
        //cout<<"i am reaching here "<<endl;
        int **dp=(int **)calloc(n+1,sizeof(int*));
        for(int i=0;i<=n;i++)
            dp[i]=(int *)calloc(w+1,sizeof(int));
        //cout<<" i am reaching hre too "<<endl;
        for(int i=0;i<=w;i++)
            dp[0][i]=INT_MAX;
        //cout<<"reaching init one "<<endl;
        //cout<<"value of n"<<n<<endl;
        for(int i=0;i<=n;i++)
        {
            //cout<<i<<endl;
            dp[i][0]=0;
        }
        //cout<<"reaching here init two "<<endl;
        int a,b;
        //cout<<"reaching three"<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
            {
                b=INT_MAX;
                a=dp[i-1][j];
                if(j-weight[i]>=0)
                    b=value[i]+dp[i][j-weight[i]];
                dp[i][j]=min(a,b);
                //if(dp[i][j]!=dp[i-1][j])
                    //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                //cout<<"value and weight "<<value[i]<<" "<<weight[i]<<endl;
                //cout<<"value of"<<i<<" "<<j<<" is "<<dp[i][j]<<endl;
            }
        }
        if(abs(dp[n][w])!=INT_MAX && dp[n][w]>0)
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[n][w]<<"."<<endl;
        else
            cout<<"This is impossible."<<endl;
        for(int i=0;i<=n;i++)
            free(dp[i]);
    }
    return 0;

}
