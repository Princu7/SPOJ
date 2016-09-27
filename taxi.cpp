# include <bits/stdc++.h>
using namespace std;
bool seen[500];
int matchLeft[500];
int matchRight[500];
int persons,taxis,speed,timesec;
struct person
{
    int x,y;
} P[405];

bool graph[205][406];
bool bpm(int u);

int maximumMatch()
{

    for(int i=0;i<500;i++)
    {
    
        matchLeft[i]=-1;
        matchRight[i]=-1;
    }
    int count=0;
    for(int i=0;i<taxis;i++)
    {
        for(int j=0;j<500;j++)
            seen[j]=0;
        if(bpm(i))
            count++;
    }
    return count;
}

bool bpm(int u)
{

    for(int v=0;v<persons;v++)
    {
        if(!graph[u][v] || seen[v])
            continue;
        seen[v]=1;
        if(matchRight[v]==-1 || bpm(matchRight[v]))
        {
            matchLeft[u]=v;
            matchRight[v]=u;
            return true;
        }
    }
    return false;
}

void reset()
{
    for(int i=0;i<=taxis+2;i++)
        for(int j=0;j<=persons+2;j++)
            graph[i][j]=0;
    for(int i=0;i<persons;i++)
        P[i].x=P[i].y=0;
}

int main(void)
{
    int test,a,b;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d%d%d",&persons,&taxis,&speed,&timesec);
        for(int i=0;i<persons;i++)
        {
            scanf("%d%d",&a,&b);
            P[i].x=a;
            P[i].y=b;
        }
        for(int i=0;i<taxis;i++)
        {
            scanf("%d%d",&a,&b);
            for(int j=0;j<persons;j++)
            {
                if((abs(a-P[j].x)*200+abs(b-P[j].y)*200)<=(speed*timesec))
                    graph[i][j]=1;
                else
                    graph[i][j]=0;
            }
        }
        int answer=maximumMatch();
        cout<<answer<<endl;
        reset();
    }
    return 0;
}   
