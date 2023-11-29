#include<stdio.h>
/*void linear(int arr[],int n,int e)
{
    int c=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==e)
        {
            c=i;
            break;
        }
    }
    if(c==0)
    {
        printf("%doesn't exist in array",e);
    }
    else
    printf("%d exist at %d position",e,c);
}*/
void binary(int arr,int n,int e)
{
    int f=0,l=n-1,c=-1;
    while(f<=l)
    {
        int mid=(f+l)/2;
        if(arr[mid]==e)
        {
            c++;
            break;
        }
        else if(arr[mid]<e)
        {
            f=mid+1;
        }
        else
        {
            l=mid-1;
        }
    }
    if(c==-1)
    {
        printf("%d doesn't exist in array",e);
    }
    else
    {
        printf("exist in array");
    }
}
void main()
{
    int arr[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int e;
    scanf("%d",&e);
    binary(arr,n,e);
}
