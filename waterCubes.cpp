# include <bits/stdc++.h>
using namespace std;
bool restricted[101][101];
int a[101][101];
bool water[101][101];
int ans=0;
int n,m;
void resbfs(int x,int y)
{
    if(restricted[x][y])
        return;
    queue < pair<int,int> > Q;
    Q.push(make_pair(x,y));
    while(!Q.empty())
    {
        pair <int,int> p=Q.front();
        pair<int,int> l,r,u,d;
        Q.pop();
        //cout<<"this is the value popped "<<p.first<<" "<<p.second<<endl;
        restricted[p.first][p.second]=1;
        l.first=p.first,l.second=p.second-1;
        r.first=p.first,r.second=p.second+1;
        u.first=p.first-1,u.second=p.second;
        d.first=p.first+1,d.second=p.second;
        if(!restricted[l.first][l.second] && a[l.first][l.second]>a[p.first][p.second])
            Q.push(l);
        if(!restricted[r.first][r.second] && a[r.first][r.second]>a[p.first][p.second])
            Q.push(r);
        if(!restricted[u.first][u.second] && a[u.first][u.second]>a[p.first][p.second])
            Q.push(u);
        if(!restricted[d.first][d.second] && a[d.first][d.second]>a[p.first][p.second])
            Q.push(d);
    }
}

void bfs(int x,int y)
{
    queue < pair<int,int> > Q;
    Q.push(make_pair(x,y));
    vector < pair<int,int> > V;
    int minimum=INT_MAX;
    pair <int,int> prev;
    int count=0;
    bool vis[101][101];
    while(!Q.empty())
    {
        count++;
        pair <int,int> p=Q.front();
        pair<int,int> l,r,u,d;
        Q.pop();
        V.push_back(p);
        water[p.first][p.second]=1;
        vis[p.first][p.second]=1;
        cout<<p.first<<" "<<p.second<<"was added"<<endl;
        l.first=p.first,l.second=p.second-1;
        r.first=p.first,r.second=p.second+1;
        u.first=p.first-1,u.second=p.second;
        d.first=p.first+1,d.second=p.second;
        bool lflag,rflag,uflag,dflag;
        lflag=rflag=uflag=dflag=0;
        if(!restricted[l.first][l.second] && a[l.first][l.second]<=a[p.first][p.second] && !vis[l.first][l.second])
        {
            Q.push(l);
            V.push_back(l);
            lflag=1;
        }
        if(!restricted[r.first][r.second] && a[r.first][r.second]<=a[p.first][p.second] && !vis[r.first][r.second])
        {
            Q.push(r);
            V.push_back(r);
            rflag=1;
        }
        if(!restricted[u.first][u.second] && a[u.first][u.second]<=a[p.first][p.second] && !vis[u.first][u.second])
        {
            Q.push(u);
            V.push_back(u);
            uflag=1;
        }
        if(!restricted[d.first][d.second] && a[d.first][d.second]<=a[p.first][p.second] && !vis[d.first][d.second])
        {
            Q.push(d);
            V.push_back(d);
            dflag=1;
        }
        if(!lflag && a[l.first][l.second]<minimum && l!=prev)
            minimum=a[l.first][l.second];
        if(!rflag && a[r.first][r.second]<minimum && r!=prev)
            minimum=a[r.first][r.second];;
        if(!dflag && a[d.first][d.second]<minimum  && d!=prev)
            minimum=a[d.first][d.second];;
        if(!uflag && a[u.first][u.second]<minimum  && u!=prev)
            minimum=a[u.first][u.second];
        prev=p;
        /*if(count==10)
            exit(0); */
        cout<<"temp min value "<<minimum<<endl;
    }
    cout<<"final min value "<<minimum<<endl;
    for(int i=0;i<V.size();i++)
    {
        pair<int,int> p=V[i];
        //cout<<p.first<<" "<<p.second<<endl;
        //cout<<a[p.first][p.second]<<endl;
        if(a[p.first][p.second]<minimum)
        {
            ans=ans+minimum-a[p.first][p.second];
            a[p.first][p.second]=minimum;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }   
}

int main(void)
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<=n-1;i++)
        {
            if(i==0 || i==n-1)
            {
                for(int j=0;j<m;j++)
                    resbfs(i,j);
            }
            else
            {   
                resbfs(i,0);
                resbfs(i,m-1);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!restricted[i][j] && !water[i][j])
                {
                    cout<<i<<" "<<j<<" "<<"is selected"<<endl;
                    bfs(i,j);
                }
                //else
                  //  cout<<i<<" "<<j<<" "<<"is rejected"<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
