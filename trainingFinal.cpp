# include <bits/stdc++.h>
# define minimum(a,b) (a<=b)?a:b;
using namespace std;
int a[25][25];
int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    int ix,iy;
    scanf("%d%d",&ix,&iy);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    if(ix==n && iy==m)
    {
        cout<<"Y "<<a[n][m]<<endl;
        return 0;
    }
    int dp[25][25];
    for(int i=0;i<25;i++)
        for(int j=0;j<25;j++)
            dp[i][j]=1000000000;
    int flag=0;
    for(int i=n;i>=ix;i--)
    {
        for(int j=m;j>=iy;j--)
        {
            if(i==ix && j==iy)
            {
                flag=1;
                break;
            }
            else if(i==n && j==m)
            {
                dp[i][j]=a[i][j];
                continue;
            }
            int temp1,temp2;
                temp1=dp[i+1][j];
                temp2=dp[i][j+1];
            if(temp1<=temp2)
                dp[i][j]=a[i][j]+temp1;
            else
                dp[i][j]=a[i][j]+temp2;
        }
        if(flag==1)
            break;
    }
    if(dp[ix+1][iy]<=dp[ix][iy+1])
    {
        int ans=a[ix][iy]-dp[ix+1][iy];
        if(ans<0)
            cout<<"N\n";
        else
            cout<<"Y "<<ans<<endl;
    }
    else
    {
        int ans=a[ix][iy]-dp[ix][iy+1];
        if(ans<0)
            cout<<"N\n";
        else
            cout<<"Y "<<ans<<endl;
    }
    return 0;
}
            
