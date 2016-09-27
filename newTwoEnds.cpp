# include <bits/stdc++.h>
using namespace std;
vector <int> arr;
int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int sum=0;
        
int dp[1001][1001];        
int main(void)
{
	int n;
	int count=1;
    while(1)
    {
 		scanf("%d",&n);
		if(n==0)
			exit(0);
		int num;
		while(n--)
		{
			scanf("%d",&num);
			sum+=num;
			arr.push_back(num);
		}
        n=arr.size();
        for(int j=0;j<n;j++)
        {
            for(int i=j;i>=0;i--)
            {
                if(i==j)
                    dp[i][j]=arr[i];
                else if(j-i==1)
                    dp[i][j]=max(arr[i],arr[j]);
                else
                {
                    int max1=arr[i];
                    if(arr[i+1]>=arr[j])
                        max1+=dp[i+2][j];
                    else
                        max1+=dp[i+1][j-1];
                    int max2=arr[j];
                    if(arr[i]>=arr[j-1])
                        max2+=dp[i+1][j-1];
                    else
                        max2+=dp[i][j-2];
                    dp[i][j]=max(max1,max2);
                }
                //cout<<"i="<<i+1<<" "<<"j="<<j+1<<" value is "<<dp[i][j]<<endl;
            }
        }
        cout<<"In game "<<count<<", the greedy strategy might lose by as many as "<<2*dp[0][n-1]-sum<<" points."<<endl;
		count++;
		arr.clear();
		for(int j=0;j<n;j++)
			for(int i=j;i>=0;i--)
				dp[i][j]=0;
		sum=0;
	}
}
