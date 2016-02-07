# include <bits/stdc++.h>
using namespace std;
# define triplet pair< pair<int,int>, int >
# define mp(a,b) make_pair(a,b)
vector < pair<int,int> > V[50001];
int counter=0;
bool visited[50001]={0};
int bigmax2=-1;
int dfs(int node)
{
    /*if(counter==7)
        exit(0);
    counter++;*/
    //cout<<"value of node is "<<node<<endl;
    int flag=0;
    for(int i=0;i<V[node].size();i++)
    {
        if(!visited[V[node][i].first])
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        //cout<<"this is node "<<node<<" and i am returning zero"<<endl;
        return 0;
    }
    int max1=-1,max2=-1;
    visited[node]=1;
    for(int i=0;i<V[node].size();i++)
    {
        if(!visited[V[node][i].first])
        {
            int a=V[node][i].second+dfs(V[node][i].first);
           // cout<<"this is the value of the a "<<a<<endl;
            if(a>max2)
                max2=a;
            if(max2>max1)
            {
                int temp=max1;
                max1=max2;
                max2=temp;
            }
        }
    }
    if(max2==-1)
    {
        //cout<<"node numbered "<<node<<" is returning "<<max1<<" and value of the max2 is -1"<<endl;;
        return max1;
    }
    else
    {
        //cout<<"this is the node "<<node<<" and this is the value of the max1+max2 "<<max1+max2<<endl;
        //cout<<"this node returned max1 "<<max1<<endl;
        if(max1+max2>bigmax2)
            bigmax2=max1+max2;
        return max1;
    }
}
               
int main(void)
{
    int test;
    scanf("%d",&test);
    int a,b,c,n,vertices;
    while(test--)
    {
        scanf("%d",&n);
        vertices=n;
        n--;
        while(n--)
        {
            scanf("%d%d%d",&a,&b,&c);
            V[a].push_back(mp(b,c));
            V[b].push_back(mp(a,c));
        }
        int max1=dfs(a);
        if(max1>bigmax2)
            printf("%d\n",max1);
        else
            printf("%d\n",bigmax2);
        for(int i=0;i<=vertices;i++)
            V[i].clear();
        bigmax2=-1;
        for(int i=0;i<=vertices;i++)
            visited[i]=0;
    }
    return 0;
}    
