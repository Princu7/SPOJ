# include <bits/stdc++.h>
using namespace std;
# define MAX 100
int indegree[MAX+15];
vector < int> V[MAX+15];
set < int > Set;
int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    int task,noTasks,a,b;
    while(m--)
    {
        scanf("%d%d",&task,&noTasks);
        while(noTasks--)
        {
            scanf("%d",&a);
            V[a].push_back(task);
            indegree[task]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
        //    cout<<i<<" zero degree "<<endl;
            Set.insert(i);
        }
    }
    while(!Set.empty())
    {
        int q=*Set.begin();
        cout<<q<<" ";
        Set.erase(q);
        for(int i=0;i<V[q].size();i++)
        {
            int ver=V[q][i];
            indegree[ver]--;
            if(indegree[ver]==0)
                Set.insert(ver);
        }
    }
    return 0;    
}   
            
        
