#include<stdio.h>

//Galleon.Sickle.Knut
int main()
{
    int Galleon,Sickle,Knut;
    
    scanf("%d.%d.%d", &Galleon,&Sickle,&Knut);
    int p = Galleon*17*29 + Sickle*29 + Knut;
    
    scanf("%d.%d.%d", &Galleon,&Sickle,&Knut);
    int a = Galleon*17*29 + Sickle*29 + Knut;
    
    int c = a - p;
    
    if( c < 0) printf("-%d.%d.%d",-c/(17*29), -(c/29) % 17, -c % 29);
    else printf("%d.%d.%d",c/(17*29), (c/29) % 17, c % 29);
    
    return 0;
}