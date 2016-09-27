/* Dynamic Programming implementation of LCS problem */
# include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
string X;
string Y;
int len1=0;
int len2=0;
set< string >::iterator it;
struct myset
{
    set< string >S; 
    int num;
} L[6100][6100];
bool done[6100][6100]={0};
int lcs()
{
   for (int i=0; i<=len1; i++)
   {
     for (int j=0; j<=len2; j++)
     {
       if (i == 0 || j == 0)
         L[i][j].num = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j].num = L[i-1][j-1].num + 1;
       else
         L[i][j].num = max(L[i-1][j].num, L[i][j-1].num);
     }
   }
   return L[len1][len2].num;
}

void generate_string(int i,int j)
{
    printf("i= %d and j= %d \n",i,j);
    getchar();
    done[i][j]=1;
    if(L[i][j].num==0)
        return;
    string temp="";
    if(X[i]==Y[j])
    {
        temp=X[i];
        if(!done[i-1][j-1])
            generate_string(i-1,j-1);
        for(it=L[i-1][j-1].S.begin();it<=L[i-1][j-1].S.end();it++)
            L[i][j].S.insert(temp+*it);
    }
    else if(L[i][j-1].num>L[i-1][j].num)
    {
        if(!done[i][j-1])
            generate_string(i,j-1);
        for(it=L[i][j-1].S.begin();it<=L[i][j-1].S.end();it++)
            L[i][j].S.insert(temp+*it);
    }
    else if(L[i-1][j].num>L[i][j-1].num)
    {
        if(!done[i][j-1])
            generate_string(i-1,j);
        for(it=L[i-1][j].S.begin();it<=L[i-1][j].S.end();it++)
            L[i][j].S.insert(temp+*it);
    }
    else
    {
        if(!done[i][j-1])
            generate_string(i,j-1);
        for(it=L[i][j-1].S.begin();it<=L[i][j-1].S.end();it++)
            L[i][j].S.insert(temp+*it);
        temp="";
        if(!done[i][j-1])
            generate_string(i-1,j);
        for(it=L[i-1][j].S.begin();it<=L[i-1][j].S.end();it++)
            L[i][j].S.insert(temp+*it);
    }
    return;
}       
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        cin>>X;
        cin>>Y;
        len1=X.length();
        len2=Y.length();
        generate_string(len1,len2);
    }
  return 0;
}
   
