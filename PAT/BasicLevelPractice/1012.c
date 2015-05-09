#include <stdio.h>

int main(int argc, char *argv[]) {
    
    int A1 = 0; //能被5整除的数字中所有偶数的和；
    int A2 = 0; //将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
    int A3 = 0; //被5除后余2的数字的个数；
    double A4 = 0.0; //被5除后余3的数字的平均数，精确到小数点后1位；
    int A5 = 0; //被5除后余4的数字中最大数字。
    
    int N, a[1001], i;
    scanf("%d",&N);
    for(i = 0; i < N; i++)
        scanf("%d",a+i);
    
    int f1 = 0 ,f2 = 0,f3 = 0, n;
    
    for(i = 0; i < N; i++)
    {
        n = a[i] % 5;
        switch (n) 
        {
            case 0:
                if(a[i] % 2 == 0) A1 += a[i];
                break;
            case 1:
                f1 = 1;
                if(0 == f2)
                {
                    A2 += a[i];
                    f2 = 1;
                }    
                else
                {
                    A2 -= a[i];
                    f2 = 0;
                }
                break;
            case 2: A3++;
                break;
            case 3:f3++; A4 += a[i];
                break;
            case 4: if(a[i] > A5) A5 = a[i];
                break;    
            default:
                break;
        }
        
    }
    
    if(A1) printf("%d ", A1);
    else printf("N ");
    
    if(f1) printf("%d ",A2);
    else printf("N ");
    
    if(A3) printf("%d ",A3);
    else printf("N ");
    
    if(f3) printf("%.1f ",A4/f3);
    else printf("N ");
    
    if(A5) printf("%d",A5);
    else printf("N");
    
    return 0;
}