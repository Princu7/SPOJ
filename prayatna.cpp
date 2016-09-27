# include <bits/stdc++.h>
using namespace std;
int gVis[1000004]={0};

void dfs(int node,vector<int> V[])
{
    gVis[node]=1;
    int size=V[node].size();
    for(int i=0;i<size;i++)
    {
        if(!gVis[V[node][i]])
            dfs(V[node][i],V);
    }
    return;
}
    
int main(void)
{
    int t,n,edges,a,b;
    scanf("%d",&t);
    int count=0;
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&edges);
        vector <int > dost[n+1];
        while(edges--)
        {
            scanf("%d%d",&a,&b);
            dost[a].push_back(b);
            dost[b].push_back(a);
        }
        for(int i=0;i<n;i++)
        {
            if(!gVis[i])
            {
                dfs(i,dost);
                count++;
            }
        }
        printf("%d\n",count);
        for(int i=0;i<1000004;i++)
            gVis[i]=0;
        count=0;
    }
}
