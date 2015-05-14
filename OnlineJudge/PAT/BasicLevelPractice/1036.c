#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int N,i,j;
    char ch;
    
    scanf("%d %c",&N,&ch);
    for( i = 1; i <= (N+1)/2; i ++)
    {
        if( i == 1 || i == (N+1)/2)
        {
            for( j = 0; j < N; j++)
                printf("%c",ch);     
            printf("\n");
        }
        //else if( i % 2 == 0)
        //{
          //  printf("\n");
        //}
        else {
            printf("%c",ch);
            for(j = 1; j < N - 1; j++)
                printf(" ");
            printf("%c\n",ch);    
        }
       
    }
    return 0;    
}