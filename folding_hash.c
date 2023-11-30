
#include<stdio.h>
#include<math.h>
int DigitCount(int n){
    int c=0;
    while(n!=0){
        n=n/10;
        c++;
    }
    return c;
}


int FoldingHash(long long n,int TS){
    int d=DigitCount(TS-1);
    int mod=pow(10,d);
    int sum=0;
    while(n!=0){
        int a=n%mod;
        sum=sum+a;
        n=n/mod;
    }
    return sum%TS;
}


int main(){
    printf("%d\n",FoldingHash(1234,100));
printf("%d\n",FoldingHash(4565,100));
    return 0;

}
