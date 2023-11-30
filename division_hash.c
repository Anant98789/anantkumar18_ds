#include<stdio.h>
int nearest(int ts)
{
    int flag=0,j;
    for(int i=ts;i>=2;i--)
    {
        for(j=2;j<sqrt(ts);j++)
        {

            if(i%j==0)
            {
                break;
            }
        }
        if(j>sqrt(i))
        {
            return i;
        }
    }
}
int hash(int key,int ts)
{
    int np=nearest(ts);
    return key%np;
}
void main()
{
    printf("%d \n",hash(1234,100));
    printf("%d",hash(9767,100));
}
