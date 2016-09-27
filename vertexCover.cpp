# include <bits/stdc++.h>
using namespace std;
struct vertex
{
    int no;
    int degree;
} v[100003];

bool cmpfunc(struct vertex a,struct vertex b)
{
    return a.degree<b.degree;
}

vector < int > ver[100003];

int main(void)
{
    int n;
    scanf("%d",&n);
    int count=n-1;
    bool *done=(bool*)calloc(n+1,sizeof(bool));
    for(int i=0;i<=n;i++)
    {
        v[i].no=i;
        v[i].degree=0;
    }
    while(count--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].degree++;
        v[b].degree++;
        ver[a].push_back(b);
        ver[b].push_back(a);
    }
    sort(v,v+n+1,cmpfunc); int track=0; count=0;
    int *order=(int *)calloc(n+1,sizeof(int));
    for(int i=1;i<=n;i++)
        order[v[i].no]=i;
    
    for(int i=1;i<=n;i++)
    {
        int par=0;
        //cout<<"node number "<<v[i].no<<" and degree "<<v[i].degree<<endl;
        if(v[i].degree==1)
        {
          //  cout<<"child node is "<<v[i].no<<endl;
            for(int j=0;j<ver[v[i].no].size();j++)
            {
                if(!done[ver[v[i].no][j]])
                {
                    par=ver[v[i].no][j];
                    break;
                }
            }
           // cout<<"parent node "<<par<< " selected "<<endl;
            v[order[par]].degree=0;
            for(int j=0;j<ver[par].size();j++)
            {
                int child=ver[par][j];
                if(v[order[child]].degree!=0)
                {
                    v[order[child]].degree--;
             //       cout<<"destroying edge "<<ver[par][j]<<endl;
                }
            }
            done[par]=1;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
