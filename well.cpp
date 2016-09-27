# include <iostream>
# include <cstdio>
# include <bits/stdc++.h>
using namespace std;
string word=" ALLIZZWELL";
bool vis[103][103]={0};
int row,col;
bool dfs(char **a,int c,int x,int y)
{
    /*for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
            cout<<vis[i][j]<<" ";
        cout<<endl;
    }*/
    
    if(c==10)
        return 1;
    bool ans=0;
    if(!vis[x-1][y] && a[x-1][y]==word[c+1])
    {
       // cout<<c<<"positions are "<<x-1<<" "<<y<<endl;
        vis[x-1][y]=1;
        if(dfs(a,c+1,x-1,y))
            return 1;
        vis[x-1][y]=0;
    }
    if(!vis[x+1][y] && a[x+1][y]==word[c+1])
    {
         //cout<<"The current value of the count of the characters is"<<c+1<<"and the value of the x and y selected for the next character is"<<x+1<<" "<<y<<endl;
        vis[x+1][y]=1;
        if(dfs(a,c+1,x+1,y))
            return 1;
        vis[x+1][y]=0;
    } 
    if(!vis[x][y-1] && a[x][y-1]==word[c+1])
    {
         //cout<<"The current value of the count of the characters is"<<c+1<<"and the value of the x and y selected for the next character is"<<x<<" "<<y-1<<endl;
        vis[x][y-1]=1;
        if(dfs(a,c+1,x,y-1))
            return 1;
        vis[x][y-1]=0;
    }
    if(!vis[x][y+1] && a[x][y+1]==word[c+1])
    {
         //cout<<"The current value of the count of the characters is"<<c+1<<"and the value of the x and y selected for the next character is"<<x<<" "<<y+1<<endl;
        vis[x][y+1]=1;
        if(dfs(a,c+1,x,y+1))
            return 1;
        vis[x][y+1]=0;
    }
    if(!vis[x-1][y-1] && a[x-1][y-1]==word[c+1])
    {
         //cout<<"The current value of the count of the characters is"<<c+1<<"and the value of the x and y selected for the next character is"<<x-1<<" "<<y-1<<endl;
        vis[x-1][y-1]=1;
        if(dfs(a,c+1,x-1,y-1))
            return 1;
        vis[x-1][y-1]=0;
    }
    if(!vis[x+1][y+1] && a[x+1][y+1]==word[c+1])
    {
         //cout<<"The current value of the count of the characters is"<<c+1<<"and the value of the x and y selected for the next character is"<<x+1<<" "<<y+1<<endl;
        vis[x+1][y+1]=1;
        if(dfs(a,c+1,x+1,y+1))
            return 1;
        vis[x+1][y+1]=0;
    }
    if(!vis[x-1][y+1] && a[x-1][y+1]==word[c+1])
    {
         //cout<<"The current value of the count of the characters is"<<c+1<<"and the value of the x and y selected for the next character is"<<x-1<<" "<<y+1<<endl;
        vis[x-1][y+1]=1;
        if(dfs(a,c+1,x-1,y+1))
            return 1;
        vis[x-1][y+1]=0;
    }
    if(!vis[x+1][y-1] && a[x+1][y-1]==word[c+1])
    {
         //cout<<"The current value of the count of the characters is"<<c+1<<"and the value of the x and y selected for the next character is"<<x+1<<" "<<y-1<<endl;
        vis[x+1][y-1]=1;
        if(dfs(a,c+1,x+1,y-1))
            return 1;
        vis[x+1][y-1]=0;
    } 
    return 0;
}
    
int main(void)
{
    int t,r,c;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<=102;i++)
            for(int j=0;j<=102;j++)
                vis[i][j]=0;
        scanf("%d%d",&r,&c);
        row=r,col=c;
        char **a=(char **)calloc(r+2,sizeof(char *));
        for(int i=0;i<r+2;i++)
            a[i]=(char *)calloc(c+2,sizeof(char));
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                scanf(" %c",&a[i][j]);
        int posx=0,posy=0,flag=0;bool answer=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(a[i][j]=='A')
                {
                    vis[i][j]=1;
                    answer=dfs(a,1,i,j);
					if(answer==1)
					{
						flag=1;
						break;
					}
                    for(int i=0;i<=102;i++)
            			for(int j=0;j<=102;j++)
                			vis[i][j]=0;
                }  
            }
			if(flag==1)
				break;
        }
        if(answer==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;        
    }
}
    
        
