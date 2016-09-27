# include <iostream>
# include <cstdio>
# include <math.h>
# include <algorithm>
using namespace std;
int counter=0,blockSize=0,answer=0,a[30009];
struct queries
{
    int left,right,index;
}Q[200003];
int freq[1000009]={0};
bool funcSort(const queries& a,const queries& b)
{
    if(a.left/blockSize<b.left/blockSize)
        return true;
    else if(a.left/blockSize>b.left/blockSize)
        return false;
    return a.right<b.right;
}
void display()
{
    for(int i=0;i<counter;i++)
        printf("%d %d\n",Q[i].left,Q[i].right);
}

inline void addElem(int position)
{
    freq[a[position]]++;
    if(freq[a[position]]==1)
        answer++;
}

inline void removeElem(int position)
{
    freq[a[position]]--;
    if(freq[a[position]]==0)
        answer--;
}
int n,q;
/*void displayfreq()
{
    bool seen[10]={0};
    for(int i=0;i<n;i++)
    {
        if(!seen[a[i]])
        {
            printf("elem=%d freq=%d\n",a[i],freq[a[i]]);
            seen[a[i]]=1;
        }
    }
}*/
int main(void)
{
    scanf("%d",&n);
    blockSize=sqrt(n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    scanf("%d",&q);
    int left,right;
    while(q--)
    {
        scanf("%d%d",&left,&right);
        Q[counter].left=left-1;
        Q[counter].right=right-1;
        Q[counter].index=counter;
        counter++;
    }
    //cout<<endl;
    sort(Q,Q+counter,funcSort);
    //display();
    int currentR=0,currentL=0,l,r;
    int ans[200004];
    for(int i=0;i<counter;i++)
    {
        l=Q[i].left,r=Q[i].right;
        while(currentL<l)
        {
            removeElem(currentL);
            currentL++;
        }
        while(currentL>l)
        {
            addElem(currentL-1);
            currentL--;
        }
        while(currentR<=r)
        {
            addElem(currentR);
            currentR++;
        }
        while(currentR>r+1)
        {
            removeElem(currentR-1);
            currentR--;
        }
        ans[Q[i].index]=answer;
        //displayfreq();
    } 
    for(int i=0;i<counter;i++)
        printf("%d\n",ans[i]);
    return 0;
}

