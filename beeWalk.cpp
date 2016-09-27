# include <bits/stdc++.h>
using namespace std;
# define triplet  pair< pair<int,int>,int > 
# define mpair(a,b,c) make_pair( make_pair(a,b),c)

map < triplet, int  > look;
map < triplet, int>::iterator it;

int recurse(triplet &a)
{
    if(a.second==0 && (a.first.first==0 && a.first.second==0))
        return 1;
    else if(a.second==0)
        return 0;
    //cout<<endl;
    int p1,p2,p3,p4,p5,p6;
    int x=a.first.first;
    int y=a.first.second;
    int n=a.second;
    //cout<<"x and y are "<<x<<" "<<y<<" and no of steps remaining "<<n<<" "<<endl;
    //for cell just below
    triplet temp=mpair(x,y+1,n-1);
    it=look.find(temp);
    if(it==look.end())
    {
        p1=recurse(temp);
        look.insert(make_pair(temp,p1));
    }
    else
        p1=it->second;
    //for cell just above
    temp=mpair(x,y-1,n-1);
    it=look.find(temp);
    if(it==look.end())
    {
        p2=recurse(temp);
        look.insert(make_pair(temp,p2));
    }
    else
        p2=it->second;
    // for cell upright
    temp=mpair(x+1,y-1,n-1);
    it=look.find(temp);
    if(it==look.end())
    {
        p3=recurse(temp);
        look.insert(make_pair(temp,p3));
    }
    else
        p3=it->second;
    //for cell left down
    temp=mpair(x-1,y+1,n-1);
    it=look.find(temp);
    if(it==look.end())
    {
        p4=recurse(temp);
        look.insert(make_pair(temp,p4));
    }
    else
        p4=it->second;
    //for cell right down
    temp=mpair(x+1,y,n-1);
    it=look.find(temp);
    if(it==look.end())
    {
        p5=recurse(temp);
        look.insert(make_pair(temp,p5));
    }
    else
        p5=it->second;
    //for cell left up
    temp=mpair(x-1,y,n-1);
    it=look.find(temp);
    if(it==look.end())
    {
        p6=recurse(temp);
        look.insert(make_pair(temp,p6));
    }
    else
        p6=it->second;
    return (p1+p2+p3+p4+p5+p6);
}

int main(void)
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
	    triplet initial=mpair(0,0,n);
        int answer=recurse(initial);
		look.clear();
        cout<<answer<<endl;
    }
}
        
