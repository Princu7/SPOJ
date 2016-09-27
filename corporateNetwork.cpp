# include <bits/stdc++.h>
# define MOD 1000
using namespace std;
struct subset
{
    int parent;
    int dist;
}S[20009];

int findSet( int x ) {
    if ( x != S[ x ].parent ) {
        int i = S[ x ].parent;
        S[ x ].parent = findSet( S[ x ].parent );
        S[ x ].dist += S[ i ].dist;
    }
    return S[ x ].parent;
}

void Union(int x,int y)
{
    //int xroot=find(x);
    //int yroot=find(y);
    S[x].parent=y;
    S[x].dist=(abs(x-y))%MOD;
    //if(x!=xroot)
      //  S[xroot].parent=yroot;
}

int main(void)
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int flag=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            S[i].parent=i;
            S[i].dist=0;
        }
        char c; int num1,num2;
		while(1)
		{
            /*for(int i=1;i<=n;i++)
            {
                //cout<<"parent of "<<i<<" is "<<S[i].parent<<endl;
            }*/
		    scanf(" %c",&c);
		    if(c=='O')
            {
                flag=1;
		        break;
            }   
		    else if(c=='E')
		    {
		        scanf("%d",&num1);
		        int distance=0;
		        int temp=findSet(num1);
                cout<<S[num1].dist<<endl;
		    }
		    else if(c=='I')
		    {
		        scanf("%d%d",&num1,&num2);
		        Union(num1,num2);
		    }
		}
    }
    return 0;
}
