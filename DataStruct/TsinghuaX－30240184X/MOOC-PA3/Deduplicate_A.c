#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int hashCode(char s[])
{
    unsigned int h = 0, i;
    
    for( i = 0; i < strlen(s); i++)
    {
        h = (h << 5) | (h >> 27);
        h += (int)s[i];
    }
    
    return h;
}

typedef struct _node
{
    struct _node *next;
    char *value;
    int outed;
}Node;
#define M    100000

Node h[M+1];

int main(int argc, char *argv[])
{
    char str[41] = {0};
    int key;
    struct _node *p, *newnode;
    
    int n;
    
    scanf("%d", &n);
    memset(h,0,sizeof(h));
    
    while(n--)
    {
        scanf("%s", str);
        key = hashCode(str) % M;
        
        p = h[key].next;
        
        while(p && (0 != strcmp(str, p->value)) )
            p = p->next;
        
        if(!p)//h[key]处没有p,插入
        {
            newnode = (struct _node *)malloc(sizeof(struct _node));
            newnode->outed = 0;
            newnode->value = (char *)malloc(41);
            strcpy(newnode->value,str);
            newnode->next = h[key].next;
            
            h[key].next = newnode;
        }
        else if (!p->outed)
        {
            printf("%s\n", str);
            p->outed = 1;
        }
        
    }
    
    return 0;
}