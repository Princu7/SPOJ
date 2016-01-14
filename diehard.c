# include <stdio.h>
# include <stdlib.h>
int maximum(int a ,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int time[1010][1010];
int main(void)
{
     int t;
    scanf("%d",&t);
    int health,armour,i,j,max1,max2;
    for(health=0;health<=1009;health++)
    {
        for(armour=0;armour<=1009;armour++)
        {
            if(health<=5 || armour<=10)
                max1=0;
            else
                max1=2+time[health-5+3][armour-10+2];
            if(health<=20)
                max2=0;
            else
                max2=2+time[health-20+3][armour+5+2];
                time[health][armour]=maximum(max1,max2);
        }
    }
    while(t--)
    {
        scanf("%d%d",&i,&j);
        printf("%d\n",1+time[i+3][j+2]);
    }
    return 0;
}

    
            

