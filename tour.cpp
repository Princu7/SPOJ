# include <bits/stdc++.h>
using namespace std;
stack <int> S;
bool visited[1003]={0};
vector <int> V[1004];
vector <int> R[1004];
int comp[1003];
int n,m;
int counter=0;
void dfsFirst(int source)
{
    visited[source]=1;
    for(int i=0;i<V[source].size();i++)
    {
        if(!visited[V[source][i]])
            dfsFirst(V[source][i]);
    }
    //cout<<" pushing "<<source<<" to stack"<<endl;
    S.push(source);
}
void reverseGraph()
{
    for(int i=1;i<=n;i++)
        for(int j=0;j<V[i].size();j++)
            R[V[i][j]].push_back(i);
}
void dfsSecond(int source)
{
    visited[source]=1;
    //cout<<"node "<<source<<" put in comp "<<counter<<endl;
    comp[source]=counter;
    for(int i=0;i<R[source].size();i++)
    {
        if(!visited[R[source][i]])
            dfsSecond(R[source][i]);
    }
}
int main(void)
{
    int test;
    scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		int count=1;
		while(count<=n)
		{
			scanf("%d",&m);
			int winner;
			while(m--)
			{
				scanf("%d",&winner);
				V[count].push_back(winner);
			}
			count++;
		}
		/*cout<<"contents of adjacency list "<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<"for player "<<i<<endl;
			for(int j=0;j<V[i].size();j++)
			{
				cout<<V[i][j]<<" "<<endl;
			}
			cout<<endl;
		}	*/	
		for(int i=1;i<=n;i++)
		{
		    if(!visited[i] && V[i].size()>0)
		        dfsFirst(i);
		}
		reverseGraph();
		for(int i=0;i<=1002;i++)
		    visited[i]=0;
		int *indegree=(int *)calloc(n+1,sizeof(int));
		while(!S.empty())
		{
		    int elem=S.top();
		    //cout<<elem<<" popped"<<endl;
		    S.pop();
		    if(!visited[elem])
		    {
		       // cout<<"dfs done from "<<elem<<endl;
		        dfsSecond(elem);
		        counter++;
		    }
		}
		for(int i=1;i<=n;i++)
		{
		    for(int j=0;j<R[i].size();j++)
		    {
		        if(comp[i]!=comp[R[i][j]])
		        {
		           // cout<<i<<" and "<<R[i][j]<<" dont have the same component "<<endl;
		            indegree[comp[R[i][j]]]++;
		        }
		      //  else
		    //        cout<<i<<" and "<<R[i][j]<<" have the same component "<<endl;
		    }
		}
		//for(int i=0;i<counter;i++)
		  //  cout<<"value of comp "<<i<<" is "<<indegree[i]<<endl;
		int ansComp=0;int flag=0;
		for(int i=0;i<counter;i++)
		{
		    if(indegree[i]==0)
		    {
		        if(flag==0)
		        {
		            ansComp=i;
		            flag=1;
		        }
		        else
		        {
		            flag=2;
		            break;
		        }
		    }
		}
		if(flag==1)
		{
		    int answerCount=0;
		    for(int i=1;i<=n;i++)
		    {
		        if(comp[i]==ansComp)
		            answerCount++;
		    }
		    cout<<answerCount<<endl;
		}
		else
			cout<<"0"<<endl;
		for(int i=0;i<=n+2;i++)
		{
			R[i].clear();
			V[i].clear();
		}
		for(int i=1;i<=n;i++)
			visited[i]=0;
		for(int i=0;i<=counter;i++)
			comp[i]=0;
		counter=0;
	}
    return 0;
}            
