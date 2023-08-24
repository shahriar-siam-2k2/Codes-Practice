#include<stdio.h>

int main()
{
    int a,b,bfol,bsesh;
    scanf("%d %d",&a,&b);
    bfol= a/b;
    bsesh= a%b;
    printf("bfol= %d\n",bfol);
    printf("bsesh= %d\n\n",bsesh);
    printf("Format= %d-%d\n",bfol,bsesh);
    return 0;
}
