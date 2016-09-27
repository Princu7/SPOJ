# include <bits/stdc++.h>
# define MOD 1000
using namespace std;
vector < pair<int,int> > V[20009];
queue < pair<int,int> > Q;
int dist[20009];
int main(void)
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        scanf("%d",&n);
		for(int i=0;i<=n+5;i++)
		{
            dist[i]=0;
			V[i].clear();
		}
        char c; int num1,num2;
		while(1)
		{
			scanf( "%*c%c", &c );
		    if(c=='O')
		        break;
		    else if(c=='E')
		    {
		        scanf("%d",&num1);
		        cout<<dist[num1]<<endl;
		    }
		    else if(c=='I')
		    {
		        scanf("%d%d",&num1,&num2);
		        int a=dist[num2]+(abs(num1-num2))%MOD;
		        V[num2].push_back(make_pair(num1,(abs(num1-num2))%MOD));
		        dist[num1]=a;
		        Q.push(make_pair(num1,a));
		        while(!Q.empty())
		        {
		            int p=Q.front().first;
					int add=Q.front().second;
		            Q.pop();
		            for(int i=0;i<V[p].size();i++)
		            {
		                dist[V[p][i].first]=add+V[p][i].second;
		                Q.push(make_pair(V[p][i].first,add+V[p][i].second));
		            }
		        }
		    }
		}
    }
    return 0;
}
