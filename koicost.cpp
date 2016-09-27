# include <bits/stdc++.h>
# define MOD 1000000000
using namespace std;

struct edge
{
    int a;
    int b;
    int weight;
}E[100009];

struct subset
{
    int parent;
    int rank;
    int no;
}S[100009];

bool func(const struct edge&a,const struct edge&b)
{
    return a.weight>b.weight;
}

int find(int i)
{
    if(S[i].parent!=i)
        S[i].parent=find(S[i].parent);
    return S[i].parent;
}

void Union(int x,int y)
{
    int xroot=find(x);
    int yroot=find(y);
    if(S[xroot].rank>S[yroot].rank)
    {
        S[yroot].parent=xroot;
        S[xroot].no+=S[yroot].no;
    }
    else if(S[xroot].rank<S[yroot].rank)
    {
        S[xroot].parent=yroot;
        S[yroot].no+=S[xroot].no;
    }
    else
    {
        S[yroot].parent=xroot;
        S[xroot].rank++;
        S[xroot].no+=S[yroot].no;
    }
	/*S[xroot].parent=yroot;
	S[yroot].no+=S[xroot].no;*/
}

        
int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    int front,end,cost;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&front,&end,&cost);
        E[i].a=front;
        E[i].b=end;
        E[i].weight=cost;
    }
    sort(E,E+m,func);
    /*for(int i=0;i<m;i++)
    {
        //cout<<E[i].weight<<endl;
    }*/
    for(int i=1;i<=n;i++)
    {
        S[i].rank=0;
        S[i].parent=i;
        S[i].no=1;
    }
    long long int noConnected=0;
    long long int answer=0;
    for(int i=0;i<m;i++)
    {
        front=E[i].a;
        end=E[i].b;
        cost=E[i].weight;
        //cout<<"father of "<<front<<" is "<<find(front)<<" it contains "<<S[find(front)].no<<" nodes "<<" and its rank is "<<S[find(front)].rank<<endl;
        //cout<<"father of "<<end<<" is "<<find(end)<<" it contains "<<S[find(end)].no<<" nodes "<<" and its rank is "<<S[find(end)].rank<<endl;
        if(find(front)!=find(end))
        {
            noConnected=noConnected+((long long)S[find(front)].no)*S[find(end)].no;
            answer=(answer+((long long)noConnected)*cost)%MOD;
            Union(front,end);
        }
        else
            answer=(answer+(long long)noConnected*cost)%MOD;
        //cout<<"no of pairs "<<noConnected<<endl;
        //cout<<"answer "<<answer<<endl;
    }
    cout<<answer<<endl;
}
