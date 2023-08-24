//Solving X,Y,Z using Cramer's Rule & Array
#include<stdio.h>
#include<math.h>

int main()
{
    double D[10][10],BD[10][10],C[5][5],d,det,dx=0.0,dy=0.0,dz=0.0,x,y,z;
    int i,j,r,c;
    printf("\t\t***EQUATION SOLVING USING CRAMER'S RULE & ARRAY***\n\n");
    printf("**Equation format must be>> ax+-by+-cz=+-C**\n\n");
    for(i=0 ; i<3 ; i++)
    {
        printf("Enter %d no. equation's coefficients(C[x]<space>C[y]<space>C[z])= ",i+1);
        for(j=0 ; j<3 ; j++)
        {
            scanf("%lf",&D[i][j]);
        }
    }
    for(i=0 ; i<3 ; i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            BD[i][j] = D[i][j];
        }
    }
    printf("\n");
    for(i=0 ; i<3 ; i++)
    {
        printf("Enter %d no. equation's constant= ",i+1);
        scanf("%lf",&C[i][0]);
    }
    d = (D[0][0] * ((D[1][1] * D[2][2]) - (D[2][1] * D[1][2]))) - (D[0][1] * ((D[1][0] * D[2][2]) - (D[2][0] * D[1][2]))) + (D[0][2] * ((D[1][0] * D[2][1]) - (D[2][0] * D[1][1])));
    if(d==0.0)
    {
        printf("\n\t\t\t<MATH ERROR>\n");
    }
    else
    {
        for(i=0 ; i<3 ; i++)
        {
            for(r=0 ; r<3 ; r++)
            {
                for(c=0 ; c<3 ; c++)
                {
                    D[r][c] = BD[r][c];
                }
            }
            for(j=0 ; j<3 ; j++)
            {
                D[j][i] = C[j][0];
            }
            det = (D[0][0] * ((D[1][1] * D[2][2]) - (D[2][1] * D[1][2]))) - (D[0][1] * ((D[1][0] * D[2][2]) - (D[2][0] * D[1][2]))) + (D[0][2] * ((D[1][0] * D[2][1]) - (D[2][0] * D[1][1])));
            if(i==0)
            {
                dx = det;
            }
            else if(i==1)
            {
                dy = det;
            }
            else if(i==2)
            {
                dz = det;
            }
        }
        x = dx/d;
        y = dy/d;
        z = dz/d;
        printf("\n\t\tx=%0.3lf\ty=%0.3lf\tz=%0.3lf\n",x,y,z);
    }
    printf("\n\t\t***Programmed By SHAHRIAR ALI SIAM***\n");
    return 0;
}
