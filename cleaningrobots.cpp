# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <bits/stdc++.h>
using namespace std;
map <pair < pair<int,int> ,pair<int,int> > ,bool> edges;
map <pair < pair<int,int> ,pair<int,int> > ,bool>::iterator it;
int main(void)
{
    pair<int,int> a,b;
    int w,h;
    cin>>w>>h;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            a=make_pair(i,j);
            b=make_pair(i-1,j);
            if(b.first>=1)
            {
                if(edges.find(make_pair(a,b))==edges.end())
                    edges.insert(make_pair(make_pair(a,b),1));
            }
            b=make_pair(i+1,j);
            if(b.first<=h)
            {
                if(edges.find(make_pair(a,b))==edges.end())
                    edges.insert(make_pair(make_pair(a,b),1));
            }
            b=make_pair(i,j-1);
            if(b.second>=1)
            {
                if(edges.find(make_pair(a,b))==edges.end())
                    edges.insert(make_pair(make_pair(a,b),1));
            }
            b=make_pair(i,j+1);
            if(b.second<=w)
            {
                if(edges.find(make_pair(a,b))==edges.end())
                    edges.insert(make_pair(make_pair(a,b),1));
            }
        }
    }
    it=edges.begin();
    for(it=edges.begin();it!=edges.end();it++)
        cout<<it->first.first.first<<"  "<<it->first.first.second<<"    "<<it->first.second.first<<" "<<it->first.second.second<<endl;
}

