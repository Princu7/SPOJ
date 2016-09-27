# include <iostream>
# include <limits.h>
# include <cstdio>
# define LARGE 10000000
using namespace std;
int risk[200][200],tm[200][200];
int lookup[300][300];
int timelook[300][300],n;
int recurse(int curNode,int curTime,int parent)
{
    /*cout<<endl;
    getchar();
    printf("curNode=%d and CurTime=%d \n",curNode,curTime); */
    if(curTime<0 || curTime==0 && curNode!=n)
        return 10000000;
    if(curNode==n)
    {
        timelook[curNode][curTime]=0;
        return 0;
    }
    int min=INT_MAX,curPath=0,timeTemp;
    for(int i=1;i<=n;i++)
    {
        if(curNode==i || (i==parent && tm[curNode][i]==0))
            continue;
        curPath=0;
        if(!lookup[i][curTime-tm[curNode][i]])
        {
            curPath=recurse(i,curTime-tm[curNode][i],curNode);
            if(curPath<10000000)
                timeTemp=tm[curNode][i]+timelook[i][curTime-tm[curNode][i]];
            else
                timeTemp=LARGE;
            lookup[i][curTime-tm[curNode][i]]=curPath;
            curPath+=risk[curNode][i];
        }
        else
        {
            //cout<<" memoization "<<endl;
           //printf("node=%d and time=%d\n",i,curTime-tm[curNode][i]);
            curPath=risk[curNode][i]+lookup[i][curTime-tm[curNode][i]];
            timeTemp=tm[curNode][i]+timelook[i][curTime-tm[curNode][i]];
        }
        if(min>curPath)
        {
            min=curPath;
            timelook[curNode][curTime]=timeTemp;
        }
    }
    //printf("node=%d and time=%d min= %d\n",curNode,curTime,min);
    //cout<<" time "<<timelook[curNode][curTime]<<endl;
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
        if(timelook[1][tmDest]>=275 || answer>=10000000)
            printf("-1\n");
        else
            printf("%d %d\n",answer,timelook[1][tmDest]);
        for(int i=0;i<200;i++)
            for(int j=0;j<200;j++)
                risk[i][j]=0,tm[i][j]=0;
        for(int i=0;i<300;i++)
            for(int j=0;j<300;j++)
                lookup[i][j]=0,timelook[i][j]=0;
    }
}
