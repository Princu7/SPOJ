# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <bits/stdc++.h>
using namespace std;
map <pair < pair<int,int> ,pair<int,int> > ,bool> edges;
map <pair < pair<int,int> ,pair<int,int> > ,bool>::iterator it;
int main(void)
{
    int robHeight=0,robWidth=0;
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
                    edges.insert(make_pair(make_pair(a,b),1));
            b=make_pair(i+1,j);
            if(b.first<=h)
                    edges.insert(make_pair(make_pair(a,b),1));
            b=make_pair(i,j-1);
            if(b.second>=1)
                edges.insert(make_pair(make_pair(a,b),1));
            b=make_pair(i,j+1);
            if(b.second<=w)
                    edges.insert(make_pair(make_pair(a,b),1));
        }
    }
    //char c[w+1][h+1];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            char c;
            scanf(" %c",&c);
            if(c=='x')
            {
                int height=i+1,width=j+1;
                a=make_pair(height,width);
                b=make_pair(height-1,width);
                if(b.first>=1)
                {
                    if(edges.find(make_pair(a,b))!=edges.end())
                        edges.erase(make_pair(a,b));
                    if(edges.find(make_pair(b,a))!=edges.end())
                        edges.erase(make_pair(b,a));
                }
                b=make_pair(height+1,width);
                if(b.first<=h)
                {
                    if(edges.find(make_pair(a,b))!=edges.end())
                        edges.erase(make_pair(a,b));
                    if(edges.find(make_pair(b,a))!=edges.end())
                        edges.erase(make_pair(b,a));
                }
                b=make_pair(height,width-1);
                if(b.second>=1)
                {
                    if(edges.find(make_pair(a,b))!=edges.end())
                        edges.erase(make_pair(a,b));
                    if(edges.find(make_pair(b,a))!=edges.end())
                        edges.erase(make_pair(b,a));
                }
                b=make_pair(height,width+1);
                if(b.second<=w)
                {
                    if(edges.find(make_pair(a,b))!=edges.end())
                        edges.erase(make_pair(a,b));
                    if(edges.find(make_pair(b,a))!=edges.end())
                        edges.erase(make_pair(b,a));
                }
            }
            else if(c=='o')
            {
                robHeight=i+1;
                robWidth=j+1;
            }
        }
    }
    vector < pair<int,int> > V[30];
    it=edges.begin();
    for(it=edges.begin();it!=edges.end();it++)
    {
        //cout<<it->first.first.first<<"  "<<it->first.first.second<<"    "<<it->first.second.first<<" "<<it->first.second.second<<endl;
        a=make_pair(it->first.first.first,it->first.first.second);
        b=make_pair(it->first.second.first,it->first.second.second);
        V[a].append(b);
        V[b].append(a);
    }
}

