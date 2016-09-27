# include <bits/stdc++.h>
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
} L[101][101];
bool done[101][101]={0};
void lcs()
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
}

void generate_string(int i,int j)
{
    //getchar();
    //printf("i= %d and j= %d \n",i,j);
    done[i][j]=1;
    if(L[i][j].num==0)
        return;
    string temp="";
    if(X[i-1]==Y[j-1])
    {
        temp=X[i-1];
        if(!done[i-1][j-1])
            generate_string(i-1,j-1);
        //else
          //  printf("i= %d and j= %d \n done so not doing",i-1,j-1);
        if(L[i-1][j-1].S.size()==0)
            L[i][j].S.insert(temp);
        else
        {
            for( auto it=L[i-1][j-1].S.cbegin();it!=L[i-1][j-1].S.cend();it++)
                L[i][j].S.insert(*it+temp);
        }
    }
    else if(L[i][j-1].num>L[i-1][j].num)
    {
        if(!done[i][j-1])
            generate_string(i,j-1);
        //else
          //  printf("i= %d and j= %d \n done so not doing",i,j-1);
        for(auto it=L[i][j-1].S.cbegin();it!=L[i][j-1].S.cend();it++)
            L[i][j].S.insert(*it+temp);
    }
    else if(L[i-1][j].num>L[i][j-1].num)
    {
        if(!done[i][j-1])
            generate_string(i-1,j);
        //else
          //  printf("i= %d and j= %d \n done so not doing",i-1,j);
        for( auto it=L[i-1][j].S.cbegin();it!=L[i-1][j].S.cend();it++)
            L[i][j].S.insert(*it+temp);
    }
    else
    {
        if(!done[i][j-1])
            generate_string(i,j-1);
        //else
          // printf("i= %d and j= %d \n done so not doing",i,j-1);
        for(auto it=L[i][j-1].S.cbegin();it!=L[i][j-1].S.cend();it++)
            L[i][j].S.insert(*it+temp);
        temp="";
        if(!done[i-1][j])
            generate_string(i-1,j);
        //else
          // printf("i= %d and j= %d \n done so not doing",i-1,j);
        for(auto it=L[i-1][j].S.cbegin();it!=L[i-1][j].S.cend();it++)
            L[i][j].S.insert(*it+temp);
    }
    /*printf(" iam  printing i=%d and j=%d \n",i,j);
    for(auto it=L[i][j].S.cbegin();it!=L[i][j].S.cend();it++)
            cout<<*it<<" ";
    cout<<endl;*/
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
        for(int i=0;i<=100;i++)
            for(int j=0;j<=100;j++)
                L[i][j].S.clear(),L[i][j].num=0,done[i][j]=0;;
        lcs();
        /*for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++)
                cout<<L[i][j].num<<" ";
            cout<<endl;
        }*/
        generate_string(len1,len2);
        if(L[len1][len2].S.size()==0)
            cout<<endl;
        else
        {
            for(it=L[len1][len2].S.begin();it!=L[len1][len2].S.end();it++)
                cout<<*it<<endl;
        }
        cout<<endl;
    }
  return 0;
}
