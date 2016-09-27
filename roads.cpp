# include <bits/stdc++.h>
using namespace std;
# define mp(a,b,c) make_pair( make_pair(a,b) , c)
# define triplet pair< pair<int,int> , int>
struct node
{
    vector < triplet > V;
}nodes[101][10001];


class Prioritize
{
    public:
        int operator() (const triplet& a,const triplet& b)
        {
            return a.second < b.second;
        }
};

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
            while(w+t<=k)
            {
                nodes[s][w].V.push_back(mp(d,w+t,l));
                w++;
            }
        }
        //the below part is for printing and debugging purposes.
        /*for(int i=1;i<=4;i++)
        {
            for(int j=0;j<=3;j++)
            {
                if(nodes[i][j].V.size())
                {
                    cout<<"node"<<i<<" "<<j<<" "<<"is connected to"<<endl;
                    for(int k=0;k<nodes[i][j].V.size();k++)
                    {
                        int vertex=nodes[i][j].V[k].first.first;
                        int coins=nodes[i][j].V[k].first.second;
                        int edge=nodes[i][j].V[k].second;
                        cout<<vertex<<" "<<coins<<" "<<edge<<endl;
                    }
                }
            }
        }*/
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
        while(!Q.empty())
        {
            triplet p=Q.top();
            Q.pop();
            int vertex=p.first.first;
            int coins=p.first.second;
            int length=p.second;
            for(int i=0;i<nodes[vertex][coins].V.size();i++)
            {
                int curVertex=nodes[vertex][coins].V[i].first.first;
                int curCoins=nodes[vertex][coins].V[i].first.second;
                int curLength=nodes[vertex][coins].V[i].second;
                /*cout<<"curVerted "<<curVertex<<" curcoins "<<curCoins<<" "<<curLength<<endl;
                 cout<<"length + curlenght="<<length+curLength<<endl;
                cout<<"dist max "<<dist[curVertex][curCoins]<<endl; */
                if(length+curLength<dist[curVertex][curCoins])
                {
                //cout<<"length + curlenght="<<length+curLength;
                    dist[curVertex][curCoins]=length+curLength;
                    Q.push(mp(curVertex,curCoins,dist[curVertex][curCoins]));
                }
            }
        }
        int min=INT_MAX;
        for(int i=0;i<=k;i++)
        {
            if(dist[n][i]<min)
                min=dist[n][i];
        }
        if(min==INT_MAX)
            printf("-1\n");
        else
            printf("%d\n",min);
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<10001;j++)
            {
                nodes[i][j].V.clear();
            }
        }

    }
    return 0;
}
