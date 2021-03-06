# include <stdio.h>
# include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int test_array[4];

int max(int a,int b){
return (a>=b)?a:b;
}

struct node
{
	int first;
	int second;
};

struct node merge(struct node a,struct node b)
{
	struct node c;
	test_array[0]=a.first;
	test_array[1]=b.first;
	test_array[2]=a.second;
	test_array[3]=b.second;
	qsort(test_array,4,sizeof(int),cmpfunc);
    c.first=test_array[3];
	c.second=test_array[2];
	return c;
}
	
 
void build_tree(struct node *tree,int *arr,int node, int a, int b)
{
    if(a > b) 
        return;
    if(a == b) 
    { 
        tree[node].first=arr[a];
		tree[node].second=0;
        return;
    }
    build_tree(tree,arr,node*2, a, (a+b)/2); 
    build_tree(tree,arr,node*2+1, 1+(a+b)/2, b); 
    tree[node]=merge(tree[node*2],tree[node*2+1]);
}
 
struct node Query(struct node *tree,int node, int start, int end, int x, int y)
{
    if(start == x && end == y) return tree[node];
    int l = node<<1 ;
    int r = node<<1|1;

    int mid = (start + end )>>1;

    if(y <= mid ) return Query(tree,l,start,mid,x,y); // whole side is in left

    else if( x > mid ) return Query(tree,r,mid+1,end,x,y) ; // whole side is in right

    else
    {
        return merge( Query(tree,l,start,mid,x,mid) , Query(tree,r,mid+1,end,mid+1,y)  ) ; // split in two side so merging
    }
}


void update_tree(struct node *tree,int node, int a, int b, int i, int value) {
    
	if(a > b || a >i || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a == b) { // Leaf node
    		tree[node].first=value;
			tree[node].second=0;
    		return;
	}

	update_tree(tree,node*2, a, (a+b)/2, i, value); // Updating left child
	update_tree(tree,1+node*2, 1+(a+b)/2, b, i, value); // Updating right child

	tree[node] = merge(tree[node*2], tree[node*2+1]); // Updating root with max value
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int i=0,j=0,k=0;
	struct node *tree=calloc(4*n,sizeof(struct node));
	int *a=calloc(n,sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	build_tree(tree,a,1,0,n-1);
	/*for(i=1;i<=15;i++)
		printf("this is the  information for the %d node..FIrst maximum = %d and second maximum=%d\n",i,tree[i].first,tree[i].second); */
	int m;
	scanf("%d",&m);
	m=m*2;
	while(m--)
	{
		int x,y;
		char c;
		scanf("%c%d%d",&c,&x,&y);
		if(c=='Q')
		{
			//printf(" I am in query section\n");
			struct node answer_node=Query(tree,1,0,n-1,x-1,y-1);
			printf("%d\n",answer_node.first+answer_node.second);
		}
		else if(c=='U')
		{
			//printf("I am in update section\n");
			update_tree(tree,1,0,n-1,x-1,y);
			//printf("THis is what the tree looks like now\n");
			//for(i=1;i<=15;i++)
				//printf("this is the  information for the %d node..FIrst maximum = %d and second maximum=%d\n",i,tree[i].first,tree[i].second);
		}
		//printf("%d this is m\n",m);
	}
	return 0;
}
	
	
	
    
