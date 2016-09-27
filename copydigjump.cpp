# include <bits/stdc++.h>
using namespace std;
char s[1000005];
bool visited[1000005];
int level[1000005];
vector<int> digit[10];
queue < int > q; 

void addSame(int in)
{
    int size=digit[s[in]-48].size();
	int l=level[in];
	int num=s[in]-48;
    for(int i=0;i<size;i++)
    {
        if(!visited[digit[num][i]])
        {
			if(digit[num][i]==strlen(s)-1)
			{
				printf("%d",l+1);
				exit(0);
			}
            q.push(digit[num][i]);
            level[digit[num][i]]=l+1;
            visited[digit[num][i]]=1;
        }
    }
}

void addNeighbour(int index)
{
    int left=index-1;
    int right=index+1;
	int l=level[index];
    if(left>=0)
    {
        if(!visited[left])
        {
            visited[left]=1;
            level[left]=l+1;
            q.push(left);
        }
    }
	if(!visited[right])
	{
		visited[right]=1;
		level[right]=l+1;
		q.push(right);
		if(right==strlen(s)-1)
		{
			printf("%d",l+1);
			exit(0);
		}
	}
}
    
void bfs()
{
    q.push(0);
    visited[0]=1;
    level[0]=0;
    while(!q.empty())
    {
        int  p=q.front();
        q.pop();
        if(digit[s[p]-48].size())
        {
            addSame(p);
            digit[s[p]-48].clear();
        }
        addNeighbour(p);
    }
}
        
    
int main(void)
{
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
        digit[s[i]-48].push_back(i);
	if(strlen(s)==1)
		printf("0\n");
	else
    	bfs();
    return 0;
}
