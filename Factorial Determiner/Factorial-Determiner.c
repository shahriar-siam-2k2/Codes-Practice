#include<stdio.h>
#include<conio.h>

int main() {
    int N, F;
    printf("Enter Integer Number= ");
    scanf("%d", &N);
    F = 1;
    for(N; N > 0;) {
        F = F*N;
        N = N-1;
    }
    printf("Factorial is %d\n", F);
    getch();
    return 0;
}
