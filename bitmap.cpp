# include <bits/stdc++.h>
int ans[200][200];
using namespace std;
int row,col;
queue < pair<int,int> > q;
void insert(pair <int,int> p,int answer)
{
    if((p.first>=1 && p.first<=row) && (p.second>=1 && p.second<=col))
    {
        if(ans[p.first][p.second]>answer+1)
        {
            q.push(p);
            ans[p.first][p.second]=answer+1;
        }
    }
}
        
void bfs(int a,int b)
{
    ans[a][b]=0;
    q.push(make_pair(a,b));
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        int x=p.first;
        int y=p.second;
        insert(make_pair(x+1,y),ans[x][y]);
        insert(make_pair(x,y+1),ans[x][y]);
        insert(make_pair(x-1,y),ans[x][y]);
        insert(make_pair(x,y-1),ans[x][y]);
    }
}
        
int main(void)
{
    int t;char bit;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<200;i++)
            for(int j=0;j<200;j++)
                ans[i][j]=785456;
        scanf("%d%d",&row,&col);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                scanf(" %c",&bit);
                if(bit=='1')
                {
                    bfs(i+1,j+1);
                    /*for(int i=1;i<=row;i++)
                    {
                        for(int j=1;j<=col;j++)
                        {
                            cout<<ans[i][j]<<" ";
                        }
                        cout<<endl;
                    }*/
                }
            }
        }
        for(int i=1;i<=row;i++)
        {
             for(int j=1;j<=col;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
