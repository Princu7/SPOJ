# include <bits/stdc++.h>
using namespace std;
struct info
{
    int width;
    int height;
};
int counter=0;
string s;
long long area=0;
struct info recurse(int level)
{
    if(s[counter]==')')
    {
        counter++;
        struct info temp;
        temp.width=temp.height=1;
        if(level%2==0)
            area-=1;
        else
            area+=1;
        return temp;
    }
    int width=0; int count=0; int height=-1;
    while(s[counter]!=')')
    {
        counter++;
        struct info a=recurse(level+1);
        if(a.height>height)
            height=a.height;
        count++;
        width+=a.width;
    }
    if(count==1)
    {
        struct info a;
        a.width=width+2;
        a.height=height+1;
        if(level%2==0)
            area-=((long long)a.width)*a.height;
        else
            area+=((long long)a.width)*a.height;
        counter++;
        return a;
    }
    else
    {
        struct info a;
        a.width=width+(count-1)+2;
        a.height=height+1;
        if(level%2==0)
            area-=((long long)a.width)*a.height;
        else
            area+=((long long)a.width)*a.height;
        counter++;
        return a;
    }
}
           
int main(void)
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>s;
        counter=1;
        while(counter<s.length())
        {
            struct info  a=recurse(1);
            counter++;
        }
        printf("%lld\n",area);
        area=0;
    }
}
