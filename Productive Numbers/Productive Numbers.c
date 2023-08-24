//Productive Numbers
#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,c=0;
    printf("Enter integer number: ");
    scanf("%d",&n);
    printf("\nThe producers of number %d are: ",n);
    for(i=1 ; i<=n ; i++)
    {
        if(n%i==0)
        {
            c++;
            if(i==n)
            {
                printf("%d.\n",i);
            }
            else
            {
                printf("%d,",i);
            }
        }
    }
    printf("Total Producers: %d.\n",c);
    printf("\n\t***Programmed By SHAHRIAR ALI SIAM***\n");
    return 0;
}
