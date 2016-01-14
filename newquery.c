        # include <stdio.h>
        # include <stdlib.h>
        int max(int a,int b){
        return (a>=b)?a:b;
        }
		int n;
		struct t
		{
			int prefix_sum;
			int suffix_sum;
			int total_sum;
			int max_sum;
		} ;
		
        void build_tree(struct t *tree,int *arr,int node, int a, int b)
        {
		    if(a > b)
		    	return;
		    if(a == b)
		    {
		    	tree[node].prefix_sum = tree[node].suffix_sum=tree[node].total_sum=tree[node].max_sum=arr[a];
		    	return;
		    }
		    build_tree(tree,arr,node*2, a, (a+b)/2);
		    build_tree(tree,arr,node*2+1, 1+(a+b)/2, b);
		    tree[node].total_sum =tree[node*2].total_sum+tree[node*2+1].total_sum;
			tree[node].prefix_sum=max(tree[node*2].prefix_sum,tree[node*2].total_sum+tree[node*2+1].prefix_sum);
			tree[node].suffix_sum=max(tree[node*2+1].suffix_sum,tree[node*2+1].total_sum+tree[node*2].suffix_sum);
			tree[node].max_sum=max(tree[node*2].max_sum,max(tree[node*2+1].max_sum,tree[node*2].suffix_sum+tree[node*2+1].prefix_sum));
        }
         
        struct t query_tree(struct t *tree,int node, int a, int b, int i, int j)
        {
			if(a>b ||  a>j || b<i)
			{
				struct t node;
				node.prefix_sum=-999999999;;
				node.suffix_sum=-999999999;;
				node.suffix_sum=-999999999;;
				node.suffix_sum=-999999999;;
				return node;
			}

		    else if(a >= i && b <= j)
		    	return tree[node];
			
				int mid=(a+b)/2;
                struct t node1=query_tree(tree,2*node,a,mid,i,j);
				struct t node2=query_tree(tree,2*node+1,mid+1,b,i,j);
				struct t main_node;
				main_node.prefix_sum=max(node1.prefix_sum,node1.total_sum+node2.prefix_sum);
				main_node.suffix_sum=max(node2.suffix_sum,node2.suffix_sum+node1.total_sum);
				main_node.total_sum=node1.total_sum+node2.total_sum;
				main_node.max_sum=max(node1.max_sum,max(node2.max_sum,node1.suffix_sum+node2.prefix_sum));
				return main_node;
		}
         
        int main(void)
        {
			scanf("%d",&n);
		    int *arr=calloc(n,sizeof(int));
			struct t tree[4*n];
			int i=0,j=0,k=0;
			for(i=0;i<n;i++)
				scanf("%d",arr+i);
			build_tree(tree,arr,1,0,n-1);
			/*for(i=6;i<=7;i++)
				printf("for node %d,the properties are total_sum=%d,max_sum=%d,prefix_sum=%d,suffix_sum=%d\n\n",i,tree[i].total_sum,tree[i].max_sum,tree[i].prefix_sum,tree[i].suffix_sum); */
			int m;
			scanf("%d",&m);
			int x,y;
			while(m--)
			{
				scanf("%d%d",&x,&y);
				struct t answer_node=query_tree(tree,1,0,n-1,x-1,y-1);
				printf("%d\n",answer_node.max_sum);
        	}
			return 0;
		} 
