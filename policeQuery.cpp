# include <bits/stdc++.h>
using namespace std;
vector <int> V[10010];
vector <int> cutAdjacent[10009];
map< pair<int,int>,bool> m;
map< pair<int,int>,bool>::iterator it;
int parent[10009];
int low[10009];
int disc[10009];
bool visited[10009];
bool cut[100009];
int disctime=0;
int n,e;

void init()
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        visited[i]=0;
        cut[i]=0;
        low[i]=0;
        disc[i]=0;
        disctime=0;
        V[i].clear();
    }
}

void dfs(int u)
{
    visited[u]=true;
    low[u]=disc[u]=++disctime;
    int child=0;
    for(int i=0;i<V[u].size();i++)
    {
        int v=V[u][i];
        if(!visited[v])
        {
            child++;
            parent[v]=u;
            dfs(v);
            low[u]=minimum(low[u],low[v]);
            if((parent[u]!=-1) && low[v]>=disc[u])
            {
                cut[u]=1;
                cutAdjacent[u].push_back(v);
            }
            if(low[v]>disc[u])
                m.insert(make_pair(make_pair(u,v),1));
            if((parent[u]==-1) && (child>1))
                cut[u]=1;
        }
        else if(v!=parent[u])
            low[u]=min(low[u],disc[v]);
    }
}


int main(void)
{
    int front,back;
    scanf("%d%d",&n,&e);
    while(e--)
    {
        scanf("%d%d",&front,&back);
        V[front].push_back(back);
        V[back].push_back(front);
    }
    dfs(1);
    int queries;
    scanf("%d",&queries);
    int type,a,b,c,g1,g2;
    while(queries--)
    {
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d%d%d",&a,&b,&g1,&g2);
            if(map.
    
