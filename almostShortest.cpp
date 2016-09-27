#include<bits/stdc++.h>
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
        vector<int> prev[501];
        for(int i=0;i<edges;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            a++,b++;
            G[a].push_back(pp(b,w));
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
                 dis[b] = dis[a]+w;
                 Q.push(pp(b,dis[b]));
                 prev[b].clear();
                 prev[b].push_back(a);
               }
               else if(dis[b]==dis[a]+w)
                {
                    prev[b].push_back(a);
                }
            }
         }
         bool mark[510][510];
         bool visited[510];
         clearQueue(Q);
         visited[d]=1;
        queue <int > q;
         q.push(d);
         while(!q.empty())
         {
            //cout<<"initial this is the size of the queue "<<q.size()<<endl;
            a=q.front();
            q.pop();
             //cout<<"middle this is the size of the queue "<<q.size()<<endl;
            int size=prev[a].size();
            for(int i=0;i<size;i++)
            {
                mark[prev[a][i]][a]=1;
               // cout<<"this is the edge being marked "<<prev[a][i]<<" "<<a<<endl;
                if(!visited[prev[a][i]])
                {
                    q.push(prev[a][i]);
                    visited[prev[a][i]]=1;
                }
                
            }
             //cout<<"final this is the size of the queue "<<q.size()<<endl;
        }
        for(int i=1;i<=node;i++)
        {
           dis[i] = INT_MAX;
        }
        dis[s]=0;
        Q.push(pp(s,dis[s]));
        while(!Q.empty())
        {
            a=Q.top().first;
            Q.pop();
            int size=G[a].size();
            for(int i=0;i<size;i++)
            {
                b=G[a][i].first;
                w=G[a][i].second;
                if(!mark[a][b])
                {
                    if(dis[b]>dis[a]+w)
                    {
                        dis[b]=dis[a]+w;
                        Q.push(pp(b,dis[b]));
                    }
                }
            }
        }
        if(dis[d]==INF)
            printf("-1\n");
        else
            printf("%d\n",dis[d]);
    }
    return 0;
}    
