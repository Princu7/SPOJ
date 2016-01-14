# include <stdio.h>
# include <stdlib.h>
# define small -566666666;
int n;
int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}
void order(int *a,int *start)
{
	 int i=0,j=0,k=0;
	  int temp_sum=0;
    int temp_end=0,start_end=0;
    int max=0;
	for(i=0;i<n;i++)
    {
        if(temp_sum>=0 && a[i]>=0)
        {
            if(temp_sum+a[i]>=max)
                start[i]=i,max=temp_sum+a[i];
            else
                start[i]=temp_end;
            temp_sum+=a[i];
            temp_end=start[i];
        }
        else if(temp_sum>=0 && a[i]<0)
        {
            start[i]=temp_end;
            temp_sum+=a[i];
        }
        else if(temp_sum<0 && a[i]>=0)
        {
            start[i]=i;
            temp_sum=a[i];
            if(temp_sum>max)
                max=temp_sum;
            temp_end=i;
        }
        else
        {
            if(temp_sum<a[i])
            {
                start[i]=i;
                temp_sum=a[i];
                temp_end=i;
            }
            else
            {
                start[i]=temp_end;
                temp_sum+=a[i];
            }
        }
    }
}

int main(void)
{
    scanf("%d",&n);
	int i=0;
    int *a=calloc(n,sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    int *start=calloc(n,sizeof(int));
    order(a,start);
    int *end=calloc(n,sizeof(int));
	int *end_dup=calloc(n,sizeof(int));
    int *end_array=calloc(n,sizeof(int));
    for(i=0;i<n;i++)
        end_array[i]=a[n-i-1],start[i]++;
	order(end_array,end_dup);
	for(i=0;i<n;i++)
		end[i]=n-end_dup[n-i-1];
	for(i=0;i<n;i++)
		printf("%d\n",start[i]);
	int m;
	scanf("%d",&m);
	int x,y;
	int *cum_sum=calloc(n+1,sizeof(int));
	for(i=1;i<=n;i++)
		cum_sum[i]=a[i-1]+cum_sum[i-1];
	int temp1,temp2,answer;
	while(m--)
	{
		scanf("%d%d",&x,&y);
		int right=start[y-1];
		int left=end[x-1];
		printf("%d this is the left and %d this is the right\n",left,right);
		if(right<left)
		{
			if(right>=x && right<=y)
				temp1=a[right-1];
			else
				right=small;
			if(left>=x && left<=y)
				temp2=a[left-1];
			else
				left=small;
			answer=max(temp1,temp2);
			printf("%d\n",answer);
		}
		else
		{
			printf("%d-cum_right,%d-cum_left\n",cum_sum[right],cum_sum[left]);
			printf("%d\n",cum_sum[right]-cum_sum[left-1]);
		}
	}
}
            
            
            
    
