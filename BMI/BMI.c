//BMI_Body Mass Index
#include <stdio.h>
#include <math.h>

int main()
{
    double m,h,BMI;
    printf("\n\nEnter your weight(Kg)= ");
    scanf("%lf",&m);
    printf("Enter your height(meter)= ");
    scanf("%lf",&h);

    BMI = m / (h*h);

    printf("\nBMI report:\n\n");

    if(BMI < 18.5)
    {
        printf("BMI: %0.3lf\n",BMI);
        printf("Tui shukna, beshi beshi kha.\n\n");
    }
    else if(BMI >= 18.5 && BMI <=24.99)
    {
        printf("BMI: %0.3lf\n",BMI);
        printf("Tomar weight normal and tomar sastho onk valo\n\n");
    }
    else if(BMI >= 25.0 && BMI <=29.99)
    {
        printf("BMI: %0.3lf\n",BMI);
        printf("Tui Motku\n\n");
    }
    else if(BMI >= 30.0 && BMI <=34.99)
    {
        printf("BMI: %0.3lf\n",BMI);
        printf("Tui Motku number 1.\n\n");
    }else if(BMI >= 35.0 && BMI <=39.99)
    {
        printf("BMI: %0.3lf\n",BMI);
        printf("Tui Motku number 2.\n\n");
    }
    else if(BMI >=40.0)
    {
        printf("BMI: %0.3lf\n",BMI);
        printf("Kom kha, ar koto mota hobi? tui Motku number 3.\n\n");
    }
    return 0;
}
