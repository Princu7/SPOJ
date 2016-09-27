# include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        scanf("%d",&n);
        vector <int> team[n+1];
        bool **look=(bool **)calloc(n+1,sizeof(bool*));
        for(int i=0;i<=n;i++)
            look[i]=(bool *)calloc(n+1,sizeof(bool));
        int m; int better;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&better);
                look[i][better]=1;
                team[i].push_back(better);
            }
        }
        int ansCount=0;
        for(int i=1;i<=n;i++)
        {
            cout<<endl;
            cout<<"player "<<i<<" currently "<<endl;
            if(team[i].size()==0)
            {
                cout<<"player "<<i<<" set "<<endl;
                ansCount++;
                continue;
            }
            bool *finished=(bool *)calloc(n+1,sizeof(bool));
            vector <int> unfinished;
            for(int j=0;j<team[i].size();j++)
            {
                int newTeam=team[i][j];
                int flag=0;
                for(int k=0;k<team[newTeam].size();k++)
                {
                    int neighbour=team[newTeam][k];
                    if(!look[i][neighbour])
                    {
                        flag=1;
                        finished[newTeam]=1;
                        break;
                    }
                }
                if(!flag)
                {
                    unfinished.push_back(newTeam);
                    cout<<newTeam<<" pushed in the unfinished list "<<endl;
                }
            }
            if(unfinished.size()==0)
            {
                ansCount++;
                cout<<"player "<<i<<" set"<<endl;
                continue;
            }
            else
            {
                int bigflag=1;
                for(int j=0;j<unfinished.size();j++)
                {
                    int reTry=unfinished[j];
                    int smallflag=0;
                    for(int k=0;k<team[reTry].size();k++)
                    {
                        if(finished[team[reTry][k]])
                        {
                            smallflag=1;
                            break;
                        }
                    }
                    if(smallflag==1)
                    {
                        cout<<"player "<<reTry<<"put off the unfinished list "<<endl;
                        continue;
                    }
                    else
                    {
                        bigflag=0;
                        cout<<"player "<<i<<" can't be set in "<<endl;
                        break;
                    }
                }
                if(bigflag)
                {
                    cout<<"player "<<i<<" set in "<<endl;
                    ansCount++;
                }
            }
        }
        cout<<ansCount++<<endl;
    }
    return 0;
}
