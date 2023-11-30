
#include<stdio.h>
int DoubleHash(int a[],int size,int x){
    int h=x%size;
    int flag=1;
    if(a[h]==0){
        a[h]=x;

    }
    else{
        flag=0;
        int i=1;
        int hdash=(2*x -7);
        while(flag==0){
            int pos=(h+ i*hdash)%size;
            i++;
            if(a[pos]==0){
                a[pos]=x;
                flag=1;
            }
        }
    }
    return flag;
}
int main(){
    int n,x,ts=15;
    int table[15]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        DoubleHash(table,ts,x);
    }
    for(int i=0;i<ts;i++){
        printf("%d  ",i);
    }
    printf("\n");
    for(int i=0;i<ts;i++){
        printf("%d  ",table[i]);
    }





    return 0;
}
