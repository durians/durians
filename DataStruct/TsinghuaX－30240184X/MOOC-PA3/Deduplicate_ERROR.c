#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hashCode(char s[])
{
    int h = 0, i;
    
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
            
            
            ///ERROR::::::::::
            //错误在这里
            //分开写才行:len = strlen(str), malloc(len)
            //这个错误导致莫名的exit，难怪一直OJ不了，害死人啊啊啊啊啊啊啊！！！！！
            newnode->value = (char *)malloc(strlen(str)), strcpy(newnode->value,str);
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