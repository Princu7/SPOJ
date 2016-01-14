# include <stdio.h>
# include <stdlib.h>
int a[2001][2001]={0};
int color[2001];
int queue[2001];
int visited[2001];
int top=-1,bottom=-1;
void push(int n)
{
	if(bottom==-1)
	{
		top=0,bottom=0;
		queue[top]=n;
	}
	else
	{
		bottom++;
		queue[bottom]=n;
	}
}
int pop()
{
	top++;
	return queue[top-1];
}

int main(void)
{
    int t;
    scanf("%d",&t);
    int count=t;
    int i=1; int j=0;
    while(i<=count)
    {
		top=-1,bottom=-1;
		for(j=1;j<=2001;j++)
			color[j]=0,queue[j]=0,visited[0]=0;
		for(i=1;i<=2001;i++)
			for(j=1;j<=2001;j++)
				a[i][j]=0;	
		i=1,j=0;
        int bugs,interactions;
        scanf("%d%d",&bugs,&interactions);
        int bug1,bug2;
        int flag=0;
		int source=0;
        while(interactions--)
		{
			scanf("%d%d",&bug1,&bug2);
			source=bug1;
			a[bug1][bug2]=1;
		}
		//1 is for male and 2 is for female
		color[source]=1;
		push(source);
		printf("%d this is source\n",source);
		while(top<=bottom)
		{
			int vertex=pop();
			visited[vertex]=1;
			printf(" This is the vertex being popped off %d\n",vertex);
			for(j=1;j<=2001;j++)
			{
				if(a[vertex][j]==1 && visited[j]==0)
				{
					if(color[j]==color[vertex])
					{
						flag=1;
						break;
					}
					printf("%d is the neighbour of the above vertex which was popped\n",j);
					if(visited[j]==0)
					{
						printf("%d is being pushed\n",j);
						push(j);
						visited[j]=1;
					}
					if(color[vertex]==1)
						color[j]=2;
					else
						color[j]=1;
				}
			}
			if(flag==1)
				break;
		}		
        if(flag==0)
            printf("Scenario #%d:\nNo suspicious bugs found!\n",i);
        else
             printf("Scenario #%d:\nSuspicious bugs found!\n",i);
        i++;
    } 
    return 0;
}
            
