#include <stdio.h>
#include <string.h>

void division(const char *A,int B,char *Q,unsigned int *R)
{
    int i,n;
    unsigned int len = strlen(A);
    for (i = 0; i < len; i++) 
    {
        n = (*R)*10 +(A[i] - '0');
        (*R) = n % B;
        Q[i] = n / B + '0';
    }
}
int main(int argc, char *argv[]) {
    
    char A[1002] = {0} , Q[1002] = {0};
    unsigned int B , R = 0;
    int i = 0;
    
    scanf("%s %d",A,&B);
    // A = B * Q + R
    
    division(A,B,Q,&R);
    
    unsigned int len = strlen(Q);
    while(i < len && Q[i] == '0')
    {
        i++;
    }
    printf("%s %d",i == len ? "0" : Q+i,R);
    return 0;
}