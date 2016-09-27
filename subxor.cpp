                # include <stdio.h>
                # include <stdlib.h>
                # include <bits/stdc++.h>
                using namespace std; 
                #define gc getchar_unlocked
                #define left lchild
                #define right rchild
                int scanint()
                {   
                register int c = gc();
                int x = 0;
                for(;(c<48 || c>57);c = gc());
                for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
                return x;
                }
                 
                struct node
                {
                    struct node *lchild;
                    struct node *rchild;
                    int no;
                    node()
                    {
                        no=0;
                    }
                };
             
                int precompute[31]=			   {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
                 
                void make_rest(struct node *root,int *a,int index)
                {
                    //cout<<endl;
                    //cout<<"make rest index"<<index<<endl;
                    if(index==30)
                        return;
                    struct node *temp=(struct node*)malloc(sizeof(struct node));
                    if(a[index])
                    {
                        //cout<<"right node created "<<endl;
                        root->rchild=temp;
                    }
                    else
                    {
                        //cout<<"left node created "<<endl;
                        root->lchild=temp;
                    }
                    index++;
                    make_rest(temp,a,index);
                    if(index==30)
                        temp->no++;
                    else
                    {
                        temp->no=0;
                        if(temp->left!=NULL)
                            temp->no+=temp->left->no;
                        if(temp->right!=NULL)
                            temp->no+=temp->right->no;
                    }
                }
                int flag=0; 
                void build_tree(struct node *root,int *a,int index)
                {
                    //cout<<endl;
                    //cout<<"current value of index "<<index<<endl;
                    if(index==30)
                    {
                        root->no++;
                        return;
                    }
                    else if(root->lchild==NULL && root->rchild==NULL)
                    {
                        //cout<<"both child NULL"<<endl;
                        //cout<<endl;
                        //flag=1;
                        make_rest(root,a,index);
                        if(index==30)
                            root->no++;
                        else
                        {
                            root->no=0;
                            if(root->left!=NULL)
                                root->no+=root->left->no;
                            if(root->right!=NULL)
                                root->no+=root->right->no;
                        }
                    }
                    else if(root->lchild==NULL)
                    {
                        //cout<<"left child null"<<endl;
                        if(a[index]) //a[index]==1
                        {
                            index++;
                            build_tree(root->rchild,a,index);
                            if(index==30)
                                root->no++;
                            else
                            {
                                root->no=0;
                                if(root->left!=NULL)
                                    root->no+=root->left->no;
                                if(root->right!=NULL)
                                    root->no+=root->right->no;
                            }
                        }
                        else
                        {
                            make_rest(root,a,index);
                            if(index==30)
                                root->no++;
                            else
                            {   
                                root->no=0;
                                if(root->left!=NULL)
                                    root->no+=root->left->no;
                                if(root->right!=NULL)
                                    root->no+=root->right->no;
                            }
                        }
                    }
                    else if(root->rchild==NULL)
                    {
                        //cout<<"right chlld null"<<endl;
                        if(!a[index]) //a[index]==0
                        {
                            index++;
                            build_tree(root->lchild,a,index);
                            //if(flag)
                            if(index==30)
                                root->no++;
                            else
                            {  
                                root->no=0; 
                                if(root->left!=NULL)
                                    root->no+=root->left->no;
                                if(root->right!=NULL)
                                    root->no+=root->right->no;
                            }
                        }
                        else
                        {
                            //flag=1;
                            //cout<<"i am now here and index"<<index<<endl;
                            make_rest(root,a,index);
                            if(index==30)
                                root->no++;
                            else
                            {   
                                root->no=0;
                                if(root->left!=NULL)
                                    root->no+=root->left->no;
                                if(root->right!=NULL)
                                    root->no+=root->right->no;
                            }
                        }
                    }
                    else
                    {
                        if(!a[index]) //a[index]==0
                        {
                            index++;
                            build_tree(root->lchild,a,index);
                            //if(flag)
                            if(index==30)
                                root->no++;
                            else
                            {   
                                root->no=0;
                                if(root->left!=NULL)
                                    root->no+=root->left->no;
                                if(root->right!=NULL)
                                    root->no+=root->right->no;
                            }
                        }
                        else
                        {
                            index++;
                            build_tree(root->rchild,a,index);
                            //if(flag)
                            if(index==30)
                                root->no++;
                            else
                            {   
                                root->no=0;
                                if(root->left!=NULL)
                                    root->no+=root->left->no;
                                if(root->right!=NULL)
                                    root->no+=root->right->no;
                            }
                        }
                    }  
                }
                int  query_tree(struct node *root,int *a,int index,int k)
                {
                    //cout<<"current depth "<<index<<" k is "<<k<<endl;
                    if(index==30 && k>0)
                    {
                        //cout<<"returning from index"<<index<<" 1"<<endl;
                        return 1;
                    }
                    if(k<=0)
                    {
                        //cout<<"returning from index promptt "<<index<<endl;
                        return 0;
                    }
                    int x=0,y=0;
                    if(root->left!=NULL)
                    {
                        //cout<<"going to left of root index"<<index<<endl;
                        if(a[index]==1)
                            x=query_tree(root->left,a,index+1,k-precompute[29-index]);
                        else
                        {
                            if(precompute[29-index]<=k)
                                    x=root->left->no;
                            else
                                x=query_tree(root->left,a,index+1,k);
                        }
                         //cout<<"returned to left index"<<index<<endl;
                    }
                    if(root->right!=NULL)
                    {
                        //cout<<"going to the right of root  index "<<index<<endl;
                        if(a[index]==0)
                            y=query_tree(root->right,a,index+1,k-precompute[29-index]);
                        else
                        {
                            if(precompute[29-index]<=k)
                                    y=root->right->no;
                            else
                                y=query_tree(root->right,a,index+1,k);
                        }
                        //cout<<"returned to right index"<<index<<endl;
                    }
                    //cout<<"x+y "<<x+y<<" returning From "<<index<<endl;
                    return (x+y);
                }
                void display(struct node *root,int count)
                {
                    if(root==NULL)
                        return;
                    display(root->lchild,count*2);
                    //cout<<root->no<<" ";
                    display(root->rchild,count*2+1);
                }
                    
                int main(void)
                {
                    int t;
                    t=scanint();
                    int a[100002];
					int consecutive_xor[100002];
					while(t--)
					{
						struct node *root=(struct node *)malloc(sizeof(struct node));
                    	root->lchild=root->rchild=NULL;
		                int n;
		                n=scanint();
		                int cost;
		                cost=scanint();
		                int i=0,k=0,count=1;
		                for(i=0;i<n;i++)
		                    a[i]=scanint();
		                int temp[20]; int first[20];
		                for(i=0;i<20;i++)
		                    first[i]=0;
		                consecutive_xor[0]=0;
		                for(i=1;i<=n;i++)
		                    consecutive_xor[i]=consecutive_xor[i-1]^a[i-1];
		                build_tree(root,first,0);
		                //display(root,1);
		                //cout<<endl;
		                int total=0;
		                for(count=1;count<=n;count++)
		                {
		                    for(k=29,i=0;k>=0;k--,i++)
		                    {
		                        if(consecutive_xor[count]&precompute[i])
		                            temp[k]=1;  // this is the binary representation of the consecutive xor array.We also have to pass the binary represetation of higher
		                        else
		                            temp[k]=0;
		                    }
		                    /*cmp=max_xor(root,temp,0);
		                    if(cmp>max)
		                        max=cmp;
		                    reverse_max[count-1]=max;*/
		                    flag=0;
		                    total+=query_tree(root,temp,0,cost);
		                    //cout<<endl;
		                    //cout<<total<<endl;
		                    build_tree(root,temp,0);
		                    //display(root,1);
		                    //cout<<endl;
		                    //cout<<"one ended "<<endl;
		                }
						cout<<total<<endl;
					}
                }    
