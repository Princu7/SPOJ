# include <bits/stdc++.h>
using namespace std;
queue< pair<int,int> > q;
map< pair<int,int>, int> m;
map< pair<int,int>, int>::iterator it;
int level=0;
int initialX,initialY,finalY,finalX;

void clearQueue( std::queue< pair<int,int> > &q )
{
   std::queue< pair<int,int> > empty;
   std::swap( q, empty );
}

void insert(pair<int,int> p)
{
    if((p.first>=1 && p.first<=8) && (p.second>=1 && p.second<=8))
    {
        if(m.find(p)==m.end())
        {
            q.push(p);
            m.insert(make_pair(p,level+1));
        }
        
    }
}

int bfs(int a,int b)
{
    m.insert(make_pair( make_pair(a,b),0));
    q.push( make_pair(a,b));
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        level=m.find(p)->second;
        if(p==make_pair(finalX,finalY))
        {
            it=m.find(p);
            return it->second;
        }
        a=p.first,b=p.second;   
        insert(make_pair(a+1,b+2));
        insert(make_pair(a+1,b-2));
        insert(make_pair(a-1,b+2));
        insert(make_pair(a-1,b-2));
        insert(make_pair(a-2,b+1));
        insert(make_pair(a+2,b+1));
        insert(make_pair(a-2,b-1));
        insert(make_pair(a+2,b-1));
    }
}

int main(void)
{
    int t; string input;
    cin>>t;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    while(t--)
    {
        getline(cin,input);
        initialX=input[0]-97+1;
        initialY=input[1]-49+1;
        finalX=input[3]-97+1;
        finalY=input[4]-49+1;
        int ans=bfs(initialX,initialY);
        cout<<ans<<endl;
        m.clear();
        clearQueue(q);
    }
}
