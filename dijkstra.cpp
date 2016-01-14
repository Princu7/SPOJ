#include<bits/stdc++.h>
#include<queue>
#include<iostream>
using namespace std;
#define pp pair<int,int>
using namespace std;
const int INF=INT_MAX;
class Prioritize
{
public:
    int operator() ( const pair<int, int>& p1, const pair<int, int>& p2 )
    {
        return p1.second < p2.second;
    }
};
int main()
{
    int tc,a,b,w;
    int node,edges;
    cin>>tc;
    while(tc--)
    {
        priority_queue<pp, vector<pp>, Prioritize> Q;
        scanf("%d%d",&node,&edges);
        vector< pp > G[node+1];
        for(int i=0;i<edges;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            G[a].push_back(pp(b,w));
        }
        int s,d;
        int dis[node+1];
        for(int i=1;i<=node;i++)
        {
           dis[i] = INT_MAX;
        }
        scanf("%d%d",&s,&d);
        dis[s]=0;
        Q.push(pp(s,dis[s]));
        while(!Q.empty())
        {
            a = Q.top().first;
            Q.pop();
            int size = G[a].size();
            for(int i=0;i<size;i++)
            {
               b = G[a][i].first;
               w = G[a][i].second;
               if(dis[b] > dis[a]+ w)
               {
                 dis[b] = dis[a]+w;
                 Q.push(pp(b,dis[b]));
               }
            }
        }
        if(dis[d]==INF)
        puts("NO");
        else printf("%d\n",dis[d]);
    }
}
