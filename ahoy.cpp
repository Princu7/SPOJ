# include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string s; int a[30];
    vector < pair<int,int> > V[30];
    int count=1;
    while(1)
    {
        cin>>s;
        if(s=="bye")
            break;
        for(int i=0;i<s.length();i++)
            a[i]=s[i]-48;
        V[0].push_back(make_pair(a[0],1));
        for(int i=1;i<s.length();i++)
        {
            int temp=0;
            for(int j=i;j>0;j--)
            {
                temp+=a[j]; int total=0;
                for(int k=0;k<V[j-1].size();k++)
                {
                    if(temp>=V[j-1][k].first)
                        total+=V[j-1][k].second;
                }
                V[i].push_back(make_pair(temp,total));
            }
            V[i].push_back(make_pair(temp+a[0],1));
        }
        int answer=0;
        for(int i=0;i<V[s.length()-1].size();i++)
            answer=answer+V[s.length()-1][i].second;
        cout<<count<<". "<<answer<<endl;
        for(int i=0;i<30;i++)
            V[i].clear();
        count++;
    }
    return 0;
}        
