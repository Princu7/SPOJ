/* Dynamic Programming implementation of LCS problem */
# include <bits/stdc++.h>
using namespace std;
string X;
string Y;
int len=0;
int L[6103][6103];
int lcs()
{
   for (int i=0; i<=len; i++)
   {
     for (int j=0; j<=len; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[len][len];
}
 
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        cin>>X;
        Y=X;
        reverse(Y.begin(),Y.end());
        len=X.length();
        cout<<len-lcs()<<endl;
    }
  return 0;
}
