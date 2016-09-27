# include <bits/stdc++.h>
using namespace std;
int *a=NULL,n,c;

int isPossible(int dist)
{
    int count=c-1;
    int prev=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]-prev>=dist)
        {
            prev=a[i];
            count--;
        }
        if(count==0)
            return 1;
    }
    return 0;
}
        
    
int binarySearch(int l,int r)
{
    int ans,flag,mid; int rescue=0;
    while(1)
    {
        if(l>r)
            break;
        mid=(l+r)/2;
        flag=isPossible(mid);
        if(flag==1)
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
        rescue++;
    }
    return ans;
}
            
        
int main(void)
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&n,&c);
        a=(int *)calloc(n,sizeof(int));
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        int totalLength=a[n-1]-a[0];
        int minLength=0;
        int ans=binarySearch(minLength,totalLength);
        cout<<ans<<endl;
    }
    return 0;
}
        
