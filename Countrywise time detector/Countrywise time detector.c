#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int a,b,i,h1,m1,dift,t1,t,h,m;
    double d1,d2,dm1,dm2,d;
    char P[10],C1[30],C2[30],A1[5],D1[3],D2[3];
    for(;;)
    {
        printf("Enter Passcode: ");
        scanf("%s",&P);
        if(strcmp("****",P)==0)
        {
            printf("\n\t\t***PROGRAMME COUNTRY TIME DETERMINER***\n\n");//input 1
            printf("Enter the country name where you know time: ");
            scanf("%s",&C1);
            printf("Enter the time of %s(12 hours format)(HH <space> MM <space> AM/PM)= ",C1);
            scanf("%d %d %s",&h1,&m1,&A1);
            printf("Enter the Longitude of %s(degree <space> minuite <space> direction(E/W))= ",C1);
            scanf("%lf %lf %s",&d1,&dm1,&D1);

            printf("\nEnter the second country name: ");//input 2
            scanf("%s",&C2);
            printf("Enter the Longitude of %s(degree <space> minuite <space> direction(E/W))= ",C2);
            scanf("%lf %lf %s",&d2,&dm2,&D2);

            d1 = d1+(dm1/60.0);//longitude convertion
            d2 = d2+(dm2/60.0);

            if(h1>0 && h1<=12 && m1>=0 && m1<=60)//time convertion 1
            {
                t1 = (h1*60)+m1;
            }
            else
            {
                printf("\n\tEnter Valid input!\n\n");
            }


            if(strcmp("E",D1)==0 && strcmp("W",D2)==0)//longitude calculation
            {
                d = d1+d2;
            }
            else if(strcmp("E",D1)==0 && strcmp("E",D2)==0 || strcmp("W",D1)==0 && strcmp("W",D2)==0)
            {
                d = abs(d1-d2);
            }
            else
            {
                printf("\n\tEnter Valid input!\n\n");
            }


            dift = ceil(d*4.0);//convertion from lon to min


            if(strcmp("E",D1)==0 && strcmp("W",D2)==0)//differenting time
            {
                if(d1==d2)
                {
                    if(strcmp("E",D1)==0)
                    {
                        t = t1-dift;
                    }
                    else if(strcmp("W",D1)==0)
                    {
                        t = t1+dift;
                    }
                }
                else if(d1<d2)
                {
                    t = t1+dift;
                }
                else
                {
                    t = t1-dift;
                }
            }
            else if(strcmp("E",D1)==0 && strcmp("E",D2)==0)
            {
                if(d1<d2)
                {
                    t = t1+dift;
                }
                else
                {
                    t = t1-dift;
                }
            }
            else if(strcmp("W",D1)==0 && strcmp("W",D2)==0)
            {
                if(d1<d2)
                {
                    t = t1-dift;
                }
                else
                {
                    t = t1+dift;
                }
            }


            h = abs(t)/60;
            m = t%60;
            if(m<0)
            {
                m = m+60;
            }


            if(strcmp("AM",A1)==0)//second time printing with valid AM/PM
            {
                if(abs(t)>720)
                {
                    if(t>0)
                    {
                        h = abs(12-h);
                        printf("\n\n\tThe time of %s= %d:%d PM\n",C2,h,m);
                    }
                    else
                    {
                        h = abs(12-h);
                        printf("\n\n\tThe time of %s= Previous day %d:%d PM\n",C2,h,m);
                    }
                }
                else if(abs(t)<=720)
                {
                    if(t>0)
                    {
                        printf("\n\n\tThe time of %s= %d:%d AM\n",C2,h,m);
                    }
                    else if(t==0)
                    {
                        h = abs(12-h);
                        printf("\n\n\tThe time of %s= %d:%d AM\n",C2,h,m);
                    }
                    else if(t<0)
                    {
                        h = abs(12-h);
                        printf("\n\n\tThe time of %s= Previous day %d:%d PM\n",C2,h,m);
                    }
                }
            }
            else if(strcmp("PM",A1)==0)
            {
                if(abs(t)>720)
                {
                    if(t>0)
                    {
                        h = abs(12-h);
                        printf("\n\n\tThe time of %s= Next day %d:%d AM\n",C2,h,m);
                    }
                    else if(t<0)
                    {
                        h = abs(12-h);
                        printf("\n\n\tThe time of %s= %d:%d AM\n",C2,h,m);
                    }
                }
                else if(abs(t)<=720)
                {
                    if(t>0)
                    {
                        printf("\n\n\tThe time of %s= %d:%d AM\n",C2,h,m);
                    }
                    else if(t<0)
                    {
                        h = abs(12-h);
                        if(m>0)
                        {
                            h = abs(h-1);
                        }
                        printf("\n\n\tThe time of %s= Previous day %d:%d PM\n",C2,h,m);
                    }
                    else if(t==0)
                    {
                        h = abs(12-h);
                        printf("\n\n\tThe time of %s= %d:%d PM\n",C2,h,m);
                    }
                }
            }
            else
            {
                printf("\n\tEnter Valid input!\n\n");
            }
            printf("\n\t\t***Programmed by SHAHRIAR ALI SIAM***\n");
            break;
        }
        else
        {
            printf("\nINVALID PASSCODE!\n");
            continue;
        }
    }
    return 0;
}
