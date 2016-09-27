# include <bits/stdc++.h>
using namespace std;
int maxThree(long long a,long long  b,long long c)
{
    if(a>=b && a>=c)
        return a;
    else if(b>=a && b>=c)
        return b;
    else
        return c;
}
long long int a[100010];
long long int dp[100019];
int main(void)
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        for(int i=0;i<100019;i++)
            dp[i]=(long long)0;
        if(n==1 || n==2)
        {
            if(n==1)
                cout<<a[0]<<endl;
            else
                cout<<a[0]+a[1]<<endl;
            continue;
        }
        dp[n-1]=a[n-1];
        dp[n-2]=dp[n-1]+a[n-2];
        dp[n-3]=dp[n-2]+a[n-3];
        for(int i=n-4;i>=0;i--)
        {
            dp[i]=maxThree((long long)a[i]+dp[i+2],(long long)a[i]+a[i+1]+dp[i+4],(long long)a[i]+a[i+1]+a[i+2]+dp[i+6]);
            //cout<<dp[i]<<endl;
        }
        cout<<dp[0]<<endl;
    }
    return 0;
}       
