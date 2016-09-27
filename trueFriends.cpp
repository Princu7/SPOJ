# include <bits/stdc++.h>
using namespace std;
bool visited[103];
vector <int> V[103];
vector <int> R[103];
stack <int> S;
char a[103][103];
int n;
int counter=0;
int invokeCnt=0;
void dfsFirst(int source)
{
    visited[source]=1;
    for(int i=0;i<V[source].size();i++)
    {
        if(!visited[V[source][i]])
            dfsFirst(V[source][i]);
    }
    //cout<<" pushing "<<source<<" to stack"<<endl;
    S.push(source);
}
void reverseGraph()
{
    for(int i=1;i<=n;i++)
        for(int j=0;j<V[i].size();j++)
            R[V[i][j]].push_back(i);
}
void dfsSecond(int source)
{
    invokeCnt++;
    visited[source]=1;
    //cout<<"node "<<source<<" put in comp "<<counter<<endl;
    for(int i=0;i<R[source].size();i++)
    {
        if(!visited[R[source][i]])
            dfsSecond(R[source][i]);
    }
}
int main(void)
{
    int test;
    cin>>test;
    string input;
    while(test--)
    {
        cin>>n;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        for(int i=0;i<n;i++)
        {
            getline(cin,input);
            //cout<<input;
            for(int j=0;j<input.length();j++)
            {
                if(input[j]=='Y')
                    V[i+1].push_back(j+1);
            }
        }
       /* for(int i=1;i<=n;i++)
        {
            for(int j=0;j<V[i].size();j++)
            {
                cout<<V[i][j]<<" ";
            }
            cout<<endl;
        } */
        for(int i=1;i<=n;i++)
        {
            if(!visited[i] && V[i].size()>0)
                dfsFirst(i);
        }
        reverseGraph();
        for(int i=0;i<=102;i++)
        visited[i]=0;
        bool flag=0;
        while(!S.empty())
        {
            int elem=S.top();
            //cout<<elem<<" popped"<<endl;
            S.pop();
            if(!visited[elem])
            {
                //cout<<"dfs done from "<<elem<<endl;
                dfsSecond(elem);
                counter++;
            }
        }
        cout<<counter<<endl;
        counter=0;
        for(int i=0;i<=n;i++)
        {
            V[i].clear();
            R[i].clear();
        }
        for(int i=0;i<=102;i++)
            visited[i]=0;
    }
    return 0;
}
