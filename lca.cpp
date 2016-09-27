# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <vector>
# include <map>
vector <int> V[2000];
bool vis1[2000]
vector <int> node1;
vector <int> node2;
int chance=1;
void firstdfs(int node)
{
    vis[node]=1;
    node1.push_back(node);
    for(int i=0;i<V[node].size();i++)
    {
        if(!vis[V[node][i]])
            dfs(V[node][i]);
    }
}

int findAncestor(int u,int v)
{
    chance=1;
    dfs(u);
    for(int i=0;i<=1999;i++)
        vis[i]=0;
    chance=2;
    dfs(v);
}

int main(void)
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,m;
        cin>>n;
        int counter=0;
        while(counter<n)
        {
            scanf("%d",&m);
            while(m--)
            {
                int childNode;
                scanf("%d",&childNode);
                V[counter].push_back(childNode);
                V[childNode].push_back(counter);
            }
            counter++;
        }
        int nQueries;
        cin>>nQueries;
        printf("Case %d:",counter+1);
        while(nQueries)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            answer=findAncestor(u,v);
            printf("%d",answer);
        }
    }
}




