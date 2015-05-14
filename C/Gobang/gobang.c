////棋子 ● ○
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define W (16)
#define H (16)

char b[H][W];
int player_O, player_X;

void print()
{
    int i, j;
    
    system("clear");
    
    for(i = 0; i < H; i++)
    {
        for(j = 0; j < W; j++)
        {
            if(i == 0 || j == 0)
                printf("%3d",b[i][j]);
            else
                printf("  %c",b[i][j]);
        }
        printf("\n");
    }
}

int check_win()
{
    if(b[5][5] != '+')
        return 1;
    return 0;
}

void play()
{
    int xpos, ypos;
    
    player_O = 1;player_X=0;
    
    print();
    while(scanf("%d %d", &xpos, &ypos)!=EOF)
    {
        if( (xpos >=1 && xpos < W) &&
            (ypos >=1 && ypos < H) &&
            b[ypos][xpos] == '+')
        {
            if(player_O)
            {
                b[ypos][xpos] = 'O';
                if(check_win())
                {
                    printf("O win!\n");
                    return;
                }
                player_O = 0;
                player_X = 1;
            }
            else
            {
                b[ypos][xpos] = 'X';
                if(check_win())
                {
                    printf("X win!\n");
                    return;
                }
                player_O = 1;
                player_X = 0;
            }
            
        }
        print();
    }
    
}

void init()
{
    int i;
    
    memset(b,'+',sizeof(b));
    for(i = 0; i < W; i++)
    {
        b[0][i] = i;
        b[i][0] = i;
    }
}

int main()
{
    init();
    
    play();
    
	return 0;
}
