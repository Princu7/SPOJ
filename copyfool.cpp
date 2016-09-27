# include <iostream>
# include <limits.h>
# include <cstdio>
# define LARGE 10000000
using namespace std;
int risk[200][200],tm[200][200];
int lookup[300][250];
int n;  int minTime=LARGE,tempMin=0;
int recurse(int curNode,int curTime,int parent)
{
    getchar();
    printf("curNode=%d and CurTime=%d \n",curNode,curTime);
    if(curTime<0 || curTime==0 && curNode!=n)
    {
        //cout<<"returning "<<LARGE<<endl;
        return LARGE;
    }
    if(curNode==n)
    {
        tempMin=curTime;
        cout<<"this is  tempmin "<<tempMin<<endl;
        return 0;
    }
    int min=LARGE,curPath=0;
    for(int i=1;i<=n;i++)
    {
        if(curNode==i /*|| i==parent*/)
            continue;
        curPath=0;
        if(!lookup[i][curTime-tm[curNode][i]])
        {
            curPath=recurse(i,curTime-tm[curNode][i],curNode);
            //lookup[i][curTime-tm[curNode][i]]=curPath;
            lookup[i][curTime-tm[curNode][i]]=curPath;
            curPath+=risk[curNode][i];
        }
        else
        {
            cout<<" memoization "<<endl;
           printf("node=%d and time=%d\n",i,curTime-tm[curNode][i]);
            curPath=risk[curNode][i]+lookup[i][curTime-tm[curNode][i]];
        }
        if(min>curPath)
        {
            min=curPath;
            if(curNode==1)
            {
                cout<<"i am being assgined tempmin "<<tempMin<<endl;
                minTime=tempMin;
            }
        }
    }
    printf("node=%d and time=%d min= %d\n",curNode,curTime,min);
    cout<<endl;
    return min;
}
int main(void)
{
    int test,tmDest;
    cin>>test;
    while(test--)
    {
        scanf("%d",&n);
        scanf("%d",&tmDest);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&tm[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&risk[i][j]);
        int answer=recurse(1,tmDest,0);
        if(minTime>=300)
            printf("-1\n");
        else
            printf("%d %d\n",answer,tmDest-minTime);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                risk[i][j]=0,tm[i][j]=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=tmDest;j++)
                lookup[i][tmDest]=0;
        minTime=LARGE;
        tempMin=0;
    }
}
