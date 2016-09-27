# include <bits/stdc++.h>
using namespace std;
struct index
{
    int nOne, nZero, diff;
};

int cOne,cZero;
int main(void)
{
    int test;
    scanf("%d",&test);
    int n;
    while(test--)
    {
        cOne=cZero=0;
        scanf("%d",&n);
        string s;
        cin>>s;
        struct index *pos=(struct index*)calloc(n,sizeof(struct index));
        for(int i=0;i<n;i++)
        {
            if(s[i]-48==0)
                cZero++;
            else
                cOne++;
            pos[i].nOne=cOne;
            pos[i].nZero=cZero;
            pos[i].diff=pos[i].nOne-pos[i].nZero;
            //cout<<"diff in ones and zeros "<<pos[i].diff<<endl;
        }
        int end=-1;
        for(int i=0;i<n;i++)
        {
            if(pos[i].diff>0)
                end=i;
        }
        int ans=0,start=0;
        if(end==-1)
            start=1;
        else
        {
            ans=end+1;
            start=end+1;
        }
        for(int i=start;i<s.length();i++)
        {
            int temp=-1;
            for(int j=i;j<s.length();j++)
            {
                if(pos[j].diff-pos[i-1].diff>0)
                    temp=j;
            }
            printf("this is the current value of temp %d and this  is the correct value of i %d\n",temp,i);
            if(temp!=-1)
            {
                ans+=temp-i+1;
                i=temp;
            }
        }
        cout<<ans<<endl;
        free(pos);
    }
}
            
            
        
