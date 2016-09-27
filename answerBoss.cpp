# include <bits/stdc++.h>
using namespace std;
# define MAX 1002
int indegree[MAX+15];
vector < int> V[MAX+15];
set < int > Set;
set < int >::iterator it;
int main(void)
{
    int n,m,test,a,b;
    scanf("%d",&test);
	int counter=1;
    while(test--)
    {
        scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
		{
			indegree[i]=0;
			V[i].clear();
		}
        while(m--)
        {
            scanf("%d%d",&a,&b);
            V[b].push_back(a);
            indegree[a]++;
        }
	    for(int i=0;i<n;i++)
	    {
			if(indegree[i]==0)
				Set.insert(i);
	    }
	    int count=1;
	    printf("Scenario #%d:\n",counter);
	    queue <int> Q;
	    while(!Set.empty())
	    {
			for(it=Set.begin();it!=Set.end();it++)
			{
				if(indegree[*it]==0)
				    Q.push(*it);
				else
				    break;
			}
			while(!Q.empty())
			{
				int node=Q.front();
				Q.pop();
				Set.erase(node);
				printf("%d %d\n",count,node);
				for(int i=0;i<V[node].size();i++)
				{
				    int ver=V[node][i];
				    indegree[ver]--;
				    if(indegree[ver]==0)
				        Set.insert(ver);
				}
			}
			count++;
	    }
		counter++;
	}
    return 0;    
}        
