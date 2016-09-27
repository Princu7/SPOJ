# include <bits/stdc++.h>
using namespace std;
vector <int> V[100009];
queue <int> Q;
int main(void)
{
    int n,m,k;
    while(1)
    {
        scanf("%d%d%d",&n,&k,&m);
        if(n==-1)
            break;
        int *saviour=(int *)calloc(n+5,sizeof(int));
        int *restricted=(int *)calloc(n+5,sizeof(int));
        int *waiting=(int *)calloc(n+5,sizeof(int));
        bool *visited=(bool *)calloc(n+5,sizeof(bool));
        int a,b,c,d;
        while(k--)
        {
            scanf("%d%d",&a,&b);
            restricted[b]=1;
            saviour[a]=b;
        }
        while(m--)
        {
            scanf("%d%d",&c,&d);
            V[c].push_back(d);
            V[d].push_back(c);
        }
        Q.push(1);
        visited[1]=1; int node;
        while(!Q.empty())
        {
            int a=Q.front();
            Q.pop();
            for(int i=0;i<V[a].size();i++)
            {
                node=V[a][i];
                if(!visited[node])
                {
                    if(saviour[node])
                    {
                        if(waiting[saviour[node]])
                        {
                            Q.push(saviour[node]);
                            visited[saviour[node]]=1;
                        }
                        else
                            restricted[saviour[node]]=0;
                        Q.push(node);
                        visited[node]=1;
                    }
                    else if(restricted[node])
                        waiting[node]=1;
                    else if(!restricted[node])
                    {
                        Q.push(node);
                        visited[node]=1;
                    }
                }
            }
        }
        if(visited[n])
            printf("Y\n");
        else
            printf("N\n");
        for(int i=0;i<=n;i++)
            V[i].clear();
    }
    return 0;
}
