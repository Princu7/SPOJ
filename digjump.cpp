# include <bits/stdc++.h>
# include <vector>
using namespace std;
char s[1000005];
bool visited[1000005];
int level[1000005];
vector<int> digit[10];
queue < pair<int,int> > q; //one integer for storing the index and the other one for storing the level of the node reached
int addSame(int num,int l)
{
    int size=digit[num].size();
    for(int i=0;i<size;i++)
    {
        if(!visited[digit[num][i]])
        {
			if(digit[num][i]==strlen(s)-1)
				return l+1;
            q.push(make_pair(num,digit[num][i]));
            level[digit[num][i]]=l+1;
            visited[digit[num][i]]=1;
			//cout<<"this is the index reached and it is the level of that index"<<digit[num][i]<<" "<<l+1<<endl;
        }
    }
	return -1;
}

int addNeighbour(int index,int l)
{
    int left=index-1;
    int right=index+1;
    if(left>=0)
    {
        if(!visited[left])
        {
            visited[left]=1;
            level[left]=l+1;
            q.push(make_pair(s[left]-48,left));
			//cout<<"this is the index reached and it is the level of that index"<<left<<" "<<l+1<<endl;
        }
    }
	//if(right<strlen(s))
	//{
		if(!visited[right])
		{
			visited[right]=1;
			level[right]=l+1;
			q.push(make_pair(s[right]-48,right));
			//cout<<"this is the index reached and it is the level of that index"<<right<<" "<<l+1<<endl;
			if(right==strlen(s)-1)
				return l+1;
		}
	//}
	return -1;
}
    
int bfs(int num,int i)
{
    q.push(make_pair(num,i));
    visited[i]=1;
    level[i]=0;
	//cout<<"this is the initial size of the queue"<<q.size()<<endl;
    while(!q.empty())
    {
        pair<int,int>  p=q.front();
		//cout<<"this is is the node"<<p.first<<endl;
        q.pop();
		//cout<<"this is the number "<<p.first<<endl;
		//cout<<"this is the level of that number "<<level[p.first]<<endl;
        if(digit[p.first].size())
        {
            int flag=addSame(p.first,level[p.second]);
			if(flag!=-1)
				return flag;
            digit[p.first].clear();
        }
        int flag=addNeighbour(p.second,level[p.second]);
		if(flag!=-1)
			return flag;
        //cout<<"this is the normal size of the queue "<<q.size()<<endl;
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
    	printf("%d\n",bfs(s[0]-48,0));
    return 0;
}
