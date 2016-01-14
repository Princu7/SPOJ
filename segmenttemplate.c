# include <stdio.h>
# include <stdlib.h>
 
int max(int a,int b){
return (a>=b)?a:b;
}
 
void build_tree(int *tree,int *arr,int node, int a, int b)
{
    if(a > b) 
        return;
    if(a == b) 
    { 
        tree[node] = arr[a]; 
        return;
    }
    build_tree(tree,arr,node*2, a, (a+b)/2); 
    build_tree(tree,arr,node*2+1, 1+(a+b)/2, b); 
    tree[node] = max(tree[node*2], tree[node*2+1]); 
}
 
int query_tree(int *tree,int node, int a, int b, int i, int j)
{
    if(a >= i && b <= j) 
        return tree[node];
    else
    {
        int mid=(a+b)/2;
        int res=0;
        if((mid>=i) && (a<=j))
            res=max(res,query_tree(tree,2*node,a,mid,i,j));
        if((b>=i) && (mid+1<=j))
            res=max(res,query_tree(tree,2*node+1,mid+1,b,i,j));
        return res;
    }
}
