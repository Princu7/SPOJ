# include <iostream>
# include <cstdio>
# include <bits/stdc++.h>
using namespace std;
string word=" ALLIZZWELL";
bool vis[102][102]={0};
bool dfs(char **a,int c,int x,int y)
{
    if(c==10)
        return 1;
    bool ans=0;
    if(!vis[x-1][y] && a[x-1][y]==word[c+1])
    {
        cout<<c<<"positions are "<<x-1<<" "<<y<<endl;
        vis[x-1][y]=1;
        if(dfs(a,c+1,x-1,y))
            return 1;
    }
    if(!vis[x+1][y] && a[x+1][y]==word[c+1])
    {
         cout<<"The current value of the count of the characters is"<<c<<"and the value of the x and y selected for the next character is"<<x+1<<" "<<y<<endl;

        vis[x+1][y]=1;
        if(dfs(a,c+1,x+1,y))
            return 1;
    }
    if(!vis[x][y-1] && a[x][y-1]==word[c+1])
    {
         cout<<"The current value of the count of the characters is"<<c<<"and the value of the x and y selected for the next character is"<<x<<" "<<y-1<<endl;
        vis[x][y-1]=1;
        if(dfs(a,c+1,x,y-1))
            return 1;
    }
    if(!vis[x][y+1] && a[x][y+1]==word[c+1])
    {
         cout<<"The current value of the count of the characters is"<<c<<"and the value of the x and y selected for the next character is"<<x<<" "<<y+1<<endl;
        vis[x][y+1]=1;
        if(dfs(a,c+1,x,y+1))
            return 1;
    }
    if(!vis[x-1][y-1] && a[x-1][y-1]==word[c+1])
    {
         cout<<"The current value of the count of the characters is"<<c<<"and the value of the x and y selected for the next character is"<<x-1<<" "<<y-1<<endl;
        vis[x-1][y-1]=1;
        if(dfs(a,c+1,x-1,y-1))
            return 1;
    }
    if(!vis[x+1][y+1] && a[x+1][y+1]==word[c+1])
    {
         cout<<"The current value of the count of the characters is"<<c<<"and the value of the x and y selected for the next character is"<<x+1<<" "<<y+1<<endl;
        vis[x+1][y+1]=1;
        if(dfs(a,c+1,x+1,y+1))
            return 1;
    }
    if(!vis[x-1][y+1] && a[x-1][y+1]==word[c+1])
    {
         cout<<"The current value of the count of the characters is"<<c<<"and the value of the x and y selected for the next character is"<<x-1<<" "<<y+1<<endl;
        vis[x-1][y+1]=1;
        if(dfs(a,c+1,x-1,y+1))
            return 1;
    }
    if(!vis[x+1][y-1] && a[x+1][y-1]==word[c+1])
    {
         cout<<"The current value of the count of the characters is"<<c<<"and the value of the x and y selected for the next character is"<<x+1<<" "<<y-1<<endl;
        vis[x+1][y-1]=1;
        if(dfs(a,c+1,x+1,y-1))
            return 1;
    }
    return 0;
}
    
int main(void)
{
    int t,r,c;
    scanf("%d",&t);
    while(t--)
    {
        vis[102][102]={0};
        scanf("%d%d",&r,&c);
        char **a=(char **)calloc(r+2,sizeof(char *));
        for(int i=0;i<r+2;i++)
            a[i]=(char *)calloc(c+2,sizeof(char));
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                scanf(" %c",&a[i][j]);
        int posx=0,posy=0,flag=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(a[i][j]=='A')
                    posx=i,posy=j,flag=1;
            }
            if(flag)
                break;
        }
        int count=1;
        vis[posx][posy]=1;
        bool answer=dfs(a,count,posx,posy);
        if(answer==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;        
    }
}
    
        
