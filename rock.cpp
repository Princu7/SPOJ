# include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        scanf("%d",&n);
        string input;
        cin>>input;
        int len=input.length();
        int *dp=(int *)calloc(len+1,sizeof(int));
        dp[len]=0;
        if(input[len-1]==49)
            dp[len-1]=1;
        else
            dp[len-1]=0;
        for(int i=len-2;i>=0;i--)
        {
            int countOne=0, lenTraversed=1,tempAns=0;
            for(int j=i;j<len;j++)
            {
                if(input[j]==49)
                    countOne++;
                if(countOne*2-lenTraversed>0)
                {
                    if(lenTraversed+dp[j+1]>tempAns)
                        tempAns=lenTraversed+dp[j+1];
                }
                lenTraversed++;
            }
            if(tempAns>dp[i+1])
                dp[i]=tempAns;
            else
                dp[i]=dp[i+1];
        }
        cout<<dp[0]<<endl;
    }
    return 0;
}
