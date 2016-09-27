# include <bits/stdc++.h>
# define minimum(a,b) (a<=b)?a:b
using namespace std;

vector <int> V[10009];
int parent[10009];
int low[10009];
int disc[10009];
bool visited[10009];
bool cut[100009];
int disctime=0;
int n,m;

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
                cut[u]=1;
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
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0 && m==0)
            break;
        init();
        while(m--)
        {
            scanf("%d%d",&front,&back);
            V[front].push_back(back);
            V[back].push_back(front);
        }
        int countAns=0;
        dfs(1);
        for(int i=1;i<=n;i++)
        {
            if(cut[i])
                countAns++;
        }
        cout<<countAns<<endl;
    }
    return 0;
}
