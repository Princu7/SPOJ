#include<bits/stdc++.h>
#include<queue>
#include<iostream>
using namespace std;
#define pp pair<int,int>
using namespace std;
const int INF=INT_MAX;
map< pair<int,int> , int > m;
map< pair<int,int> ,int >::iterator it;
class Prioritize
{
public:
    int operator() ( const pair<int, int>& p1, const pair<int, int>& p2 )
    {
        return p1.second < p2.second;
    }
};

void clearQueue(priority_queue< pp , vector<pp>, Prioritize> q )
{
   std::priority_queue< pp, vector<pp>, Prioritize > empty;
   std::swap( q, empty );
}

int main()
{
    int a,b,w;
    int node,edges;
    while(1)
    {
        priority_queue<pp, vector<pp>, Prioritize> Q;
        int s,d;
        scanf("%d%d",&node,&edges);
        if(node==0 && edges==0)
            break;
        scanf("%d%d",&s,&d);
        vector< pp > G[node+1];
        int parent[node+1];
        for(int i=0;i<edges;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            a++,b++;
            G[a].push_back(pp(b,w));
            m.insert(make_pair( make_pair(a,b),w));
        }
        int dis[node+1];
        for(int i=1;i<=node;i++)
        {
           dis[i] = INT_MAX;
        }
        s++,d++;
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
                 parent[b]=a;
                 dis[b] = dis[a]+w;
                 Q.push(pp(b,dis[b]));
               }
            }
        }
        if(dis[d]==INF)
        {
            cout<<-1<<endl;
            continue;
        }
        int dest=d;
        int papa=parent[dest];
        m.erase(make_pair(papa,dest));
        while(papa!=s)
        {
            dest=papa;
            papa=parent[dest];
            m.erase(make_pair(papa,dest));
        }
        for(int i=0;i<=node;i++)
            G[i].clear();
        for(it=m.begin();it!=m.end();it++)
        {
            cout<<it->first.first<<" "<<it->first.second<<" "<<endl;
            G[it->first.first].push_back(pp(it->first.second,it->second));
        }
        //cout<<endl<<endl;
            for(int i=1;i<=node;i++)
            {
                dis[i] = INT_MAX;
            }
            dis[s]=0;
            clearQueue(Q);
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
               
        if(dis[d]==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<dis[d]<<endl;
        m.clear();
    }
}
