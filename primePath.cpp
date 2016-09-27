# include <bits/stdc++.h>
# include <string>
using namespace std;
queue <int> q;
bool visited[10001];
int prime[10001];
int level=0;
int primeLevel[10001];
int a,b;
int to_number(string a)
{
    return ((a[0]-48)*1000+(a[1]-48)*100+(a[2]-48)*10+(a[3]-48));
}
void clearQueue( std::queue< int > &q )
{
   std::queue< int > empty;
   std::swap( q, empty );
}

int addPrime(int number)
{
    string num=to_string(number);
    int temp=0;
    for(int i=1;i<=9;i++)
    {
        num[0]=i+48;
        temp=to_number(num);
        if(prime[temp]!=-1)
        {
            if(temp==b)
                return level+1;
            if(!visited[temp])
            {
                primeLevel[temp]=level+1;
                //cout<<temp<<endl;
                q.push(temp);
                visited[temp]=1;
            }
        }
    }
    num=to_string(number);
    for(int i=0;i<=9;i++)
    {
        num[1]=i+48;
        temp=to_number(num);
        if(prime[temp]!=-1)
        {
            if(temp==b)
                return level+1;
            if(!visited[temp])
            {
                primeLevel[temp]=level+1;
                //cout<<temp<<endl;
                q.push(temp);
                visited[temp]=1;
            }
        }
    }
    num=to_string(number);
    for(int i=0;i<=9;i++)
    {
        num[2]=i+48;
        temp=to_number(num);
        if(prime[temp]!=-1)
        {
            if(temp==b)
                return level+1;
            if(!visited[temp])
            {
                primeLevel[temp]=level+1;
                //cout<<temp<<endl;
                q.push(temp);
                visited[temp]=1;
            }
        }
    }
    num=to_string(number);
    for(int i=0;i<=9;i++)
    {
        num[3]=i+48;
        temp=to_number(num);
        if(prime[temp]!=-1)
        {
            if(temp==b)
                return level+1;
            if(!visited[temp])
            {
                primeLevel[temp]=level+1;
                //cout<<temp<<endl;
                q.push(temp);
                visited[temp]=1;
            }
        }
    }
    return -1;
}            
int main(void)
{
    prime[1]=-1;
    for(int i=2;i<=10001;i++)
    {
        if(prime[i]==-1)
            continue;
        int count=2;
        while(count*i<=10001)
        {
            prime[count*i]=-1;
            count++;
        }
    }
    int test;
    scanf("%d",&test);
    primeLevel[a]=0;
    int count=0;
    while(test--)
    {
        scanf("%d%d",&a,&b);
        if(a==b)
        {
            printf("0\n");
            continue;
        }
        q.push(a);
        int answer;
        while(!q.empty())
        {
            answer=-1;
            int number=q.front();
            q.pop();
            level=primeLevel[number];
            visited[number]=1;
            answer=addPrime(number);
            count++;
            if(answer!=-1)
            {
                printf("%d\n",answer);
                break;
            }
        }
        for(int i=0;i<=10001;i++)
        {
            primeLevel[i]=0;
            visited[i]=0;
        }
        clearQueue(q);
    }
}
