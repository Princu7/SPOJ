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
    queue < int> Q;    
    for(int i=1;i<=n;i++)
    {
        if(v[i].degree==1)
            Q.push(v[i].no);
        else
            break;
    }
    while(!Q.empty())
    {
        int cur=Q.front();
        Q.pop();
        //cout<<"current node "<<cur<<endl;
        for(int i=0;i<ver[cur].size();i++)
        {
            if(!done[ver[cur][i]])
            {
                cur=ver[cur][i];
                //cout<<"its parent is "<<cur<<endl;
                break;
            }
        }
        if(v[order[cur]].degree==0)
        {
            //cout<<"it's already been chosen so moving on "<<endl;
            continue;
        }
        v[order[cur]].degree=0;
        for(int i=0;i<ver[cur].size();i++)
        {
            if(done[ver[cur][i]])
                continue;
            if(v[order[ver[cur][i]]].degree!=0)
            {
                //cout<<"edge destroyed "<<ver[cur][i]<<endl;
                v[order[ver[cur][i]]].degree--;
                if(v[order[ver[cur][i]]].degree==1)
                    Q.push(ver[cur][i]);
            }
        }
        done[cur]=1;
        count++;
        //cout<<endl;
    }
    cout<<count<<endl;
    return 0;
}
