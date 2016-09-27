#include<bits/stdc++.h>
#include<queue>
#include<iostream>
using namespace std;
#define pp pair<int,int>
using namespace std;
const int INF=INT_MAX;
# define gc getchar_unlocked
int scanint()
{
    register int c = gc();
    int x = 0;
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
	return x;
}
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
    int a,b,w,s,d;
    int node,edges;
    vector< pp > G[510];
    vector< pp > R[510];
    int dis[510], rev_dis[510],final_dis[510];
    priority_queue<pp, vector<pp>, Prioritize> Q;
    while(1)
    {
        node=scanint();
		edges=scanint();
        if(node==0 && edges==0)
            break;
        s=scanint();
		d=scanint();
        for(int i=0;i<edges;i++)
        {
            a=scanint();
			b=scanint();
			w=scanint();
            a++,b++;
            G[a].push_back(pp(b,w));
            R[b].push_back(pp(a,w));
        }
        for(int i=1;i<=node;i++)
        {
           dis[i] = INT_MAX;
            rev_dis[i]=INT_MAX;
        }
        s++,d++;
        dis[s]=0;
        rev_dis[d]=0;
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
        {
            cout<<-1<<endl;
            continue;
        }
        //for(int i=1;i<=node;i++)
          //  cout<<dis[i]<<endl;
        int max=dis[d];
        clearQueue(Q);
        Q.push(pp(d,rev_dis[d]));
        while(!Q.empty())
        {
            a = Q.top().first;
            Q.pop();
            int size = R[a].size();
            for(int i=0;i<size;i++)
            {
               b = R[a][i].first;
               w = R[a][i].second;
               if(rev_dis[b] > rev_dis[a]+ w)
               {
                 rev_dis[b] = rev_dis[a]+w;
                 Q.push(pp(b,rev_dis[b]));
               }
            }
        }
        for(int i=0;i<=node;i++)
            final_dis[i]=INT_MAX;
        final_dis[s]=0;
        clearQueue(Q);
        Q.push(pp(s,final_dis[s]));
        while(!Q.empty())
        {
            a = Q.top().first;
            Q.pop();
            int size = G[a].size();
            for(int i=0;i<size;i++)
            {
               b = G[a][i].first;
               w = G[a][i].second;
               if(dis[a]+w+rev_dis[b]==max)
                  continue;
               if(final_dis[b] > final_dis[a]+ w)
               {
                 final_dis[b] = final_dis[a]+w;
                 Q.push(pp(b,dis[b]));
               }
            }
        }
        if(final_dis[d]==INF)
            printf("-1\n");
        else
            printf("%d\n",final_dis[d]);
        for(int i=0;i<510;i++)
		G[i].clear(),R[i].clear();
        clearQueue(Q);
    }
    return 0;
}
