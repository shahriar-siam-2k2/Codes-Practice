#include<stdio.h>
#include<math.h>

int main()
{
    double x,y,r,ang,thet,pie;
    pie=3.1416;
    char c;
    printf("\t***PROGRAMME CARTESIAN<>POLAR CONVERTER***\n\n");
    printf("***If you want to determine CARTESIAN to POLAR, Enter 'p' or 'P'***\n");
    printf("***If you want to determine POLAR to CARTESIAN, Enter 'c' or 'C'***\n\n");
    
    printf("Which form do you want to determine?= ");
    scanf("%c",&c);
    
    if(c=='p' || c=='P')
    {
        printf("Enter the value of x= ");
        scanf("%lf",&x);
        printf("Enter the value of y= ");
        scanf("%lf",&y);
        r=sqrt(pow(x,2)+pow(y,2));
        //determining quadrant side
        if(x>0 && y>0)//1st quadrant
        {
            ang=atan(y/x);
            thet=(180.0*ang)/pie;
            if(-180.0<thet && thet<=180.0)
            {
                printf("\nCartesian form: (%0.10lf,%0.10lf)\n",x,y);
                printf("Polar form: (%0.5lf,%0.5lf)\n\n",r,thet);
                printf("\t***Programmed by Shahriar Ali Siam***\n");
            }
            else
            {
                printf("\n<<ERROR>>\n");
                printf("The value of angle should be -180<angle<=180\n\n");
                printf("\t***Programmed by Shahriar Ali Siam***\n");
            }
        }
        else if(x<0 && y>0)//2nd quadrant
        {
            ang=atan(y/x);
            thet=((180.0*ang)/pie)+180.0;
            if(-180.0<thet && thet<=180.0)
            {
                printf("\nCartesian form: (%0.10lf,%0.10lf)\n",x,y);
                printf("Polar form: (%0.5lf,%0.5lf)\n\n",r,thet);
                printf("\t***Programmed by Shahriar Ali Siam***\n");
            }
            else
            {
                printf("\n<<ERROR>>\n");
                printf("The value of angle should be -180<angle<=180\n\n");
                printf("\t***Programmed by Shahriar Ali Siam***\n");
            }
        }
        else if(x<0 && y<0)//3rd quadrant
        {
            ang=atan(y/x);
            thet=((180.0*ang)/pie)-180.0;
            if(-180.0<ang && ang<=180.0)
            {
                printf("\nCartesian form: (%0.10lf,%0.10lf)\n",x,y);
                printf("Polar form: (%0.5lf,%0.5lf)\n\n",r,thet);
                printf("\t***Programmed by Shahriar Ali Siam***\n");
            }
            else
            {
                printf("\n<<ERROR>>\n");
                printf("The value of angle should be -180<angle<=180\n\n");
                printf("\t***Programmed by Shahriar Ali Siam***\n");
            }
        }
        else if(x>0 && y<0)//4th quadrant
        {
            ang=atan(y/x);
            thet=(180.0*ang)/pie;
            if(-180.0<thet && thet<=180.0)
            {
                printf("\nCartesian form: (%0.10lf,%0.10lf)\n",x,y);
                printf("Polar form: (%0.5lf,%0.5lf)\n\n",r,thet);
                printf("\t***Programmed by Shahriar Ali Siam***\n");
            }
            else
            {
                printf("\n<<ERROR>>\n");
                printf("The value of angle should be -180<angle<=180\n\n");
                printf("\t***Programmed by Shahriar Ali Siam***\n");
            }
        }
        else if(x==0 && y==0)
        {
            printf("\nCartesian form: (%0.10lf,%0.10lf)\n",x,y);
            printf("\t***THE MIDDLE POINT***\n");
            printf("\t***INVALID POLAR FORM!***\n\n");
            printf("\t***Programmed by Shahriar Ali Siam***\n");
        }
    }
    else if(c=='c' || c=='C')
    {
        printf("Enter the value of r (Integer or Decimal number only)= ");
        scanf("%lf",&r);
        printf("Enter the value of angle (Degree only)= ");
        scanf("%lf",&ang);
        if(r==0 && ang==0)
        {
            printf("\nCartesian form: (%0.5lf,%0.5lf)\n",x,y);
            printf("Polar form: (0.00000,0.00000)\n");
            printf("\t***THE MIDDLE POINT***\n\n");
            printf("\t***Programmed by Shahriar Ali Siam***\n");
        }
        else if(r<0)
        {
            printf("\n\t\t<<ERROR>>\n");
            printf("***The value of 'r' shouldn't be negative!***\n\n");
            printf("\t***Programmed by Shahriar Ali Siam***\n");
        }
        else
        {
            thet=(pie*ang)/180.0;
            x=r*cos(thet);
            y=r*sin(thet);
            printf("\nPolar form: (%0.5lf,%0.5lf)\n",r,ang);
            printf("Cartesian form: (%0.5lf,%0.5lf)\n\n",x,y);
            printf("\t***Programmed by Shahriar Ali Siam***\n");
        }
    }
    else
    {
        printf("\n\t\t<<ERROR>>\n");
        printf("You have to enter 'p'/'P' or 'c'/'C' to proceed!\n\n");
        printf("\t***Programmed by Shahriar Ali Siam***\n");
    }
    
    return 0;
}





