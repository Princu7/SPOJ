# include <bits/stdc++.h>
using namespace std;
# define mp(a,b,c) make_pair( make_pair(a,b) , c)
# define triplet pair< pair<int,int> , int>
vector <triplet> V[101];
bool nodeVisited[101][10001]={0};


class Prioritize
{
    public:
        int operator() (const triplet& a,const triplet& b)
        {
            return a.second < b.second;
        }
};

void clearQueue(priority_queue< triplet , vector<triplet>, Prioritize> q )
{
   std::priority_queue< triplet, vector<triplet>, Prioritize > empty;
   std::swap( q, empty );
}

void scanint(int &x)
{
 register int c = getchar_unlocked();
 x = 0;
 for(;(c<48 || c>57);c = getchar_unlocked())
  ;
 for(;c>47 && c<58;c = getchar_unlocked()) 
 {
   x = (x<<1) + (x<<3) + c - 48;
 }
}
            
int dist[101][10001];
int main(void)
{
    int test,k,n,r,s,d,l,t,w=0;
    scanint(test);
    while(test--)
    {    
        scanint(k);
        scanint(n);
        scanint(r);
        while(r--)
        {
            w=0;
            scanint(s);
            scanint(d);
            scanint(l);
            scanint(t);
            V[s].push_back(mp(d,t,l));
        }
        priority_queue< triplet, vector<triplet>, Prioritize> Q;
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<10001;j++)
            {
                dist[i][j]=INT_MAX;
            }
        }
        dist[1][0]=0;
        Q.push(mp(1,0,dist[1][0]));
        int flag=0;
        while(!Q.empty())
        {
            triplet p=Q.top();
            Q.pop();
            int vertex=p.first.first;
            int coins=p.first.second;
            int length=p.second;
            //printf("%d %d\n",coins,length);
            if(vertex==n)
            {
                    printf("%d\n",length);
                    flag=1;
                break;
            }
            for(int i=0;i<V[vertex].size();i++)
            {
                int curVertex=V[vertex][i].first.first;
                int curCoins=V[vertex][i].first.second;
                int curLength=V[vertex][i].second;
                /*cout<<"curVerted "<<curVertex<<" curcoins "<<curCoins<<" "<<curLength<<endl;
                 cout<<"length + curlenght="<<length+curLength<<endl;
                cout<<"dist max "<<dist[curVertex][curCoins]<<endl; */
                if(length+curLength<=dist[curVertex][curCoins])
                {
                //cout<<"length + curlenght="<<length+curLength;
                    if(coins+curCoins<=k)
                    {
                        dist[curVertex][curCoins]=length+curLength;
                        Q.push(mp(curVertex,coins+curCoins,dist[curVertex][curCoins]));
                        //printf("vertex pushed %d  %d having length %d\n",curVertex,curCoins+coins,dist[curVertex][curCoins]);
                    }
                }
            }
        }
        for(int i=0;i<=100;i++)
            V[i].clear();
        if(flag==0)
            printf("-1\n");
	clearQueue(Q);
    }
    return 0;
}
