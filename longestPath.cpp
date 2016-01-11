# include <iostream>
# include <cstdio>
# include <vector>
# include <map>
# include <algorithm>
using namespace std;
vector <int> V[10010];
int vis[10010],dist[10010];
void dfs(int v,int n)
{
    vis[v]=1;
    dist[v]=n;
    for(int u=0;u<V[v].size();u++)
    {
        if(!vis[V[v][u]])
            dfs(V[v][u],n+1);
    }
}
    
int main(void)
{
    int n,t1,t2;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            vis[i]=0,dist[i]=0,V[i].clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&t1,&t2);
            V[t1-1].push_back(t2-1);
            V[t2-1].push_back(t1-1);
        }
        dist[0]=0;
        dfs(0,0);
        int node=0;
        for(int i=0;i<n;i++)
            if(dist[i]>dist[node])
                node=i;
  	for(int i=0;i<n;i++)
		vis[i]=0;
        dfs(node,0);
        sort(dist,dist+n);
        cout<<dist[n-1]<<endl;
    }
}            
