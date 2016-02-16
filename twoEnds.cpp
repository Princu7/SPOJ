# include <bits/stdc++.h>
using namespace std;
vector <char> V;
vector <int> arr;
int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int sum=0;
int toNumber(vector <char> V)
{
    int power=1;int num=0;
    for(int i=V.size()-1;i>=0;i--,power*=10)
        num=num+power*(V[i]-48);
    sum+=num;
    return num;
}
        
void split(string input)
{
    for(int i=0;i<input.length();i++)
    {
        while(input[i]!=' ' && input[i]!='\0')
        {
            V.push_back(input[i]);
            i++;
        }
        arr.push_back(toNumber(V));
        V.clear();
    }
}
        
int dp[1001][1001];        
int main(void)
{
    string input="";
    while(1)
    {
        arr.clear();
        getline(cin,input);
        if(input=="0")
            exit(0);
        split(input);
        int n=arr.size();
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
        cout<<"this is the margin by which the player 2 will lose "<<sum-dp[0][n-1]<<endl;
    }
}
