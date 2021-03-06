# include <bits/stdc++.h>
using namespace std;
# define triplet pair< pair< int ,bool>, int >
# define mp(a,b,c) make_pair( make_pair(a,b),c)
# define mpair(a,b) make_pair(a,b)
# define pp pair<int,int>

class Prioritize
{
public:
    int operator() ( const pp& p1, const pp& p2 )
    {
        return p1.second > p2.second;
    }
};

priority_queue < pp,vector<pp>,Prioritize > Q;

int main(void)
{
    int k,n;
    scanf("%d%d",&k,&n);
    vector < pair<int,bool> > V[k+2];
    bool *visited=(bool*)calloc(k+2,sizeof(bool));
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        V[a].push_back(mpair(b,0));
        V[b].push_back(mpair(a,1));
    }
    int *d=(int *)calloc(k+2,sizeof(int));
    for(int i=0;i<=k;i++)
        d[i]=INT_MAX;
    d[1]=0;
    Q.push(mpair(1,0));
    while(!Q.empty())
    {
        cout<<endl;
        pp temp=Q.top();
        Q.pop();
        int svertex=temp.first;
        int curTime=temp.second;
        visited[svertex]=1;
        cout<<"vertex "<<svertex<<"having time  "<<curTime<<" popped off "<<endl;
        for(int i=0;i<V[svertex].size();i++)
        {
            int dvertex=V[svertex][i].first;
            if(visited[dvertex]==1)
                continue;
            bool pos=V[svertex][i].second;
            int timediff=abs((dvertex-svertex)*5);
            if(curTime<=timediff)
            {
                if(curTime==0)
                {
                    d[dvertex]=timediff;
                    Q.push(mpair(dvertex,d[dvertex]));
                    cout<<"vertex "<<dvertex<<"having time  "<<d[dvertex]<<" added "<<endl;
                    continue;
                }
                if(pos)
                {
                    if(d[dvertex]>2*timediff)
                    {
                        d[dvertex]=2*timediff;
                        Q.push(mpair(dvertex,d[dvertex]));
                        cout<<"vertex "<<dvertex<<"having time  "<<d[dvertex]<<" added "<<endl;
                    }
                }
                else
                {
                    if(d[dvertex]>3*timediff)
                    {
                        d[dvertex]=3*timediff;
                        Q.push(mpair(dvertex,d[dvertex]));
                         cout<<"vertex "<<dvertex<<"having time  "<<d[dvertex]<<" added "<<endl;
                    }
                }
            }
            else
            {
                int div=curTime/timediff;
                int mod=curTime%timediff;
                if(!mod)
                {
                    if(!pos) // pos is the source vertex
                    {
                        if(div%2==0)
                        {
                            if(d[dvertex]>curTime+timediff)
                            {
                                d[dvertex]=curTime+timediff;
                                Q.push(mpair(dvertex,d[dvertex]));
                                 cout<<"vertex "<<dvertex<<"having time  "<<d[dvertex]<<" added "<<endl;
                            }
                        }
                        else
                        {
                            if(d[dvertex]>curTime+2*timediff)
                            {
                                d[dvertex]=curTime+2*timediff;
                                Q.push(mpair(dvertex,d[dvertex]));
                                 cout<<"vertex "<<dvertex<<"having time  "<<d[dvertex]<<" added "<<endl;
                            }
                        }
                    }
                    else
                    {
                        if(div%2==0)
                        {
                            if(d[dvertex]>curTime+2*timediff)
                            {
                                d[dvertex]=curTime+2*timediff;
                                Q.push(mpair(dvertex,d[dvertex]));
                                 cout<<"vertex "<<dvertex<<"having time  "<<d[dvertex]<<" added "<<endl;
                            }
                        }
                        else
                        {
                            if(d[dvertex]>curTime+timediff)
                            {            
                                d[dvertex]=curTime+timediff;
                                Q.push(mpair(dvertex,d[dvertex]));
                                 cout<<"vertex "<<dvertex<<"having time  "<<d[dvertex]<<" added "<<endl;
                            }
                        }
                    }
                }
                else
                {
                    if(pos) // destination is the source vertex
                    {
                        if(div%2==0)
                        {
                            if(d[dvertex]>(timediff*(div+2)))
                            {
                                d[dvertex]=timediff*(div+2);
                                Q.push(mpair(dvertex,d[dvertex]));
                                 cout<<"vertex "<<dvertex<<"having time  "<<d[dvertex]<<" added "<<endl;
                            }
                        }
                        else
                        {
                            if(d[dvertex]>(timediff*(div+3)))
                            {
                                d[dvertex]=timediff*(div+3);
                                Q.push(mpair(dvertex,d[dvertex]));
                                 cout<<"vertex "<<dvertex<<"having time  "<<d[dvertex]<<" added "<<endl;
                            }
                        }
                    }
                    else // source is the orgin vertexc
                    {
                        if(div%2==0)
                        {
                            if(d[dvertex]>(timediff*(div+3)))
                            {
                                d[dvertex]=timediff*(div+3);
                                Q.push(mpair(dvertex,d[dvertex]));
                                 cout<<"vertex "<<dvertex<<"having time  "<<d[dvertex]<<" added "<<endl;
                            }
                        }
                        else
                        {
                            if(d[dvertex]>(timediff*(div+2)))
                            {
                                d[dvertex]=timediff*(div+2);
                                Q.push(mpair(dvertex,d[dvertex]));
                                 cout<<"vertex "<<dvertex<<"having time  "<<d[dvertex]<<" added "<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<d[k]<<endl;   
    return 0;
}

