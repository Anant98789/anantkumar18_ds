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
int MidSquare(long long n,int TS){
    int d=DigitCount(TS-1);
    int a=DigitCount(n);
    int r=((2*a)-d)/2;
    int e=pow(10,r);
    n=(n*n)/e;
    int mod=pow(10,d);
    return n%mod;

}
int main(){
    printf("%d\n",MidSquare(1234,100));
    printf("%d\n",MidSquare(4565,100));


    return 0;
}
