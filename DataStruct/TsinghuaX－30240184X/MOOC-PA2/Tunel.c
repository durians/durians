#include <stdio.h>

int a[2000000] = {0};
int b[2000000] = {0};

int main()
{
    int n, h, max = 0, f = 0, r = 0, i;
    char op;

    scanf("%d", &n);getchar();
    while(n--)
    {
        do
        {
            op = getchar();
        }while(op!='E'&&op!='M'&&op!='D');
        
        if(op == 'E')
        {
            scanf("%d", &h);

            //in
            a[r] = h;
            b[r] = h;

            for(i = r - 1; i >= f && b[i] < h; i--)
                b[i] = h;
            r++;
        } 
        else if(op == 'M')
        {
            printf("%d\n",b[f]);
        }
        else if(op == 'D')
        {
            //out
            printf("%d\n",a[f++]);
        }
    }
    return 0;
}